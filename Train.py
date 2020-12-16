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
        self.categorical_feature_fields = []
        self.col_names = []
        self.min_max = preprocessing.MinMaxScaler(feature_range=(0, 1))

        self.events_onehot = None
        self.events = self.load_events()

    def load_events(self):
        print('loading data......', end='')
        train_df = pd.read_csv('./trace_data/match.csv')
        train_df.columns = event_para_dict.keys()
        train_df.drop(['request', 'S', 'E', 'D'], axis=1, inplace=True)
        train_df.dropna(axis=1, inplace=True, how='all')
        self.col_names = train_df.columns
        # the last column 'Blank' is a numeric feature
        self.categorical_feature_fields = self.col_names.copy().drop('Blank')
        train_df['Blank'] = self.min_max.fit_transform(train_df['Blank'].to_numpy().reshape(-1, 1))

        # get one-hot form of events data as label
        dummies = []
        for column in self.categorical_feature_fields:
            dummies.append(pd.get_dummies(train_df[column], prefix=column, dummy_na=train_df[column].hasnans))
        self.events_onehot = pd.concat(dummies + [train_df['Blank']], axis=1)

        # preprocess for embeddings of multiple categorical features, convert input data to global index format
        self.n_categorical_features = 0
        for column in self.categorical_feature_fields:
            # get unique values in each column
            indices, values = pd.factorize(train_df[column], na_sentinel=None, sort=True)
            self.values_dict[column] = values
            # assign global indices
            self.index_offset[column] = self.n_categorical_features
            indices = indices + self.n_categorical_features
            self.n_categorical_features += values.size
            self.feature_field_size[column] = values.size
            # map values to indices
            train_df[column] = indices

        self.n_feature_fields = train_df.columns.size

        # fig, ax = plt.subplots(1, 1)
        # ax.hist(train_df['Blank'].to_numpy(), bins=100)
        # plt.show()

        print('done')
        return train_df

    #
    def decode_local_index(self, event_onehot, column, softmax=False):
        feature_field = event_onehot[
                        self.index_offset[column]:self.index_offset[column] + self.feature_field_size[column]]
        if softmax:
            p = scipy.special.softmax(feature_field)
            local_index = np.random.choice(len(feature_field), p=p)
        else:
            local_index = np.argmax(feature_field)
        return local_index

    # convert one-hot format (used in label data) to
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
        for column in self.categorical_feature_fields:
            local_index = self.decode_local_index(event_onehot, column, softmax)
            if shield:
                # file must be -1 (local_index = 0) for collective functions
                if mpi_func in collectiveList and column == 'file':
                    local_index = 0
                # unused para must be nan (local_index = -1)
                if column not in function_para_dict[mpi_func]:
                    local_index = self.feature_field_size[column] - 1
                    if str(self.values_dict[column][local_index]) != 'nan':
                        print('error: unused parameter must be nan')
            global_index = local_index + self.index_offset[column]
            event_input.append(global_index)
            event_raw.append(self.values_dict[column][local_index])
        event_input.append(blank[0])
        event_raw.append(blank_raw)
        return event_input, event_raw

    def print_event_raw(self, event_raw):
        line = ''
        for feature in event_raw:
            if str(feature) == 'nan':
                line += ','
            else:
                line += str(feature) + ','
        line = str.rstrip(line, ',')
        print(line)

    def __len__(self):
        return len(self.events) - self.args.sequence_length

    def __getitem__(self, index):
        x = torch.tensor(self.events[index:index + self.args.sequence_length].to_numpy(), dtype=torch.float).to(device)
        y = torch.tensor(self.events_onehot[index + 1:index + 1 + self.args.sequence_length].to_numpy(),
                         dtype=torch.float).to(device)
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
        shuffle=True
    )

    criterion_num = nn.MSELoss()
    criterion_cat = nn.CrossEntropyLoss()

    optimizer = optim.Adam(model.parameters(), lr=0.01)
    scheduler = torch.optim.lr_scheduler.MultiStepLR(optimizer, milestones=[15,30], gamma=0.1)
    # optimizer = optim.RMSprop(model.parameters(), lr=0.01)

    for epoch in range(args.max_epochs):
        state_h, state_c = model.init_state(args.sequence_length)

        for batch, (x, y) in enumerate(dataloader):
            optimizer.zero_grad()
            y_pred, (state_h, state_c) = model(x, (state_h, state_c))

            # # for debug
            # # fig, ax = plt.subplots(2, 1)
            # y_pred_plt = y_pred.detach().to('cpu').numpy()[0][-1].reshape(-1)
            # y_plt = y.detach().to('cpu').numpy()[0][-1].reshape(-1)
            # # ax[0].hist(y_pred_plt, bins=20)
            # # ax[1].hist(y_plt, bins=20)
            # # plt.show()
            # _, event_pred = dataset.decode_onehot(y_pred_plt)
            # _, event = dataset.decode_onehot(y_plt)

            loss = criterion_num(y_pred[:, :, -1:], y[:, :, -1:]) * 2
            for feature_field in dataset.categorical_feature_fields:
                begin = dataset.index_offset[feature_field]
                end = dataset.index_offset[feature_field] + dataset.feature_field_size[feature_field]
                loss = loss + criterion_cat(y_pred[:, :, begin:end].transpose(1, 2),
                                            torch.argmax(y[:, :, begin:end], dim=2))
            loss = loss / (len(dataset.categorical_feature_fields)+1)


            state_h = state_h.detach()
            state_c = state_c.detach()

            loss.backward()
            optimizer.step()

            print({'epoch': epoch, 'batch': batch, 'lr':scheduler.get_last_lr(), 'loss': loss.item()})

            # for debug
            # dataset.print_event_raw(event)
            # dataset.print_event_raw(event_pred)
            # print('')

        scheduler.step()


def predict(dataset, model, events, next_events=100):
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
        dataset.print_event_raw(event_raw)
    return events


parser = argparse.ArgumentParser()
parser.add_argument('--max-epochs', type=int, default=10)
parser.add_argument('--batch-size', type=int, default=128)
parser.add_argument('--sequence-length', type=int, default=30)
args = parser.parse_args()

dataset = Dataset(args)

model = Model(dataset).to(device)
pytorch_total_params = sum(p.numel() for p in model.parameters())
print('%d parameters in total' % pytorch_total_params)
train(dataset, model, args)

print('')
test_begin = 0
test_input = dataset.events[test_begin:test_begin + args.sequence_length].copy()
predict(dataset, model, test_input) #, dataset.events.shape[0] - args.sequence_length)
