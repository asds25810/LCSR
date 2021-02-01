from mpi4py import MPI
import numpy as np
from Model_LSTM import *
from Trace_Dataset import Dataset
import time
from TraceStat import TraceStat

device = torch.device('cuda:0' if torch.cuda.is_available() else 'cpu')
torch.cuda.set_device(device)

torch.manual_seed(0)
np.random.seed(0)

# global variables
time_infer = 0
time_decode = 0

data_path = '/data/sunjw/LCSR/LULESH-64/'
flag_replay = False
flag_profile = True


def predict(dataset, input_data , model, state_h, state_c):
    # x = torch.tensor(dataset_np, dtype=torch.float)
    if flag_profile:
        begin = time.perf_counter_ns()
    y_pred, (state_h, state_c) = model(input_data, (state_h, state_c))
    if flag_profile:
        end = time.perf_counter_ns()
        global time_infer
        time_infer += end - begin

    state_h = state_h.detach()
    state_c = state_c.detach()

    # last_event_logits = y_pred[:, :, :]
    if flag_profile:
        begin = time.perf_counter_ns()
    input_data = dataset.onehot2global_gpu(y_pred, input_data)
    if flag_profile:
        end = time.perf_counter_ns()
        global time_decode
        time_decode += end - begin

    # dataset_np = event_input
    return input_data, state_h, state_c


dataset = Dataset()
dataset.deserialize(data_path + 'dataset.info')
# input_data = dataset.initial_data.reshape(dataset.n_procs, 1, dataset.n_feature_fields)
input_data = torch.tensor(dataset.initial_data.reshape(dataset.n_procs, 1, dataset.n_feature_fields),
                          dtype=torch.float).to(device)
dataset.prepare4decode_gpu(device)

model = Model(dataset.n_feature_fields, dataset.n_features, dataset.n_numerical_features).to(device)
state_dict = torch.load(data_path + 'trace.model')
model.load_state_dict(state_dict)
model.eval()

# (state_h, state_c) = dataset.initial_state_gpu

state_h, state_c = model.init_state(dataset.n_procs)
state_h = state_h.to(device)
state_c = state_c.to(device)

MAX_STEPS = int(np.max(dataset.n_events))

print('%d batches in total' % MAX_STEPS)

prediction = []

time_prediction = 0
time_replay = 0
begin = 0
end = 0

# event_input = torch.zeros((dataset.n_procs, 1, dataset.n_feature_fields)).to(device)

t_begin = time.perf_counter_ns()
# generate remainder events
for i in range(0, MAX_STEPS):
    begin = time.perf_counter_ns()
    # state_h, state_c = model.init_state(1)
    pred , state_h, state_c = predict(dataset, input_data, model, state_h, state_c)
    input_data = pred.detach()
    end = time.perf_counter_ns()
    time_prediction += end - begin

    prediction.append(input_data.cpu().numpy())
    # print('rank=%d replaying predicted %s' % (rank, dataset.get_event_str(event_raw)))

    if i % 2000 == 0:
        print('predicted %d batches of events' % i)
        print('Average time for predicting a batch of events: %.1fus' % (time_prediction / (i + 1) / 1000.0))
        print('Average time for inference: %.1fus' % (time_infer / (i + 1) / 1000.0))
        print('Average time for decoding: %.1fus' % (time_decode / (i + 1) / 1000.0))

t_end = time.perf_counter_ns()

print(
    'Total time cost for %d batches of events: %fs' % (MAX_STEPS , (t_end - t_begin) / 1000000000.0))
print('Average time for predicting a batch of events: %.1fus' % (time_prediction / MAX_STEPS / 1000.0))

# get predicted trace statistics
t_begin = time.perf_counter_ns()

trace_stats = TraceStat(dataset.n_procs, dataset.n_events)
file = open(data_path + 'prediction.csv', 'w')



# need acceleration
for i in range(dataset.n_procs):
    print('Writing trace %d, %d events' % (i, dataset.n_events[i]))
    time_global2raw = 0
    time_write = 0
    for event_batch in prediction:
        if not trace_stats.is_done(i):
            if flag_profile:
                begin = time.perf_counter_ns()
            event = dataset.global2raw(event_batch[i, 0, :])
            if flag_profile:
                end = time.perf_counter_ns()
                time_global2raw += end - begin
            trace_stats.update(event)
            if flag_profile:
                begin = time.perf_counter_ns()
            file.write(dataset.get_event_str(event) + '\n')
            if flag_profile:
                end = time.perf_counter_ns()
                time_write += end - begin
        else:
            break
    print('average time for decoding an event %fus' %(time_global2raw/dataset.n_events[i]/1000.0))
    print('average time for writing an event %fus' % (time_write /dataset.n_events[i]/1000.0))
file.close()
trace_stats.save(data_path + 'prediction.stat')

t_end = time.perf_counter_ns()
print('Total time cost for predicted trace statistics: %fs' % ((t_end - t_begin) / 1000000000.0))

trace_stats.visualize()
