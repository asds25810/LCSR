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

def predict(dataset, model, state_h, state_c):
    x = torch.tensor([dataset.events[0:].to_numpy()], dtype=torch.float)
    y_pred, (state_h, state_c) = model(x, (state_h, state_c))

    last_event_logits = y_pred[0][-1]
    event_input, event_raw = dataset.onehot2global(last_event_logits.detach().numpy(), softmax=True, shield=True)
    dataset.events=dataset.events.shift(-1)
    dataset.events.loc[len(dataset.events.index)-1] = event_input

    # output predicted events
    # print(dataset.get_event_str(event_raw))
    return event_raw, state_h, state_c

def replay(event):
    mpi_func = event['function']
    # send_buf = None
    # recv_buf = None
    if mpi_func == 'MPI_Sendrecv':
        # print('rank=%d, source=%d, dest=%d'%(rank, int(event['source']), int(event['dest'])))
        if rank == int(event['source']) or rank == int(event['dest']):
            send_buf = np.zeros(int(event['sendcount']*event['sendtype']), dtype=np.byte)
            recv_buf = np.zeros(int(event['recvcount']*event['recvtype']), dtype=np.byte)
            comm.Sendrecv(sendbuf=send_buf, dest=int(event['dest']), recvbuf=recv_buf, source=int(event['source']),
                          sendtag=0, recvtag=0)
            time.sleep(event['Blank']/1000000.0)
    elif mpi_func == 'MPI_Allreduce':
        send_buf = np.zeros(int(event['count'] * event['datatype']), dtype=np.byte)
        recv_buf = np.zeros(int(event['count'] * event['datatype']), dtype=np.byte)
        comm.Allreduce(sendbuf=send_buf, recvbuf=recv_buf, op=MPI.MAX) # op doesn't matter so much
        time.sleep(event['Blank']/1000000.0)
    elif mpi_func == 'MPI_Bcast':
        send_buf = np.zeros(int(event['count'] * event['datatype']), dtype=np.byte)
        comm.Bcast(buf=send_buf, root=int(event['root']))
        time.sleep(event['Blank']/1000000.0)
    elif mpi_func == 'MPI_Barrier':
        comm.Barrier()
        time.sleep(event['Blank']/1000000.0)
    else:
        print('error! unexpected MPI function %s' % mpi_func)


dataset = Dataset()
dataset.load_events_eval('./trace_data/lu.C.4/partial_dataset.csv', './trace_data/lu.C.4/dataset.info')

model = Model(dataset.n_feature_fields, dataset.n_categorical_features + 1, device)
state_dict = torch.load('./trace_data/lu.C.4/trace.model')
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

    print('rank=%d replaying given %s' % (rank, dataset.get_event_str(event_raw)))
    if rank == 0:
        print('replayed %d given events' % i)

    replay(dict(zip(dataset.col_names, event_raw)))

# generate remainder events
for i in range(0, MAX_STEPS):
    event_raw, state_h, state_c = predict(dataset, model, state_h, state_c)

    print('rank=%d replaying predicted %s' % (rank, dataset.get_event_str(event_raw)))

    replay(dict(zip(dataset.col_names, event_raw)))
    if rank == 0:
        if i % 1 == 0:
            print('replayed %d predicted events' % i)
comm.Barrier()

t_end = MPI.Wtime()
if rank == 0:
    print('time cost for replay: %f'%(t_end-t_begin))
