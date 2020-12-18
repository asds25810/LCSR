import argparse
import torch
import numpy as np
from torch import nn, optim
from torch.utils.data import DataLoader
import pandas as pd
from collections import Counter
from MPI_define import *
from sklearn import preprocessing
import matplotlib.pyplot as plt
import scipy.special
from time import perf_counter
from torch.multiprocessing import Pool, Process, set_start_method

device = torch.device('cuda:6' if torch.cuda.is_available() else 'cpu')
torch.cuda.set_device(device)


class Dataset(torch.utils.data.Dataset):
    def __init__(
            self,
            args,
    ):
        self.args = args
        self.n_feature_fields = 0
        self.n_categorical_features = 0
        self.feature_field_size = {}
        self.values_dict = {}
        self.index_offset = {}
        self.index_offset_np = None
        self.categorical_feature_fields = []
        self.col_names = []
        self.min_max = preprocessing.MinMaxScaler(feature_range=(0, 1))

        self.events = self.load_events()

    def load_events(self):
        print('loading data......', end='')
        train_df = pd.read_csv('./trace_data/lu.S.8/match.csv')
        train_df.columns = event_para_dict.keys()
        train_df.drop(['request', 'S', 'E', 'D'], axis=1, inplace=True)
        train_df.dropna(axis=1, inplace=True, how='all')
        self.col_names = train_df.columns

        # the last column 'Blank' is a numeric feature
        self.categorical_feature_fields = self.col_names.copy().drop('Blank')
        train_df['Blank'] =  self.min_max.fit_transform(np.log(train_df['Blank'].to_numpy().reshape(-1, 1)+1))
        fig, ax = plt.subplots(1, 1)
        ax.hist(train_df['Blank'].to_numpy(), bins=100)
        plt.show()

        # preprocess for embeddings of multiple categorical features, convert input data to global index format
        self.n_categorical_features = 0
        self.index_offset_np = []
        for column in self.categorical_feature_fields:
            # get unique values in each column
            indices, values = pd.factorize(train_df[column], na_sentinel=None, sort=True)
            self.values_dict[column] = values
            # assign global indices
            self.index_offset[column] = self.n_categorical_features
            self.index_offset_np.append(self.index_offset[column])
            indices = indices + self.n_categorical_features
            self.n_categorical_features += values.size
            self.feature_field_size[column] = values.size
            # map values to indices
            train_df[column] = indices

        self.n_feature_fields = train_df.columns.size
        self.index_offset_np.append(0)  # the offset of 'Blank' column is 0
        self.index_offset_np = np.array(self.index_offset_np)
        # self.index_offset_np = np.array(self.index_offset.values())  # is it equivalent???



        print('done')
        return train_df

    # convert one-hot format (used in prediction data) to
    # local index format (used in label data)
    def decode_local_index(self, event_onehot, column, softmax=False):
        feature_field = event_onehot[
                        self.index_offset[column]:self.index_offset[column] + self.feature_field_size[column]]
        if softmax:
            p = scipy.special.softmax(feature_field)
            local_index = np.random.choice(len(feature_field), p=p)
        else:
            local_index = np.argmax(feature_field)
        return local_index

    # convert one-hot format (used in prediction data) to
    # global index format (used in input data) and
    # raw format of trace
    def decode_onehot(self, event_onehot, softmax=False, shield=False):
        blank = event_onehot[-1:]
        blank_raw = self.min_max.inverse_transform([blank])[0][0]
        event_input = []
        event_raw = []

        # first, decode mpi function name
        local_index = self.decode_local_index(event_onehot, 'function', softmax)
        mpi_func = self.values_dict['function'][local_index]
        if mpi_func not in function_para_dict.keys():
            print('error: unexpected mpi function')
        for column in self.categorical_feature_fields:
            local_index = self.decode_local_index(event_onehot, column, softmax)
            # force parameter values to fit corresponding mpi function
            if shield:
                # file must be -1 (local_index = 0) for collective functions
                if mpi_func in collectiveList and column == 'file':
                    local_index = 0
                # unused para must be nan (local_index = feature_field_size - 1)
                if column not in function_para_dict[mpi_func]:
                    local_index = self.feature_field_size[column] - 1
                    if str(self.values_dict[column][local_index]) != 'nan':
                        print('error: unused parameter must be nan')
            global_index = local_index + self.index_offset[column]
            event_input.append(global_index)
            event_raw.append(self.values_dict[column][local_index])
        event_input.append(blank[0])
        event_raw.append(np.exp(blank_raw)-1)
        return event_input, event_raw

    def get_event_str(self, event_raw):
        line = ''
        for feature in event_raw:
            if str(feature) == 'nan':
                line += ','
            else:
                line += str(feature) + ','
        line = str.rstrip(line, ',')
        return line

    def __len__(self):
        return len(self.events) - self.args.sequence_length

    def __getitem__(self, index):
        # x is global index format, y is local index format
        # local = global - offset
        x = torch.tensor(self.events[index:index + self.args.sequence_length].to_numpy(), dtype=torch.float)
        y = torch.tensor(self.events[index + 1:index + self.args.sequence_length + 1].to_numpy() - self.index_offset_np,
                         dtype=torch.float)
        return x, y


