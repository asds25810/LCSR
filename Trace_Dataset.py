import torch
import numpy as np
from sklearn.preprocessing import KBinsDiscretizer
from sklearn.cluster import KMeans
from sklearn.cluster import MiniBatchKMeans
import scipy.special
from MPI_define import *
import pandas as pd
import pickle
import matplotlib.pyplot as plt


class Dataset(torch.utils.data.Dataset):
    def __init__(self):
        self.n_events = []
        self.sq_length = 0
        self.n_feature_fields = 0
        self.n_categorical_features = 0
        self.n_numerical_features = 0
        self.n_features = 0
        self.feature_field_size = {}
        self.index2value = {}
        self.index_offset = {}
        self.index_offset_np = None
        self.categorical_feature_fields = []
        self.numerical_feature_fields = []
        self.col_names = []
        self.n_procs = 0
        self.events = None
        self.times = None
        self.length = 0
        self.initial_data = None
        self.initial_state = None
        self.prior_dist = []

        self.index_offset_gpu = None
        self.scale_bias_gpu = None
        self.scale_coef_gpu = None
        self.initial_state_gpu = None

    def scale(self, data, field):
        # return np.power(data, 0.5)
        data = self.min_max[field].transform(np.log(data + 1))
        return data
        #
        # return data

    def fit_scale(self, data, field):
        # return np.power(data, 0.5)
        data = self.min_max[field].fit_transform(np.log(data + 1))
        return data
        #
        # return data

    def inverse_scale(self, data, field):
        # return np.power(data, 2)
        data = self.min_max[field].inverse_transform(data)
        return np.exp(data) - 1
        #
        # return data

    def load_events_train(self, dataset_train_path, sq_length, dataset_eval_path):
        self.sq_length = sq_length

        print('load data')
        train_df = pd.read_csv(dataset_train_path, header=None)
        train_df.columns = ['file', 'event', 'D', 'Blank']
        # train_df.dropna(axis=1, inplace=True, how='all')

        self.col_names = train_df.columns

        train_df.fillna(-1, inplace=True)

        print('discretize numerical features')
        # the last two columns 'D' and 'Blank' are numeric features
        # self.categorical_feature_fields = ['file', 'function', 'count', 'datatype', 'target', 'tag']
        self.categorical_feature_fields = ['file', 'event']
        self.numerical_feature_fields = ['D', 'Blank']
        for field in self.numerical_feature_fields:
            km = MiniBatchKMeans(n_clusters=16, n_init=1)
            train_df[field] = km.fit_predict(np.log(1 + train_df[field].to_numpy(dtype=np.float).reshape(-1, 1)))
            self.index2value[field] = km.cluster_centers_

            # quantile discretizing is faster
            # kbins = KBinsDiscretizer(n_bins=30, encode='ordinal', strategy='quantile')
            # train_df[field] = kbins.fit_transform(
            #     train_df[field].to_numpy(dtype=np.float).reshape(-1,1))
            # self.index2value[field] = []
            # for i in range(len(kbins.bin_edges_)-1):
            #     self.index2value[field].apped((kbins.bin_edges_[i] + kbins.bin_edges_[i+1])/2)

        print('prepare embeddings')
        # preprocess for embeddings of multiple categorical features, convert input data to global index format
        self.n_features = 0
        self.index_offset_np = []
        for field in self.categorical_feature_fields:
            # get unique values in each column
            indices, values = pd.factorize(train_df[field], na_sentinel=None, sort=True)
            self.index2value[field] = values
            # assign global indices
            self.index_offset[field] = self.n_features
            self.index_offset_np.append(self.index_offset[field])
            indices = indices + self.n_features
            self.n_features += values.size
            self.feature_field_size[field] = values.size
            # map values to global indices
            train_df[field] = indices
        self.n_categorical_features = self.n_features
        print('%d unique events' % self.feature_field_size['event'])

        # preprocess for embeddings of multiple discrete numerical features,
        # convert input data to global index format
        self.n_numerical_features = 0
        for field in self.numerical_feature_fields:
            # assign global indices
            self.index_offset[field] = self.n_features
            self.index_offset_np.append(self.index_offset[field])
            # map local indices to global indices
            train_df[field] = train_df[field] + self.n_features
            self.n_features += len(self.index2value[field])
            self.feature_field_size[field] = len(self.index2value[field])
        self.n_numerical_features = self.n_features - self.n_categorical_features

        self.n_feature_fields = len(train_df.columns)
        # self.n_features = self.n_categorical_features + len(self.numerical_feature_fields)
        # for i in range(len(self.numerical_feature_fields)):
        #     self.index_offset_np.append(0)  # the offset of numerical feature column is 0
        self.index_offset_np = np.array(self.index_offset_np)

        self.events = train_df[self.categorical_feature_fields].to_numpy()
        self.times = train_df[self.numerical_feature_fields].to_numpy()
        self.n_events = train_df['file'].value_counts(sort=False).values.tolist()
        self.n_procs = len(self.index2value['file'])
        self.prior_dist = train_df.groupby(['file', 'event']).size().unstack(fill_value=0).to_numpy()
        self.prior_dist = (self.prior_dist == 0)
        print('done')

    def local2raw(self, event_local):
        event_raw = []
        for i, field in enumerate(self.categorical_feature_fields + self.numerical_feature_fields):
            event_raw.append(self.index2value[field][int(event_local[i])])
        return event_raw

    def global2raw(self, event_global):
        event_raw = [int(event_global[0]),
                     self.index2value['event'][int(event_global[1] - self.index_offset['event'])],
                     np.exp(self.index2value['D'][int(event_global[2])]) - 1,
                     np.exp(self.index2value['Blank'][int(event_global[3])]) - 1]
        # for i, field in enumerate(self.categorical_feature_fields + self.numerical_feature_fields):
        #     event_raw.append(self.index2value[field][int(event_global[i])])
        # event_raw.append(self.index2value[field][int(event_global[i] - self.index_offset[field])])
        return event_raw

    def decode_event(self, logits, proc_id):
        # 1. get proc_id for step 2
        # 2. punish the outputs that were unseen in training
        # 3. randomly choose final output class
        # 4. add offset, convert local index to global index
        output = logits - self.prior_dist[proc_id] * 100
        p = torch.softmax(output[:, 0, :], dim=1)
        output = torch.multinomial(p, num_samples=1, replacement=True) + self.index_offset_gpu[1]
        # output = torch.argmax(output, dim=2) + self.index_offset_gpu[1]
        return output

    def decode_time(self, logits, output):
        for i, feature_field in enumerate(self.numerical_feature_fields):
            begin = i * self.feature_field_size[feature_field]
            end = begin + self.feature_field_size[feature_field]
            p = torch.softmax(logits[:, 0, begin:end], dim=1)
            output[:, :, i] = torch.multinomial(p, num_samples=1, replacement=True)
        return output

    def prepare4decode_gpu(self, device):
        self.index_offset_gpu = torch.tensor(self.index_offset_np, dtype=torch.float).to(device)
        if self.initial_state is not None:
            self.initial_state_gpu = (torch.tensor(self.initial_state[0], dtype=torch.float).to(device),
                                      torch.tensor(self.initial_state[1], dtype=torch.float).to(device))
        self.prior_dist = torch.tensor(self.prior_dist.astype(int)).to(device)

    # stupid, just work
    def get_event_str(self, event_raw):
        line = ''
        for feature in event_raw:
            try:
                f = float(feature)
                if f < 0.0:
                    line += ','
                else:
                    if int(f) < f:
                        line += ('%.2f' % f) + ','
                    else:
                        line += str(int(f)) + ','
            except ValueError:
                # trying to convert string to float will throw ValueError
                line += str(feature) + ','
            # if str(feature).isnumeric(): # cannot correctly check negative float number
            #     if feature<0.0:
            #         line += ','
            #     else:
            #         line+=str(int(feature)) + ','
            # else:
            #     line += str(feature) + ','
        line = str.rstrip(line, ',')
        return line

    def debug(self):
        x = self.events[:, -2]
        plt.hist(x, 100, density=False, facecolor='g', alpha=0.75, log=True)
        plt.show()

        # while True:
        #     ids = np.random.randint(0, len(train_df))
        #     d = train_df['D'].to_numpy()[ids:ids+256]
        #     b = train_df['Blank'].to_numpy()[ids:ids+256]
        #     plt.hist(np.log(d), 32, density=False, facecolor='g', alpha=0.75, log=True)
        #     plt.title('D')
        #     plt.show()
        #     plt.hist(np.log(b), 32, density=False, facecolor='g', alpha=0.75, log=True)
        #     plt.title('B')
        #     plt.show()
        #     plt.hist(np.log(d+b), 32, density=False, facecolor='g', alpha=0.75, log=True)
        #     plt.title('SUM')
        #     plt.show()

        # d_dist = train_df.groupby(['file'])['D']
        # b_dist = train_df.groupby(['file'])['Blank']

        # for (event_id, data) in d_dist:
        #     plt.hist(data.values, 50, density=False, facecolor='g', alpha=0.75, log=True)
        #     plt.title('event %s' % event_id)
        #     plt.show()

        # for (event_id, data) in b_dist:
        #     plt.hist(data.values, 50, density=False, facecolor='g', alpha=0.75, log=True)
        #     plt.title('event %s' % event_id)
        #     plt.show()

        # todo visualization
        # x = train_df[field].to_numpy()
        # plt.hist(x, 10, density=True, facecolor='g', alpha=0.75, log=True)
        # plt.ylabel(field)
        # plt.show()

        # test for zipping features
        # print('test for zipping features')
        # data_fileds = self.categorical_feature_fields[1:]  # exclude process id
        # indices, values = pd.factorize(list(train_df[data_fileds].itertuples(index=False, name=None)),
        #                                na_sentinel=None, sort=True)
        # print('%d unique events' % values.size)

    def serialize(self, dataset_info_path):
        dataset_info = {
            'n_events': self.n_events,
            'sq_length': self.sq_length,
            'n_feature_fields': self.n_feature_fields,
            'n_categorical_features': self.n_categorical_features,
            'n_numerical_features': self.n_numerical_features,
            'n_features': self.n_features,
            'feature_field_size': self.feature_field_size,
            'index2value': self.index2value,
            'index_offset': self.index_offset,
            'index_offset_np': self.index_offset_np,
            'categorical_feature_fields': self.categorical_feature_fields,
            'numerical_feature_fields': self.numerical_feature_fields,
            'col_names': self.col_names,
            'n_procs': self.n_procs,
            'initial_data': self.initial_data,
            'initial_state': self.initial_state,
            'prior_dist': self.prior_dist
        }
        with open(dataset_info_path, 'wb') as file:
            pickle.dump(dataset_info, file)

    def deserialize(self, dataset_info_path):
        with open(dataset_info_path, 'rb') as file:
            dataset_info = pickle.load(file)
        self.n_events = dataset_info['n_events']
        self.sq_length = dataset_info['sq_length']
        self.n_feature_fields = dataset_info['n_feature_fields']
        self.n_categorical_features = dataset_info['n_categorical_features']
        self.n_numerical_features = dataset_info['n_numerical_features']
        self.n_features = dataset_info['n_features']
        self.feature_field_size = dataset_info['feature_field_size']
        self.index2value = dataset_info['index2value']
        self.index_offset = dataset_info['index_offset']
        self.index_offset_np = dataset_info['index_offset_np']
        self.categorical_feature_fields = dataset_info['categorical_feature_fields']
        self.numerical_feature_fields = dataset_info['numerical_feature_fields']
        self.col_names = dataset_info['col_names']
        self.n_procs = dataset_info['n_procs']
        self.initial_data = dataset_info['initial_data']
        self.initial_state = dataset_info['initial_state']
        self.prior_dist = dataset_info['prior_dist']

    def __len__(self):
        if self.length == 0:
            self.length = len(self.events) - (self.sq_length + 1) * self.n_procs
        return self.length

    def __getitem__(self, index):
        # dataset is a concatenation of n_procs trace files
        # the end of each trace file cannot be get as data samples

        # find the corresponding trace file of the given index
        rank = 0
        index_begin = 0
        while index > index_begin + self.n_events[rank] - (self.sq_length + 1):
            index_begin += self.n_events[rank] - (self.sq_length + 1)
            rank += 1

        # skip the data at the end of each trace file
        # ensure all data within a sequence are from the same trace file
        index = index + rank * (self.sq_length + 1)

        # x is global index format, y is local index format
        # local = global - offset
        # x_event contains two fields ['file', 'event'], y_event contains one field 'event'
        x_event = torch.tensor(self.events[index:index + self.sq_length], dtype=torch.float)
        y_event = torch.tensor(self.events[index + 1: index + 1 + self.sq_length, 1] -
                               self.index_offset_np[1], dtype=torch.float)
        # x_time = torch.tensor(
        #     np.concatenate((self.events[index:index + self.sq_length],
        #                     self.times[index:index + self.sq_length]),
        #                    axis=1), dtype=torch.float)
        x_time = torch.tensor(self.times[index:index + self.sq_length], dtype=torch.float)
        y_time = torch.tensor(self.times[index + 1:index + 1 + self.sq_length] -
                              self.index_offset_np[2:4], dtype=torch.float)
        # check if the sequence is from the same trace file
        file_index = x_event[:, 0]
        if np.count_nonzero(file_index - rank) != 0:
            print('error: inconsistent data sequence')

        return x_event, x_time, y_event, y_time
