# README

**app:** target applications, including NPB CG and LU, and LULESH.  

### mpiP-3.5: Used for trace generating  

+ **mpiPi.h:** Some important global information is located in the mpiPi_t structure.  

+ **mpiPi.c:** The main operating logic of mpiP.  

+ **make-wrappers.py:** Used to add custom operations after intercepting MPI, mainly in the createWrapper function.  

+ **mpiP-wrappers.c:** MPI function with trace function generated after running make-wrappers.py. Do not modify it directly.

### dwarfcode: Used for inter-process merge  

+ **trace2symbol:** Remove some redundant information.  

+ **order:** Reorder events.  

+ **combine:** Trace merge between processes.  

**Train.py:** Data preprocessing (processing each categorical feature field into global index for embedding table, numerical feature normalization), training and testing.  

**Replay.py:** Replay trace.  

**Combine.py:** Organize and merge multiple .order files.    

**MPI_define.py:** Define MPI-related information.  

**Model_LSTM.py:** LSTM model  

**Trace_Dataset.py:** Dataset class for processing trace data  

**TraceStat.py:** Record the statistical information in the trace, including the amount of data sent and received between processes, computation time and communication time, etc.  



## Concise steps  

1. Compile mpiP and dependent libraries to generate libmpiP.so.  

2. Compile the target application, remember to add -lmpiP.  

3. Compile several programs in dwarfcode.  

4. Run the target application, generate a total of np trace files [0:np].trace, and put them into the trace_data folder.  

5. Run trace2symbol 0.trace 0.symbol np, generate [0:np].symbol  

6. Run order 0.symbol 0.order np, generate [0:np].order  

7. Run Combine.py, generate train_dataset.csv  

8. Run Train.py  

9. Run Replay.py

