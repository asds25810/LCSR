import torch
from torch import nn
import numpy as np
from sklearn import preprocessing
import scipy.special
from MPI_define import *
import pandas as pd
import pickle

class Dataset(torch.utils.data.Dataset):
    def __init__(self):
        self.n_events = 0
        self.sq_length = 0
        self.n_feature_fields = 0
        self.n_categorical_features = 0
        self.feature_field_size = {}
        self.index2value = {}
        self.value2index = {}
        self.index_offset = {}
        self.index_offset_np = None
        self.categorical_feature_fields = []
        self.col_names = []
        self.min_max = preprocessing.MinMaxScaler(feature_range=(0, 1))

        self.events = None

    def load_events_train(self, dataset_train_path, sq_length, dataset_eval_path):
        self.sq_length = sq_length

        print('loading data......', end='')
        train_df = pd.read_csv(dataset_train_path, header=None)
        train_df.columns = event_para_dict.keys()
        # train_df.sort_values(by='S', inplace=True) # it significantly increases loss
        train_df.drop(['request', 'op', 'S', 'E', 'D'], axis=1, inplace=True)
        train_df.dropna(axis=1, inplace=True, how='all')

        self.col_names = train_df.columns

        train_df[4096:sq_length+4096].to_csv(dataset_eval_path, index=False, header=False)
        train_df.fillna(-1, inplace=True)

        # the last column 'Blank' is a numeric feature
        self.categorical_feature_fields = self.col_names.copy().drop('Blank')
        train_df['Blank'] =  self.min_max.fit_transform(np.log(train_df['Blank'].to_numpy().reshape(-1, 1)+1))
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
            self.value2index[column] = {value:index for index, value in enumerate(values)}
            # assign global indices
            self.index_offset[column] = self.n_categorical_features
            self.index_offset_np.append(self.index_offset[column])
            indices = indices + self.n_categorical_features
            self.n_categorical_features += values.size
            self.feature_field_size[column] = values.size
            # map values to indices
            train_df[column] = indices

        self.n_feature_fields = train_df.columns.size
        self.index_offset_np.append(0)  # the offset of 'Blank' column is 0
        self.index_offset_np = np.array(self.index_offset_np)
        # self.index_offset_np = np.array(self.index_offset.values())  # is it equivalent???

        self.events = train_df
        self.n_events = len(self.events)
        print('done')


    def load_events_eval(self, dataset_path, dataset_info_path):
        self.deserialize(dataset_info_path)
        eval_df = pd.read_csv(dataset_path, header=None)
        eval_df.columns = self.col_names
        eval_df.fillna(-1, inplace=True)

        eval_df['Blank'] = self.min_max.transform(np.log(eval_df['Blank'].to_numpy().reshape(-1, 1)+1))

        # convert raw format to global index format
        for column in self.categorical_feature_fields:
            for row in range(len(eval_df[column])):
                eval_df.at[row, column] = self.value2index[column][eval_df.at[row, column]] + self.index_offset[column]
        self.events = eval_df

    def global2raw(self, event_global):
        event_raw = []
        for i,column in enumerate(self.categorical_feature_fields):
            event_raw.append(self.index2value[column][int(event_global[i] - self.index_offset[column])])
        Blank = event_global[-1]
        Blank = np.exp(self.min_max.inverse_transform([[Blank]])[0][0])-1
        event_raw.append(Blank)
        return event_raw


    # convert one-hot format (used in prediction data) to
    # local index format (used in label data)
    def onehot2local(self, event_onehot, column, softmax=False):
        feature_field = event_onehot[
                        self.index_offset[column]:self.index_offset[column] + self.feature_field_size[column]]
        if softmax:
            p = scipy.special.softmax(feature_field)
            local_index = np.random.choice(len(feature_field), p=p)
        else:
            local_index = np.argmax(feature_field)
        return local_index

    # convert one-hot format (used in prediction data) to
    # global index format (used in input data) and
    # raw format of trace
    def onehot2global(self, event_onehot, softmax=False, shield=False):
        blank = event_onehot[-1:]
        blank_raw = self.min_max.inverse_transform([blank])[0][0]
        event_input = []
        event_raw = []
        local_index_dict = {}

        # first, decode mpi function name
        local_index = self.onehot2local(event_onehot, 'function', softmax)
        mpi_func = self.index2value['function'][local_index]
        if mpi_func not in function_para_dict.keys():
            print('error: unexpected mpi function')
        for column in self.categorical_feature_fields:
            local_index = self.onehot2local(event_onehot, column, softmax)
            local_index_dict[column] = local_index
            # event_raw.append(self.index2value[column][local_index])

        # force parameter values to fit corresponding mpi function
        if shield:
            for i,column in enumerate(self.categorical_feature_fields):
                # unused para must be -1 (where local_index = 0)
                if column not in function_para_dict[mpi_func]:
                    local_index_dict[column] = 0
                    # event_raw[i]=self.index2value[column][0]
                    if int(self.index2value[column][0]) != -1:
                        print('error: unused parameter must be -1')
                # file must be 0 (where local_index = 0) for collective functions
                if mpi_func in collectiveList and column == 'file':
                    local_index_dict[column] = 0
                    # event_raw[i]=self.index2value[column][0]
            if mpi_func == 'MPI_Sendrecv':
                source = self.index2value['source'][local_index_dict['source']]
                dest = self.index2value['dest'][local_index_dict['dest']]
                if source == dest:
                    # can be better. e.g. dest = argsecondmax(), not argmax
                    dest = (source + 1) % (self.feature_field_size['dest'] - 1)
                    local_index_dict['dest'] = dest + 1
                    print('error: source==dest==%d, new dest=%d'%(source, dest))
            # todo: add more constraints

        for i,column in enumerate(self.categorical_feature_fields):
            global_index = local_index_dict[column] + self.index_offset[column]
            event_raw.append(self.index2value[column][local_index_dict[column]])
            event_input.append(global_index)

        event_input.append(blank[0])
        event_raw.append(np.exp(blank_raw)-1)
        return event_input, event_raw

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

    def serialize(self, dataset_info_path):
        dataset_info = {
            'n_events':self.n_events,
            'sq_length':self.sq_length,
            'n_feature_fields':self.n_feature_fields,
            'n_categorical_features':self.n_categorical_features,
            'feature_field_size':self.feature_field_size,
            'index2value':self.index2value,
            'value2index':self.value2index,
            'index_offset':self.index_offset,
            # 'index_offset_np':self.index_offset_np,
            'categorical_feature_fields':self.categorical_feature_fields,
            'col_names':self.col_names,
            'min_max':self.min_max
        }
        with open(dataset_info_path,'wb') as file:
            pickle.dump(dataset_info, file)

    def deserialize(self, dataset_info_path):
        with open(dataset_info_path, 'rb') as file:
            dataset_info = pickle.load(file)
        self.n_events = dataset_info['n_events']
        self.sq_length = dataset_info['sq_length']
        self.n_feature_fields = dataset_info['n_feature_fields']
        self.n_categorical_features = dataset_info['n_categorical_features']
        self.feature_field_size = dataset_info['feature_field_size']
        self.index2value = dataset_info['index2value']
        self.value2index = dataset_info['value2index']
        self.index_offset = dataset_info['index_offset']
        # self.index_offset_np = dataset_info['index_offset_np']
        self.categorical_feature_fields = dataset_info['categorical_feature_fields']
        self.col_names = dataset_info['col_names']
        self.min_max = dataset_info['min_max']

    def __len__(self):
        return len(self.events) - self.sq_length

    def __getitem__(self, index):
        # x is global index format, y is local index format
        # local = global - offset
        x = torch.tensor(self.events[index:index + self.sq_length].to_numpy(), dtype=torch.float)
        y = torch.tensor(self.events[index + 1:index + self.sq_length + 1].to_numpy() - self.index_offset_np,
                         dtype=torch.float)
        return x, y
