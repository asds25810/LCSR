import pickle
from matplotlib.colors import LogNorm
import seaborn as sns
import matplotlib.pyplot as plt
from MPI_define import *
import numpy as np
import math

class Stat:
    def __init__(self, n_procs):
        self.time = 0
        self.comp_time = 0
        self.comm_time = 0
        self.n_events = 0
        # self.send_count = []
        self.send_bytes = [0] * n_procs
        # self.recv_count = 0
        self.recv_bytes = [0] * n_procs


class TraceStat:
    def __init__(self, n_procs, scale_factor=1, max_events=None):
        self.stats = [Stat(n_procs) for _ in range(n_procs)]
        self.n_procs = n_procs
        self.max_events = max_events
        self.scale_factor = scale_factor
        if max_events is None:
            self.max_events = [0] * n_procs

    def update(self, event):
        proc_id = int(event[0])
        comp_time = int(event[-2])
        comm_time = int(event[-3])
        time = int(event[-1])
        mpi_func = event[1]

        if mpi_func in send_list:
            source = proc_id
            target = int(event[4])
            n_bytes = int(event[2]) * int(event[3])
            self.stats[source].send_bytes[target] += n_bytes
        elif mpi_func in recv_list:
            source = int(event[4])
            target = proc_id
            n_bytes = int(event[2]) * int(event[3])
            self.stats[target].recv_bytes[source] += n_bytes
        else:
            pass

        self.stats[proc_id].time += time
        self.stats[proc_id].comp_time += comp_time
        self.stats[proc_id].comm_time += comm_time
        self.stats[proc_id].n_events += 1

    def time(self):
        comp = []
        comm = []
        time = []
        sum = []
        for i in range(self.n_procs):
            # print('rank %d, comp %fs, comm %fs, time %fs, sum %fs' % (
            # i, self.stats[i].comp_time/1000000.0, self.stats[i].comm_time/1000000.0,
            # self.stats[i].time/1000000.0, self.stats[i].comp_time/1000000.0 + self.stats[i].comm_time/1000000.0))
            comp.append(self.stats[i].comp_time/1000000.0 * self.scale_factor)
            comm.append(self.stats[i].comm_time/1000000.0 * self.scale_factor)
            time.append(self.stats[i].time/1000000.0 * self.scale_factor)
            sum.append((self.stats[i].comp_time/1000000.0+self.stats[i].comm_time/1000000.0) * self.scale_factor)
        print('median %fs %fs %fs %fs' % (
            np.median(comp).item(), np.median(comm).item(), np.median(time).item(), np.median(sum).item()))
        print('mean %fs %fs %fs %fs'%(
            np.mean(comp).item(), np.mean(comm).item(), np.mean(time).item(), np.mean(sum).item()))
        print('min %fs %fs %fs %fs' % (
            np.min(comp).item(), np.min(comm).item(), np.min(time).item(), np.min(sum).item()))
        print('max %fs %fs %fs %fs'% (
            np.max(comp).item(), np.max(comm).item(), np.max(time).item(), np.max(sum).item()))

    def visualize(self):
        matrix_send = np.zeros(shape=(self.n_procs, self.n_procs))
        matrix_recv = np.zeros(shape=(self.n_procs, self.n_procs))
        for i in range(self.n_procs):
            matrix_send[i, :] = np.array(self.stats[i].send_bytes)
            matrix_recv[i, :] = np.array(self.stats[i].recv_bytes)
        matrix = matrix_recv * self.scale_factor # np.maximum(matrix_send, matrix_recv)
        plt.figure(figsize=(8, 6))
        # sns.heatmap(matrix, cmap="binary", linecolor='Black', linewidths=0.5, norm=LogNorm(vmin=1000))
        sns.heatmap(matrix, cmap="binary", linecolor='Black', norm=LogNorm(vmin=100))
        plt.xlabel("Sender Rank")
        plt.ylabel("Receiver Rank")
        plt.ylim(0, self.n_procs)
        plt.xlim(0, self.n_procs)
        plt.show()
        # print(matrix)

    def save(self, file_path):
        trace_stat = {
            'stats': self.stats,
            'n_procs': self.n_procs,
            'scale_factor': self.scale_factor,
            'max_events': self.max_events
        }
        with open(file_path, 'wb') as file:
            pickle.dump(trace_stat, file)

    def load(self, file_path):
        with open(file_path, 'rb') as file:
            trace_stat = pickle.load(file)
        self.stats = trace_stat['stats']
        self.n_procs = trace_stat['n_procs']
        self.scale_factor = trace_stat['scale_factor']
        self.max_events = trace_stat['max_events']

    def is_done(self, proc_id):
        return self.max_events[proc_id] / self.scale_factor <= self.stats[proc_id].n_events
