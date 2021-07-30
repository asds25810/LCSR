import argparse
import torch
import numpy as np
from torch import nn, optim
from torch.utils.data import DataLoader
from Model_Transformer import Model
from Trace_Dataset import Dataset
import matplotlib.pyplot as plt
import math
import time

from torchvision.models import AlexNet
from torchviz import make_dot

device = torch.device('cuda:5' if torch.cuda.is_available() else 'cpu')
torch.cuda.set_device(device)

# data_path = '/data/sunjw/LCSR/LULESH-512/'
data_path = '/data/sunjw/LCSR/CG-MG-128/'


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

    criterion = nn.CrossEntropyLoss()

    optimizer = optim.AdamW(model.parameters(), lr=0.0005, weight_decay=0.0)
    # optimizer = optim.Adam(model.parameters(), lr=0.0001, weight_decay=0.0)
    print('%d parameter group(s)' % len(list(model.parameters())))
    print('%d parameter group(s)' % len(optimizer.param_groups))

    n_iter = 0
    src_mask = model.generate_square_subsequent_mask(dataset.sq_length).to(device)
    for epoch in range(args.max_epochs):
        prefetcher = DataPrefetcher(dataloader)
        batch = prefetcher.next()
        batch_id = 0

        while batch is not None:
            optimizer.zero_grad()
            (x, y) = batch
            # x = x.to(device)
            # y = y.to(device)
            y_pred = model(x, src_mask).transpose(0, 1)

            # loss for categorical feature field
            loss_cat = 0
            for i, feature_field in enumerate(dataset.categorical_feature_fields):
                begin = dataset.index_offset[feature_field]
                end = dataset.index_offset[feature_field] + dataset.feature_field_size[feature_field]
                loss_cat = loss_cat + criterion(y_pred[:, :, begin:end].transpose(1, 2), y[:, :, i].long())
            loss_num = 0
            for i, feature_field in enumerate(dataset.numerical_feature_fields):
                begin = dataset.index_offset[feature_field]
                end = dataset.index_offset[feature_field] + dataset.feature_field_size[feature_field]
                index = i + len(dataset.categorical_feature_fields)
                loss_num = loss_num + criterion(y_pred[:, :, begin:end].transpose(1, 2), y[:, :, index].long())
            loss_cat = loss_cat / len(dataset.categorical_feature_fields)
            loss_num = loss_num / len(dataset.numerical_feature_fields) * 0.005  # a hyper-parameter, a trick
            loss = loss_cat + loss_num

            loss.backward()
            optimizer.step()

            if batch_id % 50 == 0:
                print({'epoch': epoch, 'batch': batch_id, 'lr': optimizer.param_groups[0]['lr'],
                       'loss_cat': loss_cat.item(),
                       'loss_num': loss_num.item()})

            n_iter += 1
            if n_iter > 25000:
                break

            batch_id += 1
            batch = prefetcher.next()

        if n_iter > 25000:
            break


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--max-epochs', type=int, default=5)
    parser.add_argument('--batch-size', type=int, default=128)
    parser.add_argument('--sequence-length', type=int, default=256)
    parser.add_argument('--data-dir', type=str, default='')
    args = parser.parse_args()

    dataset = Dataset()
    dataset.load_events_train(data_path + 'train_dataset.csv', args.sequence_length,
                              data_path + 'partial_dataset.csv')

    model = Model(dataset.n_feature_fields, dataset.n_features, 8, 4, 16, 2).to(device)

    pytorch_total_params = sum(p.numel() for p in model.parameters())
    print('%d parameters in total' % pytorch_total_params)
    print('%d samples in total' % len(dataset))

    t_begin = time.perf_counter_ns()
    train(dataset, model, args)
    t_end = time.perf_counter_ns()
    print('Total time cost for training: %fs' % ((t_end - t_begin) / 1000000000.0))

    begin_index = np.cumsum(dataset.n_events) - dataset.n_events
    dataset.initial_data = np.zeros(shape=(dataset.n_procs, dataset.sq_length, dataset.n_feature_fields))
    for proc_id in range(dataset.n_procs):
        dataset.initial_data[proc_id, :, :] = dataset.events[
                                              begin_index[proc_id] + 0:begin_index[
                                                                              proc_id] + dataset.sq_length + 0, :]

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
