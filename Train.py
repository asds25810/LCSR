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

torch.manual_seed(0)
np.random.seed(0)

device = torch.device('cuda:3' if torch.cuda.is_available() else 'cpu')
torch.cuda.set_device(device)

# data_path = '/data/sunjw/LCSR/LULESH-64/'
data_path = '/data/sunjw/LCSR/SP-D-529/'


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
            # (x_event, x_time, y_event, y_time) = self.batch
            self.batch[0] = self.batch[0].to(device=device, non_blocking=True)
            self.batch[1] = self.batch[1].to(device=device, non_blocking=True)
            self.batch[2] = self.batch[2].to(device=device, non_blocking=True)
            self.batch[3] = self.batch[3].to(device=device, non_blocking=True)

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
        pin_memory=False,
        drop_last=True,
        shuffle=True
    )

    criterion = nn.CrossEntropyLoss()
    optimizer = optim.AdamW(model.parameters(), lr=0.002)

    # print('%d parameter group(s)' % len(list(model.parameters())))
    # print('%d parameter group(s)' % len(optimizer.param_groups))

    n_iter = 0
    for epoch in range(args.max_epochs):
        prefetcher = DataPrefetcher(dataloader)
        batch = prefetcher.next()
        batch_id = 0

        while batch is not None:
            state = model.init_state(args.batch_size, device)
            optimizer.zero_grad()
            (x_event, x_time, y_event, y_time) = batch

            y_pred_event, y_pred_time, state = model(x_event, state)
            # loss for predicting event sequence
            loss_event = criterion(y_pred_event.transpose(1, 2), y_event.long())

            # loss for predicting time cost
            loss_time = 0
            for i, feature_field in enumerate(dataset.numerical_feature_fields):
                begin = i * dataset.feature_field_size[feature_field]
                end = begin + dataset.feature_field_size[feature_field]
                loss_time = loss_time + criterion(y_pred_time[:, :, begin:end].transpose(1, 2), y_time[:, :, i].long())
            loss = loss_event + loss_time
            loss.backward()
            # nn.utils.clip_grad_norm_(model_time.parameters(), max_norm=1.5, norm_type=2)
            optimizer.step()

            if batch_id % 50 == 0:
                print({'epoch': epoch, 'batch': batch_id,
                       'lr': optimizer.param_groups[0]['lr'],
                       'loss_event': loss_event.item(),
                       'loss_time': loss_time.item()})

            n_iter += 1
            if n_iter > 25000:
                break

            batch_id += 1
            batch = prefetcher.next()

        if n_iter > 25000:
            break


# prepare initial states for predicting
def warmup(dataset, model, n_steps):
    begin_index = np.cumsum(dataset.n_events) - dataset.n_events
    n_steps = 8192

    model.eval()

    state = model.init_state(dataset.n_procs, device)

    for i in range(n_steps):
        x = np.zeros(shape=(dataset.n_procs, 1, 2))
        for proc_id in range(dataset.n_procs):
            x[proc_id, 0, :] = dataset.events[begin_index[proc_id] + i, :]
        x = torch.tensor(x, dtype=torch.float).to(device)
        y_pred_event, y_pred_time, state = model(x, state)

    # dataset.initial_state = (state_h.cpu().detach().numpy(), state_c.cpu().detach().numpy())

    dataset.initial_data = np.zeros(shape=(dataset.n_procs, 1, 2))
    for proc_id in range(dataset.n_procs):
        dataset.initial_data[proc_id, 0, :] = dataset.events[begin_index[proc_id] + n_steps, :]


# if __name__ == '__main__':
parser = argparse.ArgumentParser()
parser.add_argument('--max-epochs', type=int, default=5)
parser.add_argument('--batch-size', type=int, default=128)
parser.add_argument('--sequence-length', type=int, default=256)
parser.add_argument('--data-dir', type=str, default='')
args = parser.parse_args()

t_begin = time.perf_counter_ns()
dataset = Dataset()
dataset.load_events_train(data_path + 'train_dataset.csv', args.sequence_length,
                          data_path + 'partial_dataset.csv')

model = Model(dataset.n_categorical_features,
                    2,
                    dataset.feature_field_size['event'], dataset.n_numerical_features,
                    24, 8, 2).to(device)

# model.half()
n_param = sum(p.numel() for p in model.parameters())
print('%d parameters' % (n_param))
print('%d samples in total' % len(dataset))

t_end = time.perf_counter_ns()
print('Total time cost for preprocess: %fs' % ((t_end - t_begin) / 1000000000.0))

t_begin = time.perf_counter_ns()
train(dataset, model, args)
t_end = time.perf_counter_ns()
print('Total time cost for training: %fs' % ((t_end - t_begin) / 1000000000.0))

warmup(dataset, model, 121920)
torch.save(model.state_dict(), data_path + 'trace.model')
dataset.serialize(data_path + 'dataset.info')
