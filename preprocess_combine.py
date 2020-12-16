import pandas as pd
import os
from MPI_define import *
import sys

event_list = []


def send2sendrecv(send):
    sendrecv = [''] * len(send)
    for (para, index) in event_para_dict.items():
        if para in send_para_list and para in sendrecv_para_list:
            sendrecv[index] = send[index]
    sendrecv[event_para_dict['function']] = 'MPI_Sendrecv'
    sendrecv[event_para_dict['source']] = sendrecv[event_para_dict['file']]
    sendrecv[event_para_dict['sendcount']] = send[event_para_dict['count']]
    sendrecv[event_para_dict['recvcount']] = send[event_para_dict['count']]
    sendrecv[event_para_dict['sendtype']] = send[event_para_dict['datatype']]
    sendrecv[event_para_dict['recvtype']] = send[event_para_dict['datatype']]
    return sendrecv

n_events = 0
with open("./trace_data/combine.csv") as file:
    line = file.readline().rstrip('\n')
    while line:
        n_events += 1
        if n_events % 1000 == 0:
            print('%d combined events, %s'% (n_events, line))

        data = line.split(',')
        nprocs = int(data[0])
        same_list = []  # 在combine中被判定为same的不同进程上的事件
        for i in range(nprocs):
            line = file.readline().rstrip('\n')
            event = line.split(',')
            same_list.append(event)

        mpi_func_name = same_list[0][1]
        if mpi_func_name in collectiveList:  # 群集通信
            reserve_blank = 0
            for i in range(nprocs):
                # blank取最大值
                blank = int(same_list[i][event_para_dict['Blank']])
                if blank>reserve_blank:
                    reserve_blank=blank
            same_list[0][event_para_dict['Blank']] =  str(reserve_blank)
            same_list[0][event_para_dict['file']] = '-1' # 群集通信的进程号设定为-1
            # 群集通信每个进程上都一样，只需保留一个，加入event_list
            event_list.append(same_list[0])

        elif mpi_func_name in pt2ptList :  # p2p通信
            # 将Send/Isend变为Sendrecv
            if 'MPI_Send' == mpi_func_name or 'MPI_Isend' == mpi_func_name:
                for i in range(nprocs):
                    same_list[i] = send2sendrecv(same_list[i])
                    # p2p通信每个进程上的都需要保留，加入event_list
                    event_list.append(same_list[i])
            elif 'MPI_Recv' == mpi_func_name or 'MPI_Irecv' == mpi_func_name or 'MPI_Wait' == mpi_func_name:
                # 忽略trace中原有的Recv/Irecv/Wait
                pass
            else:
                print('Unexpected p2p MPI function %s'% mpi_func_name)
        else:
            print('Unexpected MPI function %s'% mpi_func_name)

        line = file.readline().rstrip('\n')

n_events = 0
with open("./trace_data/match.csv", 'w') as file:
    for event in event_list:
        n_events += 1
        if n_events % 1000 == 0:
            print('writing %d/%d event'% (n_events, len(event_list)))

        line = ''
        for para in event:
            line += para
            line += ','
        line = str.rstrip(line, ',')
        file.write(line+'\n')


