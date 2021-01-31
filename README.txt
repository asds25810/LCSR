README

app: target applications, including NPB CG and LU, and LULESH
mpiP-3.5 用于生成trace
    mpiPi.h 一些重要全局信息位于mpiPi_t结构体中
    mpiPi.c mpiP的主要运行逻辑
    make-wrappers.py 用于拦截MPI后添加自定义操作，主要在createWrapper函数
    mpiP-wrappers.c 运行make-wrappers.py之后生成的带trace功能的MPI函数，不要直接修改
dwarfcode 用于进程间合并
    trace2symbol 去掉一些多余信息
    order 将事件重新排序
    combine 进程间trace合并
Train.py 数据预处理（将每个categorical feature field处理为global index for embedding table, numerical feature归一化）、训练和测试
Replay.py 回放trace
Combine.py 将多个.order文件进行整理和合并
MPI_define.py 定义MPI相关的信息
Model_LSTM.py LSTM model 
Trace_Dataset.py Dataset class for processing trace data
TraceStat.py 记录trace中的统计信息，包括进程间数据收发量、computation time和communication time等


简明步骤
1. 编译mpiP及依赖库，生成libmpiP.so
2. 编译目标应用，记得加上-lmpiP
3. 编译dwarfcode中的几个程序
4. 运行目标应用，生成[0:np].trace一共np个trace文件，放入trace_data
5. 运行trace2symbol 0.trace 0.symbol np，生成[0:np].symbol
6. 运行order 0.symbol 0.order np，生成[0:np].order
7. 运行Combine.py，生成train_dataset.csv
8. 运行Train.py
9. 运行Replay.py

