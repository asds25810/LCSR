import csv
import re

para_dict = {'function': 0,
             'file': 1,
             'incount': 2,
             'count': 3,
             'datatype': 4,
             'source': 5,
             'dest': 6,
             'request': 7,
             'sendcount': 8,
             'sendcnt': 9,
             'sendcnts': 10,
             'sendtype': 11,
             'recvcount': 12,
             'recvcnt': 13,
             'recvcnts': 14,
             'recvtype': 15,
             'op': 16,
             'root': 17,
             'S': 18,
             'E': 19,
             'D': 20,
             'Blank': 21}

f_in = open("./trace_data/0.combine", 'r')
f_out = open("./trace_data/combine.csv", 'w', encoding='utf8', newline='')

writer = csv.writer(f_out)
for line in f_in:
    if "same=" in line:
        same = re.findall(r'\d', line)
        writer.writerow(same)
    if "file=" in line:
        para_list = ['' for _ in range(22)]
        file = re.findall(r'file=(.*?),', line)
        if file:
            para_list[0] = file[0]
        function = re.findall(r'func=(.*?),', line)
        if function:
            para_list[1] = function[0]
        # print(function)
        incount = re.findall(r'incount= (.*?),', line)
        if incount:
            para_list[2] = incount[0]
        count = re.findall(r'count= (.*?),', line)
        if count:
            para_list[3] = count[0]
        datatype = re.findall(r'datatype= (.*?),', line)
        if datatype:
            para_list[4] = datatype[0]
        source = re.findall(r'source= (.*?),', line)
        if source:
            para_list[5] = source[0]
        dest = re.findall(r'dest= (.*?),', line)
        if dest:
            para_list[6] = dest[0]
        request = re.findall(r'request= (.*?),', line)
        if request:
            para_list[7] = request[0]
        sendcount = re.findall(r'sendcount= (.*?),', line)
        if sendcount:
            para_list[8] = sendcount[0]
        sendcnt = re.findall(r'sendcnt= (.*?),', line)
        if sendcnt:
            para_list[9] = sendcnt[0]
        sendcnts = re.findall(r'sendcnts= (.*?),', line)
        if sendcnts:
            para_list[10] = sendcnts[0]
        sendtype = re.findall(r'sendtype= (.*?),', line)
        if sendtype:
            para_list[11] = sendtype[0]
        recvcount = re.findall(r'recvcount= (.*?),', line)
        if recvcount:
            para_list[12] = recvcount[0]
        recvcnt = re.findall(r'recvcnt= (.*?),', line)
        if recvcnt:
            para_list[13] = recvcnt[0]
        recvcnts = re.findall(r'recvcnts= (.*?),', line)
        if recvcnts:
            para_list[14] = recvcnts[0]
        recvtype = re.findall(r'recvtype= (.*?),', line)
        if recvtype:
            para_list[15] = recvtype[0]
        op = re.findall(r'op= (.*?),', line)
        if op:
            para_list[16] = op[0]
        root = re.findall(r'root= (.*?),', line)
        if root:
            para_list[17] = root[0]
        S = re.findall(r'S=\[ (.*?) \],', line)
        if S:
            para_list[18] = S[0]
        E = re.findall(r'E=\[ (.*?) \],', line)
        if E:
            para_list[19] = E[0]
        D = re.findall(r'D=\[ (.*?) \],', line)
        if D:
            para_list[20] = D[0]
        Blank = re.findall(r'Blank=\[ (.*?) \]', line)
        if Blank:
            para_list[21] = Blank[0]
        writer.writerow(para_list)
