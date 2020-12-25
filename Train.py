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
from Model_LSTM import Model
from Trace_Dataset import Dataset

device = torch.device('cuda:6' if torch.cuda.is_available() else 'cpu')
torch.cuda.set_device(device)


def train(dataset, model, args):
    model.train()

    dataloader = DataLoader(
        dataset,
        batch_size=args.batch_size,
        num_workers=8,
        pin_memory=True,
        drop_last=True,
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
            state_h, state_c = model.init_state(args.batch_size)
            state_h = state_h.to(device)
            state_c = state_c.to(device)
            optimizer.zero_grad()
            x = x.to(device)
            y = y.to(device)
            y_pred, (state_h, state_c) = model(x, (state_h, state_c))

            # loss for numerical feature field
            loss_num = criterion_num(y_pred[:, :, -1:], y[:, :, -1:])
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

            loss.backward()
            optimizer.step()

            if batch % 20 == 0:
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
            num_workers=8,
            pin_memory=True,
            drop_last=True,
        )
        criterion_num = nn.MSELoss()
        criterion_cat = nn.CrossEntropyLoss()

        state_h, state_c = model.init_state(args.batch_size)
        state_h = state_h.to(device)
        state_c = state_c.to(device)
        for batch, (x, y) in enumerate(dataloader):
            x = x.to(device)
            y = y.to(device)
            y_pred, (state_h, state_c) = model(x, (state_h, state_c))

            # loss for numerical feature field
            loss_num = criterion_num(y_pred[:, :, -1:], y[:, :, -1:])
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

            if (batch + 1) * args.batch_size >= len(dataset):
                break
            y = y.detach().to('cpu').numpy()
            y_pred = y_pred.detach().to('cpu').numpy()
            for index in range(args.batch_size):
                last_event_logits = y_pred[index][-1]
                _, event_raw = dataset.onehot2global(last_event_logits, softmax=False,
                                                     shield=True)
                event_pred = dataset.get_event_str(event_raw)

                event = []
                for i, feature_field in enumerate(dataset.categorical_feature_fields):
                    event.append(dataset.value2index[feature_field][y[index, -1, i].astype(int)])
                Blank = y[index, -1, -1]
                Blank = dataset.min_max.inverse_transform(Blank.reshape(1, -1))[0][0]
                Blank = np.exp(Blank) - 1
                event.append(Blank)
                event = dataset.get_event_str(event)
                file.write('%f %f\n' % (loss_cat, loss_num))
                file.write(event + '\n')
                file.write(event_pred + '\n')
            print(batch)


def predict(dataset, model, events, next_events=1000):
    model.to('cpu')
    model.eval()

    state_h, state_c = model.init_state(1)

    for i in range(0, next_events):
        x = torch.tensor([events[i:].to_numpy()], dtype=torch.float)
        y_pred, (state_h, state_c) = model(x, (state_h, state_c))

        last_event_logits = y_pred[0][-1]
        event_input, event_raw = dataset.onehot2global(last_event_logits.detach().numpy(), softmax=False,
                                                       shield=True)
        events.loc[len(events.index)] = event_input

        # output predicted events
        print(dataset.get_event_str(event_raw))
    return events


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--max-epochs', type=int, default=1)
    parser.add_argument('--batch-size', type=int, default=128)
    parser.add_argument('--sequence-length', type=int, default=128)
    parser.add_argument('--data-dir', type=str, default='')
    args = parser.parse_args()

    dataset = Dataset()
    dataset.load_events_train('./trace_data/lu.C.4/match.csv', args.sequence_length,
                              './trace_data/lu.C.4/partial_dataset.csv')

    model = Model(dataset.n_feature_fields, dataset.n_categorical_features + 1).to(device)
    pytorch_total_params = sum(p.numel() for p in model.parameters())
    print('%d parameters in total' % pytorch_total_params)
    train(dataset, model, args)

    model = model.to('cpu')
    torch.save(model.state_dict(), './trace_data/lu.C.4/trace.model')
    dataset.serialize('./trace_data/lu.C.4/dataset.info')

    # print('validating model......', end='')
    # validate(dataset, model)
    # print('done')


    # print('')
    # test_begin = 2000
    # test_input = dataset.events[test_begin:test_begin + args.sequence_length].copy()
    # test_n_event = 1000
    #
    # t_begin = perf_counter()
    # predict(dataset, model, test_input, test_n_event)  # , dataset.events.shape[0] - args.sequence_length)
    # t_end = perf_counter()
    # print("Total elapsed time for generating %d events: %f sec" % (test_n_event, t_end - t_begin))
