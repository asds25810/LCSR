from TraceStat import *

data_path = '/data/sunjw/LCSR/SP-D-529/'
trace_stat1 = TraceStat(16)
trace_stat1.load(data_path + 'train_data.stat')
trace_stat1.visualize()
trace_stat1.time()
print('')
trace_stat2 = TraceStat(16)
trace_stat2.load(data_path + 'prediction.stat')
trace_stat2.visualize()
trace_stat2.time()
pass