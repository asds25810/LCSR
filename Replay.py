from mpi4py import MPI
import numpy as np
from Model_LSTM import *
from Trace_Dataset import Dataset
import time
from TraceStat import TraceStat

device = torch.device('cuda:3' if torch.cuda.is_available() else 'cpu')
# device = torch.device('cpu')
torch.cuda.set_device(device)

torch.manual_seed(0)
np.random.seed(0)

# global variables
time_infer = 0
time_decode = 0

data_path = '/data/sunjw/LCSR/CG-D-64/'
flag_replay = False
flag_profile = True


def predict(dataset, input_data, output_time, model_event, model_time, state_event, state_time):
    if flag_profile:
        begin = time.perf_counter_ns()
    y_pred_event, state_event = model_event(input_data, state_event)
    y_pred_time, state_time = model_time(input_data, state_time)
    if flag_profile:
        end = time.perf_counter_ns()
        global time_infer
        time_infer += end - begin

    if flag_profile:
        begin = time.perf_counter_ns()
    # output_event is the next input data
    output_event = dataset.decode_event(y_pred_event, input_data[:, :, 0].long())
    output_time = dataset.decode_time(y_pred_time, output_time)
    if flag_profile:
        end = time.perf_counter_ns()
        global time_decode
        time_decode += end - begin

    return output_event, output_time, state_event, state_time


dataset = Dataset()
dataset.deserialize(data_path + 'dataset.info')
# input_data = dataset.initial_data.reshape(dataset.n_procs, 1, dataset.n_feature_fields)
input_data = torch.tensor(dataset.initial_data.reshape(dataset.n_procs, 1, 2),
                          dtype=torch.float).to(device)
output_time = torch.zeros((dataset.n_procs, 1, 2), dtype=torch.float).to(device)
dataset.prepare4decode_gpu(device)

model_event = Model(dataset.n_categorical_features,
                    2,
                    dataset.feature_field_size['event'],
                    24, 8, 2).to(device)
model_time = Model(dataset.n_categorical_features,
                   2,
                   dataset.n_numerical_features,
                   16, 8, 0).to(device)

# use GPU to replay
state_dict = torch.load(data_path + 'event.model')
model_event.load_state_dict(state_dict)
model_event.to(device)
state_dict = torch.load(data_path + 'time.model')
model_time.load_state_dict(state_dict)
model_time.to(device)

# use CPU to replay
# model.load_state_dict(torch.load(data_path + 'trace.model', map_location=device))

model_event.eval()
model_time.eval()

# (state_h, state_c) = dataset.initial_state_gpu

state_event = model_event.init_state(dataset.n_procs, device)
state_time = model_time.init_state(dataset.n_procs, device)

scale_factor = 10

MAX_STEPS = int(np.max(dataset.n_events) / scale_factor)

print('%d batches in total' % np.max(dataset.n_events))
print('predict %d batches to approximate' % MAX_STEPS)

time_prediction = 0
time_replay = 0
begin = 0
end = 0

# event_input = torch.zeros((dataset.n_procs, 1, dataset.n_feature_fields)).to(device)
prediction = np.zeros(shape=(MAX_STEPS, dataset.n_procs, 4))
t_begin = time.perf_counter_ns()
# generate remainder events
for i in range(0, MAX_STEPS):
    begin = time.perf_counter_ns()
    pred_event, pred_time, state_event, state_time = predict(dataset, input_data, output_time,
                                                             model_event, model_time,
                                                             state_event, state_time)
    input_data[:, :, 1] = pred_event

    end = time.perf_counter_ns()
    time_prediction += end - begin

    prediction[i, :, :] = torch.cat([input_data, pred_time], dim=2).cpu().numpy().reshape(dataset.n_procs, 4)
    # print('rank=%d replaying predicted %s' % (rank, dataset.get_event_str(event_raw)))

    if i % 2000 == 0:
        print('predicted %d batches of events' % i)
        print('Average time for predicting a batch of events: %.1fus' % (time_prediction / (i + 1) / 1000.0))
        print('Average time for inference: %.1fus' % (time_infer / (i + 1) / 1000.0))
        print('Average time for decoding: %.1fus' % (time_decode / (i + 1) / 1000.0))

t_end = time.perf_counter_ns()
t1 = t_end - t_begin
print(
    'Total time cost for %d batches of events: %fs' % (MAX_STEPS, (t_end - t_begin) / 1000000000.0))
print('Average time for predicting a batch of events: %.1fus' % (time_prediction / MAX_STEPS / 1000.0))

# get predicted trace statistics
t_begin = time.perf_counter_ns()

trace_stats = TraceStat(dataset.n_procs, scale_factor, dataset.n_events)
file = open(data_path + 'prediction.csv', 'w')

# need acceleration
for i in range(dataset.n_procs):
    print('Writing trace %d, %d events' % (i, dataset.n_events[i]))
    time_global2raw = 0
    time_write = 0
    for event_batch in prediction:
        if trace_stats.stats[i].n_events < trace_stats.max_events[i] / trace_stats.scale_factor:
            if flag_profile:
                begin = time.perf_counter_ns()
            event = dataset.global2raw(event_batch[i, :])
            if flag_profile:
                end = time.perf_counter_ns()
                time_global2raw += end - begin

            unzip_event = [event[0]] + event[1].split(';') + [event[-2], event[-1]]
            trace_stats.update(unzip_event)

            if flag_profile:
                begin = time.perf_counter_ns()
            file.write(dataset.get_event_str(event) + '\n')
            if flag_profile:
                end = time.perf_counter_ns()
                time_write += end - begin
        else:
            break
    print('average time for decoding an event %fus' % (time_global2raw / dataset.n_events[i] / 1000.0))
    print('average time for writing an event %fus' % (time_write / dataset.n_events[i] / 1000.0))
file.close()
trace_stats.save(data_path + 'prediction.stat')

t_end = time.perf_counter_ns()
print('Total time cost for predicted trace statistics: %fs' % ((t_end - t_begin) / 1000000000.0))

t2 = t_end - t_begin
print('Total time cost for replay: %fs' % ((t1 + t2) / 1000000000.0))
# trace_stats.visualize()
