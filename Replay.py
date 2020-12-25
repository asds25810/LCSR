import argparse
import mpi4py
from mpi4py import MPI
from MPI_define import *
import numpy as np
import argparse
import torch
from Model_LSTM import *
from Trace_Dataset import Dataset
import pandas as pd
import time

device = torch.device('cpu')
torch.manual_seed(0)
np.random.seed(0)


# global variables


def predict(dataset, model, state_h, state_c):
    x = torch.tensor([dataset.events[0:].to_numpy()], dtype=torch.float)
    y_pred, (state_h, state_c) = model(x, (state_h, state_c))

    last_event_logits = y_pred[0][-1]
    event_input, event_raw = dataset.onehot2global(last_event_logits.detach().numpy(), softmax=True, shield=True)
    dataset.events = dataset.events.shift(-1)
    dataset.events.loc[len(dataset.events.index) - 1] = event_input

    # output predicted events
    # print(dataset.get_event_str(event_raw))
    return event_raw, state_h, state_c


class Replayer:
    def __init__(self, init_buf_size=1024):
        self.send_buf = np.zeros(init_buf_size, dtype=np.byte)
        self.recv_buf = np.zeros(init_buf_size, dtype=np.byte)
        self.max_send_size = init_buf_size
        self.max_recv_size = init_buf_size

    def check_send_buf(self, send_size):
        if send_size > self.max_send_size:
            self.max_send_size = send_size
            self.send_buf = np.zeros(self.max_send_size, dtype=np.byte)

    def check_recv_buf(self, recv_size):
        if recv_size > self.max_recv_size:
            self.max_recv_size = recv_size
            self.recv_buf = np.zeros(self.max_recv_size, dtype=np.byte)

    def sleep(self,v):
        if v>0:
            time.sleep(v / 1000000.0)

    def replay(self, event):
        mpi_func = event['function']
        if mpi_func == 'MPI_Sendrecv':
            if rank == int(event['source']) or rank == int(event['dest']):
                # sometimes send_size != recv_size in prediction
                data_size = max(int(event['sendcount'] * event['sendtype']), int(event['recvcount'] * event['recvtype']))

                print('rank=%d, send_size=%d, recv_size=%d, replaying predicted %s' % (
                    rank, data_size, data_size,
                    dataset.get_event_str(event.values())))

                if rank == int(event['source']):
                    self.check_send_buf(data_size)
                    comm.Send([self.send_buf, data_size, MPI.BYTE], int(event['dest']))
                if rank == int(event['dest']):
                    self.check_recv_buf(data_size)
                    comm.Recv([self.recv_buf, data_size, MPI.BYTE], int(event['source']))
                    # comm.Sendrecv(sendbuf=send_buf, dest=int(event['dest']), recvbuf=recv_buf, source=int(event['source']),
                    #               sendtag=0, recvtag=0)
                sleep(event['Blank'])
        elif mpi_func == 'MPI_Allreduce':
            data_size = max(int(event['count'] * event['datatype']), int(event['count'] * event['datatype']))
            self.check_send_buf(data_size)
            self.check_recv_buf(data_size)
            comm.Allreduce(sendbuf=[self.send_buf, data_size, MPI.BYTE], recvbuf=[self.recv_buf, data_size, MPI.BYTE],
                           op=MPI.MAX)  # op doesn't matter so much
            sleep(event['Blank'])
        elif mpi_func == 'MPI_Bcast':
            data_size = int(event['count'] * event['datatype'])
            self.check_send_buf(data_size)
            comm.Bcast(buf=[self.send_buf, data_size, MPI.BYTE], root=int(event['root']))
            sleep(event['Blank'])
        elif mpi_func == 'MPI_Barrier':
            comm.Barrier()
            sleep(event['Blank'])
        else:
            print('error! unexpected MPI function %s' % mpi_func)


dataset = Dataset()
dataset.load_events_eval('./trace_data/lu.C.4/partial_dataset.csv', './trace_data/lu.C.4/dataset.info')

model = Model(dataset.n_feature_fields, dataset.n_categorical_features + 1).to(device)
state_dict = torch.load('./trace_data/lu.C.4/trace.model')
model.load_state_dict(state_dict)
model.eval()
state_h, state_c = model.init_state(1)

replayer = Replayer()
comm = MPI.COMM_WORLD
rank = comm.Get_rank()

MAX_STEPS = dataset.n_events - dataset.sq_length

if rank == 0:
    print('replay starts')

t_begin = MPI.Wtime()
comm.Barrier()
# events of number sq_length are given
for i in range(dataset.sq_length):
    event_raw = dataset.global2raw(dataset.events.loc[i])

    print('rank=%d replaying given %s' % (rank, dataset.get_event_str(event_raw)))
    # if rank == 0:
    #     print('replayed %d given events' % i)

    replayer.replay(dict(zip(dataset.col_names, event_raw)))
    comm.Barrier()
# generate remainder events
for i in range(0, MAX_STEPS):
    event_raw, state_h, state_c = predict(dataset, model, state_h, state_c)

    # print('rank=%d, send_size=%d, recv_size=%d, replaying predicted %s' % (
    #     rank, replayer.max_send_size, replayer.max_recv_size, dataset.get_event_str(event_raw)))

    replayer.replay(dict(zip(dataset.col_names, event_raw)))
    if rank == 0:
        if i % 1 == 0:
            print('replayed %d predicted events' % i)
    comm.Barrier()

t_end = MPI.Wtime()
if rank == 0:
    print('time cost for replay: %f' % (t_end - t_begin))
