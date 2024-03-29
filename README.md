# README

### app: target applications, including NPB CG, MG, and LULESH.  

### mpiP-3.5: Tracing tool, modified from the original mpiP-3.5 and DwarfCode version of mpiP.  

+ **mpiPi.h:** Some important global information is located in the mpiPi_t structure.  

+ **mpiPi.c:** The main operating logic of mpiP.  

+ **make-wrappers.py:** Add customized operations after intercepting MPI.  

+ **mpiP-wrappers.c:** Wrapped MPI  generated by make-wrappers.py. Do not modify it directly.

### dwarfcode: Used for preprocess  

+ **trace2symbol:** Remove some redundant information.  

+ **order:** Reorder events.  


**Train.py:** Data preprocessing (processing each categorical feature field into global index for embedding table, numerical feature discretization), model training.  

**Replay.py:** Predict and simulate MPI event sequence.  

**Combine.py:** Organize and concatenate multiple .order files.    

**MPI_define.py:** Define MPI-related information.  

**Model_LSTM.py:** LSTM model.  

**Trace_Dataset.py:** Dataset class for processing trace data.  

**TraceStat.py:** Record the statistical information in the trace, including the amount of data sent and received between processes, computation time and communication time, etc.  



## Quick start  

1. Compile mpiP and dependent libraries to generate libmpiP.so.  

2. Compile the target application, add -lmpiP after -lmpi. An alternative way is runtime instrument via export LD_PRELOAD=[path to mpiP]/libmpiP.so 

3. Compile trace2symbol and order programs in dwarfcode.  

4. Run the target application, generate np trace files [0:np].trace, and put them into the trace_data folder.  

5. Run trace2symbol 0.trace 0.symbol np, generate [0:np].symbol  

6. Run order 0.symbol 0.order np, generate [0:np].order  

7. Run Combine.py, generate train_dataset.csv  

8. Run Train.py  

9. Run Replay.py