class Model(nn.Module):
    def __init__(self, dataset):
        super(Model, self).__init__()
        self.lstm_size = 32
        self.embedding_dim = 16
        self.num_layers = 2

        self.embedding = nn.Embedding(
            num_embeddings=dataset.n_categorical_features,
            embedding_dim=self.embedding_dim,
        )

        self.lstm = nn.LSTM(
            input_size=(dataset.n_feature_fields - 1) * self.embedding_dim + 1,
            hidden_size=self.lstm_size,
            num_layers=self.num_layers,
            # dropout=0.2
        )
        for param in self.lstm.parameters():
            if len(param.shape) >= 2:
                torch.nn.init.orthogonal_(param.data)
            else:
                torch.nn.init.normal_(param.data)
        self.fc = nn.Linear(self.lstm_size, dataset.n_categorical_features + 1)
        torch.nn.init.xavier_normal_(self.fc.weight.data)
        torch.nn.init.normal_(self.fc.bias.data)

    def forward(self, x, prev_state):
        categorical_x = x[:, :, 0:-1].long()
        numeric_x = x[:, :, -1:]
        embed = self.embedding(categorical_x)
        output = torch.cat([torch.reshape(embed, (embed.shape[0], embed.shape[1], -1)), numeric_x], dim=2)

        output, state = self.lstm(output, prev_state)
        logits = self.fc(output)

        return logits, state

    def init_state(self, sequence_length):
        return (torch.zeros(self.num_layers, sequence_length, self.lstm_size).to(device),
                torch.zeros(self.num_layers, sequence_length, self.lstm_size).to(device))


def train(dataset, model, args):
    model.train()

    dataloader = DataLoader(
        dataset,
        batch_size=args.batch_size,
        num_workers=8,
        pin_memory=True,
        shuffle=True
    )

    criterion_num = nn.MSELoss()
    criterion_cat = nn.CrossEntropyLoss()

    optimizer = optim.Adam(model.parameters(), lr=0.01)
    scheduler = torch.optim.lr_scheduler.MultiStepLR(optimizer, milestones=[15, 30], gamma=0.1)
    # scheduler = torch.optim.lr_scheduler.ExponentialLR(optimizer, gamma=0.1)
    # scheduler = torch.optim.lr_scheduler.StepLR(optimizer, step_size=2000, gamma=0.1)
    # optimizer = optim.RMSprop(model.parameters(), lr=0.01)

    for epoch in range(args.max_epochs):
        # state_h, state_c = model.init_state(args.sequence_length)
        for batch, (x, y) in enumerate(dataloader):
            state_h, state_c = model.init_state(args.sequence_length)
            optimizer.zero_grad()
            x = x.to(device)
            y = y.to(device)
            y_pred, (state_h, state_c) = model(x, (state_h, state_c))

            # loss for numerical feature field
            loss_num = criterion_num(y_pred[:, :, -1:], y[:, :, -1:]) * 5
            # loss for categorical feature field
            loss_cat = 0
            for i, feature_field in enumerate(dataset.categorical_feature_fields):
                begin = dataset.index_offset[feature_field]
                end = dataset.index_offset[feature_field] + dataset.feature_field_size[feature_field]
                loss_cat = loss_cat + criterion_cat(y_pred[:, :, begin:end].transpose(1, 2), y[:, :, i].long())
            loss_cat = loss_cat/len(dataset.categorical_feature_fields)
            loss = loss_cat + loss_num

            state_h = state_h.detach()
            state_c = state_c.detach()

            loss.backward()
            optimizer.step()

            if batch % 10 == 0:
                print({'epoch': epoch, 'batch': batch, 'lr': scheduler.get_last_lr(), 'loss_cat': loss_cat.item(),
                   'loss_num': loss_num.item()})

                # for debug
                # y_pred_plt = y_pred.detach().to('cpu').numpy()[0][-1]
                # y_plt = y.detach().to('cpu').numpy()[0][-1]
                # _, event_pred = dataset.decode_onehot(y_pred_plt)
                # _, event = dataset.decode_onehot(y_plt)
                # print(dataset.get_event_str(event))
                # print(dataset.get_event_str(event_pred))
                # print('')

        scheduler.step()

