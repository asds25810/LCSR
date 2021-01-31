import torch
import numpy as np
from sklearn import preprocessing
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
        self.value2index = {}
        self.index_offset = {}
        self.index_offset_np = None
        self.categorical_feature_fields = []
        self.numerical_feature_fields = []
        self.col_names = []
        self.min_max = {}  # preprocessing.MinMaxScaler(feature_range=(0, 1))
        self.n_procs = 0
        self.events = None
        self.length = 0
        self.initial_data = None
        self.initial_state = None

        self.index_offset_gpu = None
        self.scale_bias_gpu = None
        self.scale_coef_gpu = None
        self.initial_state_gpu = None

    def scale(self, data, field):
        # return np.power(data, 0.5)
        data = self.min_max[field].transform(np.log(data+1))
        return data
        #
        # return data

    def fit_scale(self, data, field):
        # return np.power(data, 0.5)
        data = self.min_max[field].fit_transform(np.log(data+1))
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

        print('loading data......', end='')
        train_df = pd.read_csv(dataset_train_path, header=None)
        train_df.columns = event_para_dict.keys()
        # train_df.dropna(axis=1, inplace=True, how='all')

        self.col_names = train_df.columns

        # train_df[8192:sq_length + 8192].to_csv(dataset_eval_path, index=False, header=False)
        train_df.fillna(-1, inplace=True)

        # the last two columns 'D' and 'Blank' is a numeric feature
        self.categorical_feature_fields = self.col_names.copy().drop('D').drop('Blank').drop('SUM')
        self.numerical_feature_fields = ['D', 'Blank','SUM']
        self.n_numerical_features = len(self.numerical_feature_fields)
        for field in self.numerical_feature_fields:
            train_df.loc[train_df[field] == 0, field] = 1
            self.min_max[field] = preprocessing.MinMaxScaler(feature_range=(0.0, 1.0))
            # train_df[field] = self.min_max[field].fit_transform(train_df[field].to_numpy().reshape(-1, 1))

            # origin = train_df[field].to_numpy(dtype=np.float).reshape(-1, 1)

            train_df[field] = self.fit_scale(train_df[field].to_numpy(dtype=np.float).reshape(-1, 1), field)

            # train_df[field] = self.min_max[field].fit_transform(
            #     self.scale(train_df[field].to_numpy(dtype=np.float).reshape(-1, 1)))


            # tmp = self.inverse_scale(
            #     self.min_max[field].inverse_transform(train_df[field].to_numpy(dtype=np.float).reshape(-1, 1)))
            # error = np.mean(np.abs(tmp - origin)/origin)
            # print(error)

            # x = train_df[field].to_numpy()
            # plt.hist(x, 100, density=True, facecolor='g', alpha=0.75, log=True)
            # plt.ylabel(field)
            # plt.show()

        # fig, ax = plt.subplots(1, 1)
        # ax.hist(train_df['Blank'].to_numpy(), bins=100)
        # plt.show()

        # preprocess for embeddings of multiple categorical features, convert input data to global index format
        self.n_categorical_features = 0
        self.index_offset_np = []
        for column in self.categorical_feature_fields:
            # get unique values in each column
            indices, values = pd.factorize(train_df[column], na_sentinel=None, sort=True)
            self.index2value[column] = values
            self.value2index[column] = {value: index for index, value in enumerate(values)}
            # assign global indices
            self.index_offset[column] = self.n_categorical_features
            self.index_offset_np.append(self.index_offset[column])
            indices = indices + self.n_categorical_features
            self.n_categorical_features += values.size
            self.feature_field_size[column] = values.size
            # map values to indices
            train_df[column] = indices

        self.n_feature_fields = train_df.columns.size
        self.n_features = self.n_categorical_features + len(self.numerical_feature_fields)
        for i in range(len(self.numerical_feature_fields)):
            self.index_offset_np.append(0)  # the offset of numerical feature column is 0
        self.index_offset_np = np.array(self.index_offset_np)
        # self.index_offset_np = np.array(self.index_offset.values())  # is it equivalent???

        self.events = train_df.to_numpy()
        self.n_events = train_df['file'].value_counts(sort=False).values.tolist()
        self.n_procs = len(self.value2index['file'].keys())

        # self.initial_data = np.zeros(shape=(self.n_procs,self.n_feature_fields), dtype=np.float)
        # begin = 0
        # for i in range(self.n_procs):
        #     self.initial_data[i,:]=self.events[begin + 1024,:]
        #     begin += self.n_events[i]
        print('done')

    # to be deprecated
    def load_events_eval(self, dataset_path, dataset_info_path):
        self.deserialize(dataset_info_path)
        eval_df = pd.read_csv(dataset_path, header=None)
        eval_df.columns = self.col_names
        eval_df.fillna(-1, inplace=True)

        for field in self.numerical_feature_fields:
            eval_df[field] = self.scale(eval_df[field].to_numpy().reshape(-1, 1), field)

        # convert raw format to global index format
        for fields in self.categorical_feature_fields:
            for row in range(len(eval_df[fields])):
                eval_df.at[row, fields] = self.value2index[fields][eval_df.at[row, fields]] + self.index_offset[fields]
        self.events = eval_df.to_numpy()

    def local2raw(self, event_local):
        event_raw = []
        for i, field in enumerate(self.categorical_feature_fields):
            event_raw.append(self.index2value[field][int(event_local[i])])

        # numerical features do not use embeddings
        for i, field in enumerate(self.numerical_feature_fields):
            feature_normalized = np.clip(event_local[i - self.n_numerical_features], a_min=0.0, a_max=100.0)
            # feature_normalized = event_local[i - self.n_numerical_features]
            feature_raw = self.inverse_scale([[feature_normalized]], field)[0][0]
            event_raw.append(feature_raw)
        return event_raw

    def global2raw(self, event_global):
        event_raw = []
        for i, field in enumerate(self.categorical_feature_fields):
            event_raw.append(self.index2value[field][int(event_global[i] - self.index_offset[field])])

        # numerical features do not use embeddings
        for i, field in enumerate(self.numerical_feature_fields):
            feature_normalized = np.clip(event_global[i - self.n_numerical_features], a_min=0.0, a_max=100.0)
            # feature_normalized = event_global[i - self.n_numerical_features]
            feature_raw = self.inverse_scale([[feature_normalized]], field)[0][0]
            event_raw.append(feature_raw)
        return event_raw


    # convert one-hot format (used in prediction data) to
    # local index format (used in label data)
    def onehot2local(self, event_onehot, column, softmax=False):
        feature_field = event_onehot[
                        self.index_offset[column]:self.index_offset[column] + self.feature_field_size[column]]
        if softmax:
            if column != 'function' and column != 'file':
                feature_field = feature_field[1:]  # ignore N/A
            p = scipy.special.softmax(feature_field)
            local_index = np.random.choice(len(feature_field), p=p)
        else:
            local_index = np.argmax(feature_field)
        return local_index

    # convert one-hot format (used in prediction data) to
    # global index format (used in input data) and
    # raw format of trace
    def onehot2global(self, event_onehot, softmax=False, shield=False):
        event_input = []
        event_raw = []
        local_index_dict = {}

        # first, decode mpi function name
        local_index = self.onehot2local(event_onehot, 'function', softmax)
        mpi_func = self.index2value['function'][local_index]
        local_index_dict['function'] = local_index

        if mpi_func not in function_para_dict.keys():
            print('error: unexpected mpi function')
        for column in self.categorical_feature_fields:
            if column in function_para_dict[mpi_func] and column != 'function':
                local_index = self.onehot2local(event_onehot, column, softmax)
                local_index_dict[column] = local_index
            # event_raw.append(self.index2value[column][local_index])

        for i, column in enumerate(self.categorical_feature_fields):
            global_index = local_index_dict[column] + self.index_offset[column]
            event_raw.append(self.index2value[column][local_index_dict[column]])
            event_input.append(global_index)

        # numerical features
        # note that each numerical feature field only contain one feature,
        # so n_numerical_features == n_numerical_feature_fields
        for i, column in enumerate(self.numerical_feature_fields):
            feature_normalized = np.clip(event_onehot[i - self.n_numerical_features], a_min=0.0, a_max=1.0)
            # feature_normalized = event_onehot[i - self.n_numerical_features]
            feature_raw = self.inverse_scale([[feature_normalized]])[0][0]
            event_input.append(feature_normalized)
            # event_raw.append(feature_raw)
            event_raw.append(feature_raw)

        return event_input, event_raw

    def onehot2global_gpu(self, event_onehot, event_input):

        for i, feature_field in enumerate(self.categorical_feature_fields):
            begin = self.index_offset[feature_field]
            end = self.index_offset[feature_field] + self.feature_field_size[feature_field]
            # loss_cat = loss_cat + criterion_cat(y_pred[:, -1, begin:end].transpose(1, 2), y[:, -1, i].long())
            event_input[:, :, i] = torch.argmax(event_onehot[:, :, begin:end], dim=2)
        event_input = event_input + self.index_offset_gpu
        event_input[:, :, -self.n_numerical_features:] = torch.clamp(event_onehot[:, :, -self.n_numerical_features:],
                                                                     min=0.0, max=1.0)
        return event_input

    def prepare4decode_gpu(self, device):
        self.index_offset_gpu = torch.tensor(self.index_offset_np, dtype=torch.float).to(device)
        if self.initial_state is not None:
            self.initial_state_gpu = (torch.tensor(self.initial_state[0], dtype=torch.float).to(device),
                                         torch.tensor(self.initial_state[1], dtype=torch.float).to(device))

        scale_bias = []
        scale_coef = []
        for i, feature_field in enumerate(self.numerical_feature_fields):
            scale_bias.append(self.min_max[feature_field].min_[0])
            scale_coef.append(self.min_max[feature_field].scale_[0])
        self.scale_bias_gpu = torch.tensor(scale_bias, dtype=torch.float).to(device)
        self.scale_coef_gpu = torch.tensor(scale_coef, dtype=torch.float).to(device)

    def get_event_str(self, event_raw):
        line = ''
        for feature in event_raw:
            try:
                f = float(feature)
                if f < 0.0:
                    line += ','
                else:
                    line += str(int(feature)) + ','
            except ValueError:
                # trying to convert string to float will throw ValueError
                line += str(feature) + ','
            # if str(feature).isnumeric(): # no method to correctly check negative float number
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
            'value2index': self.value2index,
            'index_offset': self.index_offset,
            'index_offset_np':self.index_offset_np,
            'categorical_feature_fields': self.categorical_feature_fields,
            'numerical_feature_fields': self.numerical_feature_fields,
            'col_names': self.col_names,
            'min_max': self.min_max,
            'n_procs': self.n_procs,
            'initial_data':self.initial_data,
            'initial_state':self.initial_state
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
        self.value2index = dataset_info['value2index']
        self.index_offset = dataset_info['index_offset']
        self.index_offset_np = dataset_info['index_offset_np']
        self.categorical_feature_fields = dataset_info['categorical_feature_fields']
        self.numerical_feature_fields = dataset_info['numerical_feature_fields']
        self.col_names = dataset_info['col_names']
        self.min_max = dataset_info['min_max']
        self.n_procs = dataset_info['n_procs']
        self.initial_data = dataset_info['initial_data']
        self.initial_state = dataset_info['initial_state']

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
        x = torch.tensor(self.events[index:index + self.sq_length], dtype=torch.float)
        y = torch.tensor(self.events[index + 1 : index + 1 + self.sq_length] -
                         self.index_offset_np, dtype=torch.float)

        # check if the sequence is from the same trace file
        file_index = x[:, 0]
        if np.count_nonzero(file_index - rank) != 0:
            print('error: inconsistent data batch')

        return x, y
