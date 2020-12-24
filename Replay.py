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


def predict(events, model, state_h, state_c):
    x = torch.tensor([events[0:-1].to_numpy()], dtype=torch.float)
    y_pred, (state_h, state_c) = model(x, (state_h, state_c))

    last_event_logits = y_pred[0][-1]
    event_input, event_raw = dataset.onehot2global(last_event_logits.detach().numpy(), softmax=False, shield=True)
    events.shift(-1)
    events.loc[-1] = event_input

    # output predicted events
    # print(dataset.get_event_str(event_raw))
    return events, state_h, state_c

def replay(event):
    mpi_func = event['function']
    # send_buf = None
    # recv_buf = None
    if mpi_func == 'MPI_Sendrecv':
        if rank == int(event['source']) or rank == int(event['dest']):
            send_buf = np.zeros(int(event['sendcount']*event['sendtype']), dtype=np.byte)
            recv_buf = np.zeros(int(event['recvcount']*event['recvtype']), dtype=np.byte)
            comm.Sendrecv(send_buf=send_buf, dest=int(event['dest']), recvbuf=recv_buf, source=int(event['source']))
            time.sleep(event['Blank']/1000.0)
    elif mpi_func == 'MPI_Allreduce':
        send_buf = np.zeros(int(event['count'] * event['datatype']), dtype=np.byte)
        recv_buf = np.zeros(int(event['count'] * event['datatype']), dtype=np.byte)
        comm.Allreduce(send_buf=send_buf, recv_buf=recv_buf, Op_op=MPI.MAX) # Op doesn't matter so much
        time.sleep(event['Blank']/1000.0)
    elif mpi_func == 'MPI_Bcast':
        send_buf = np.zeros(int(event['count'] * event['datatype']), dtype=np.byte)
        comm.Bcast(buf=send_buf, root=int(event['root']))
        time.sleep(event['Blank']/1000.0)
    elif mpi_func == 'MPI_Barrier':
        comm.Barrier()
        time.sleep(event['Blank']/1000.0)
    else:
        print('error! unexpected MPI function %s' % mpi_func)


dataset = Dataset()
dataset.load_events_eval('dataset.csv', 'dataset.info')

model = Model(dataset.n_feature_fields, dataset.n_categorical_features + 1, device)
state_dict = torch.load('trace.model')
model.load_state_dict(state_dict)
model.eval()
state_h, state_c = model.init_state(1)

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
    replay(dict(zip(dataset.col_names, event_raw)))
# generate remainder events
for i in range(0, MAX_STEPS):
    predict(dataset.events, model, state_h, state_c)
    _, event_raw = dataset.onehot2global(dataset.events.loc[-1], softmax=False, shield=True)
    replay(dict(zip(dataset.col_names, event_raw)))
    if rank == 0:
        if i % 1000 == 0:
            print('replayed %d events' % i)
comm.Barrier()

t_end = MPI.Wtime()
if rank == 0:
    print('time cost for replay: %f'%(t_end-t_begin))
