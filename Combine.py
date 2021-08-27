import csv
import re
from MPI_define import *
from TraceStat import TraceStat
import sys

para_dict = {
    'file': 0,
    'function': 1,
    'count': 2,
    'datatype': 3,
    'target': 4,
    'tag': 5,
    'D': 6,
    'Blank': 7,
}


def get_offset(source, dest, nprocs):
    offset = (dest + nprocs - source) % nprocs
    return offset


nprocs = 64
data_path = '/data/sunjw/LCSR/sweep3d-64/'

if len(sys.argv) > 1:
    nprocs = int(sys.argv[1])
    data_path = sys.argv[2]

trace_stat = TraceStat(nprocs)

f_out = open(data_path + 'train_dataset.csv', 'w', encoding='utf8', newline='')
csv_writer = csv.writer(f_out)

for i in range(nprocs):
    with open(data_path + str(i) + '.order', 'r') as f_in:
        print('Processing trace %d' % i)
        last_end = 0
        for line in f_in:
            para_list = [''] * len(para_dict)
            para_list[0] = str(i)
            func = re.findall(r': (.*?)= \(', line)
            if func:
                para_list[1] = func[0]

            result = re.findall(r': (.*?)= \(', line)
            if result:
                para_list[1] = result[0]
            result = re.findall(r': (.*?)= \(', line)
            if result:
                para_list[1] = result[0]

            count = re.findall(r'incount= (.*?),', line)
            if count:
                para_list[2] = count[0]
            count = re.findall(r'count= (.*?),', line)
            if count:
                para_list[2] = count[0]
            count = re.findall(r'sendcount= (.*?),', line)
            if count:
                para_list[2] = count[0]
            count = re.findall(r'sendcnt= (.*?),', line)
            if count:
                para_list[2] = count[0]
            count = re.findall(r'recvcount= (.*?),', line)
            if count:
                para_list[2] = count[0]
            count = re.findall(r'recvcnt= (.*?),', line)
            if count:
                para_list[2] = count[0]

            datatype = re.findall(r'datatype= (.*?),', line)
            if datatype:
                para_list[3] = datatype[0]
            datatype = re.findall(r'sendtype= (.*?),', line)
            if datatype:
                para_list[3] = datatype[0]
            datatype = re.findall(r'recvtype= (.*?),', line)
            if datatype:
                para_list[3] = datatype[0]

            source = re.findall(r'source= (.*?),', line)
            if source:
                assert func[0] in recv_list
                s = int(source[0])
                offset = get_offset(s, i, nprocs)
                para_list[4] = str(offset)

            dest = re.findall(r'dest= (.*?),', line)
            if dest:
                assert func[0] in send_list
                d = int(dest[0])
                offset = get_offset(i, d, nprocs)
                para_list[4] = str(offset)

            root = re.findall(r'root= (.*?),', line)
            if root:
                para_list[4] = root[0]

            tag = re.findall(r'tag= (.*?),', line)
            if tag:
                para_list[5] = tag[0]

            S = re.findall(r'S=\[ (.*?) \]', line)
            E = re.findall(r'E=\[ (.*?) \]', line)
            D = re.findall(r'D=\[ (.*?) \]', line)
            if D:
                para_list[6] = D[0]
                # para_list[6] = str(int(E[0]) - int(S[0]))


            if E:
                Blank = int(S[0]) - last_end
                # last_end = int(E[0]) + int(D[0])
                last_end = int(E[0])
                para_list[7] = str(Blank)

            # zip event feature fields
            zip_list = para_list[1]
            for j in range(2, 6):
                zip_list += ';'+ para_list[j]

            csv_writer.writerow([para_list[0], zip_list, para_list[6], para_list[7]])

            trace_stat.update(para_list)
            trace_stat.max_events[i] += 1

trace_stat.save(data_path + 'train_data.stat')
