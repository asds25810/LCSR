import csv
import re

para_dict = {
    'file': 0,
    'function': 1,
    'count': 2,
    'datatype': 3,
    'source': 4,
    'dest': 5,
    'root': 6,
    'Blank': 7
}

data_path = './trace_data/lulesh.8/'
f_in = open(data_path+"0.combine", 'r')
f_out = open(data_path+"combine.csv", 'w', encoding='utf8', newline='')

writer = csv.writer(f_out)
for line in f_in:
    if "same=" in line:
        same = re.findall(r'\d+', line)
        writer.writerow(same)
    if "file=" in line:
        para_list = ['' for _ in range(len(para_dict))]
        file = re.findall(r'file=(.*?),', line)
        if file:
            para_list[0] = file[0]
        function = re.findall(r'func=(.*?),', line)
        if function:
            para_list[1] = function[0]
        # print(function)

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
            para_list[4] = source[0]

        dest = re.findall(r'dest= (.*?),', line)
        if dest:
            para_list[5] = dest[0]

        root = re.findall(r'root= (.*?),', line)
        if root:
            para_list[6] = root[0]

        Blank = re.findall(r'Blank=\[ (.*?) \]', line)
        if Blank:
            para_list[7] = Blank[0]
        writer.writerow(para_list)