def validate(dataset, model):
    with open('validate.txt', 'w') as file:
        model.eval()
        dataloader = DataLoader(
            dataset,
            batch_size=args.batch_size,
            num_workers=4,
            pin_memory=True,
            # shuffle=True
        )
        criterion_num = nn.MSELoss()
        criterion_cat = nn.CrossEntropyLoss()

        state_h, state_c = model.init_state(args.sequence_length)
        for batch, (x, y) in enumerate(dataloader):
            x = x.to(device)
            y = y.to(device)
            y_pred, (state_h, state_c) = model(x, (state_h, state_c))

            # loss for numerical feature field
            loss_num = criterion_num(y_pred[:, :, -1:], y[:, :, -1:]) * 5
            # loss for categorical feature field
            loss_cat = 0
            for i, feature_field in enumerate(dataset.categorical_feature_fields):
                begin = dataset.index_offset[feature_field]
                end = dataset.index_offset[feature_field] + dataset.feature_field_size[feature_field]
                loss_cat = loss_cat + criterion_cat(y_pred[:, :, begin:end].transpose(1, 2), y[:, :, i].long())
            loss_cat = loss_cat / len(dataset.categorical_feature_fields)
            loss = loss_cat + loss_num

            state_h = state_h.detach()
            state_c = state_c.detach()

            if (batch+1) * args.batch_size >= len(dataset):
                break
            for index in range(args.batch_size):
                last_event_logits = y_pred[index][-1]
                _, event_raw = dataset.decode_onehot(last_event_logits.detach().to('cpu').numpy(), softmax=False,
                                                               shield=True)
                event_pred = dataset.get_event_str(event_raw)

                event = []
                for i, feature_field in enumerate(dataset.categorical_feature_fields):
                   event.append(dataset.values_dict[feature_field][y[index,-1,i].detach().to('cpu').numpy().astype(int)])
                Blank = y[index, -1, -1].detach().to('cpu').numpy()
                Blank = dataset.min_max.inverse_transform(Blank.reshape(1, -1))[0][0]
                Blank = np.exp(Blank)-1
                event.append(Blank)
                event = dataset.get_event_str(event)
                file.write('%f %f\n'%(loss_cat, loss_num))
                file.write(event+'\n')
                file.write(event_pred+'\n')
            print(batch)



def predict(dataset, model, events, next_events=1000):
    model.eval()

    state_h, state_c = model.init_state(events.shape[0])

    for i in range(0, next_events):
        x = torch.tensor([events[i:].to_numpy()], dtype=torch.float).to(device)
        y_pred, (state_h, state_c) = model(x, (state_h, state_c))

        last_event_logits = y_pred[0][-1]
        event_input, event_raw = dataset.decode_onehot(last_event_logits.detach().to('cpu').numpy(), softmax=True,
                                                       shield=True)
        events.loc[len(events.index)] = event_input

        # output predicted events
        print(dataset.get_event_str(event_raw))
    return events


if __name__ == '__main__':
    # set_start_method('spawn')

    parser = argparse.ArgumentParser()
    parser.add_argument('--max-epochs', type=int, default=10)
    parser.add_argument('--batch-size', type=int, default=128)
    parser.add_argument('--sequence-length', type=int, default=128)
    args = parser.parse_args()

    dataset = Dataset(args)

    model = Model(dataset).to(device)
    pytorch_total_params = sum(p.numel() for p in model.parameters())
    print('%d parameters in total' % pytorch_total_params)
    train(dataset, model, args)

    print('')
    test_begin = 0
    test_input = dataset.events[test_begin:test_begin + args.sequence_length].copy()
    test_n_event = 1000

    print('validating model......', end='')
    validate(dataset, model)
    print('done')

    t_begin = perf_counter()
    predict(dataset, model, test_input, test_n_event)  # , dataset.events.shape[0] - args.sequence_length)
    t_end = perf_counter()
    print("Total elapsed time for generating %d events: %f sec" % (test_n_event, t_end - t_begin))
