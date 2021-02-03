import argparse
import torch
import numpy as np
from torch import nn, optim
from torch.utils.data import DataLoader
from Model_LSTM import Model
from Trace_Dataset import Dataset
import matplotlib.pyplot as plt
import math
import time
from TraceStat import TraceStat

device = torch.device('cuda:0' if torch.cuda.is_available() else 'cpu')
torch.cuda.set_device(device)
data_path = '/data/sunjw/LCSR/MG-D-64/'


class DataPrefetcher():
    def __init__(self, loader):
        self.loader = iter(loader)
        self.stream = torch.cuda.Stream()
        self.preload()

    def preload(self):
        try:
            self.batch = next(self.loader)
        except StopIteration:
            self.batch = None
            return
        with torch.cuda.stream(self.stream):
            self.batch[0] = self.batch[0].to(device=device, non_blocking=True)  # x
            self.batch[1] = self.batch[1].to(device=device, non_blocking=True)  # y

    def next(self):
        torch.cuda.current_stream().wait_stream(self.stream)
        batch = self.batch
        self.preload()
        return batch


def train(dataset, model, args):
    model.train()

    dataloader = DataLoader(
        dataset,
        batch_size=args.batch_size,
        num_workers=2,
        pin_memory=True,
        drop_last=True,
        shuffle=True
    )
    criterion_num = nn.MSELoss()
    criterion_cat = nn.CrossEntropyLoss()

    # optimizer = optim.Adam(model.parameters(), lr=0.01)
    optimizer = optim.AdamW(model.parameters(), lr=0.01)
    print('%d parameter group(s)' % len(list(model.parameters())))
    print('%d parameter group(s)' % len(optimizer.param_groups))
    scheduler = torch.optim.lr_scheduler.MultiStepLR(optimizer, milestones=[2, 3], gamma=0.5)

    for epoch in range(args.max_epochs):
        prefetcher = DataPrefetcher(dataloader)
        batch = prefetcher.next()
        batch_id = 0

        # state_h, state_c = model.init_state(args.batch_size)
        # state_h = state_h.to(device)
        # state_c = state_c.to(device)

        while batch is not None:
            state_h, state_c = model.init_state(args.batch_size)
            state_h = state_h.to(device)
            state_c = state_c.to(device)
            optimizer.zero_grad()
            (x, y) = batch
            # x = x.to(device)
            # y = y.to(device)
            y_pred, (state_h, state_c) = model(x, (state_h, state_c))

            # loss for numerical feature field
            loss_num = criterion_num(y_pred[:, :, -dataset.n_numerical_features:],
                                     y[:, :, -dataset.n_numerical_features:]) * 2.0
            #
            # loss_num = torch.mean(torch.log(torch.cosh(
            #     y_pred[:, -1, -dataset.n_numerical_features:] - y[:, -1, -dataset.n_numerical_features:]))) * 1.0

            # MAPE of numerical features
            mape = []
            spe = []
            for i, field in enumerate(dataset.numerical_feature_fields):
                prediction = y_pred[:, :, i - dataset.n_numerical_features].cpu().detach().numpy()
                label = y[:, :, i - dataset.n_numerical_features].cpu().detach().numpy()
                prediction = np.clip(prediction, a_min=0.0, a_max = 100.0)
                mask = label > 0.0
                prediction = prediction[mask]
                label = label[mask]

                # if batch_id>2000 or batch_id ==0:
                #     max = np.max(np.stack([prediction, label]))
                #     min = np.min(np.stack([prediction, label]))
                #     plt.xlim([min, max])
                #     plt.ylim([min, max])
                #     plt.scatter(prediction, label)
                #     plt.xlabel('prediction')
                #     plt.ylabel(str(field))
                #     plt.show()

                mape.append(np.mean(np.abs(prediction - label) / label))
                spe.append((np.sum(prediction) - np.sum(label)) / np.sum(label))

                # prediction = dataset.min_max[field].inverse_transform(prediction.reshape(-1, 1))
                prediction = dataset.inverse_scale(prediction.reshape(-1, 1), field)
                # label = dataset.min_max[field].inverse_transform(label.reshape(-1, 1))
                label = dataset.inverse_scale(label.reshape(-1, 1), field)
                mape.append(np.mean(np.abs(prediction - label) / label))
                spe.append((np.sum(prediction) - np.sum(label)) / np.sum(label))

                # if batch_id > 2000 or batch_id ==0:
                #     max = np.max(np.stack([prediction, label]))
                #     min = np.min(np.stack([prediction, label]))
                #     plt.xlim([min, max])
                #     plt.ylim([min, max])
                #     plt.scatter(prediction, label)
                #     plt.xlabel('prediction')
                #     plt.ylabel(str(field))
                #     plt.show()

            # loss for categorical feature field
            loss_cat = 0
            for i, feature_field in enumerate(dataset.categorical_feature_fields):
                begin = dataset.index_offset[feature_field]
                end = dataset.index_offset[feature_field] + dataset.feature_field_size[feature_field]
                loss_cat = loss_cat + criterion_cat(y_pred[:, :, begin:end].transpose(1, 2), y[:, :, i].long())
                # loss_cat = loss_cat + criterion_cat(y_pred[:, :, begin:end], y[:, :, i].long())
            loss_cat = loss_cat / len(dataset.categorical_feature_fields)
            loss = loss_cat + loss_num

            state_h = state_h.detach()
            state_c = state_c.detach()

            loss.backward()
            optimizer.step()

            if batch_id % 50 == 0:
                print({'epoch': epoch, 'batch': batch_id, 'lr': optimizer.param_groups[0]['lr'],
                       'loss_cat': loss_cat.item(),
                       'loss_num': loss_num.item(),
                       'SPE': spe,
                       'MAPE': mape})

            batch_id += 1
            batch = prefetcher.next()

            # optimizer.param_groups[0]['lr'] = 0.05 * math.pow(0.01, args.batch_size * batch_id * 1.0 /len(dataset))

        scheduler.step()


