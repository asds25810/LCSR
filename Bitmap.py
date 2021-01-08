from MPI_define import *
import seaborn as sns
import csv
import matplotlib.pyplot as plt
import pickle
from matplotlib.colors import LogNorm

nprocs = 128
file_path = "./trace_data/lulesh.8/"
file_name = "prediction.csv"
# 处理器数目，文件名，根据文件名为判断使用哪一个字典(match.csv 或者 prediction.csv)
result = [[0 for _ in range(nprocs)] for _ in range(nprocs)]
# the communication volume (in byte)，计算结束后将结果保存为res.csv文件


def manage_sendrecv(sr_data, para_dict):
    sendrecv_source = int(sr_data[para_dict['source']])
    sendrecv_dest = int(sr_data[para_dict['dest']])
    count_result = int(sr_data[para_dict['count']]) * int(sr_data[para_dict['datatype']])
    result[sendrecv_source][sendrecv_dest] += count_result
    result[sendrecv_dest][sendrecv_source] += count_result


def manage_bcast(bc_data, para_dict):
    root = int(bc_data[para_dict['root']])
    count_result = int(bc_data[para_dict['count']]) * int(bc_data[para_dict['datatype']])
    for i in range(nprocs):
        if i != root:
            result[i][root] += count_result
            result[root][i] += count_result


def manage_allreduce(ar_data, para_dict):
    count_result = int(ar_data[para_dict['count']]) * int(ar_data[para_dict['datatype']])
    for i in range(nprocs):
        for j in range(nprocs):
            result[i][j] += count_result


def manage_data():

    if file_name == "match.csv":
        para_dict = event_para_dict
    elif file_name == "prediction.csv":
        with open(file_path + 'dataset.info', 'rb') as file:
            dataset_info = pickle.load(file)
            col_names = dataset_info['col_names']

        index_list = []
        for i in range(len(col_names)):
            index_list.append(i)
        para_dict = dict(zip(col_names, index_list))
    else:
        print("wrong file name, must be \"match.csv\" or \"prediction.csv\"")
        return

    n_events = 0
    with open(file_path + file_name) as file:
        line = file.readline().rstrip('\n')
        while line:
            n_events += 1
            if n_events % 20000 == 0:
                print('%d managed events, %s' % (n_events, line))

            data = line.split(',')

            mpi_func_name = data[1]

            if mpi_func_name in collectiveList:
                # 群集通信
                if 'MPI_Bcast' == mpi_func_name:
                    manage_bcast(data, para_dict)
                if 'MPI_Allreduce' == mpi_func_name:
                    manage_allreduce(data, para_dict)

            elif mpi_func_name in pt2ptList:
                # p2p通信
                if 'MPI_Sendrecv' == mpi_func_name:
                    manage_sendrecv(data, para_dict)
                elif 'MPI_Recv' == mpi_func_name or 'MPI_Irecv' == mpi_func_name or \
                     'MPI_Wait' == mpi_func_name or 'MPI_Waitall' == mpi_func_name:
                    # 忽略trace中原有的Recv/Irecv/Wait
                    pass
                else:
                    print('Unexpected p2p MPI function %s' % mpi_func_name)
            else:
                print('Unexpected MPI function %s' % mpi_func_name)

            line = file.readline().rstrip('\n')

    with open(file_path+"res.csv", 'w', encoding='utf8', newline='') as fout:
        writer = csv.writer(fout)
        for line in result:
            writer.writerow(line)


def load_res():
    res = []
    with open(file_path+"res.csv", 'r') as fin:
        for line in fin:
            line = line.rstrip('\n')
            data = line.split(',')
            res.append(data)
    if not res:
        print("the file is empty")
        return
    for i in range(nprocs):
        for j in range(nprocs):
            result[i][j] = int(res[i][j])


def create_picture(matrix):
    plt.figure(figsize=(8, 6))
    # sns.heatmap(matrix, cmap="binary", linecolor='Black', linewidths=0.5, norm=LogNorm(vmin=1000))
    sns.heatmap(matrix, cmap="binary", linecolor='Black', norm=LogNorm(vmin=1000))
    plt.xlabel("Sender Rank")
    plt.ylabel("Receiver Rank")
    plt.ylim(0, nprocs)
    plt.xlim(0, nprocs)
    plt.show()
    print(matrix)


manage_data()
# load_res()
create_picture(result)
