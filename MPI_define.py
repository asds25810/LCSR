collectiveList = [
    "MPI_Allgather",
    "MPI_Allgatherv",
    "MPI_Allreduce",
    "MPI_Alltoall",
    "MPI_Alltoallv",
    "MPI_Barrier",
    "MPI_Bcast",
    "MPI_Gather",
    "MPI_Gatherv",
    "MPI_Iallgather",
    "MPI_Iallgatherv",
    "MPI_Iallreduce",
    "MPI_Ialltoall",
    "MPI_Ialltoallv",
    "MPI_Ialltoallw",
    "MPI_Ibcast",
    "MPI_Ibarrier",
    "MPI_Iexscan",
    "MPI_Igather",
    "MPI_Igatherv",
    "MPI_Ireduce",
    "MPI_Ireduce_scatter_block",
    "MPI_Ireduce_scatter",
    "MPI_Iscan",
    "MPI_Iscatter",
    "MPI_Iscatterv",
    "MPI_Reduce",
    "MPI_Reduce_scatter",
    "MPI_Scatter",
    "MPI_Scatterv"
]

# incomplete
pt2ptList = [
    "MPI_Bsend",
    "MPI_Ibsend",
    "MPI_Irsend",
    "MPI_Isend",
    "MPI_Issend",
    "MPI_Rsend",
    "MPI_Send",
    "MPI_Sendrecv",
    "MPI_Sendrecv_replace",
    "MPI_Ssend",
    "MPI_Recv",
    "MPI_Irecv",
    "MPI_Wait"
]

send_para_list = [
    'file',
    'function',
    'count',
    'datatype',
    'dest',
    'S',
    'E',
    'D',
    'Blank'
]

sendrecv_para_list = [
    'file',
    'function',
    'source',
    'dest',
    'sendcount',
    'sendtype',
    'recvcount',
    'recvtype',
    'S',
    'E',
    'D',
    'Blank'
]

function_para_dict = {
    'MPI_Allreduce' : ['file', 'function', 'count', 'datatype', 'Op', 'Blank'],
    'MPI_Sendrecv': ['file', 'function', 'source', 'dest', 'sendcount', 'sendtype', 'recvcount', 'recvtype', 'Blank'],
    'MPI_Barrier' : ['file', 'function', 'Blank'],
    'MPI_Bcast' : ['file', 'function','count','datatype','root', 'Blank'],
}

event_para_dict = {
    'file': 0,
    'function': 1,
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