# prepare initial states for predicting
def warmup(dataset, model, n_steps):
    model.eval()

    state_h, state_c = model.init_state(dataset.n_procs)
    state_h = state_h.to(device)
    state_c = state_c.to(device)

    begin_index = np.cumsum(dataset.n_events) - dataset.n_events

    for i in range(n_steps):
        x = np.zeros(shape=(dataset.n_procs, 1, dataset.n_feature_fields))
        for proc_id in range(dataset.n_procs):
            x[proc_id, 0, :] = dataset.events[begin_index[proc_id] + i, :]
        x = torch.tensor(x, dtype=torch.float).to(device)

        y_pred, (state_h, state_c) = model(x, (state_h, state_c))
        state_h = state_h.detach()
        state_c = state_c.detach()
    # dataset.initial_state = (state_h.cpu().detach().numpy(), state_c.cpu().detach().numpy())
    dataset.initial_data = np.zeros(shape=(dataset.n_procs, 1, dataset.n_feature_fields))
    for proc_id in range(dataset.n_procs):
        dataset.initial_data[proc_id, 0, :] = dataset.events[begin_index[proc_id] + n_steps, :]


def validate(dataset, model, n_steps):
    model.eval()
    dataset.prepare4decode_gpu(device)

    criterion_num = nn.MSELoss()
    criterion_cat = nn.CrossEntropyLoss()

    state_h, state_c = model.init_state(dataset.n_procs)
    state_h = state_h.to(device)
    state_c = state_c.to(device)

    begin_index = np.cumsum(dataset.n_events) - dataset.n_events

    for i in range(n_steps):
        x_np = np.zeros(shape=(dataset.n_procs, 1, dataset.n_feature_fields))
        y_np = np.zeros(shape=(dataset.n_procs, 1, dataset.n_feature_fields))
        for proc_id in range(dataset.n_procs):
            x_np[proc_id, 0, :] = dataset.events[begin_index[proc_id] + i, :]
            y_np[proc_id, 0, :] = dataset.events[begin_index[proc_id] + i + 1, :] - dataset.index_offset_np
        x = torch.tensor(x_np, dtype=torch.float).to(device)
        y = torch.tensor(y_np, dtype=torch.float).to(device)

        y_pred, (state_h, state_c) = model(x, (state_h, state_c))
        state_h = state_h.detach()
        state_c = state_c.detach()

        # loss for numerical feature field
        loss_num = criterion_num(y_pred[:, 0, -dataset.n_numerical_features:],
                                 y[:, 0, -dataset.n_numerical_features:]) * 1.0
        loss_cat = 0
        for j, feature_field in enumerate(dataset.categorical_feature_fields):
            begin = dataset.index_offset[feature_field]
            end = dataset.index_offset[feature_field] + dataset.feature_field_size[feature_field]
            # loss_cat = loss_cat + criterion_cat(y_pred[:, :, begin:end].transpose(1, 2), y[:, :, j].long())
            loss_cat = loss_cat + criterion_cat(y_pred[:, 0, begin:end], y[:, 0, j].long())
        loss_cat = loss_cat / len(dataset.categorical_feature_fields)
        loss = loss_cat + loss_num
        print({
            'step':i,
            'loss_cat':loss_cat.item(),
            'loss_num':loss_num.item(),
        })
        tmp = torch.zeros((dataset.n_procs, 1, dataset.n_feature_fields), dtype=torch.float).to(device)
        y_pred_global = dataset.onehot2global_gpu(y_pred, tmp)
        y_pred_np = y_pred_global.cpu().detach().numpy()
        for proc_id in range(dataset.n_procs):
            x = dataset.get_event_str(dataset.global2raw(x_np[proc_id, 0, :]))
            y = dataset.get_event_str(dataset.local2raw(y_np[proc_id, 0, :]))
            y_pred = dataset.get_event_str(dataset.global2raw(y_pred_np[proc_id, 0, :]))
            print({
                'x': x,
                'y': y,
                'y_pred': y_pred
            })

#
# def predict(dataset, model, events, next_events=1000):
#     model.to('cpu')
#     model.eval()
#
#     state_h, state_c = model.init_state(1)
#
#     for i in range(0, next_events):
#         x = torch.tensor([events[i:].to_numpy()], dtype=torch.float)
#         y_pred, (state_h, state_c) = model(x, (state_h.detach(), state_c.detach()))
#
#         last_event_logits = y_pred[0][-1]
#         event_input, event_raw = dataset.onehot2global(last_event_logits.detach().numpy(), softmax=False,
#                                                        shield=True)
#         events.loc[len(events.index)] = event_input
#
#         # output predicted events
#         print(dataset.get_event_str(event_raw))
#     return events

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--max-epochs', type=int, default=5)
    parser.add_argument('--batch-size', type=int, default=256)
    parser.add_argument('--sequence-length', type=int, default=256)
    parser.add_argument('--data-dir', type=str, default='')
    args = parser.parse_args()

    dataset = Dataset()
    dataset.load_events_train(data_path + 'train_dataset.csv', args.sequence_length,
                              data_path + 'partial_dataset.csv')

    model = Model(dataset.n_feature_fields, dataset.n_features, dataset.n_numerical_features, torch.float).to(device)
    # model.half()
    pytorch_total_params = sum(p.numel() for p in model.parameters())
    print('%d parameters in total' % pytorch_total_params)
    print('%d samples in total' % len(dataset))
    train(dataset, model, args)


    warmup(dataset, model, 1024)
    torch.save(model.state_dict(), data_path + 'trace.model')
    dataset.serialize(data_path + 'dataset.info')

    # state_dict = torch.load(data_path + 'trace.model')
    # model.load_state_dict(state_dict)
    # validate(dataset, model, 1024)

    # print('')
    # test_begin = 2000
    # test_input = dataset.events[test_begin:test_begin + args.sequence_length].copy()
    # test_n_event = 1000
    #
    # t_begin = perf_counter()
    # predict(dataset, model, test_input, test_n_event)  # , dataset.events.shape[0] - args.sequence_length)
    # t_end = perf_counter()
    # print("Total elapsed time for generating %d events: %f sec" % (test_n_event, t_end - t_begin))
