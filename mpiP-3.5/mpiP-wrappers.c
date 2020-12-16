/* /home/sunjw/mpiP/source/mpiP-3.5/mpiP-wrappers.c */
/* DO NOT EDIT -- AUTOMATICALLY GENERATED! */
/* Timestamp: 10 December 2020 22:13  */
/* Location: ada-server posix */
/* Creator: sunjw  */


#include <string.h>
#include "mpiPi.h"
#include "symbols.h"
#include "mpiPi_def.h"




/* --------------- MPI_Accumulate --------------- */

static int mpiPif_MPI_Accumulate( jmp_buf * base_jbuf, mpip_const_void_t  *origin_addr, int  * origin_count, MPI_Datatype  * origin_datatype, int  * target_rank, MPI_Aint  * target_disp, int  * target_count, MPI_Datatype  * target_datatype, MPI_Op  * op, MPI_Win  * win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Accumulate\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t origin_addr, int* origin_count, MPI_Datatype* origin_datatype, int* target_rank, MPI_Aint* target_disp, int* target_count, MPI_Datatype* target_datatype, MPI_Op* op, MPI_Win* win )\n");
MPI_Type_size(*origin_datatype, &DT_size);
MPI_Type_size(*target_datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t origin_addr= %d, int origin_count= %d, MPI_Datatype origin_datatype= %d, int target_rank= %d, MPI_Aint target_disp= %d, int target_count= %d, MPI_Datatype target_datatype= %d, MPI_Op op= %d, MPI_Win win= %d, )\n", origin_addr, *origin_count, DT_size, *target_rank, *target_disp, *target_count, DT_size, *op, *win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Accumulate( origin_addr,  * origin_count,  * origin_datatype,  * target_rank,  * target_disp,  * target_count,  * target_datatype,  * op,  * win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

PMPI_Type_size(*target_datatype, &tsize);
rmaSize = (double)(tsize * *target_count);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Accumulate");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Accumulate, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Accumulate */



extern int MPI_Accumulate ( mpip_const_void_t *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Accumulate( &jbuf, origin_addr,  & origin_count,  & origin_datatype,  & target_rank,  & target_disp,  & target_count,  & target_datatype,  & op,  & win );

return rc;
} /* MPI_Accumulate */


extern void F77_MPI_ACCUMULATE(mpip_const_void_t  *origin_addr, int  * origin_count, MPI_Fint  * origin_datatype, int  * target_rank, MPI_Aint  * target_disp, int  * target_count, MPI_Fint  * target_datatype, MPI_Fint  * op, MPI_Win  * win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_origin_datatype;
MPI_Datatype c_target_datatype;
MPI_Op c_op;

c_origin_datatype = MPI_Type_f2c(*origin_datatype);
c_target_datatype = MPI_Type_f2c(*target_datatype);
c_op = MPI_Op_f2c(*op);

rc = mpiPif_MPI_Accumulate( &jbuf, origin_addr, origin_count, &c_origin_datatype, target_rank, target_disp, target_count, &c_target_datatype, &c_op, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_accumulate */



/* --------------- MPI_Allgather --------------- */

static int mpiPif_MPI_Allgather( jmp_buf * base_jbuf, mpip_const_void_t  *sendbuf, int  * sendcount, MPI_Datatype  * sendtype, void  *recvbuf, int  * recvcount, MPI_Datatype  * recvtype, MPI_Comm  * comm)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Allgather\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t sendbuf, int* sendcount, MPI_Datatype* sendtype, void recvbuf, int* recvcount, MPI_Datatype* recvtype, MPI_Comm* comm )\n");
MPI_Type_size(*sendtype, &DT_size);
MPI_Type_size(*recvtype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t sendbuf= %d, int sendcount= %d, MPI_Datatype sendtype= %d, void recvbuf= %d, int recvcount= %d, MPI_Datatype recvtype= %d, MPI_Comm comm= %d, )\n", sendbuf, *sendcount, DT_size, recvbuf, *recvcount, DT_size, *comm);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Allgather( sendbuf,  * sendcount,  * sendtype, recvbuf,  * recvcount,  * recvtype,  * comm);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *sendtype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*sendtype, &tsize);
messSize = (double)(tsize * *sendcount);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Allgather");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Allgather, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Allgather, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Allgather */



extern int MPI_Allgather ( mpip_const_void_t *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Allgather( &jbuf, sendbuf,  & sendcount,  & sendtype, recvbuf,  & recvcount,  & recvtype,  & comm );

return rc;
} /* MPI_Allgather */


extern void F77_MPI_ALLGATHER(mpip_const_void_t  *sendbuf, int  * sendcount, MPI_Fint  * sendtype, void  *recvbuf, int  * recvcount, MPI_Fint  * recvtype, MPI_Fint  * comm , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Allgather( &jbuf, sendbuf, sendcount, &c_sendtype, recvbuf, recvcount, &c_recvtype, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_allgather */



/* --------------- MPI_Allgatherv --------------- */

static int mpiPif_MPI_Allgatherv( jmp_buf * base_jbuf, mpip_const_void_t  *sendbuf, int  * sendcount, MPI_Datatype  * sendtype, void  *recvbuf, mpip_const_int_t  *recvcounts, mpip_const_int_t  *displs, MPI_Datatype  * recvtype, MPI_Comm  * comm)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Allgatherv\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t sendbuf, int* sendcount, MPI_Datatype* sendtype, void recvbuf, mpip_const_int_t recvcounts, mpip_const_int_t displs, MPI_Datatype* recvtype, MPI_Comm* comm )\n");
MPI_Type_size(*sendtype, &DT_size);
MPI_Type_size(*recvtype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t sendbuf= %d, int sendcount= %d, MPI_Datatype sendtype= %d, void recvbuf= %d, mpip_const_int_t recvcounts= %d, mpip_const_int_t displs= %d, MPI_Datatype recvtype= %d, MPI_Comm comm= %d, )\n", sendbuf, *sendcount, DT_size, recvbuf, recvcounts, displs, DT_size, *comm);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Allgatherv( sendbuf,  * sendcount,  * sendtype, recvbuf, recvcounts, displs,  * recvtype,  * comm);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *sendtype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*sendtype, &tsize);
messSize = (double)(tsize * *sendcount);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Allgatherv");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Allgatherv, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Allgatherv, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Allgatherv */



extern int MPI_Allgatherv ( mpip_const_void_t *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, mpip_const_int_t *recvcounts, mpip_const_int_t *displs, MPI_Datatype recvtype, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Allgatherv( &jbuf, sendbuf,  & sendcount,  & sendtype, recvbuf, recvcounts, displs,  & recvtype,  & comm );

return rc;
} /* MPI_Allgatherv */


extern void F77_MPI_ALLGATHERV(mpip_const_void_t  *sendbuf, int  * sendcount, MPI_Fint  * sendtype, void  *recvbuf, mpip_const_int_t  *recvcounts, mpip_const_int_t  *displs, MPI_Fint  * recvtype, MPI_Fint  * comm , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Allgatherv( &jbuf, sendbuf, sendcount, &c_sendtype, recvbuf, recvcounts, displs, &c_recvtype, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_allgatherv */



/* --------------- MPI_Allreduce --------------- */

static int mpiPif_MPI_Allreduce( jmp_buf * base_jbuf, mpip_const_void_t  *sendbuf, void  *recvbuf, int  * count, MPI_Datatype  * datatype, MPI_Op  * op, MPI_Comm  * comm)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Allreduce\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t sendbuf, void recvbuf, int* count, MPI_Datatype* datatype, MPI_Op* op, MPI_Comm* comm )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t sendbuf= %d, void recvbuf= %d, int count= %d, MPI_Datatype datatype= %d, MPI_Op op= %d, MPI_Comm comm= %d, )\n", sendbuf, recvbuf, *count, DT_size, *op, *comm);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Allreduce( sendbuf, recvbuf,  * count,  * datatype,  * op,  * comm);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Allreduce");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Allreduce, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Allreduce, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Allreduce */



extern int MPI_Allreduce ( mpip_const_void_t *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Allreduce( &jbuf, sendbuf, recvbuf,  & count,  & datatype,  & op,  & comm );

return rc;
} /* MPI_Allreduce */


extern void F77_MPI_ALLREDUCE(mpip_const_void_t  *sendbuf, void  *recvbuf, int  * count, MPI_Fint  * datatype, MPI_Fint  * op, MPI_Fint  * comm , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Op c_op;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_op = MPI_Op_f2c(*op);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Allreduce( &jbuf, sendbuf, recvbuf, count, &c_datatype, &c_op, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_allreduce */



/* --------------- MPI_Alltoall --------------- */

static int mpiPif_MPI_Alltoall( jmp_buf * base_jbuf, mpip_const_void_t  *sendbuf, int  * sendcount, MPI_Datatype  * sendtype, void  *recvbuf, int  * recvcnt, MPI_Datatype  * recvtype, MPI_Comm  * comm)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Alltoall\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t sendbuf, int* sendcount, MPI_Datatype* sendtype, void recvbuf, int* recvcnt, MPI_Datatype* recvtype, MPI_Comm* comm )\n");
MPI_Type_size(*sendtype, &DT_size);
MPI_Type_size(*recvtype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t sendbuf= %d, int sendcount= %d, MPI_Datatype sendtype= %d, void recvbuf= %d, int recvcnt= %d, MPI_Datatype recvtype= %d, MPI_Comm comm= %d, )\n", sendbuf, *sendcount, DT_size, recvbuf, *recvcnt, DT_size, *comm);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Alltoall( sendbuf,  * sendcount,  * sendtype, recvbuf,  * recvcnt,  * recvtype,  * comm);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *sendtype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*sendtype, &tsize);
messSize = (double)(tsize * *sendcount);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Alltoall");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Alltoall, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Alltoall, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Alltoall */



extern int MPI_Alltoall ( mpip_const_void_t *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcnt, MPI_Datatype recvtype, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Alltoall( &jbuf, sendbuf,  & sendcount,  & sendtype, recvbuf,  & recvcnt,  & recvtype,  & comm );

return rc;
} /* MPI_Alltoall */


extern void F77_MPI_ALLTOALL(mpip_const_void_t  *sendbuf, int  * sendcount, MPI_Fint  * sendtype, void  *recvbuf, int  * recvcnt, MPI_Fint  * recvtype, MPI_Fint  * comm , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Alltoall( &jbuf, sendbuf, sendcount, &c_sendtype, recvbuf, recvcnt, &c_recvtype, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_alltoall */



/* --------------- MPI_Alltoallv --------------- */

static int mpiPif_MPI_Alltoallv( jmp_buf * base_jbuf, mpip_const_void_t  *sendbuf, mpip_const_int_t  *sendcnts, mpip_const_int_t  *sdispls, MPI_Datatype  * sendtype, void  *recvbuf, mpip_const_int_t  *recvcnts, mpip_const_int_t  *rdispls, MPI_Datatype  * recvtype, MPI_Comm  * comm)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Alltoallv\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t sendbuf, mpip_const_int_t sendcnts, mpip_const_int_t sdispls, MPI_Datatype* sendtype, void recvbuf, mpip_const_int_t recvcnts, mpip_const_int_t rdispls, MPI_Datatype* recvtype, MPI_Comm* comm )\n");
MPI_Type_size(*sendtype, &DT_size);
MPI_Type_size(*recvtype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t sendbuf= %d, mpip_const_int_t sendcnts= %d, mpip_const_int_t sdispls= %d, MPI_Datatype sendtype= %d, void recvbuf= %d, mpip_const_int_t recvcnts= %d, mpip_const_int_t rdispls= %d, MPI_Datatype recvtype= %d, MPI_Comm comm= %d, )\n", sendbuf, sendcnts, sdispls, DT_size, recvbuf, recvcnts, rdispls, DT_size, *comm);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Alltoallv( sendbuf, sendcnts, sdispls,  * sendtype, recvbuf, recvcnts, rdispls,  * recvtype,  * comm);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Alltoallv");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Alltoallv, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Alltoallv, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Alltoallv */



extern int MPI_Alltoallv ( mpip_const_void_t *sendbuf, mpip_const_int_t *sendcnts, mpip_const_int_t *sdispls, MPI_Datatype sendtype, void *recvbuf, mpip_const_int_t *recvcnts, mpip_const_int_t *rdispls, MPI_Datatype recvtype, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Alltoallv( &jbuf, sendbuf, sendcnts, sdispls,  & sendtype, recvbuf, recvcnts, rdispls,  & recvtype,  & comm );

return rc;
} /* MPI_Alltoallv */


extern void F77_MPI_ALLTOALLV(mpip_const_void_t  *sendbuf, mpip_const_int_t  *sendcnts, mpip_const_int_t  *sdispls, MPI_Fint  * sendtype, void  *recvbuf, mpip_const_int_t  *recvcnts, mpip_const_int_t  *rdispls, MPI_Fint  * recvtype, MPI_Fint  * comm , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Alltoallv( &jbuf, sendbuf, sendcnts, sdispls, &c_sendtype, recvbuf, recvcnts, rdispls, &c_recvtype, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_alltoallv */



/* --------------- MPI_Barrier --------------- */

static int mpiPif_MPI_Barrier( jmp_buf * base_jbuf, MPI_Comm  * comm)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Barrier\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, )\n", *comm);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Barrier(  * comm);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Barrier");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Barrier, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Barrier, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Barrier */



extern int MPI_Barrier ( MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Barrier( &jbuf,  & comm );

return rc;
} /* MPI_Barrier */


extern void F77_MPI_BARRIER(MPI_Fint  * comm , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Barrier( &jbuf, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_barrier */



/* --------------- MPI_Bcast --------------- */

static int mpiPif_MPI_Bcast( jmp_buf * base_jbuf, void  *buffer, int  * count, MPI_Datatype  * datatype, int  * root, MPI_Comm  * comm)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Bcast\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( void buffer, int* count, MPI_Datatype* datatype, int* root, MPI_Comm* comm )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (void buffer= %d, int count= %d, MPI_Datatype datatype= %d, int root= %d, MPI_Comm comm= %d, )\n", buffer, *count, DT_size, *root, *comm);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Bcast( buffer,  * count,  * datatype,  * root,  * comm);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Bcast");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Bcast, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Bcast, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Bcast */



extern int MPI_Bcast ( void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Bcast( &jbuf, buffer,  & count,  & datatype,  & root,  & comm );

return rc;
} /* MPI_Bcast */


extern void F77_MPI_BCAST(void  *buffer, int  * count, MPI_Fint  * datatype, int  * root, MPI_Fint  * comm , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Bcast( &jbuf, buffer, count, &c_datatype, root, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_bcast */



/* --------------- MPI_Bsend --------------- */

static int mpiPif_MPI_Bsend( jmp_buf * base_jbuf, mpip_const_void_t  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * tag, MPI_Comm  * comm)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Bsend\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t buf, int* count, MPI_Datatype* datatype, int* dest, int* tag, MPI_Comm* comm )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t buf= %d, int count= %d, MPI_Datatype datatype= %d, int dest= %d, int tag= %d, MPI_Comm comm= %d, )\n", buf, *count, DT_size, *dest, *tag, *comm);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Bsend( buf,  * count,  * datatype,  * dest,  * tag,  * comm);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Bsend");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Bsend, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_pt2pt_stats_report) { mpiPi_update_pt2pt_stats(hndl, mpiPi_MPI_Bsend, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Bsend */



extern int MPI_Bsend ( mpip_const_void_t *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Bsend( &jbuf, buf,  & count,  & datatype,  & dest,  & tag,  & comm );

return rc;
} /* MPI_Bsend */


extern void F77_MPI_BSEND(mpip_const_void_t  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * tag, MPI_Fint  * comm , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Bsend( &jbuf, buf, count, &c_datatype, dest, tag, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_bsend */



/* --------------- MPI_Bsend_init --------------- */

static int mpiPif_MPI_Bsend_init( jmp_buf * base_jbuf, mpip_const_void_t  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * tag, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Bsend_init\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t buf, int* count, MPI_Datatype* datatype, int* dest, int* tag, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t buf= %d, int count= %d, MPI_Datatype datatype= %d, int dest= %d, int tag= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", buf, *count, DT_size, *dest, *tag, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Bsend_init( buf,  * count,  * datatype,  * dest,  * tag,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Bsend_init");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Bsend_init, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Bsend_init */



extern int MPI_Bsend_init ( mpip_const_void_t *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Bsend_init( &jbuf, buf,  & count,  & datatype,  & dest,  & tag,  & comm, request );

return rc;
} /* MPI_Bsend_init */


extern void F77_MPI_BSEND_INIT(mpip_const_void_t  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * tag, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Bsend_init( &jbuf, buf, count, &c_datatype, dest, tag, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_bsend_init */



/* --------------- MPI_Buffer_attach --------------- */

static int mpiPif_MPI_Buffer_attach( jmp_buf * base_jbuf, void  *buffer, int  * size)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Buffer_attach\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( void buffer, int* size )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (void buffer= %d, int size= %d, )\n", buffer, *size);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Buffer_attach( buffer,  * size);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Buffer_attach");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Buffer_attach, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Buffer_attach */



extern int MPI_Buffer_attach ( void *buffer, int size )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Buffer_attach( &jbuf, buffer,  & size );

return rc;
} /* MPI_Buffer_attach */


extern void F77_MPI_BUFFER_ATTACH(void  *buffer, int  * size , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Buffer_attach( &jbuf, buffer, size );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_buffer_attach */



/* --------------- MPI_Buffer_detach --------------- */

static int mpiPif_MPI_Buffer_detach( jmp_buf * base_jbuf, void  *bufferptr, int  *size)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Buffer_detach\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( void bufferptr, int size )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (void bufferptr= %d, int size= %d, )\n", bufferptr, size);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Buffer_detach( bufferptr, size);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Buffer_detach");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Buffer_detach, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Buffer_detach */



extern int MPI_Buffer_detach ( void *bufferptr, int *size )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Buffer_detach( &jbuf, bufferptr, size );

return rc;
} /* MPI_Buffer_detach */


extern void F77_MPI_BUFFER_DETACH(void  *bufferptr, int  *size , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Buffer_detach( &jbuf, bufferptr, size );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_buffer_detach */



/* --------------- MPI_Cancel --------------- */

static int mpiPif_MPI_Cancel( jmp_buf * base_jbuf, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Cancel\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Request request )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Request request= %d, )\n", request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Cancel( request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Cancel");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Cancel, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Cancel */



extern int MPI_Cancel ( MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Cancel( &jbuf, request );

return rc;
} /* MPI_Cancel */


extern void F77_MPI_CANCEL(MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Request c_request;

c_request = MPI_Request_f2c(*request);

rc = mpiPif_MPI_Cancel( &jbuf, &c_request );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_cancel */



/* --------------- MPI_Cart_coords --------------- */

static int mpiPif_MPI_Cart_coords( jmp_buf * base_jbuf, MPI_Comm  * comm, int  * rank, int  * maxdims, int  *coords)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Cart_coords\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm, int* rank, int* maxdims, int coords )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, int rank= %d, int maxdims= %d, int coords= %d, )\n", *comm, *rank, *maxdims, coords);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Cart_coords(  * comm,  * rank,  * maxdims, coords);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Cart_coords");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Cart_coords, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Cart_coords */



extern int MPI_Cart_coords ( MPI_Comm comm, int rank, int maxdims, int *coords )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Cart_coords( &jbuf,  & comm,  & rank,  & maxdims, coords );

return rc;
} /* MPI_Cart_coords */


extern void F77_MPI_CART_COORDS(MPI_Fint  * comm, int  * rank, int  * maxdims, int  *coords , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Cart_coords( &jbuf, &c_comm, rank, maxdims, coords );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_cart_coords */



/* --------------- MPI_Cart_create --------------- */

static int mpiPif_MPI_Cart_create( jmp_buf * base_jbuf, MPI_Comm  * comm_old, int  * ndims, mpip_const_int_t  *dims, mpip_const_int_t  *periods, int  * reorder, MPI_Comm  *comm_cart)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Cart_create\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm_old, int* ndims, mpip_const_int_t dims, mpip_const_int_t periods, int* reorder, MPI_Comm comm_cart )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm_old= %d, int ndims= %d, mpip_const_int_t dims= %d, mpip_const_int_t periods= %d, int reorder= %d, MPI_Comm comm_cart= %d, )\n", *comm_old, *ndims, dims, periods, *reorder, comm_cart);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Cart_create(  * comm_old,  * ndims, dims, periods,  * reorder, comm_cart);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Cart_create");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Cart_create, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Cart_create */



extern int MPI_Cart_create ( MPI_Comm comm_old, int ndims, mpip_const_int_t *dims, mpip_const_int_t *periods, int reorder, MPI_Comm *comm_cart )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Cart_create( &jbuf,  & comm_old,  & ndims, dims, periods,  & reorder, comm_cart );

return rc;
} /* MPI_Cart_create */


extern void F77_MPI_CART_CREATE(MPI_Fint  * comm_old, int  * ndims, mpip_const_int_t  *dims, mpip_const_int_t  *periods, int  * reorder, MPI_Fint  *comm_cart , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm_old;
MPI_Comm c_comm_cart;

c_comm_old = MPI_Comm_f2c(*comm_old);

rc = mpiPif_MPI_Cart_create( &jbuf, &c_comm_old, ndims, dims, periods, reorder, &c_comm_cart );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*comm_cart = MPI_Comm_c2f(c_comm_cart);
}
return;
} /* mpi_cart_create */



/* --------------- MPI_Cart_get --------------- */

static int mpiPif_MPI_Cart_get( jmp_buf * base_jbuf, MPI_Comm  * comm, int  * maxdims, int  *dims, int  *periods, int  *coords)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Cart_get\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm, int* maxdims, int dims, int periods, int coords )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, int maxdims= %d, int dims= %d, int periods= %d, int coords= %d, )\n", *comm, *maxdims, dims, periods, coords);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Cart_get(  * comm,  * maxdims, dims, periods, coords);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Cart_get");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Cart_get, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Cart_get */



extern int MPI_Cart_get ( MPI_Comm comm, int maxdims, int *dims, int *periods, int *coords )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Cart_get( &jbuf,  & comm,  & maxdims, dims, periods, coords );

return rc;
} /* MPI_Cart_get */


extern void F77_MPI_CART_GET(MPI_Fint  * comm, int  * maxdims, int  *dims, int  *periods, int  *coords , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Cart_get( &jbuf, &c_comm, maxdims, dims, periods, coords );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_cart_get */



/* --------------- MPI_Cart_map --------------- */

static int mpiPif_MPI_Cart_map( jmp_buf * base_jbuf, MPI_Comm  * comm_old, int  * ndims, mpip_const_int_t  *dims, mpip_const_int_t  *periods, int  *newrank)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Cart_map\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm_old, int* ndims, mpip_const_int_t dims, mpip_const_int_t periods, int newrank )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm_old= %d, int ndims= %d, mpip_const_int_t dims= %d, mpip_const_int_t periods= %d, int newrank= %d, )\n", *comm_old, *ndims, dims, periods, newrank);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Cart_map(  * comm_old,  * ndims, dims, periods, newrank);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Cart_map");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Cart_map, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Cart_map */



extern int MPI_Cart_map ( MPI_Comm comm_old, int ndims, mpip_const_int_t *dims, mpip_const_int_t *periods, int *newrank )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Cart_map( &jbuf,  & comm_old,  & ndims, dims, periods, newrank );

return rc;
} /* MPI_Cart_map */


extern void F77_MPI_CART_MAP(MPI_Fint  * comm_old, int  * ndims, mpip_const_int_t  *dims, mpip_const_int_t  *periods, int  *newrank , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm_old;

c_comm_old = MPI_Comm_f2c(*comm_old);

rc = mpiPif_MPI_Cart_map( &jbuf, &c_comm_old, ndims, dims, periods, newrank );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_cart_map */



/* --------------- MPI_Cart_rank --------------- */

static int mpiPif_MPI_Cart_rank( jmp_buf * base_jbuf, MPI_Comm  * comm, mpip_const_int_t  *coords, int  *rank)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Cart_rank\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm, mpip_const_int_t coords, int rank )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, mpip_const_int_t coords= %d, int rank= %d, )\n", *comm, coords, rank);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Cart_rank(  * comm, coords, rank);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Cart_rank");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Cart_rank, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Cart_rank */



extern int MPI_Cart_rank ( MPI_Comm comm, mpip_const_int_t *coords, int *rank )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Cart_rank( &jbuf,  & comm, coords, rank );

return rc;
} /* MPI_Cart_rank */


extern void F77_MPI_CART_RANK(MPI_Fint  * comm, mpip_const_int_t  *coords, int  *rank , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Cart_rank( &jbuf, &c_comm, coords, rank );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_cart_rank */



/* --------------- MPI_Cart_shift --------------- */

static int mpiPif_MPI_Cart_shift( jmp_buf * base_jbuf, MPI_Comm  * comm, int  * direction, int  * displ, int  *source, int  *dest)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Cart_shift\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm, int* direction, int* displ, int source, int dest )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, int direction= %d, int displ= %d, int source= %d, int dest= %d, )\n", *comm, *direction, *displ, source, dest);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Cart_shift(  * comm,  * direction,  * displ, source, dest);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Cart_shift");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Cart_shift, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Cart_shift */



extern int MPI_Cart_shift ( MPI_Comm comm, int direction, int displ, int *source, int *dest )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Cart_shift( &jbuf,  & comm,  & direction,  & displ, source, dest );

return rc;
} /* MPI_Cart_shift */


extern void F77_MPI_CART_SHIFT(MPI_Fint  * comm, int  * direction, int  * displ, int  *source, int  *dest , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Cart_shift( &jbuf, &c_comm, direction, displ, source, dest );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_cart_shift */



/* --------------- MPI_Cart_sub --------------- */

static int mpiPif_MPI_Cart_sub( jmp_buf * base_jbuf, MPI_Comm  * comm, mpip_const_int_t  *remain_dims, MPI_Comm  *comm_new)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Cart_sub\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm, mpip_const_int_t remain_dims, MPI_Comm comm_new )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, mpip_const_int_t remain_dims= %d, MPI_Comm comm_new= %d, )\n", *comm, remain_dims, comm_new);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Cart_sub(  * comm, remain_dims, comm_new);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Cart_sub");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Cart_sub, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Cart_sub */



extern int MPI_Cart_sub ( MPI_Comm comm, mpip_const_int_t *remain_dims, MPI_Comm *comm_new )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Cart_sub( &jbuf,  & comm, remain_dims, comm_new );

return rc;
} /* MPI_Cart_sub */


extern void F77_MPI_CART_SUB(MPI_Fint  * comm, mpip_const_int_t  *remain_dims, MPI_Fint  *comm_new , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;
MPI_Comm c_comm_new;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Cart_sub( &jbuf, &c_comm, remain_dims, &c_comm_new );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*comm_new = MPI_Comm_c2f(c_comm_new);
}
return;
} /* mpi_cart_sub */



/* --------------- MPI_Cartdim_get --------------- */

static int mpiPif_MPI_Cartdim_get( jmp_buf * base_jbuf, MPI_Comm  * comm, int  *ndims)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Cartdim_get\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm, int ndims )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, int ndims= %d, )\n", *comm, ndims);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Cartdim_get(  * comm, ndims);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Cartdim_get");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Cartdim_get, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Cartdim_get */



extern int MPI_Cartdim_get ( MPI_Comm comm, int *ndims )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Cartdim_get( &jbuf,  & comm, ndims );

return rc;
} /* MPI_Cartdim_get */


extern void F77_MPI_CARTDIM_GET(MPI_Fint  * comm, int  *ndims , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Cartdim_get( &jbuf, &c_comm, ndims );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_cartdim_get */



/* --------------- MPI_Comm_create --------------- */

static int mpiPif_MPI_Comm_create( jmp_buf * base_jbuf, MPI_Comm  * comm, MPI_Group  * group, MPI_Comm  *comm_out)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Comm_create\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm, MPI_Group* group, MPI_Comm comm_out )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, MPI_Group group= %d, MPI_Comm comm_out= %d, )\n", *comm, *group, comm_out);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Comm_create(  * comm,  * group, comm_out);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Comm_create");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Comm_create, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Comm_create */



extern int MPI_Comm_create ( MPI_Comm comm, MPI_Group group, MPI_Comm *comm_out )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Comm_create( &jbuf,  & comm,  & group, comm_out );

return rc;
} /* MPI_Comm_create */


extern void F77_MPI_COMM_CREATE(MPI_Fint  * comm, MPI_Fint  * group, MPI_Fint  *comm_out , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;
MPI_Group c_group;
MPI_Comm c_comm_out;

c_comm = MPI_Comm_f2c(*comm);
c_group = MPI_Group_f2c(*group);

rc = mpiPif_MPI_Comm_create( &jbuf, &c_comm, &c_group, &c_comm_out );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*comm_out = MPI_Comm_c2f(c_comm_out);
}
return;
} /* mpi_comm_create */



/* --------------- MPI_Comm_create_keyval --------------- */

static int mpiPif_MPI_Comm_create_keyval( jmp_buf * base_jbuf, MPI_Comm_copy_attr_function  *comm_copy_attr_fn, MPI_Comm_delete_attr_function  *comm_delete_attr_fn, int  *comm_keyval, void  *extra_state)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Comm_create_keyval\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm_copy_attr_function comm_copy_attr_fn, MPI_Comm_delete_attr_function comm_delete_attr_fn, int comm_keyval, void extra_state )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm_copy_attr_function comm_copy_attr_fn= %d, MPI_Comm_delete_attr_function comm_delete_attr_fn= %d, int comm_keyval= %d, void extra_state= %d, )\n", comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Comm_create_keyval( comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Comm_create_keyval");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Comm_create_keyval, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Comm_create_keyval */



extern int MPI_Comm_create_keyval ( MPI_Comm_copy_attr_function *comm_copy_attr_fn, MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval, void *extra_state )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Comm_create_keyval( &jbuf, comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state );

return rc;
} /* MPI_Comm_create_keyval */


extern void F77_MPI_COMM_CREATE_KEYVAL(MPI_Comm_copy_attr_function  *comm_copy_attr_fn, MPI_Comm_delete_attr_function  *comm_delete_attr_fn, int  *comm_keyval, void  *extra_state , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Comm_create_keyval( &jbuf, comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_comm_create_keyval */



/* --------------- MPI_Comm_delete_attr --------------- */

static int mpiPif_MPI_Comm_delete_attr( jmp_buf * base_jbuf, MPI_Comm  * comm, int  * comm_keyval)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Comm_delete_attr\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm, int* comm_keyval )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, int comm_keyval= %d, )\n", *comm, *comm_keyval);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Comm_delete_attr(  * comm,  * comm_keyval);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Comm_delete_attr");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Comm_delete_attr, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Comm_delete_attr */



extern int MPI_Comm_delete_attr ( MPI_Comm comm, int comm_keyval )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Comm_delete_attr( &jbuf,  & comm,  & comm_keyval );

return rc;
} /* MPI_Comm_delete_attr */


extern void F77_MPI_COMM_DELETE_ATTR(MPI_Fint  * comm, int  * comm_keyval , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Comm_delete_attr( &jbuf, &c_comm, comm_keyval );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_comm_delete_attr */



/* --------------- MPI_Comm_dup --------------- */

static int mpiPif_MPI_Comm_dup( jmp_buf * base_jbuf, MPI_Comm  * comm, MPI_Comm  *comm_out)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Comm_dup\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm, MPI_Comm comm_out )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, MPI_Comm comm_out= %d, )\n", *comm, comm_out);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Comm_dup(  * comm, comm_out);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Comm_dup");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Comm_dup, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Comm_dup */



extern int MPI_Comm_dup ( MPI_Comm comm, MPI_Comm *comm_out )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Comm_dup( &jbuf,  & comm, comm_out );

return rc;
} /* MPI_Comm_dup */


extern void F77_MPI_COMM_DUP(MPI_Fint  * comm, MPI_Fint  *comm_out , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;
MPI_Comm c_comm_out;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Comm_dup( &jbuf, &c_comm, &c_comm_out );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*comm_out = MPI_Comm_c2f(c_comm_out);
}
return;
} /* mpi_comm_dup */



/* --------------- MPI_Comm_free --------------- */

static int mpiPif_MPI_Comm_free( jmp_buf * base_jbuf, MPI_Comm  *commp)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Comm_free\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm commp )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm commp= %d, )\n", commp);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Comm_free( commp);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Comm_free");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Comm_free, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Comm_free */



extern int MPI_Comm_free ( MPI_Comm *commp )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Comm_free( &jbuf, commp );

return rc;
} /* MPI_Comm_free */


extern void F77_MPI_COMM_FREE(MPI_Fint  *commp , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_commp;

c_commp = MPI_Comm_f2c(*commp);

rc = mpiPif_MPI_Comm_free( &jbuf, &c_commp );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*commp = MPI_Comm_c2f(c_commp);
}
return;
} /* mpi_comm_free */



/* --------------- MPI_Comm_free_keyval --------------- */

static int mpiPif_MPI_Comm_free_keyval( jmp_buf * base_jbuf, int  *keyval)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Comm_free_keyval\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( int keyval )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (int keyval= %d, )\n", keyval);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Comm_free_keyval( keyval);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Comm_free_keyval");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Comm_free_keyval, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Comm_free_keyval */



extern int MPI_Comm_free_keyval ( int *keyval )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Comm_free_keyval( &jbuf, keyval );

return rc;
} /* MPI_Comm_free_keyval */


extern void F77_MPI_COMM_FREE_KEYVAL(int  *keyval , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Comm_free_keyval( &jbuf, keyval );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_comm_free_keyval */



/* --------------- MPI_Comm_get_attr --------------- */

static int mpiPif_MPI_Comm_get_attr( jmp_buf * base_jbuf, MPI_Comm  * comm, int  * comm_keyval, void  *attribute_value, int  *flag)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Comm_get_attr\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm, int* comm_keyval, void attribute_value, int flag )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, int comm_keyval= %d, void attribute_value= %d, int flag= %d, )\n", *comm, *comm_keyval, attribute_value, flag);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Comm_get_attr(  * comm,  * comm_keyval, attribute_value, flag);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Comm_get_attr");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Comm_get_attr, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Comm_get_attr */



extern int MPI_Comm_get_attr ( MPI_Comm comm, int comm_keyval, void *attribute_value, int *flag )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Comm_get_attr( &jbuf,  & comm,  & comm_keyval, attribute_value, flag );

return rc;
} /* MPI_Comm_get_attr */


extern void F77_MPI_COMM_GET_ATTR(MPI_Fint  * comm, int  * comm_keyval, void  *attribute_value, int  *flag , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Comm_get_attr( &jbuf, &c_comm, comm_keyval, attribute_value, flag );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_comm_get_attr */



/* --------------- MPI_Comm_group --------------- */

static int mpiPif_MPI_Comm_group( jmp_buf * base_jbuf, MPI_Comm  * comm, MPI_Group  *group)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Comm_group\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm, MPI_Group group )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, MPI_Group group= %d, )\n", *comm, group);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Comm_group(  * comm, group);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Comm_group");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Comm_group, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Comm_group */



extern int MPI_Comm_group ( MPI_Comm comm, MPI_Group *group )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Comm_group( &jbuf,  & comm, group );

return rc;
} /* MPI_Comm_group */


extern void F77_MPI_COMM_GROUP(MPI_Fint  * comm, MPI_Fint  *group , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;
MPI_Group c_group;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Comm_group( &jbuf, &c_comm, &c_group );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*group = MPI_Group_c2f(c_group);
}
return;
} /* mpi_comm_group */



/* --------------- MPI_Comm_remote_group --------------- */

static int mpiPif_MPI_Comm_remote_group( jmp_buf * base_jbuf, MPI_Comm  * comm, MPI_Group  *group)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Comm_remote_group\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm, MPI_Group group )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, MPI_Group group= %d, )\n", *comm, group);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Comm_remote_group(  * comm, group);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Comm_remote_group");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Comm_remote_group, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Comm_remote_group */



extern int MPI_Comm_remote_group ( MPI_Comm comm, MPI_Group *group )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Comm_remote_group( &jbuf,  & comm, group );

return rc;
} /* MPI_Comm_remote_group */


extern void F77_MPI_COMM_REMOTE_GROUP(MPI_Fint  * comm, MPI_Fint  *group , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;
MPI_Group c_group;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Comm_remote_group( &jbuf, &c_comm, &c_group );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*group = MPI_Group_c2f(c_group);
}
return;
} /* mpi_comm_remote_group */



/* --------------- MPI_Comm_remote_size --------------- */

static int mpiPif_MPI_Comm_remote_size( jmp_buf * base_jbuf, MPI_Comm  * comm, int  *size)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Comm_remote_size\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm, int size )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, int size= %d, )\n", *comm, size);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Comm_remote_size(  * comm, size);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Comm_remote_size");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Comm_remote_size, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Comm_remote_size */



extern int MPI_Comm_remote_size ( MPI_Comm comm, int *size )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Comm_remote_size( &jbuf,  & comm, size );

return rc;
} /* MPI_Comm_remote_size */


extern void F77_MPI_COMM_REMOTE_SIZE(MPI_Fint  * comm, int  *size , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Comm_remote_size( &jbuf, &c_comm, size );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_comm_remote_size */



/* --------------- MPI_Comm_set_attr --------------- */

static int mpiPif_MPI_Comm_set_attr( jmp_buf * base_jbuf, MPI_Comm  * comm, int  * comm_keyval, void  *attribute_value)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Comm_set_attr\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm, int* comm_keyval, void attribute_value )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, int comm_keyval= %d, void attribute_value= %d, )\n", *comm, *comm_keyval, attribute_value);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Comm_set_attr(  * comm,  * comm_keyval, attribute_value);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Comm_set_attr");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Comm_set_attr, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Comm_set_attr */



extern int MPI_Comm_set_attr ( MPI_Comm comm, int comm_keyval, void *attribute_value )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Comm_set_attr( &jbuf,  & comm,  & comm_keyval, attribute_value );

return rc;
} /* MPI_Comm_set_attr */


extern void F77_MPI_COMM_SET_ATTR(MPI_Fint  * comm, int  * comm_keyval, void  *attribute_value , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Comm_set_attr( &jbuf, &c_comm, comm_keyval, attribute_value );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_comm_set_attr */



/* --------------- MPI_Comm_split --------------- */

static int mpiPif_MPI_Comm_split( jmp_buf * base_jbuf, MPI_Comm  * comm, int  * color, int  * key, MPI_Comm  *comm_out)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Comm_split\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm, int* color, int* key, MPI_Comm comm_out )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, int color= %d, int key= %d, MPI_Comm comm_out= %d, )\n", *comm, *color, *key, comm_out);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Comm_split(  * comm,  * color,  * key, comm_out);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Comm_split");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Comm_split, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Comm_split */



extern int MPI_Comm_split ( MPI_Comm comm, int color, int key, MPI_Comm *comm_out )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Comm_split( &jbuf,  & comm,  & color,  & key, comm_out );

return rc;
} /* MPI_Comm_split */


extern void F77_MPI_COMM_SPLIT(MPI_Fint  * comm, int  * color, int  * key, MPI_Fint  *comm_out , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;
MPI_Comm c_comm_out;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Comm_split( &jbuf, &c_comm, color, key, &c_comm_out );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*comm_out = MPI_Comm_c2f(c_comm_out);
}
return;
} /* mpi_comm_split */



/* --------------- MPI_Comm_test_inter --------------- */

static int mpiPif_MPI_Comm_test_inter( jmp_buf * base_jbuf, MPI_Comm  * comm, int  *flag)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Comm_test_inter\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm, int flag )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, int flag= %d, )\n", *comm, flag);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Comm_test_inter(  * comm, flag);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Comm_test_inter");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Comm_test_inter, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Comm_test_inter */



extern int MPI_Comm_test_inter ( MPI_Comm comm, int *flag )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Comm_test_inter( &jbuf,  & comm, flag );

return rc;
} /* MPI_Comm_test_inter */


extern void F77_MPI_COMM_TEST_INTER(MPI_Fint  * comm, int  *flag , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Comm_test_inter( &jbuf, &c_comm, flag );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_comm_test_inter */



/* --------------- MPI_Compare_and_swap --------------- */

static int mpiPif_MPI_Compare_and_swap( jmp_buf * base_jbuf, mpip_const_void_t  *origin_addr, mpip_const_void_t  *compare_addr, void  *result_addr, MPI_Datatype  * datatype, int  * target_rank, MPI_Aint  * target_disp, MPI_Win  * win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Compare_and_swap\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t origin_addr, mpip_const_void_t compare_addr, void result_addr, MPI_Datatype* datatype, int* target_rank, MPI_Aint* target_disp, MPI_Win* win )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t origin_addr= %d, mpip_const_void_t compare_addr= %d, void result_addr= %d, MPI_Datatype datatype= %d, int target_rank= %d, MPI_Aint target_disp= %d, MPI_Win win= %d, )\n", origin_addr, compare_addr, result_addr, DT_size, *target_rank, *target_disp, *win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Compare_and_swap( origin_addr, compare_addr, result_addr,  * datatype,  * target_rank,  * target_disp,  * win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Compare_and_swap");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Compare_and_swap, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Compare_and_swap */



extern int MPI_Compare_and_swap ( mpip_const_void_t *origin_addr, mpip_const_void_t *compare_addr, void *result_addr, MPI_Datatype datatype, int target_rank, MPI_Aint target_disp, MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Compare_and_swap( &jbuf, origin_addr, compare_addr, result_addr,  & datatype,  & target_rank,  & target_disp,  & win );

return rc;
} /* MPI_Compare_and_swap */


extern void F77_MPI_COMPARE_AND_SWAP(mpip_const_void_t  *origin_addr, mpip_const_void_t  *compare_addr, void  *result_addr, MPI_Fint  * datatype, int  * target_rank, MPI_Aint  * target_disp, MPI_Win  * win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;

c_datatype = MPI_Type_f2c(*datatype);

rc = mpiPif_MPI_Compare_and_swap( &jbuf, origin_addr, compare_addr, result_addr, &c_datatype, target_rank, target_disp, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_compare_and_swap */



/* --------------- MPI_Dims_create --------------- */

static int mpiPif_MPI_Dims_create( jmp_buf * base_jbuf, int  * nnodes, int  * ndims, int  *dims)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Dims_create\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( int* nnodes, int* ndims, int dims )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (int nnodes= %d, int ndims= %d, int dims= %d, )\n", *nnodes, *ndims, dims);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Dims_create(  * nnodes,  * ndims, dims);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Dims_create");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Dims_create, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Dims_create */



extern int MPI_Dims_create ( int nnodes, int ndims, int *dims )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Dims_create( &jbuf,  & nnodes,  & ndims, dims );

return rc;
} /* MPI_Dims_create */


extern void F77_MPI_DIMS_CREATE(int  * nnodes, int  * ndims, int  *dims , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Dims_create( &jbuf, nnodes, ndims, dims );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_dims_create */



/* --------------- MPI_Error_class --------------- */

static int mpiPif_MPI_Error_class( jmp_buf * base_jbuf, int  * errorcode, int  *errorclass)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Error_class\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( int* errorcode, int errorclass )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (int errorcode= %d, int errorclass= %d, )\n", *errorcode, errorclass);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Error_class(  * errorcode, errorclass);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Error_class");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Error_class, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Error_class */



extern int MPI_Error_class ( int errorcode, int *errorclass )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Error_class( &jbuf,  & errorcode, errorclass );

return rc;
} /* MPI_Error_class */


extern void F77_MPI_ERROR_CLASS(int  * errorcode, int  *errorclass , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Error_class( &jbuf, errorcode, errorclass );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_error_class */



/* --------------- MPI_Fetch_and_op --------------- */

static int mpiPif_MPI_Fetch_and_op( jmp_buf * base_jbuf, mpip_const_void_t  *origin_addr, void  *result_addr, MPI_Datatype  * datatype, int  * target_rank, MPI_Aint  * target_disp, MPI_Op  * op, MPI_Win  * win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Fetch_and_op\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t origin_addr, void result_addr, MPI_Datatype* datatype, int* target_rank, MPI_Aint* target_disp, MPI_Op* op, MPI_Win* win )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t origin_addr= %d, void result_addr= %d, MPI_Datatype datatype= %d, int target_rank= %d, MPI_Aint target_disp= %d, MPI_Op op= %d, MPI_Win win= %d, )\n", origin_addr, result_addr, DT_size, *target_rank, *target_disp, *op, *win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Fetch_and_op( origin_addr, result_addr,  * datatype,  * target_rank,  * target_disp,  * op,  * win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Fetch_and_op");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Fetch_and_op, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Fetch_and_op */



extern int MPI_Fetch_and_op ( mpip_const_void_t *origin_addr, void *result_addr, MPI_Datatype datatype, int target_rank, MPI_Aint target_disp, MPI_Op op, MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Fetch_and_op( &jbuf, origin_addr, result_addr,  & datatype,  & target_rank,  & target_disp,  & op,  & win );

return rc;
} /* MPI_Fetch_and_op */


extern void F77_MPI_FETCH_AND_OP(mpip_const_void_t  *origin_addr, void  *result_addr, MPI_Fint  * datatype, int  * target_rank, MPI_Aint  * target_disp, MPI_Fint  * op, MPI_Win  * win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Op c_op;

c_datatype = MPI_Type_f2c(*datatype);
c_op = MPI_Op_f2c(*op);

rc = mpiPif_MPI_Fetch_and_op( &jbuf, origin_addr, result_addr, &c_datatype, target_rank, target_disp, &c_op, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_fetch_and_op */



/* --------------- MPI_File_close --------------- */

static int mpiPif_MPI_File_close( jmp_buf * base_jbuf, MPI_File  *fh)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_File_close\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_File fh )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_File fh= %d, )\n", fh);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_File_close( fh);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_close");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_File_close, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_close */



extern int MPI_File_close (MPI_File *fh)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_close( &jbuf, fh );

return rc;
} /* MPI_File_close */


extern void F77_MPI_FILE_CLOSE(MPI_Fint  *fh , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_File c_fh;

c_fh = MPI_File_f2c(*fh);

rc = mpiPif_MPI_File_close( &jbuf, &c_fh );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*fh = MPI_File_c2f(c_fh);
}
return;
} /* mpi_file_close */



/* --------------- MPI_File_delete --------------- */

static int mpiPif_MPI_File_delete( jmp_buf * base_jbuf, mpip_const_char_t  *filename, MPI_Info  * info)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_File_delete\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_char_t filename, MPI_Info* info )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_char_t filename= %d, MPI_Info info= %d, )\n", filename, *info);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_File_delete( filename,  * info);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_delete");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_File_delete, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_delete */



extern int MPI_File_delete (mpip_const_char_t *filename, MPI_Info info)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_delete( &jbuf, filename,  & info );

return rc;
} /* MPI_File_delete */


extern void F77_MPI_FILE_DELETE(mpip_const_char_t  *filename, MPI_Fint  * info , MPI_Fint *ierr , int filename_len) {
int rc;
jmp_buf jbuf;
  char *c_filename = NULL;
MPI_Info c_info;

  for(; filename_len > 0; filename_len--){
    if( filename[filename_len] != ' '){
      filename_len++; // The length is last symbol index + 1
      break;
    }
  }
  c_filename = calloc( filename_len + 1, sizeof(char));
  memcpy( c_filename, filename, filename_len);
c_info = MPI_Info_f2c(*info);

rc = mpiPif_MPI_File_delete( &jbuf, c_filename, &c_info );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_delete */



/* --------------- MPI_File_get_amode --------------- */

static int mpiPif_MPI_File_get_amode( jmp_buf * base_jbuf, MPI_File  * fh, int  *amode)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_File_get_amode\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_File* fh, int amode )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_File fh= %d, int amode= %d, )\n", *fh, amode);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_File_get_amode(  * fh, amode);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_get_amode");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_File_get_amode, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_get_amode */



extern int MPI_File_get_amode (MPI_File fh, int *amode)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_get_amode( &jbuf,  & fh, amode );

return rc;
} /* MPI_File_get_amode */


extern void F77_MPI_FILE_GET_AMODE(MPI_Fint  * fh, int  *amode , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_File c_fh;

c_fh = MPI_File_f2c(*fh);

rc = mpiPif_MPI_File_get_amode( &jbuf, &c_fh, amode );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_get_amode */



/* --------------- MPI_File_get_byte_offset --------------- */

static int mpiPif_MPI_File_get_byte_offset( jmp_buf * base_jbuf, MPI_File  * fh, MPI_Offset  * offset, MPI_Offset  *disp)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_File_get_byte_offset\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_File* fh, MPI_Offset* offset, MPI_Offset disp )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_File fh= %d, MPI_Offset offset= %d, MPI_Offset disp= %d, )\n", *fh, *offset, disp);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_File_get_byte_offset(  * fh,  * offset, disp);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_get_byte_offset");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_File_get_byte_offset, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_get_byte_offset */



extern int MPI_File_get_byte_offset (MPI_File fh, MPI_Offset offset, MPI_Offset *disp)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_get_byte_offset( &jbuf,  & fh,  & offset, disp );

return rc;
} /* MPI_File_get_byte_offset */


extern void F77_MPI_FILE_GET_BYTE_OFFSET(MPI_Fint  * fh, MPI_Offset  * offset, MPI_Offset  *disp , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_File c_fh;

c_fh = MPI_File_f2c(*fh);

rc = mpiPif_MPI_File_get_byte_offset( &jbuf, &c_fh, offset, disp );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_get_byte_offset */



/* --------------- MPI_File_get_group --------------- */

static int mpiPif_MPI_File_get_group( jmp_buf * base_jbuf, MPI_File  * fh, MPI_Group  *group)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_File_get_group\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_File* fh, MPI_Group group )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_File fh= %d, MPI_Group group= %d, )\n", *fh, group);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_File_get_group(  * fh, group);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_get_group");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_File_get_group, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_get_group */



extern int MPI_File_get_group (MPI_File fh, MPI_Group *group)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_get_group( &jbuf,  & fh, group );

return rc;
} /* MPI_File_get_group */


extern void F77_MPI_FILE_GET_GROUP(MPI_Fint  * fh, MPI_Fint  *group , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_File c_fh;
MPI_Group c_group;

c_fh = MPI_File_f2c(*fh);

rc = mpiPif_MPI_File_get_group( &jbuf, &c_fh, &c_group );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*group = MPI_Group_c2f(c_group);
}
return;
} /* mpi_file_get_group */



/* --------------- MPI_File_get_info --------------- */

static int mpiPif_MPI_File_get_info( jmp_buf * base_jbuf, MPI_File  * fh, MPI_Info  *info)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_File_get_info\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_File* fh, MPI_Info info )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_File fh= %d, MPI_Info info= %d, )\n", *fh, info);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_File_get_info(  * fh, info);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_get_info");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_File_get_info, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_get_info */



extern int MPI_File_get_info (MPI_File fh, MPI_Info *info)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_get_info( &jbuf,  & fh, info );

return rc;
} /* MPI_File_get_info */


extern void F77_MPI_FILE_GET_INFO(MPI_Fint  * fh, MPI_Fint  *info , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_File c_fh;
MPI_Info c_info;

c_fh = MPI_File_f2c(*fh);

rc = mpiPif_MPI_File_get_info( &jbuf, &c_fh, &c_info );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*info = MPI_Info_c2f(c_info);
}
return;
} /* mpi_file_get_info */



/* --------------- MPI_File_get_position --------------- */

static int mpiPif_MPI_File_get_position( jmp_buf * base_jbuf, MPI_File  * fh, MPI_Offset  *offset)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_File_get_position\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_File* fh, MPI_Offset offset )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_File fh= %d, MPI_Offset offset= %d, )\n", *fh, offset);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_File_get_position(  * fh, offset);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_get_position");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_File_get_position, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_get_position */



extern int MPI_File_get_position (MPI_File fh, MPI_Offset *offset)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_get_position( &jbuf,  & fh, offset );

return rc;
} /* MPI_File_get_position */


extern void F77_MPI_FILE_GET_POSITION(MPI_Fint  * fh, MPI_Offset  *offset , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_File c_fh;

c_fh = MPI_File_f2c(*fh);

rc = mpiPif_MPI_File_get_position( &jbuf, &c_fh, offset );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_get_position */



/* --------------- MPI_File_get_size --------------- */

static int mpiPif_MPI_File_get_size( jmp_buf * base_jbuf, MPI_File  * fh, MPI_Offset  *size)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_File_get_size\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_File* fh, MPI_Offset size )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_File fh= %d, MPI_Offset size= %d, )\n", *fh, size);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_File_get_size(  * fh, size);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_get_size");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_File_get_size, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_get_size */



extern int MPI_File_get_size (MPI_File fh, MPI_Offset *size)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_get_size( &jbuf,  & fh, size );

return rc;
} /* MPI_File_get_size */


extern void F77_MPI_FILE_GET_SIZE(MPI_Fint  * fh, MPI_Offset  *size , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_File c_fh;

c_fh = MPI_File_f2c(*fh);

rc = mpiPif_MPI_File_get_size( &jbuf, &c_fh, size );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_get_size */



/* --------------- MPI_File_get_view --------------- */

static int mpiPif_MPI_File_get_view( jmp_buf * base_jbuf, MPI_File  * fh, MPI_Offset  *disp, MPI_Datatype  *etype, MPI_Datatype  *filetype, char  *datarep)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_File_get_view\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_File* fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype, char datarep )\n");
MPI_Type_size(*etype, &DT_size);
MPI_Type_size(*filetype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_File fh= %d, MPI_Offset disp= %d, MPI_Datatype etype= %d, MPI_Datatype filetype= %d, char datarep= %d, )\n", *fh, disp, DT_size, DT_size, datarep);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_File_get_view(  * fh, disp, etype, filetype, datarep);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_get_view");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_File_get_view, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_get_view */



extern int MPI_File_get_view (MPI_File fh, MPI_Offset *disp, MPI_Datatype *etype, MPI_Datatype *filetype, char *datarep)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_get_view( &jbuf,  & fh, disp, etype, filetype, datarep );

return rc;
} /* MPI_File_get_view */


extern void F77_MPI_FILE_GET_VIEW(MPI_Fint  * fh, MPI_Offset  *disp, MPI_Fint  *etype, MPI_Fint  *filetype, char  *datarep , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_File c_fh;
MPI_Datatype c_etype;
MPI_Datatype c_filetype;

c_fh = MPI_File_f2c(*fh);

rc = mpiPif_MPI_File_get_view( &jbuf, &c_fh, disp, &c_etype, &c_filetype, datarep );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_get_view */



/* --------------- MPI_File_open --------------- */

static int mpiPif_MPI_File_open( jmp_buf * base_jbuf, MPI_Comm  * comm, mpip_const_char_t  *filename, int  * amode, MPI_Info  * info, MPI_File  *fh)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_File_open\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm, mpip_const_char_t filename, int* amode, MPI_Info* info, MPI_File fh )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, mpip_const_char_t filename= %d, int amode= %d, MPI_Info info= %d, MPI_File fh= %d, )\n", *comm, filename, *amode, *info, fh);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_File_open(  * comm, filename,  * amode,  * info, fh);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_open");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_File_open, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_open */



extern int MPI_File_open (MPI_Comm comm, mpip_const_char_t *filename, int amode, MPI_Info info, MPI_File *fh)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_open( &jbuf,  & comm, filename,  & amode,  & info, fh );

return rc;
} /* MPI_File_open */


extern void F77_MPI_FILE_OPEN(MPI_Fint  * comm, mpip_const_char_t  *filename, int  * amode, MPI_Fint  * info, MPI_Fint  *fh , MPI_Fint *ierr , int filename_len) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;
  char *c_filename = NULL;
MPI_Info c_info;
MPI_File c_fh;

  for(; filename_len > 0; filename_len--){
    if( filename[filename_len] != ' '){
      filename_len++; // The length is last symbol index + 1
      break;
    }
  }
  c_filename = calloc( filename_len + 1, sizeof(char));
  memcpy( c_filename, filename, filename_len);
c_comm = MPI_Comm_f2c(*comm);
c_info = MPI_Info_f2c(*info);

rc = mpiPif_MPI_File_open( &jbuf, &c_comm, c_filename, amode, &c_info, &c_fh );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*fh = MPI_File_c2f(c_fh);
}
return;
} /* mpi_file_open */



/* --------------- MPI_File_preallocate --------------- */

static int mpiPif_MPI_File_preallocate( jmp_buf * base_jbuf, MPI_File  * fh, MPI_Offset  * size)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_File_preallocate\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_File* fh, MPI_Offset* size )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_File fh= %d, MPI_Offset size= %d, )\n", *fh, *size);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_File_preallocate(  * fh,  * size);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_preallocate");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_File_preallocate, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_preallocate */



extern int MPI_File_preallocate (MPI_File fh, MPI_Offset size)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_preallocate( &jbuf,  & fh,  & size );

return rc;
} /* MPI_File_preallocate */


extern void F77_MPI_FILE_PREALLOCATE(MPI_Fint  * fh, MPI_Offset  * size , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_File c_fh;

c_fh = MPI_File_f2c(*fh);

rc = mpiPif_MPI_File_preallocate( &jbuf, &c_fh, size );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_preallocate */



/* --------------- MPI_File_read --------------- */

static int mpiPif_MPI_File_read( jmp_buf * base_jbuf, MPI_File  * fh, void  *buf, int  * count, MPI_Datatype  * datatype, MPI_Status  *status)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_File_read\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_File* fh, void buf, int* count, MPI_Datatype* datatype, MPI_Status status )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_File fh= %d, void buf= %d, int count= %d, MPI_Datatype datatype= %d, MPI_Status status= %d, )\n", *fh, buf, *count, DT_size, status);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_File_read(  * fh, buf,  * count,  * datatype, status);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

PMPI_Type_size(*datatype, &tsize);
ioSize = (double)(tsize * *count);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_read");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_File_read, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_read */



extern int MPI_File_read (MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_read( &jbuf,  & fh, buf,  & count,  & datatype, status );

return rc;
} /* MPI_File_read */


extern void F77_MPI_FILE_READ(MPI_Fint  * fh, void  *buf, int  * count, MPI_Fint  * datatype, MPI_Status  *status , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_File c_fh;
MPI_Datatype c_datatype;

c_fh = MPI_File_f2c(*fh);
c_datatype = MPI_Type_f2c(*datatype);

rc = mpiPif_MPI_File_read( &jbuf, &c_fh, buf, count, &c_datatype, status );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_read */



/* --------------- MPI_File_read_all --------------- */

static int mpiPif_MPI_File_read_all( jmp_buf * base_jbuf, MPI_File  * fh, void  *buf, int  * count, MPI_Datatype  * datatype, MPI_Status  *status)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_File_read_all\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_File* fh, void buf, int* count, MPI_Datatype* datatype, MPI_Status status )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_File fh= %d, void buf= %d, int count= %d, MPI_Datatype datatype= %d, MPI_Status status= %d, )\n", *fh, buf, *count, DT_size, status);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_File_read_all(  * fh, buf,  * count,  * datatype, status);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

PMPI_Type_size(*datatype, &tsize);
ioSize = (double)(tsize * *count);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_read_all");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_File_read_all, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_read_all */



extern int MPI_File_read_all (MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_read_all( &jbuf,  & fh, buf,  & count,  & datatype, status );

return rc;
} /* MPI_File_read_all */


extern void F77_MPI_FILE_READ_ALL(MPI_Fint  * fh, void  *buf, int  * count, MPI_Fint  * datatype, MPI_Status  *status , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_File c_fh;
MPI_Datatype c_datatype;

c_fh = MPI_File_f2c(*fh);
c_datatype = MPI_Type_f2c(*datatype);

rc = mpiPif_MPI_File_read_all( &jbuf, &c_fh, buf, count, &c_datatype, status );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_read_all */



/* --------------- MPI_File_read_at --------------- */

static int mpiPif_MPI_File_read_at( jmp_buf * base_jbuf, MPI_File  * fh, MPI_Offset  * offset, void  *buf, int  * count, MPI_Datatype  * datatype, MPI_Status  *status)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_File_read_at\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_File* fh, MPI_Offset* offset, void buf, int* count, MPI_Datatype* datatype, MPI_Status status )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_File fh= %d, MPI_Offset offset= %d, void buf= %d, int count= %d, MPI_Datatype datatype= %d, MPI_Status status= %d, )\n", *fh, *offset, buf, *count, DT_size, status);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_File_read_at(  * fh,  * offset, buf,  * count,  * datatype, status);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

PMPI_Type_size(*datatype, &tsize);
ioSize = (double)(tsize * *count);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_read_at");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_File_read_at, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_read_at */



extern int MPI_File_read_at (MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_read_at( &jbuf,  & fh,  & offset, buf,  & count,  & datatype, status );

return rc;
} /* MPI_File_read_at */


extern void F77_MPI_FILE_READ_AT(MPI_Fint  * fh, MPI_Offset  * offset, void  *buf, int  * count, MPI_Fint  * datatype, MPI_Status  *status , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_File c_fh;
MPI_Datatype c_datatype;

c_fh = MPI_File_f2c(*fh);
c_datatype = MPI_Type_f2c(*datatype);

rc = mpiPif_MPI_File_read_at( &jbuf, &c_fh, offset, buf, count, &c_datatype, status );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_read_at */



/* --------------- MPI_File_read_at_all --------------- */

static int mpiPif_MPI_File_read_at_all( jmp_buf * base_jbuf, MPI_File  * fh, MPI_Offset  * offset, void  *buf, int  * count, MPI_Datatype  * datatype, MPI_Status  *status)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_File_read_at_all\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_File* fh, MPI_Offset* offset, void buf, int* count, MPI_Datatype* datatype, MPI_Status status )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_File fh= %d, MPI_Offset offset= %d, void buf= %d, int count= %d, MPI_Datatype datatype= %d, MPI_Status status= %d, )\n", *fh, *offset, buf, *count, DT_size, status);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_File_read_at_all(  * fh,  * offset, buf,  * count,  * datatype, status);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_read_at_all");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_File_read_at_all, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_read_at_all */



extern int MPI_File_read_at_all (MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_read_at_all( &jbuf,  & fh,  & offset, buf,  & count,  & datatype, status );

return rc;
} /* MPI_File_read_at_all */


extern void F77_MPI_FILE_READ_AT_ALL(MPI_Fint  * fh, MPI_Offset  * offset, void  *buf, int  * count, MPI_Fint  * datatype, MPI_Status  *status , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_File c_fh;
MPI_Datatype c_datatype;

c_fh = MPI_File_f2c(*fh);
c_datatype = MPI_Type_f2c(*datatype);

rc = mpiPif_MPI_File_read_at_all( &jbuf, &c_fh, offset, buf, count, &c_datatype, status );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_read_at_all */



/* --------------- MPI_File_seek --------------- */

static int mpiPif_MPI_File_seek( jmp_buf * base_jbuf, MPI_File  * fh, MPI_Offset  * offset, int  * whence)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_File_seek\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_File* fh, MPI_Offset* offset, int* whence )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_File fh= %d, MPI_Offset offset= %d, int whence= %d, )\n", *fh, *offset, *whence);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_File_seek(  * fh,  * offset,  * whence);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_seek");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_File_seek, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_seek */



extern int MPI_File_seek (MPI_File fh, MPI_Offset offset, int whence)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_seek( &jbuf,  & fh,  & offset,  & whence );

return rc;
} /* MPI_File_seek */


extern void F77_MPI_FILE_SEEK(MPI_Fint  * fh, MPI_Offset  * offset, int  * whence , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_File c_fh;

c_fh = MPI_File_f2c(*fh);

rc = mpiPif_MPI_File_seek( &jbuf, &c_fh, offset, whence );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_seek */



/* --------------- MPI_File_set_info --------------- */

static int mpiPif_MPI_File_set_info( jmp_buf * base_jbuf, MPI_File  * fh, MPI_Info  * info)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_File_set_info\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_File* fh, MPI_Info* info )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_File fh= %d, MPI_Info info= %d, )\n", *fh, *info);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_File_set_info(  * fh,  * info);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_set_info");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_File_set_info, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_set_info */



extern int MPI_File_set_info (MPI_File fh, MPI_Info info)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_set_info( &jbuf,  & fh,  & info );

return rc;
} /* MPI_File_set_info */


extern void F77_MPI_FILE_SET_INFO(MPI_Fint  * fh, MPI_Fint  * info , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_File c_fh;
MPI_Info c_info;

c_fh = MPI_File_f2c(*fh);
c_info = MPI_Info_f2c(*info);

rc = mpiPif_MPI_File_set_info( &jbuf, &c_fh, &c_info );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_set_info */



/* --------------- MPI_File_set_size --------------- */

static int mpiPif_MPI_File_set_size( jmp_buf * base_jbuf, MPI_File  * fh, MPI_Offset  * size)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_File_set_size\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_File* fh, MPI_Offset* size )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_File fh= %d, MPI_Offset size= %d, )\n", *fh, *size);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_File_set_size(  * fh,  * size);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_set_size");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_File_set_size, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_set_size */



extern int MPI_File_set_size (MPI_File fh, MPI_Offset size)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_set_size( &jbuf,  & fh,  & size );

return rc;
} /* MPI_File_set_size */


extern void F77_MPI_FILE_SET_SIZE(MPI_Fint  * fh, MPI_Offset  * size , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_File c_fh;

c_fh = MPI_File_f2c(*fh);

rc = mpiPif_MPI_File_set_size( &jbuf, &c_fh, size );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_set_size */



/* --------------- MPI_File_set_view --------------- */

static int mpiPif_MPI_File_set_view( jmp_buf * base_jbuf, MPI_File  * fh, MPI_Offset  * disp, MPI_Datatype  * etype, MPI_Datatype  * filetype, mpip_const_char_t  *datarep, MPI_Info  * info)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_File_set_view\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_File* fh, MPI_Offset* disp, MPI_Datatype* etype, MPI_Datatype* filetype, mpip_const_char_t datarep, MPI_Info* info )\n");
MPI_Type_size(*etype, &DT_size);
MPI_Type_size(*filetype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_File fh= %d, MPI_Offset disp= %d, MPI_Datatype etype= %d, MPI_Datatype filetype= %d, mpip_const_char_t datarep= %d, MPI_Info info= %d, )\n", *fh, *disp, DT_size, DT_size, datarep, *info);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_File_set_view(  * fh,  * disp,  * etype,  * filetype, datarep,  * info);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_set_view");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_File_set_view, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_set_view */



extern int MPI_File_set_view (MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype, mpip_const_char_t *datarep, MPI_Info info)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_set_view( &jbuf,  & fh,  & disp,  & etype,  & filetype, datarep,  & info );

return rc;
} /* MPI_File_set_view */


extern void F77_MPI_FILE_SET_VIEW(MPI_Fint  * fh, MPI_Offset  * disp, MPI_Fint  * etype, MPI_Fint  * filetype, mpip_const_char_t  *datarep, MPI_Fint  * info , MPI_Fint *ierr , int datarep_len) {
int rc;
jmp_buf jbuf;
MPI_File c_fh;
MPI_Datatype c_etype;
MPI_Datatype c_filetype;
  char *c_datarep = NULL;
MPI_Info c_info;

  for(; datarep_len > 0; datarep_len--){
    if( datarep[datarep_len] != ' '){
      datarep_len++; // The length is last symbol index + 1
      break;
    }
  }
  c_datarep = calloc( datarep_len + 1, sizeof(char));
  memcpy( c_datarep, datarep, datarep_len);
c_fh = MPI_File_f2c(*fh);
c_etype = MPI_Type_f2c(*etype);
c_filetype = MPI_Type_f2c(*filetype);
c_info = MPI_Info_f2c(*info);

rc = mpiPif_MPI_File_set_view( &jbuf, &c_fh, disp, &c_etype, &c_filetype, c_datarep, &c_info );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_set_view */



/* --------------- MPI_File_sync --------------- */

static int mpiPif_MPI_File_sync( jmp_buf * base_jbuf, MPI_File  * fh)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_File_sync\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_File* fh )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_File fh= %d, )\n", *fh);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_File_sync(  * fh);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_sync");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_File_sync, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_sync */



extern int MPI_File_sync (MPI_File fh)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_sync( &jbuf,  & fh );

return rc;
} /* MPI_File_sync */


extern void F77_MPI_FILE_SYNC(MPI_Fint  * fh , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_File c_fh;

c_fh = MPI_File_f2c(*fh);

rc = mpiPif_MPI_File_sync( &jbuf, &c_fh );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_sync */



/* --------------- MPI_File_write --------------- */

static int mpiPif_MPI_File_write( jmp_buf * base_jbuf, MPI_File  * fh, mpip_const_void_t  *buf, int  * count, MPI_Datatype  * datatype, MPI_Status  *status)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_File_write\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_File* fh, mpip_const_void_t buf, int* count, MPI_Datatype* datatype, MPI_Status status )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_File fh= %d, mpip_const_void_t buf= %d, int count= %d, MPI_Datatype datatype= %d, MPI_Status status= %d, )\n", *fh, buf, *count, DT_size, status);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_File_write(  * fh, buf,  * count,  * datatype, status);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

PMPI_Type_size(*datatype, &tsize);
ioSize = (double)(tsize * *count);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_write");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_File_write, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_write */



extern int MPI_File_write (MPI_File fh, mpip_const_void_t *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_write( &jbuf,  & fh, buf,  & count,  & datatype, status );

return rc;
} /* MPI_File_write */


extern void F77_MPI_FILE_WRITE(MPI_Fint  * fh, mpip_const_void_t  *buf, int  * count, MPI_Fint  * datatype, MPI_Status  *status , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_File c_fh;
MPI_Datatype c_datatype;

c_fh = MPI_File_f2c(*fh);
c_datatype = MPI_Type_f2c(*datatype);

rc = mpiPif_MPI_File_write( &jbuf, &c_fh, buf, count, &c_datatype, status );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_write */



/* --------------- MPI_File_write_all --------------- */

static int mpiPif_MPI_File_write_all( jmp_buf * base_jbuf, MPI_File  * fh, mpip_const_void_t  *buf, int  * count, MPI_Datatype  * datatype, MPI_Status  *status)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_File_write_all\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_File* fh, mpip_const_void_t buf, int* count, MPI_Datatype* datatype, MPI_Status status )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_File fh= %d, mpip_const_void_t buf= %d, int count= %d, MPI_Datatype datatype= %d, MPI_Status status= %d, )\n", *fh, buf, *count, DT_size, status);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_File_write_all(  * fh, buf,  * count,  * datatype, status);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

PMPI_Type_size(*datatype, &tsize);
ioSize = (double)(tsize * *count);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_write_all");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_File_write_all, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_write_all */



extern int MPI_File_write_all (MPI_File fh, mpip_const_void_t *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_write_all( &jbuf,  & fh, buf,  & count,  & datatype, status );

return rc;
} /* MPI_File_write_all */


extern void F77_MPI_FILE_WRITE_ALL(MPI_Fint  * fh, mpip_const_void_t  *buf, int  * count, MPI_Fint  * datatype, MPI_Status  *status , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_File c_fh;
MPI_Datatype c_datatype;

c_fh = MPI_File_f2c(*fh);
c_datatype = MPI_Type_f2c(*datatype);

rc = mpiPif_MPI_File_write_all( &jbuf, &c_fh, buf, count, &c_datatype, status );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_write_all */



/* --------------- MPI_File_write_at --------------- */

static int mpiPif_MPI_File_write_at( jmp_buf * base_jbuf, MPI_File  * fh, MPI_Offset  * offset, mpip_const_void_t  *buf, int  * count, MPI_Datatype  * datatype, MPI_Status  *status)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_File_write_at\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_File* fh, MPI_Offset* offset, mpip_const_void_t buf, int* count, MPI_Datatype* datatype, MPI_Status status )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_File fh= %d, MPI_Offset offset= %d, mpip_const_void_t buf= %d, int count= %d, MPI_Datatype datatype= %d, MPI_Status status= %d, )\n", *fh, *offset, buf, *count, DT_size, status);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_File_write_at(  * fh,  * offset, buf,  * count,  * datatype, status);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

PMPI_Type_size(*datatype, &tsize);
ioSize = (double)(tsize * *count);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_write_at");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_File_write_at, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_write_at */



extern int MPI_File_write_at (MPI_File fh, MPI_Offset offset, mpip_const_void_t *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_write_at( &jbuf,  & fh,  & offset, buf,  & count,  & datatype, status );

return rc;
} /* MPI_File_write_at */


extern void F77_MPI_FILE_WRITE_AT(MPI_Fint  * fh, MPI_Offset  * offset, mpip_const_void_t  *buf, int  * count, MPI_Fint  * datatype, MPI_Status  *status , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_File c_fh;
MPI_Datatype c_datatype;

c_fh = MPI_File_f2c(*fh);
c_datatype = MPI_Type_f2c(*datatype);

rc = mpiPif_MPI_File_write_at( &jbuf, &c_fh, offset, buf, count, &c_datatype, status );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_write_at */



/* --------------- MPI_File_write_at_all --------------- */

static int mpiPif_MPI_File_write_at_all( jmp_buf * base_jbuf, MPI_File  * fh, MPI_Offset  * offset, mpip_const_void_t  *buf, int  * count, MPI_Datatype  * datatype, MPI_Status  *status)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_File_write_at_all\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_File* fh, MPI_Offset* offset, mpip_const_void_t buf, int* count, MPI_Datatype* datatype, MPI_Status status )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_File fh= %d, MPI_Offset offset= %d, mpip_const_void_t buf= %d, int count= %d, MPI_Datatype datatype= %d, MPI_Status status= %d, )\n", *fh, *offset, buf, *count, DT_size, status);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_File_write_at_all(  * fh,  * offset, buf,  * count,  * datatype, status);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_write_at_all");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_File_write_at_all, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_write_at_all */



extern int MPI_File_write_at_all (MPI_File fh, MPI_Offset offset, mpip_const_void_t *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_write_at_all( &jbuf,  & fh,  & offset, buf,  & count,  & datatype, status );

return rc;
} /* MPI_File_write_at_all */


extern void F77_MPI_FILE_WRITE_AT_ALL(MPI_Fint  * fh, MPI_Offset  * offset, mpip_const_void_t  *buf, int  * count, MPI_Fint  * datatype, MPI_Status  *status , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_File c_fh;
MPI_Datatype c_datatype;

c_fh = MPI_File_f2c(*fh);
c_datatype = MPI_Type_f2c(*datatype);

rc = mpiPif_MPI_File_write_at_all( &jbuf, &c_fh, offset, buf, count, &c_datatype, status );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_write_at_all */



/* --------------- MPI_Gather --------------- */

static int mpiPif_MPI_Gather( jmp_buf * base_jbuf, mpip_const_void_t  *sendbuf, int  * sendcnt, MPI_Datatype  * sendtype, void  *recvbuf, int  * recvcount, MPI_Datatype  * recvtype, int  * root, MPI_Comm  * comm)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Gather\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t sendbuf, int* sendcnt, MPI_Datatype* sendtype, void recvbuf, int* recvcount, MPI_Datatype* recvtype, int* root, MPI_Comm* comm )\n");
MPI_Type_size(*sendtype, &DT_size);
MPI_Type_size(*recvtype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t sendbuf= %d, int sendcnt= %d, MPI_Datatype sendtype= %d, void recvbuf= %d, int recvcount= %d, MPI_Datatype recvtype= %d, int root= %d, MPI_Comm comm= %d, )\n", sendbuf, *sendcnt, DT_size, recvbuf, *recvcount, DT_size, *root, *comm);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Gather( sendbuf,  * sendcnt,  * sendtype, recvbuf,  * recvcount,  * recvtype,  * root,  * comm);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *sendtype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*sendtype, &tsize);
messSize = (double)(tsize * *sendcnt);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Gather");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Gather, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Gather, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Gather */



extern int MPI_Gather ( mpip_const_void_t *sendbuf, int sendcnt, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Gather( &jbuf, sendbuf,  & sendcnt,  & sendtype, recvbuf,  & recvcount,  & recvtype,  & root,  & comm );

return rc;
} /* MPI_Gather */


extern void F77_MPI_GATHER(mpip_const_void_t  *sendbuf, int  * sendcnt, MPI_Fint  * sendtype, void  *recvbuf, int  * recvcount, MPI_Fint  * recvtype, int  * root, MPI_Fint  * comm , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Gather( &jbuf, sendbuf, sendcnt, &c_sendtype, recvbuf, recvcount, &c_recvtype, root, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_gather */



/* --------------- MPI_Gatherv --------------- */

static int mpiPif_MPI_Gatherv( jmp_buf * base_jbuf, mpip_const_void_t  *sendbuf, int  * sendcnt, MPI_Datatype  * sendtype, void  *recvbuf, mpip_const_int_t  *recvcnts, mpip_const_int_t  *displs, MPI_Datatype  * recvtype, int  * root, MPI_Comm  * comm)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Gatherv\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t sendbuf, int* sendcnt, MPI_Datatype* sendtype, void recvbuf, mpip_const_int_t recvcnts, mpip_const_int_t displs, MPI_Datatype* recvtype, int* root, MPI_Comm* comm )\n");
MPI_Type_size(*sendtype, &DT_size);
MPI_Type_size(*recvtype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t sendbuf= %d, int sendcnt= %d, MPI_Datatype sendtype= %d, void recvbuf= %d, mpip_const_int_t recvcnts= %d, mpip_const_int_t displs= %d, MPI_Datatype recvtype= %d, int root= %d, MPI_Comm comm= %d, )\n", sendbuf, *sendcnt, DT_size, recvbuf, recvcnts, displs, DT_size, *root, *comm);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Gatherv( sendbuf,  * sendcnt,  * sendtype, recvbuf, recvcnts, displs,  * recvtype,  * root,  * comm);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *sendtype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*sendtype, &tsize);
messSize = (double)(tsize * *sendcnt);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Gatherv");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Gatherv, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Gatherv, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Gatherv */



extern int MPI_Gatherv ( mpip_const_void_t *sendbuf, int sendcnt, MPI_Datatype sendtype, void *recvbuf, mpip_const_int_t *recvcnts, mpip_const_int_t *displs, MPI_Datatype recvtype, int root, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Gatherv( &jbuf, sendbuf,  & sendcnt,  & sendtype, recvbuf, recvcnts, displs,  & recvtype,  & root,  & comm );

return rc;
} /* MPI_Gatherv */


extern void F77_MPI_GATHERV(mpip_const_void_t  *sendbuf, int  * sendcnt, MPI_Fint  * sendtype, void  *recvbuf, mpip_const_int_t  *recvcnts, mpip_const_int_t  *displs, MPI_Fint  * recvtype, int  * root, MPI_Fint  * comm , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Gatherv( &jbuf, sendbuf, sendcnt, &c_sendtype, recvbuf, recvcnts, displs, &c_recvtype, root, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_gatherv */



/* --------------- MPI_Get --------------- */

static int mpiPif_MPI_Get( jmp_buf * base_jbuf, void  *origin_addr, int  * origin_count, MPI_Datatype  * origin_datatype, int  * target_rank, MPI_Aint  * target_disp, int  * target_count, MPI_Datatype  * target_datatype, MPI_Win  * win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Get\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( void origin_addr, int* origin_count, MPI_Datatype* origin_datatype, int* target_rank, MPI_Aint* target_disp, int* target_count, MPI_Datatype* target_datatype, MPI_Win* win )\n");
MPI_Type_size(*origin_datatype, &DT_size);
MPI_Type_size(*target_datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (void origin_addr= %d, int origin_count= %d, MPI_Datatype origin_datatype= %d, int target_rank= %d, MPI_Aint target_disp= %d, int target_count= %d, MPI_Datatype target_datatype= %d, MPI_Win win= %d, )\n", origin_addr, *origin_count, DT_size, *target_rank, *target_disp, *target_count, DT_size, *win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Get( origin_addr,  * origin_count,  * origin_datatype,  * target_rank,  * target_disp,  * target_count,  * target_datatype,  * win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Get");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Get, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Get */



extern int MPI_Get ( void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Get( &jbuf, origin_addr,  & origin_count,  & origin_datatype,  & target_rank,  & target_disp,  & target_count,  & target_datatype,  & win );

return rc;
} /* MPI_Get */


extern void F77_MPI_GET(void  *origin_addr, int  * origin_count, MPI_Fint  * origin_datatype, int  * target_rank, MPI_Aint  * target_disp, int  * target_count, MPI_Fint  * target_datatype, MPI_Win  * win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_origin_datatype;
MPI_Datatype c_target_datatype;

c_origin_datatype = MPI_Type_f2c(*origin_datatype);
c_target_datatype = MPI_Type_f2c(*target_datatype);

rc = mpiPif_MPI_Get( &jbuf, origin_addr, origin_count, &c_origin_datatype, target_rank, target_disp, target_count, &c_target_datatype, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_get */



/* --------------- MPI_Get_accumulate --------------- */

static int mpiPif_MPI_Get_accumulate( jmp_buf * base_jbuf, mpip_const_void_t  *origin_addr, int  * origin_count, MPI_Datatype  * origin_datatype, void  *result_addr, int  * result_count, MPI_Datatype  * result_datatype, int  * target_rank, MPI_Aint  * target_disp, int  * target_count, MPI_Datatype  * target_datatype, MPI_Op  * op, MPI_Win  * win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Get_accumulate\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t origin_addr, int* origin_count, MPI_Datatype* origin_datatype, void result_addr, int* result_count, MPI_Datatype* result_datatype, int* target_rank, MPI_Aint* target_disp, int* target_count, MPI_Datatype* target_datatype, MPI_Op* op, MPI_Win* win )\n");
MPI_Type_size(*origin_datatype, &DT_size);
MPI_Type_size(*result_datatype, &DT_size);
MPI_Type_size(*target_datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t origin_addr= %d, int origin_count= %d, MPI_Datatype origin_datatype= %d, void result_addr= %d, int result_count= %d, MPI_Datatype result_datatype= %d, int target_rank= %d, MPI_Aint target_disp= %d, int target_count= %d, MPI_Datatype target_datatype= %d, MPI_Op op= %d, MPI_Win win= %d, )\n", origin_addr, *origin_count, DT_size, result_addr, *result_count, DT_size, *target_rank, *target_disp, *target_count, DT_size, *op, *win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Get_accumulate( origin_addr,  * origin_count,  * origin_datatype, result_addr,  * result_count,  * result_datatype,  * target_rank,  * target_disp,  * target_count,  * target_datatype,  * op,  * win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

PMPI_Type_size(*target_datatype, &tsize);
rmaSize = (double)(tsize * *target_count);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Get_accumulate");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Get_accumulate, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Get_accumulate */



extern int MPI_Get_accumulate ( mpip_const_void_t *origin_addr, int origin_count, MPI_Datatype origin_datatype, void *result_addr, int result_count, MPI_Datatype result_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Get_accumulate( &jbuf, origin_addr,  & origin_count,  & origin_datatype, result_addr,  & result_count,  & result_datatype,  & target_rank,  & target_disp,  & target_count,  & target_datatype,  & op,  & win );

return rc;
} /* MPI_Get_accumulate */


extern void F77_MPI_GET_ACCUMULATE(mpip_const_void_t  *origin_addr, int  * origin_count, MPI_Fint  * origin_datatype, void  *result_addr, int  * result_count, MPI_Fint  * result_datatype, int  * target_rank, MPI_Aint  * target_disp, int  * target_count, MPI_Fint  * target_datatype, MPI_Fint  * op, MPI_Win  * win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_origin_datatype;
MPI_Datatype c_result_datatype;
MPI_Datatype c_target_datatype;
MPI_Op c_op;

c_origin_datatype = MPI_Type_f2c(*origin_datatype);
c_result_datatype = MPI_Type_f2c(*result_datatype);
c_target_datatype = MPI_Type_f2c(*target_datatype);
c_op = MPI_Op_f2c(*op);

rc = mpiPif_MPI_Get_accumulate( &jbuf, origin_addr, origin_count, &c_origin_datatype, result_addr, result_count, &c_result_datatype, target_rank, target_disp, target_count, &c_target_datatype, &c_op, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_get_accumulate */



/* --------------- MPI_Graph_create --------------- */

static int mpiPif_MPI_Graph_create( jmp_buf * base_jbuf, MPI_Comm  * comm_old, int  * nnodes, mpip_const_int_t  *index, mpip_const_int_t  *edges, int  * reorder, MPI_Comm  *comm_graph)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Graph_create\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm_old, int* nnodes, mpip_const_int_t index, mpip_const_int_t edges, int* reorder, MPI_Comm comm_graph )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm_old= %d, int nnodes= %d, mpip_const_int_t index= %d, mpip_const_int_t edges= %d, int reorder= %d, MPI_Comm comm_graph= %d, )\n", *comm_old, *nnodes, index, edges, *reorder, comm_graph);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Graph_create(  * comm_old,  * nnodes, index, edges,  * reorder, comm_graph);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Graph_create");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Graph_create, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Graph_create */



extern int MPI_Graph_create ( MPI_Comm comm_old, int nnodes, mpip_const_int_t *index, mpip_const_int_t *edges, int reorder, MPI_Comm *comm_graph )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Graph_create( &jbuf,  & comm_old,  & nnodes, index, edges,  & reorder, comm_graph );

return rc;
} /* MPI_Graph_create */


extern void F77_MPI_GRAPH_CREATE(MPI_Fint  * comm_old, int  * nnodes, mpip_const_int_t  *index, mpip_const_int_t  *edges, int  * reorder, MPI_Fint  *comm_graph , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm_old;
MPI_Comm c_comm_graph;

c_comm_old = MPI_Comm_f2c(*comm_old);

rc = mpiPif_MPI_Graph_create( &jbuf, &c_comm_old, nnodes, index, edges, reorder, &c_comm_graph );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*comm_graph = MPI_Comm_c2f(c_comm_graph);
}
return;
} /* mpi_graph_create */



/* --------------- MPI_Graph_get --------------- */

static int mpiPif_MPI_Graph_get( jmp_buf * base_jbuf, MPI_Comm  * comm, int  * maxindex, int  * maxedges, int  *index, int  *edges)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Graph_get\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm, int* maxindex, int* maxedges, int index, int edges )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, int maxindex= %d, int maxedges= %d, int index= %d, int edges= %d, )\n", *comm, *maxindex, *maxedges, index, edges);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Graph_get(  * comm,  * maxindex,  * maxedges, index, edges);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Graph_get");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Graph_get, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Graph_get */



extern int MPI_Graph_get ( MPI_Comm comm, int maxindex, int maxedges, int *index, int *edges )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Graph_get( &jbuf,  & comm,  & maxindex,  & maxedges, index, edges );

return rc;
} /* MPI_Graph_get */


extern void F77_MPI_GRAPH_GET(MPI_Fint  * comm, int  * maxindex, int  * maxedges, int  *index, int  *edges , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Graph_get( &jbuf, &c_comm, maxindex, maxedges, index, edges );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_graph_get */



/* --------------- MPI_Graph_map --------------- */

static int mpiPif_MPI_Graph_map( jmp_buf * base_jbuf, MPI_Comm  * comm_old, int  * nnodes, mpip_const_int_t  *index, mpip_const_int_t  *edges, int  *newrank)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Graph_map\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm_old, int* nnodes, mpip_const_int_t index, mpip_const_int_t edges, int newrank )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm_old= %d, int nnodes= %d, mpip_const_int_t index= %d, mpip_const_int_t edges= %d, int newrank= %d, )\n", *comm_old, *nnodes, index, edges, newrank);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Graph_map(  * comm_old,  * nnodes, index, edges, newrank);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Graph_map");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Graph_map, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Graph_map */



extern int MPI_Graph_map ( MPI_Comm comm_old, int nnodes, mpip_const_int_t *index, mpip_const_int_t *edges, int *newrank )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Graph_map( &jbuf,  & comm_old,  & nnodes, index, edges, newrank );

return rc;
} /* MPI_Graph_map */


extern void F77_MPI_GRAPH_MAP(MPI_Fint  * comm_old, int  * nnodes, mpip_const_int_t  *index, mpip_const_int_t  *edges, int  *newrank , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm_old;

c_comm_old = MPI_Comm_f2c(*comm_old);

rc = mpiPif_MPI_Graph_map( &jbuf, &c_comm_old, nnodes, index, edges, newrank );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_graph_map */



/* --------------- MPI_Graph_neighbors --------------- */

static int mpiPif_MPI_Graph_neighbors( jmp_buf * base_jbuf, MPI_Comm  * comm, int  * rank, int  * maxneighbors, int  *neighbors)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Graph_neighbors\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm, int* rank, int* maxneighbors, int neighbors )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, int rank= %d, int maxneighbors= %d, int neighbors= %d, )\n", *comm, *rank, *maxneighbors, neighbors);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Graph_neighbors(  * comm,  * rank,  * maxneighbors, neighbors);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Graph_neighbors");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Graph_neighbors, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Graph_neighbors */



extern int MPI_Graph_neighbors ( MPI_Comm comm, int rank, int maxneighbors, int *neighbors )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Graph_neighbors( &jbuf,  & comm,  & rank,  & maxneighbors, neighbors );

return rc;
} /* MPI_Graph_neighbors */


extern void F77_MPI_GRAPH_NEIGHBORS(MPI_Fint  * comm, int  * rank, int  * maxneighbors, int  *neighbors , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Graph_neighbors( &jbuf, &c_comm, rank, maxneighbors, neighbors );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_graph_neighbors */



/* --------------- MPI_Graph_neighbors_count --------------- */

static int mpiPif_MPI_Graph_neighbors_count( jmp_buf * base_jbuf, MPI_Comm  * comm, int  * rank, int  *nneighbors)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Graph_neighbors_count\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm, int* rank, int nneighbors )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, int rank= %d, int nneighbors= %d, )\n", *comm, *rank, nneighbors);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Graph_neighbors_count(  * comm,  * rank, nneighbors);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Graph_neighbors_count");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Graph_neighbors_count, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Graph_neighbors_count */



extern int MPI_Graph_neighbors_count ( MPI_Comm comm, int rank, int *nneighbors )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Graph_neighbors_count( &jbuf,  & comm,  & rank, nneighbors );

return rc;
} /* MPI_Graph_neighbors_count */


extern void F77_MPI_GRAPH_NEIGHBORS_COUNT(MPI_Fint  * comm, int  * rank, int  *nneighbors , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Graph_neighbors_count( &jbuf, &c_comm, rank, nneighbors );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_graph_neighbors_count */



/* --------------- MPI_Graphdims_get --------------- */

static int mpiPif_MPI_Graphdims_get( jmp_buf * base_jbuf, MPI_Comm  * comm, int  *nnodes, int  *nedges)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Graphdims_get\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm, int nnodes, int nedges )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, int nnodes= %d, int nedges= %d, )\n", *comm, nnodes, nedges);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Graphdims_get(  * comm, nnodes, nedges);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Graphdims_get");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Graphdims_get, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Graphdims_get */



extern int MPI_Graphdims_get ( MPI_Comm comm, int *nnodes, int *nedges )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Graphdims_get( &jbuf,  & comm, nnodes, nedges );

return rc;
} /* MPI_Graphdims_get */


extern void F77_MPI_GRAPHDIMS_GET(MPI_Fint  * comm, int  *nnodes, int  *nedges , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Graphdims_get( &jbuf, &c_comm, nnodes, nedges );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_graphdims_get */



/* --------------- MPI_Group_compare --------------- */

static int mpiPif_MPI_Group_compare( jmp_buf * base_jbuf, MPI_Group  * group1, MPI_Group  * group2, int  *result)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Group_compare\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Group* group1, MPI_Group* group2, int result )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Group group1= %d, MPI_Group group2= %d, int result= %d, )\n", *group1, *group2, result);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Group_compare(  * group1,  * group2, result);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Group_compare");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Group_compare, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Group_compare */



extern int MPI_Group_compare ( MPI_Group group1, MPI_Group group2, int *result )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Group_compare( &jbuf,  & group1,  & group2, result );

return rc;
} /* MPI_Group_compare */


extern void F77_MPI_GROUP_COMPARE(MPI_Fint  * group1, MPI_Fint  * group2, int  *result , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Group c_group1;
MPI_Group c_group2;

c_group1 = MPI_Group_f2c(*group1);
c_group2 = MPI_Group_f2c(*group2);

rc = mpiPif_MPI_Group_compare( &jbuf, &c_group1, &c_group2, result );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_group_compare */



/* --------------- MPI_Group_difference --------------- */

static int mpiPif_MPI_Group_difference( jmp_buf * base_jbuf, MPI_Group  * group1, MPI_Group  * group2, MPI_Group  *group_out)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Group_difference\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Group* group1, MPI_Group* group2, MPI_Group group_out )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Group group1= %d, MPI_Group group2= %d, MPI_Group group_out= %d, )\n", *group1, *group2, group_out);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Group_difference(  * group1,  * group2, group_out);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Group_difference");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Group_difference, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Group_difference */



extern int MPI_Group_difference ( MPI_Group group1, MPI_Group group2, MPI_Group *group_out )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Group_difference( &jbuf,  & group1,  & group2, group_out );

return rc;
} /* MPI_Group_difference */


extern void F77_MPI_GROUP_DIFFERENCE(MPI_Fint  * group1, MPI_Fint  * group2, MPI_Fint  *group_out , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Group c_group1;
MPI_Group c_group2;
MPI_Group c_group_out;

c_group1 = MPI_Group_f2c(*group1);
c_group2 = MPI_Group_f2c(*group2);

rc = mpiPif_MPI_Group_difference( &jbuf, &c_group1, &c_group2, &c_group_out );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*group_out = MPI_Group_c2f(c_group_out);
}
return;
} /* mpi_group_difference */



/* --------------- MPI_Group_excl --------------- */

static int mpiPif_MPI_Group_excl( jmp_buf * base_jbuf, MPI_Group  * group, int  * n, mpip_const_int_t  *ranks, MPI_Group  *newgroup)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Group_excl\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Group* group, int* n, mpip_const_int_t ranks, MPI_Group newgroup )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Group group= %d, int n= %d, mpip_const_int_t ranks= %d, MPI_Group newgroup= %d, )\n", *group, *n, ranks, newgroup);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Group_excl(  * group,  * n, ranks, newgroup);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Group_excl");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Group_excl, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Group_excl */



extern int MPI_Group_excl ( MPI_Group group, int n, mpip_const_int_t *ranks, MPI_Group *newgroup )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Group_excl( &jbuf,  & group,  & n, ranks, newgroup );

return rc;
} /* MPI_Group_excl */


extern void F77_MPI_GROUP_EXCL(MPI_Fint  * group, int  * n, mpip_const_int_t  *ranks, MPI_Fint  *newgroup , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Group c_group;
MPI_Group c_newgroup;

c_group = MPI_Group_f2c(*group);

rc = mpiPif_MPI_Group_excl( &jbuf, &c_group, n, ranks, &c_newgroup );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*newgroup = MPI_Group_c2f(c_newgroup);
}
return;
} /* mpi_group_excl */



/* --------------- MPI_Group_free --------------- */

static int mpiPif_MPI_Group_free( jmp_buf * base_jbuf, MPI_Group  *group)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Group_free\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Group group )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Group group= %d, )\n", group);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Group_free( group);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Group_free");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Group_free, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Group_free */



extern int MPI_Group_free ( MPI_Group *group )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Group_free( &jbuf, group );

return rc;
} /* MPI_Group_free */


extern void F77_MPI_GROUP_FREE(MPI_Fint  *group , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Group c_group;

c_group = MPI_Group_f2c(*group);

rc = mpiPif_MPI_Group_free( &jbuf, &c_group );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*group = MPI_Group_c2f(c_group);
}
return;
} /* mpi_group_free */



/* --------------- MPI_Group_incl --------------- */

static int mpiPif_MPI_Group_incl( jmp_buf * base_jbuf, MPI_Group  * group, int  * n, mpip_const_int_t  *ranks, MPI_Group  *group_out)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Group_incl\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Group* group, int* n, mpip_const_int_t ranks, MPI_Group group_out )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Group group= %d, int n= %d, mpip_const_int_t ranks= %d, MPI_Group group_out= %d, )\n", *group, *n, ranks, group_out);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Group_incl(  * group,  * n, ranks, group_out);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Group_incl");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Group_incl, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Group_incl */



extern int MPI_Group_incl ( MPI_Group group, int n, mpip_const_int_t *ranks, MPI_Group *group_out )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Group_incl( &jbuf,  & group,  & n, ranks, group_out );

return rc;
} /* MPI_Group_incl */


extern void F77_MPI_GROUP_INCL(MPI_Fint  * group, int  * n, mpip_const_int_t  *ranks, MPI_Fint  *group_out , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Group c_group;
MPI_Group c_group_out;

c_group = MPI_Group_f2c(*group);

rc = mpiPif_MPI_Group_incl( &jbuf, &c_group, n, ranks, &c_group_out );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*group_out = MPI_Group_c2f(c_group_out);
}
return;
} /* mpi_group_incl */



/* --------------- MPI_Group_intersection --------------- */

static int mpiPif_MPI_Group_intersection( jmp_buf * base_jbuf, MPI_Group  * group1, MPI_Group  * group2, MPI_Group  *group_out)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Group_intersection\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Group* group1, MPI_Group* group2, MPI_Group group_out )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Group group1= %d, MPI_Group group2= %d, MPI_Group group_out= %d, )\n", *group1, *group2, group_out);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Group_intersection(  * group1,  * group2, group_out);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Group_intersection");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Group_intersection, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Group_intersection */



extern int MPI_Group_intersection ( MPI_Group group1, MPI_Group group2, MPI_Group *group_out )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Group_intersection( &jbuf,  & group1,  & group2, group_out );

return rc;
} /* MPI_Group_intersection */


extern void F77_MPI_GROUP_INTERSECTION(MPI_Fint  * group1, MPI_Fint  * group2, MPI_Fint  *group_out , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Group c_group1;
MPI_Group c_group2;
MPI_Group c_group_out;

c_group1 = MPI_Group_f2c(*group1);
c_group2 = MPI_Group_f2c(*group2);

rc = mpiPif_MPI_Group_intersection( &jbuf, &c_group1, &c_group2, &c_group_out );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*group_out = MPI_Group_c2f(c_group_out);
}
return;
} /* mpi_group_intersection */



/* --------------- MPI_Group_translate_ranks --------------- */

static int mpiPif_MPI_Group_translate_ranks( jmp_buf * base_jbuf, MPI_Group  * group_a, int  * n, mpip_const_int_t  *ranks_a, MPI_Group  * group_b, int  *ranks_b)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Group_translate_ranks\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Group* group_a, int* n, mpip_const_int_t ranks_a, MPI_Group* group_b, int ranks_b )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Group group_a= %d, int n= %d, mpip_const_int_t ranks_a= %d, MPI_Group group_b= %d, int ranks_b= %d, )\n", *group_a, *n, ranks_a, *group_b, ranks_b);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Group_translate_ranks(  * group_a,  * n, ranks_a,  * group_b, ranks_b);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Group_translate_ranks");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Group_translate_ranks, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Group_translate_ranks */



extern int MPI_Group_translate_ranks ( MPI_Group group_a, int n, mpip_const_int_t *ranks_a, MPI_Group group_b, int *ranks_b )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Group_translate_ranks( &jbuf,  & group_a,  & n, ranks_a,  & group_b, ranks_b );

return rc;
} /* MPI_Group_translate_ranks */


extern void F77_MPI_GROUP_TRANSLATE_RANKS(MPI_Fint  * group_a, int  * n, mpip_const_int_t  *ranks_a, MPI_Fint  * group_b, int  *ranks_b , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Group c_group_a;
MPI_Group c_group_b;

c_group_a = MPI_Group_f2c(*group_a);
c_group_b = MPI_Group_f2c(*group_b);

rc = mpiPif_MPI_Group_translate_ranks( &jbuf, &c_group_a, n, ranks_a, &c_group_b, ranks_b );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_group_translate_ranks */



/* --------------- MPI_Group_union --------------- */

static int mpiPif_MPI_Group_union( jmp_buf * base_jbuf, MPI_Group  * group1, MPI_Group  * group2, MPI_Group  *group_out)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Group_union\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Group* group1, MPI_Group* group2, MPI_Group group_out )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Group group1= %d, MPI_Group group2= %d, MPI_Group group_out= %d, )\n", *group1, *group2, group_out);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Group_union(  * group1,  * group2, group_out);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Group_union");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Group_union, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Group_union */



extern int MPI_Group_union ( MPI_Group group1, MPI_Group group2, MPI_Group *group_out )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Group_union( &jbuf,  & group1,  & group2, group_out );

return rc;
} /* MPI_Group_union */


extern void F77_MPI_GROUP_UNION(MPI_Fint  * group1, MPI_Fint  * group2, MPI_Fint  *group_out , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Group c_group1;
MPI_Group c_group2;
MPI_Group c_group_out;

c_group1 = MPI_Group_f2c(*group1);
c_group2 = MPI_Group_f2c(*group2);

rc = mpiPif_MPI_Group_union( &jbuf, &c_group1, &c_group2, &c_group_out );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*group_out = MPI_Group_c2f(c_group_out);
}
return;
} /* mpi_group_union */



/* --------------- MPI_Iallgather --------------- */

static int mpiPif_MPI_Iallgather( jmp_buf * base_jbuf, const void  *sendbuf, int  * sendcount, MPI_Datatype  * sendtype, void  *recvbuf, int  * recvcount, MPI_Datatype  * recvtype, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Iallgather\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( const void sendbuf, int* sendcount, MPI_Datatype* sendtype, void recvbuf, int* recvcount, MPI_Datatype* recvtype, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*sendtype, &DT_size);
MPI_Type_size(*recvtype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (const void sendbuf= %d, int sendcount= %d, MPI_Datatype sendtype= %d, void recvbuf= %d, int recvcount= %d, MPI_Datatype recvtype= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", sendbuf, *sendcount, DT_size, recvbuf, *recvcount, DT_size, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Iallgather( sendbuf,  * sendcount,  * sendtype, recvbuf,  * recvcount,  * recvtype,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *sendtype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*sendtype, &tsize);
messSize = (double)(tsize * *sendcount);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Iallgather");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Iallgather, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Iallgather, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Iallgather */



extern int MPI_Iallgather ( const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request ) 
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Iallgather( &jbuf, sendbuf,  & sendcount,  & sendtype, recvbuf,  & recvcount,  & recvtype,  & comm, request );

return rc;
} /* MPI_Iallgather */


extern void F77_MPI_IALLGATHER(const void  *sendbuf, int  * sendcount, MPI_Fint  * sendtype, void  *recvbuf, int  * recvcount, MPI_Fint  * recvtype, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;
MPI_Request c_request;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Iallgather( &jbuf, sendbuf, sendcount, &c_sendtype, recvbuf, recvcount, &c_recvtype, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_iallgather */



/* --------------- MPI_Iallgatherv --------------- */

static int mpiPif_MPI_Iallgatherv( jmp_buf * base_jbuf, const void  *sendbuf, int  * sendcount, MPI_Datatype  * sendtype, void  *recvbuf, mpip_const_int_t recvcounts[], mpip_const_int_t displs[], MPI_Datatype  * recvtype, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Iallgatherv\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( const void sendbuf, int* sendcount, MPI_Datatype* sendtype, void recvbuf, mpip_const_int_t recvcounts, mpip_const_int_t displs, MPI_Datatype* recvtype, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*sendtype, &DT_size);
MPI_Type_size(*recvtype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (const void sendbuf= %d, int sendcount= %d, MPI_Datatype sendtype= %d, void recvbuf= %d, mpip_const_int_t recvcounts= %d, mpip_const_int_t displs= %d, MPI_Datatype recvtype= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", sendbuf, *sendcount, DT_size, recvbuf, recvcounts, displs, DT_size, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Iallgatherv( sendbuf,  * sendcount,  * sendtype, recvbuf, recvcounts, displs,  * recvtype,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *sendtype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*sendtype, &tsize);
messSize = (double)(tsize * *sendcount);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Iallgatherv");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Iallgatherv, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Iallgatherv, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Iallgatherv */



extern int MPI_Iallgatherv ( const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, mpip_const_int_t recvcounts[], mpip_const_int_t displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request* request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Iallgatherv( &jbuf, sendbuf,  & sendcount,  & sendtype, recvbuf, recvcounts, displs,  & recvtype,  & comm, request );

return rc;
} /* MPI_Iallgatherv */


extern void F77_MPI_IALLGATHERV(const void  *sendbuf, int  * sendcount, MPI_Fint  * sendtype, void  *recvbuf, mpip_const_int_t recvcounts[], mpip_const_int_t displs[], MPI_Fint  * recvtype, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;
MPI_Request c_request;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Iallgatherv( &jbuf, sendbuf, sendcount, &c_sendtype, recvbuf, recvcounts, displs, &c_recvtype, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_iallgatherv */



/* --------------- MPI_Iallreduce --------------- */

static int mpiPif_MPI_Iallreduce( jmp_buf * base_jbuf, const void  *sendbuf, void  *recvbuf, int  * count, MPI_Datatype  * datatype, MPI_Op  * op, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Iallreduce\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( const void sendbuf, void recvbuf, int* count, MPI_Datatype* datatype, MPI_Op* op, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (const void sendbuf= %d, void recvbuf= %d, int count= %d, MPI_Datatype datatype= %d, MPI_Op op= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", sendbuf, recvbuf, *count, DT_size, *op, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Iallreduce( sendbuf, recvbuf,  * count,  * datatype,  * op,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Iallreduce");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Iallreduce, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Iallreduce, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Iallreduce */



extern int MPI_Iallreduce ( const void* sendbuf, void* recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request )  
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Iallreduce( &jbuf, sendbuf, recvbuf,  & count,  & datatype,  & op,  & comm, request );

return rc;
} /* MPI_Iallreduce */


extern void F77_MPI_IALLREDUCE(const void  *sendbuf, void  *recvbuf, int  * count, MPI_Fint  * datatype, MPI_Fint  * op, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Op c_op;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_op = MPI_Op_f2c(*op);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Iallreduce( &jbuf, sendbuf, recvbuf, count, &c_datatype, &c_op, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_iallreduce */



/* --------------- MPI_Ialltoall --------------- */

static int mpiPif_MPI_Ialltoall( jmp_buf * base_jbuf, const void  *sendbuf, int  * sendcount, MPI_Datatype  * sendtype, void  *recvbuf, int  * recvcount, MPI_Datatype  * recvtype, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Ialltoall\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( const void sendbuf, int* sendcount, MPI_Datatype* sendtype, void recvbuf, int* recvcount, MPI_Datatype* recvtype, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*sendtype, &DT_size);
MPI_Type_size(*recvtype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (const void sendbuf= %d, int sendcount= %d, MPI_Datatype sendtype= %d, void recvbuf= %d, int recvcount= %d, MPI_Datatype recvtype= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", sendbuf, *sendcount, DT_size, recvbuf, *recvcount, DT_size, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Ialltoall( sendbuf,  * sendcount,  * sendtype, recvbuf,  * recvcount,  * recvtype,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *sendtype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*sendtype, &tsize);
messSize = (double)(tsize * *sendcount);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Ialltoall");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Ialltoall, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Ialltoall, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Ialltoall */



extern int MPI_Ialltoall ( const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request )  
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Ialltoall( &jbuf, sendbuf,  & sendcount,  & sendtype, recvbuf,  & recvcount,  & recvtype,  & comm, request );

return rc;
} /* MPI_Ialltoall */


extern void F77_MPI_IALLTOALL(const void  *sendbuf, int  * sendcount, MPI_Fint  * sendtype, void  *recvbuf, int  * recvcount, MPI_Fint  * recvtype, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;
MPI_Request c_request;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Ialltoall( &jbuf, sendbuf, sendcount, &c_sendtype, recvbuf, recvcount, &c_recvtype, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_ialltoall */



/* --------------- MPI_Ialltoallv --------------- */

static int mpiPif_MPI_Ialltoallv( jmp_buf * base_jbuf, const void  *sendbuf, mpip_const_int_t sendcounts[], mpip_const_int_t sdispls[], MPI_Datatype  * sendtype, void  *recvbuf, mpip_const_int_t recvcounts[], mpip_const_int_t rdispls[], MPI_Datatype  * recvtype, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Ialltoallv\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( const void sendbuf, mpip_const_int_t sendcounts, mpip_const_int_t sdispls, MPI_Datatype* sendtype, void recvbuf, mpip_const_int_t recvcounts, mpip_const_int_t rdispls, MPI_Datatype* recvtype, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*sendtype, &DT_size);
MPI_Type_size(*recvtype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (const void sendbuf= %d, mpip_const_int_t sendcounts= %d, mpip_const_int_t sdispls= %d, MPI_Datatype sendtype= %d, void recvbuf= %d, mpip_const_int_t recvcounts= %d, mpip_const_int_t rdispls= %d, MPI_Datatype recvtype= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", sendbuf, sendcounts, sdispls, DT_size, recvbuf, recvcounts, rdispls, DT_size, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Ialltoallv( sendbuf, sendcounts, sdispls,  * sendtype, recvbuf, recvcounts, rdispls,  * recvtype,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *sendtype != MPI_DATATYPE_NULL ) { 
  int loc_comm_size, i;
  int loc_sent = 0;

  PMPI_Comm_size(*comm, &loc_comm_size);
  PMPI_Type_size(*sendtype, &tsize);
  for ( i = 0; i<loc_comm_size; i++) 
    loc_sent += sendcounts[i];
  messSize = (double)(tsize * loc_sent);
}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Ialltoallv");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Ialltoallv, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Ialltoallv, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Ialltoallv */



extern int MPI_Ialltoallv ( const void* sendbuf, mpip_const_int_t sendcounts[], mpip_const_int_t sdispls[], MPI_Datatype sendtype, void* recvbuf, mpip_const_int_t recvcounts[], mpip_const_int_t rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Ialltoallv( &jbuf, sendbuf, sendcounts, sdispls,  & sendtype, recvbuf, recvcounts, rdispls,  & recvtype,  & comm, request );

return rc;
} /* MPI_Ialltoallv */


extern void F77_MPI_IALLTOALLV(const void  *sendbuf, mpip_const_int_t sendcounts[], mpip_const_int_t sdispls[], MPI_Fint  * sendtype, void  *recvbuf, mpip_const_int_t recvcounts[], mpip_const_int_t rdispls[], MPI_Fint  * recvtype, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;
MPI_Request c_request;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Ialltoallv( &jbuf, sendbuf, sendcounts, sdispls, &c_sendtype, recvbuf, recvcounts, rdispls, &c_recvtype, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_ialltoallv */



/* --------------- MPI_Ialltoallw --------------- */

static int mpiPif_MPI_Ialltoallw( jmp_buf * base_jbuf, const void  *sendbuf, mpip_const_int_t sendcounts[], mpip_const_int_t sdispls[], mpip_const_datatype_t sendtypes[], void  *recvbuf, mpip_const_int_t recvcounts[], mpip_const_int_t rdispls[], mpip_const_datatype_t recvtypes[], MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Ialltoallw\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( const void sendbuf, mpip_const_int_t sendcounts, mpip_const_int_t sdispls, mpip_const_datatype_t sendtypes, void recvbuf, mpip_const_int_t recvcounts, mpip_const_int_t rdispls, mpip_const_datatype_t recvtypes, MPI_Comm* comm, MPI_Request request )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (const void sendbuf= %d, mpip_const_int_t sendcounts= %d, mpip_const_int_t sdispls= %d, mpip_const_datatype_t sendtypes= %d, void recvbuf= %d, mpip_const_int_t recvcounts= %d, mpip_const_int_t rdispls= %d, mpip_const_datatype_t recvtypes= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Ialltoallw( sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

  int loc_comm_size, i;
  int loc_sent = 0;

  PMPI_Comm_size(*comm, &loc_comm_size);

  for ( i = 0; i<loc_comm_size; i++) { 
    if ( sendtypes[i] != MPI_DATATYPE_NULL ) { 
      PMPI_Type_size(sendtypes[i], &tsize);
      loc_sent = sendcounts[i];
      messSize += (double)(tsize * loc_sent);
    }
    else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
     mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}
}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Ialltoallw");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Ialltoallw, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Ialltoallw, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Ialltoallw */



extern int MPI_Ialltoallw ( const void* sendbuf, mpip_const_int_t sendcounts[], mpip_const_int_t sdispls[], mpip_const_datatype_t sendtypes[], void* recvbuf, mpip_const_int_t recvcounts[], mpip_const_int_t rdispls[], mpip_const_datatype_t recvtypes[], MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Ialltoallw( &jbuf, sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes,  & comm, request );

return rc;
} /* MPI_Ialltoallw */


extern void F77_MPI_IALLTOALLW(const void  *sendbuf, mpip_const_int_t sendcounts[], mpip_const_int_t sdispls[], mpip_const_datatype_t sendtypes[], void  *recvbuf, mpip_const_int_t recvcounts[], mpip_const_int_t rdispls[], mpip_const_datatype_t recvtypes[], MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;
MPI_Request c_request;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Ialltoallw( &jbuf, sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_ialltoallw */



/* --------------- MPI_Ibarrier --------------- */

static int mpiPif_MPI_Ibarrier( jmp_buf * base_jbuf, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Ibarrier\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm, MPI_Request request )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, MPI_Request request= %d, )\n", *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Ibarrier(  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Ibarrier");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Ibarrier, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Ibarrier, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Ibarrier */



extern int MPI_Ibarrier ( MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Ibarrier( &jbuf,  & comm, request );

return rc;
} /* MPI_Ibarrier */


extern void F77_MPI_IBARRIER(MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;
MPI_Request c_request;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Ibarrier( &jbuf, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_ibarrier */



/* --------------- MPI_Ibcast --------------- */

static int mpiPif_MPI_Ibcast( jmp_buf * base_jbuf, void  *buffer, int  * count, MPI_Datatype  * datatype, int  * root, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Ibcast\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( void buffer, int* count, MPI_Datatype* datatype, int* root, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (void buffer= %d, int count= %d, MPI_Datatype datatype= %d, int root= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", buffer, *count, DT_size, *root, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Ibcast( buffer,  * count,  * datatype,  * root,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Ibcast");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Ibcast, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Ibcast, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Ibcast */



extern int MPI_Ibcast ( void* buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm, MPI_Request *request ) 
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Ibcast( &jbuf, buffer,  & count,  & datatype,  & root,  & comm, request );

return rc;
} /* MPI_Ibcast */


extern void F77_MPI_IBCAST(void  *buffer, int  * count, MPI_Fint  * datatype, int  * root, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Ibcast( &jbuf, buffer, count, &c_datatype, root, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_ibcast */



/* --------------- MPI_Ibsend --------------- */

static int mpiPif_MPI_Ibsend( jmp_buf * base_jbuf, mpip_const_void_t  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * tag, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Ibsend\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t buf, int* count, MPI_Datatype* datatype, int* dest, int* tag, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t buf= %d, int count= %d, MPI_Datatype datatype= %d, int dest= %d, int tag= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", buf, *count, DT_size, *dest, *tag, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Ibsend( buf,  * count,  * datatype,  * dest,  * tag,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Ibsend");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Ibsend, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_pt2pt_stats_report) { mpiPi_update_pt2pt_stats(hndl, mpiPi_MPI_Ibsend, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Ibsend */



extern int MPI_Ibsend ( mpip_const_void_t *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Ibsend( &jbuf, buf,  & count,  & datatype,  & dest,  & tag,  & comm, request );

return rc;
} /* MPI_Ibsend */


extern void F77_MPI_IBSEND(mpip_const_void_t  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * tag, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Ibsend( &jbuf, buf, count, &c_datatype, dest, tag, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_ibsend */



/* --------------- MPI_Iexscan --------------- */

static int mpiPif_MPI_Iexscan( jmp_buf * base_jbuf, const void  *sendbuf, void  *recvbuf, int  * count, MPI_Datatype  * datatype, MPI_Op  * op, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Iexscan\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( const void sendbuf, void recvbuf, int* count, MPI_Datatype* datatype, MPI_Op* op, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (const void sendbuf= %d, void recvbuf= %d, int count= %d, MPI_Datatype datatype= %d, MPI_Op op= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", sendbuf, recvbuf, *count, DT_size, *op, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Iexscan( sendbuf, recvbuf,  * count,  * datatype,  * op,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Iexscan");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Iexscan, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Iexscan, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Iexscan */



extern int MPI_Iexscan ( const void* sendbuf, void* recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request )  
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Iexscan( &jbuf, sendbuf, recvbuf,  & count,  & datatype,  & op,  & comm, request );

return rc;
} /* MPI_Iexscan */


extern void F77_MPI_IEXSCAN(const void  *sendbuf, void  *recvbuf, int  * count, MPI_Fint  * datatype, MPI_Fint  * op, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Op c_op;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_op = MPI_Op_f2c(*op);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Iexscan( &jbuf, sendbuf, recvbuf, count, &c_datatype, &c_op, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_iexscan */



/* --------------- MPI_Igather --------------- */

static int mpiPif_MPI_Igather( jmp_buf * base_jbuf, const void  *sendbuf, int  * sendcount, MPI_Datatype  * sendtype, void  *recvbuf, int  * recvcount, MPI_Datatype  * recvtype, int  * root, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Igather\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( const void sendbuf, int* sendcount, MPI_Datatype* sendtype, void recvbuf, int* recvcount, MPI_Datatype* recvtype, int* root, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*sendtype, &DT_size);
MPI_Type_size(*recvtype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (const void sendbuf= %d, int sendcount= %d, MPI_Datatype sendtype= %d, void recvbuf= %d, int recvcount= %d, MPI_Datatype recvtype= %d, int root= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", sendbuf, *sendcount, DT_size, recvbuf, *recvcount, DT_size, *root, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Igather( sendbuf,  * sendcount,  * sendtype, recvbuf,  * recvcount,  * recvtype,  * root,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *sendtype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*sendtype, &tsize);
messSize = (double)(tsize * *sendcount);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Igather");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Igather, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Igather, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Igather */



extern int MPI_Igather ( const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) 
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Igather( &jbuf, sendbuf,  & sendcount,  & sendtype, recvbuf,  & recvcount,  & recvtype,  & root,  & comm, request );

return rc;
} /* MPI_Igather */


extern void F77_MPI_IGATHER(const void  *sendbuf, int  * sendcount, MPI_Fint  * sendtype, void  *recvbuf, int  * recvcount, MPI_Fint  * recvtype, int  * root, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;
MPI_Request c_request;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Igather( &jbuf, sendbuf, sendcount, &c_sendtype, recvbuf, recvcount, &c_recvtype, root, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_igather */



/* --------------- MPI_Igatherv --------------- */

static int mpiPif_MPI_Igatherv( jmp_buf * base_jbuf, const void  *sendbuf, int  * sendcount, MPI_Datatype  * sendtype, void  *recvbuf, mpip_const_int_t recvcounts[], mpip_const_int_t displs[], MPI_Datatype  * recvtype, int  * root, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Igatherv\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( const void sendbuf, int* sendcount, MPI_Datatype* sendtype, void recvbuf, mpip_const_int_t recvcounts, mpip_const_int_t displs, MPI_Datatype* recvtype, int* root, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*sendtype, &DT_size);
MPI_Type_size(*recvtype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (const void sendbuf= %d, int sendcount= %d, MPI_Datatype sendtype= %d, void recvbuf= %d, mpip_const_int_t recvcounts= %d, mpip_const_int_t displs= %d, MPI_Datatype recvtype= %d, int root= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", sendbuf, *sendcount, DT_size, recvbuf, recvcounts, displs, DT_size, *root, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Igatherv( sendbuf,  * sendcount,  * sendtype, recvbuf, recvcounts, displs,  * recvtype,  * root,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *sendtype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*sendtype, &tsize);
messSize = (double)(tsize * *sendcount);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Igatherv");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Igatherv, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Igatherv, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Igatherv */



extern int MPI_Igatherv ( const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, mpip_const_int_t recvcounts[], mpip_const_int_t displs[], MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Igatherv( &jbuf, sendbuf,  & sendcount,  & sendtype, recvbuf, recvcounts, displs,  & recvtype,  & root,  & comm, request );

return rc;
} /* MPI_Igatherv */


extern void F77_MPI_IGATHERV(const void  *sendbuf, int  * sendcount, MPI_Fint  * sendtype, void  *recvbuf, mpip_const_int_t recvcounts[], mpip_const_int_t displs[], MPI_Fint  * recvtype, int  * root, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;
MPI_Request c_request;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Igatherv( &jbuf, sendbuf, sendcount, &c_sendtype, recvbuf, recvcounts, displs, &c_recvtype, root, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_igatherv */



/* --------------- MPI_Intercomm_create --------------- */

static int mpiPif_MPI_Intercomm_create( jmp_buf * base_jbuf, MPI_Comm  * local_comm, int  * local_leader, MPI_Comm  * peer_comm, int  * remote_leader, int  * tag, MPI_Comm  *comm_out)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Intercomm_create\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* local_comm, int* local_leader, MPI_Comm* peer_comm, int* remote_leader, int* tag, MPI_Comm comm_out )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm local_comm= %d, int local_leader= %d, MPI_Comm peer_comm= %d, int remote_leader= %d, int tag= %d, MPI_Comm comm_out= %d, )\n", *local_comm, *local_leader, *peer_comm, *remote_leader, *tag, comm_out);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Intercomm_create(  * local_comm,  * local_leader,  * peer_comm,  * remote_leader,  * tag, comm_out);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Intercomm_create");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Intercomm_create, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Intercomm_create */



extern int MPI_Intercomm_create ( MPI_Comm local_comm, int local_leader, MPI_Comm peer_comm, int remote_leader, int tag, MPI_Comm *comm_out )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Intercomm_create( &jbuf,  & local_comm,  & local_leader,  & peer_comm,  & remote_leader,  & tag, comm_out );

return rc;
} /* MPI_Intercomm_create */


extern void F77_MPI_INTERCOMM_CREATE(MPI_Fint  * local_comm, int  * local_leader, MPI_Fint  * peer_comm, int  * remote_leader, int  * tag, MPI_Fint  *comm_out , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_local_comm;
MPI_Comm c_peer_comm;
MPI_Comm c_comm_out;

c_local_comm = MPI_Comm_f2c(*local_comm);
c_peer_comm = MPI_Comm_f2c(*peer_comm);

rc = mpiPif_MPI_Intercomm_create( &jbuf, &c_local_comm, local_leader, &c_peer_comm, remote_leader, tag, &c_comm_out );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*comm_out = MPI_Comm_c2f(c_comm_out);
}
return;
} /* mpi_intercomm_create */



/* --------------- MPI_Intercomm_merge --------------- */

static int mpiPif_MPI_Intercomm_merge( jmp_buf * base_jbuf, MPI_Comm  * comm, int  * high, MPI_Comm  *comm_out)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Intercomm_merge\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm, int* high, MPI_Comm comm_out )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, int high= %d, MPI_Comm comm_out= %d, )\n", *comm, *high, comm_out);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Intercomm_merge(  * comm,  * high, comm_out);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Intercomm_merge");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Intercomm_merge, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Intercomm_merge */



extern int MPI_Intercomm_merge ( MPI_Comm comm, int high, MPI_Comm *comm_out )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Intercomm_merge( &jbuf,  & comm,  & high, comm_out );

return rc;
} /* MPI_Intercomm_merge */


extern void F77_MPI_INTERCOMM_MERGE(MPI_Fint  * comm, int  * high, MPI_Fint  *comm_out , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;
MPI_Comm c_comm_out;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Intercomm_merge( &jbuf, &c_comm, high, &c_comm_out );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*comm_out = MPI_Comm_c2f(c_comm_out);
}
return;
} /* mpi_intercomm_merge */



/* --------------- MPI_Iprobe --------------- */

static int mpiPif_MPI_Iprobe( jmp_buf * base_jbuf, int  * source, int  * tag, MPI_Comm  * comm, int  *flag, MPI_Status  *status)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Iprobe\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( int* source, int* tag, MPI_Comm* comm, int flag, MPI_Status status )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (int source= %d, int tag= %d, MPI_Comm comm= %d, int flag= %d, MPI_Status status= %d, )\n", *source, *tag, *comm, flag, status);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Iprobe(  * source,  * tag,  * comm, flag, status);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Iprobe");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Iprobe, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Iprobe */



extern int MPI_Iprobe ( int source, int tag, MPI_Comm comm, int *flag, MPI_Status *status )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Iprobe( &jbuf,  & source,  & tag,  & comm, flag, status );

return rc;
} /* MPI_Iprobe */


extern void F77_MPI_IPROBE(int  * source, int  * tag, MPI_Fint  * comm, int  *flag, MPI_Status  *status , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Iprobe( &jbuf, source, tag, &c_comm, flag, status );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_iprobe */



/* --------------- MPI_Irecv --------------- */

static int mpiPif_MPI_Irecv( jmp_buf * base_jbuf, void  *buf, int  * count, MPI_Datatype  * datatype, int  * source, int  * tag, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Irecv\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( void buf, int* count, MPI_Datatype* datatype, int* source, int* tag, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (void buf= %d, int count= %d, MPI_Datatype datatype= %d, int source= %d, int tag= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", buf, *count, DT_size, *source, *tag, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Irecv( buf,  * count,  * datatype,  * source,  * tag,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Irecv");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Irecv, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Irecv */



extern int MPI_Irecv ( void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Irecv( &jbuf, buf,  & count,  & datatype,  & source,  & tag,  & comm, request );

return rc;
} /* MPI_Irecv */


extern void F77_MPI_IRECV(void  *buf, int  * count, MPI_Fint  * datatype, int  * source, int  * tag, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Irecv( &jbuf, buf, count, &c_datatype, source, tag, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_irecv */



/* --------------- MPI_Ireduce --------------- */

static int mpiPif_MPI_Ireduce( jmp_buf * base_jbuf, const void  *sendbuf, void  *recvbuf, int  * count, MPI_Datatype  * datatype, MPI_Op  * op, int  * root, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Ireduce\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( const void sendbuf, void recvbuf, int* count, MPI_Datatype* datatype, MPI_Op* op, int* root, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (const void sendbuf= %d, void recvbuf= %d, int count= %d, MPI_Datatype datatype= %d, MPI_Op op= %d, int root= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", sendbuf, recvbuf, *count, DT_size, *op, *root, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Ireduce( sendbuf, recvbuf,  * count,  * datatype,  * op,  * root,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Ireduce");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Ireduce, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Ireduce, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Ireduce */



extern int MPI_Ireduce ( const void* sendbuf, void* recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm, MPI_Request *request )  
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Ireduce( &jbuf, sendbuf, recvbuf,  & count,  & datatype,  & op,  & root,  & comm, request );

return rc;
} /* MPI_Ireduce */


extern void F77_MPI_IREDUCE(const void  *sendbuf, void  *recvbuf, int  * count, MPI_Fint  * datatype, MPI_Fint  * op, int  * root, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Op c_op;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_op = MPI_Op_f2c(*op);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Ireduce( &jbuf, sendbuf, recvbuf, count, &c_datatype, &c_op, root, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_ireduce */



/* --------------- MPI_Ireduce_scatter --------------- */

static int mpiPif_MPI_Ireduce_scatter( jmp_buf * base_jbuf, const void  *sendbuf, void  *recvbuf, mpip_const_int_t recvcounts[], MPI_Datatype  * datatype, MPI_Op  * op, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Ireduce_scatter\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( const void sendbuf, void recvbuf, mpip_const_int_t recvcounts, MPI_Datatype* datatype, MPI_Op* op, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (const void sendbuf= %d, void recvbuf= %d, mpip_const_int_t recvcounts= %d, MPI_Datatype datatype= %d, MPI_Op op= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", sendbuf, recvbuf, recvcounts, DT_size, *op, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Ireduce_scatter( sendbuf, recvbuf, recvcounts,  * datatype,  * op,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *datatype != MPI_DATATYPE_NULL ) { 
  int loc_comm_size, i;
  int loc_sent = 0;

  PMPI_Comm_size(*comm, &loc_comm_size);
  PMPI_Type_size(*datatype, &tsize);
  for ( i = 0; i<loc_comm_size; i++) 
    loc_sent += recvcounts[i];
  messSize = (double)(tsize * loc_sent);
}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Ireduce_scatter");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Ireduce_scatter, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Ireduce_scatter, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Ireduce_scatter */



extern int MPI_Ireduce_scatter ( const void* sendbuf, void* recvbuf, mpip_const_int_t recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request )  
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Ireduce_scatter( &jbuf, sendbuf, recvbuf, recvcounts,  & datatype,  & op,  & comm, request );

return rc;
} /* MPI_Ireduce_scatter */


extern void F77_MPI_IREDUCE_SCATTER(const void  *sendbuf, void  *recvbuf, mpip_const_int_t recvcounts[], MPI_Fint  * datatype, MPI_Fint  * op, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Op c_op;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_op = MPI_Op_f2c(*op);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Ireduce_scatter( &jbuf, sendbuf, recvbuf, recvcounts, &c_datatype, &c_op, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_ireduce_scatter */



/* --------------- MPI_Ireduce_scatter_block --------------- */

static int mpiPif_MPI_Ireduce_scatter_block( jmp_buf * base_jbuf, const void  *sendbuf, void  *recvbuf, int  * recvcount, MPI_Datatype  * datatype, MPI_Op  * op, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Ireduce_scatter_block\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( const void sendbuf, void recvbuf, int* recvcount, MPI_Datatype* datatype, MPI_Op* op, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (const void sendbuf= %d, void recvbuf= %d, int recvcount= %d, MPI_Datatype datatype= %d, MPI_Op op= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", sendbuf, recvbuf, *recvcount, DT_size, *op, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Ireduce_scatter_block( sendbuf, recvbuf,  * recvcount,  * datatype,  * op,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *recvcount);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Ireduce_scatter_block");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Ireduce_scatter_block, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Ireduce_scatter_block, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Ireduce_scatter_block */



extern int MPI_Ireduce_scatter_block ( const void* sendbuf, void* recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request )  
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Ireduce_scatter_block( &jbuf, sendbuf, recvbuf,  & recvcount,  & datatype,  & op,  & comm, request );

return rc;
} /* MPI_Ireduce_scatter_block */


extern void F77_MPI_IREDUCE_SCATTER_BLOCK(const void  *sendbuf, void  *recvbuf, int  * recvcount, MPI_Fint  * datatype, MPI_Fint  * op, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Op c_op;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_op = MPI_Op_f2c(*op);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Ireduce_scatter_block( &jbuf, sendbuf, recvbuf, recvcount, &c_datatype, &c_op, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_ireduce_scatter_block */



/* --------------- MPI_Irsend --------------- */

static int mpiPif_MPI_Irsend( jmp_buf * base_jbuf, mpip_const_void_t  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * tag, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Irsend\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t buf, int* count, MPI_Datatype* datatype, int* dest, int* tag, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t buf= %d, int count= %d, MPI_Datatype datatype= %d, int dest= %d, int tag= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", buf, *count, DT_size, *dest, *tag, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Irsend( buf,  * count,  * datatype,  * dest,  * tag,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Irsend");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Irsend, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_pt2pt_stats_report) { mpiPi_update_pt2pt_stats(hndl, mpiPi_MPI_Irsend, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Irsend */



extern int MPI_Irsend ( mpip_const_void_t *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Irsend( &jbuf, buf,  & count,  & datatype,  & dest,  & tag,  & comm, request );

return rc;
} /* MPI_Irsend */


extern void F77_MPI_IRSEND(mpip_const_void_t  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * tag, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Irsend( &jbuf, buf, count, &c_datatype, dest, tag, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_irsend */



/* --------------- MPI_Iscan --------------- */

static int mpiPif_MPI_Iscan( jmp_buf * base_jbuf, const void  *sendbuf, void  *recvbuf, int  * count, MPI_Datatype  * datatype, MPI_Op  * op, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Iscan\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( const void sendbuf, void recvbuf, int* count, MPI_Datatype* datatype, MPI_Op* op, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (const void sendbuf= %d, void recvbuf= %d, int count= %d, MPI_Datatype datatype= %d, MPI_Op op= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", sendbuf, recvbuf, *count, DT_size, *op, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Iscan( sendbuf, recvbuf,  * count,  * datatype,  * op,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Iscan");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Iscan, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Iscan, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Iscan */



extern int MPI_Iscan ( const void* sendbuf, void* recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request )  
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Iscan( &jbuf, sendbuf, recvbuf,  & count,  & datatype,  & op,  & comm, request );

return rc;
} /* MPI_Iscan */


extern void F77_MPI_ISCAN(const void  *sendbuf, void  *recvbuf, int  * count, MPI_Fint  * datatype, MPI_Fint  * op, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Op c_op;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_op = MPI_Op_f2c(*op);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Iscan( &jbuf, sendbuf, recvbuf, count, &c_datatype, &c_op, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_iscan */



/* --------------- MPI_Iscatter --------------- */

static int mpiPif_MPI_Iscatter( jmp_buf * base_jbuf, const void  *sendbuf, int  * sendcount, MPI_Datatype  * sendtype, void  *recvbuf, int  * recvcount, MPI_Datatype  * recvtype, int  * root, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Iscatter\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( const void sendbuf, int* sendcount, MPI_Datatype* sendtype, void recvbuf, int* recvcount, MPI_Datatype* recvtype, int* root, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*sendtype, &DT_size);
MPI_Type_size(*recvtype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (const void sendbuf= %d, int sendcount= %d, MPI_Datatype sendtype= %d, void recvbuf= %d, int recvcount= %d, MPI_Datatype recvtype= %d, int root= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", sendbuf, *sendcount, DT_size, recvbuf, *recvcount, DT_size, *root, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Iscatter( sendbuf,  * sendcount,  * sendtype, recvbuf,  * recvcount,  * recvtype,  * root,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *sendtype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*sendtype, &tsize);
messSize = (double)(tsize * *sendcount);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Iscatter");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Iscatter, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Iscatter, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Iscatter */



extern int MPI_Iscatter ( const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request )  
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Iscatter( &jbuf, sendbuf,  & sendcount,  & sendtype, recvbuf,  & recvcount,  & recvtype,  & root,  & comm, request );

return rc;
} /* MPI_Iscatter */


extern void F77_MPI_ISCATTER(const void  *sendbuf, int  * sendcount, MPI_Fint  * sendtype, void  *recvbuf, int  * recvcount, MPI_Fint  * recvtype, int  * root, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;
MPI_Request c_request;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Iscatter( &jbuf, sendbuf, sendcount, &c_sendtype, recvbuf, recvcount, &c_recvtype, root, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_iscatter */



/* --------------- MPI_Iscatterv --------------- */

static int mpiPif_MPI_Iscatterv( jmp_buf * base_jbuf, const void  *sendbuf, mpip_const_int_t sendcounts[], mpip_const_int_t displs[], MPI_Datatype  * sendtype, void  *recvbuf, int  * recvcount, MPI_Datatype  * recvtype, int  * root, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Iscatterv\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( const void sendbuf, mpip_const_int_t sendcounts, mpip_const_int_t displs, MPI_Datatype* sendtype, void recvbuf, int* recvcount, MPI_Datatype* recvtype, int* root, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*sendtype, &DT_size);
MPI_Type_size(*recvtype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (const void sendbuf= %d, mpip_const_int_t sendcounts= %d, mpip_const_int_t displs= %d, MPI_Datatype sendtype= %d, void recvbuf= %d, int recvcount= %d, MPI_Datatype recvtype= %d, int root= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", sendbuf, sendcounts, displs, DT_size, recvbuf, *recvcount, DT_size, *root, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Iscatterv( sendbuf, sendcounts, displs,  * sendtype, recvbuf,  * recvcount,  * recvtype,  * root,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *sendtype != MPI_DATATYPE_NULL ) { 
  int loc_comm_size, i;
  int loc_sent = 0;

  PMPI_Comm_size(*comm, &loc_comm_size);
  PMPI_Type_size(*sendtype, &tsize);
  for ( i = 0; i<loc_comm_size; i++) 
    loc_sent += sendcounts[i];
  messSize = (double)(tsize * loc_sent);
}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Iscatterv");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Iscatterv, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Iscatterv, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Iscatterv */



extern int MPI_Iscatterv ( const void* sendbuf, mpip_const_int_t sendcounts[], mpip_const_int_t displs[], MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Iscatterv( &jbuf, sendbuf, sendcounts, displs,  & sendtype, recvbuf,  & recvcount,  & recvtype,  & root,  & comm, request );

return rc;
} /* MPI_Iscatterv */


extern void F77_MPI_ISCATTERV(const void  *sendbuf, mpip_const_int_t sendcounts[], mpip_const_int_t displs[], MPI_Fint  * sendtype, void  *recvbuf, int  * recvcount, MPI_Fint  * recvtype, int  * root, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;
MPI_Request c_request;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Iscatterv( &jbuf, sendbuf, sendcounts, displs, &c_sendtype, recvbuf, recvcount, &c_recvtype, root, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_iscatterv */



/* --------------- MPI_Isend --------------- */

static int mpiPif_MPI_Isend( jmp_buf * base_jbuf, mpip_const_void_t  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * tag, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Isend\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t buf, int* count, MPI_Datatype* datatype, int* dest, int* tag, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t buf= %d, int count= %d, MPI_Datatype datatype= %d, int dest= %d, int tag= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", buf, *count, DT_size, *dest, *tag, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Isend( buf,  * count,  * datatype,  * dest,  * tag,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Isend");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Isend, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_pt2pt_stats_report) { mpiPi_update_pt2pt_stats(hndl, mpiPi_MPI_Isend, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Isend */



extern int MPI_Isend ( mpip_const_void_t *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Isend( &jbuf, buf,  & count,  & datatype,  & dest,  & tag,  & comm, request );

return rc;
} /* MPI_Isend */


extern void F77_MPI_ISEND(mpip_const_void_t  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * tag, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Isend( &jbuf, buf, count, &c_datatype, dest, tag, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_isend */



/* --------------- MPI_Issend --------------- */

static int mpiPif_MPI_Issend( jmp_buf * base_jbuf, mpip_const_void_t  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * tag, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Issend\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t buf, int* count, MPI_Datatype* datatype, int* dest, int* tag, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t buf= %d, int count= %d, MPI_Datatype datatype= %d, int dest= %d, int tag= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", buf, *count, DT_size, *dest, *tag, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Issend( buf,  * count,  * datatype,  * dest,  * tag,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Issend");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Issend, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_pt2pt_stats_report) { mpiPi_update_pt2pt_stats(hndl, mpiPi_MPI_Issend, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Issend */



extern int MPI_Issend ( mpip_const_void_t *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Issend( &jbuf, buf,  & count,  & datatype,  & dest,  & tag,  & comm, request );

return rc;
} /* MPI_Issend */


extern void F77_MPI_ISSEND(mpip_const_void_t  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * tag, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Issend( &jbuf, buf, count, &c_datatype, dest, tag, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_issend */



/* --------------- MPI_Pack --------------- */

static int mpiPif_MPI_Pack( jmp_buf * base_jbuf, mpip_const_void_t  *inbuf, int  * incount, MPI_Datatype  * datatype, void  *outbuf, int  * count, int  *position, MPI_Comm  * comm)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Pack\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t inbuf, int* incount, MPI_Datatype* datatype, void outbuf, int* count, int position, MPI_Comm* comm )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t inbuf= %d, int incount= %d, MPI_Datatype datatype= %d, void outbuf= %d, int count= %d, int position= %d, MPI_Comm comm= %d, )\n", inbuf, *incount, DT_size, outbuf, *count, position, *comm);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Pack( inbuf,  * incount,  * datatype, outbuf,  * count, position,  * comm);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Pack");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Pack, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Pack */



extern int MPI_Pack ( mpip_const_void_t *inbuf, int incount, MPI_Datatype datatype, void *outbuf, int count, int *position, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Pack( &jbuf, inbuf,  & incount,  & datatype, outbuf,  & count, position,  & comm );

return rc;
} /* MPI_Pack */


extern void F77_MPI_PACK(mpip_const_void_t  *inbuf, int  * incount, MPI_Fint  * datatype, void  *outbuf, int  * count, int  *position, MPI_Fint  * comm , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Pack( &jbuf, inbuf, incount, &c_datatype, outbuf, count, position, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_pack */



/* --------------- MPI_Probe --------------- */

static int mpiPif_MPI_Probe( jmp_buf * base_jbuf, int  * source, int  * tag, MPI_Comm  * comm, MPI_Status  *status)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Probe\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( int* source, int* tag, MPI_Comm* comm, MPI_Status status )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (int source= %d, int tag= %d, MPI_Comm comm= %d, MPI_Status status= %d, )\n", *source, *tag, *comm, status);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Probe(  * source,  * tag,  * comm, status);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Probe");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Probe, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Probe */



extern int MPI_Probe ( int source, int tag, MPI_Comm comm, MPI_Status *status )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Probe( &jbuf,  & source,  & tag,  & comm, status );

return rc;
} /* MPI_Probe */


extern void F77_MPI_PROBE(int  * source, int  * tag, MPI_Fint  * comm, MPI_Status  *status , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Probe( &jbuf, source, tag, &c_comm, status );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_probe */



/* --------------- MPI_Put --------------- */

static int mpiPif_MPI_Put( jmp_buf * base_jbuf, mpip_const_void_t  *origin_addr, int  * origin_count, MPI_Datatype  * origin_datatype, int  * target_rank, MPI_Aint  * target_disp, int  * target_count, MPI_Datatype  * target_datatype, MPI_Win  * win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Put\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t origin_addr, int* origin_count, MPI_Datatype* origin_datatype, int* target_rank, MPI_Aint* target_disp, int* target_count, MPI_Datatype* target_datatype, MPI_Win* win )\n");
MPI_Type_size(*origin_datatype, &DT_size);
MPI_Type_size(*target_datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t origin_addr= %d, int origin_count= %d, MPI_Datatype origin_datatype= %d, int target_rank= %d, MPI_Aint target_disp= %d, int target_count= %d, MPI_Datatype target_datatype= %d, MPI_Win win= %d, )\n", origin_addr, *origin_count, DT_size, *target_rank, *target_disp, *target_count, DT_size, *win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Put( origin_addr,  * origin_count,  * origin_datatype,  * target_rank,  * target_disp,  * target_count,  * target_datatype,  * win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

PMPI_Type_size(*origin_datatype, &tsize);
rmaSize = (double)(tsize * *origin_count);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Put");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Put, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Put */



extern int MPI_Put ( mpip_const_void_t *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Put( &jbuf, origin_addr,  & origin_count,  & origin_datatype,  & target_rank,  & target_disp,  & target_count,  & target_datatype,  & win );

return rc;
} /* MPI_Put */


extern void F77_MPI_PUT(mpip_const_void_t  *origin_addr, int  * origin_count, MPI_Fint  * origin_datatype, int  * target_rank, MPI_Aint  * target_disp, int  * target_count, MPI_Fint  * target_datatype, MPI_Win  * win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_origin_datatype;
MPI_Datatype c_target_datatype;

c_origin_datatype = MPI_Type_f2c(*origin_datatype);
c_target_datatype = MPI_Type_f2c(*target_datatype);

rc = mpiPif_MPI_Put( &jbuf, origin_addr, origin_count, &c_origin_datatype, target_rank, target_disp, target_count, &c_target_datatype, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_put */



/* --------------- MPI_Raccumulate --------------- */

static int mpiPif_MPI_Raccumulate( jmp_buf * base_jbuf, mpip_const_void_t  *origin_addr, int  * origin_count, MPI_Datatype  * origin_datatype, int  * target_rank, MPI_Aint  * target_disp, int  * target_count, MPI_Datatype  * target_datatype, MPI_Op  * op, MPI_Win  * win, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Raccumulate\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t origin_addr, int* origin_count, MPI_Datatype* origin_datatype, int* target_rank, MPI_Aint* target_disp, int* target_count, MPI_Datatype* target_datatype, MPI_Op* op, MPI_Win* win, MPI_Request request )\n");
MPI_Type_size(*origin_datatype, &DT_size);
MPI_Type_size(*target_datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t origin_addr= %d, int origin_count= %d, MPI_Datatype origin_datatype= %d, int target_rank= %d, MPI_Aint target_disp= %d, int target_count= %d, MPI_Datatype target_datatype= %d, MPI_Op op= %d, MPI_Win win= %d, MPI_Request request= %d, )\n", origin_addr, *origin_count, DT_size, *target_rank, *target_disp, *target_count, DT_size, *op, *win, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Raccumulate( origin_addr,  * origin_count,  * origin_datatype,  * target_rank,  * target_disp,  * target_count,  * target_datatype,  * op,  * win, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

PMPI_Type_size(*target_datatype, &tsize);
rmaSize = (double)(tsize * *target_count);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Raccumulate");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Raccumulate, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Raccumulate */



extern int MPI_Raccumulate ( mpip_const_void_t *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Raccumulate( &jbuf, origin_addr,  & origin_count,  & origin_datatype,  & target_rank,  & target_disp,  & target_count,  & target_datatype,  & op,  & win, request );

return rc;
} /* MPI_Raccumulate */


extern void F77_MPI_RACCUMULATE(mpip_const_void_t  *origin_addr, int  * origin_count, MPI_Fint  * origin_datatype, int  * target_rank, MPI_Aint  * target_disp, int  * target_count, MPI_Fint  * target_datatype, MPI_Fint  * op, MPI_Win  * win, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_origin_datatype;
MPI_Datatype c_target_datatype;
MPI_Op c_op;
MPI_Request c_request;

c_origin_datatype = MPI_Type_f2c(*origin_datatype);
c_target_datatype = MPI_Type_f2c(*target_datatype);
c_op = MPI_Op_f2c(*op);
c_request = MPI_Request_f2c(*request);

rc = mpiPif_MPI_Raccumulate( &jbuf, origin_addr, origin_count, &c_origin_datatype, target_rank, target_disp, target_count, &c_target_datatype, &c_op, win, &c_request );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_raccumulate */



/* --------------- MPI_Recv --------------- */

static int mpiPif_MPI_Recv( jmp_buf * base_jbuf, void  *buf, int  * count, MPI_Datatype  * datatype, int  * source, int  * tag, MPI_Comm  * comm, MPI_Status  *status)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Recv\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( void buf, int* count, MPI_Datatype* datatype, int* source, int* tag, MPI_Comm* comm, MPI_Status status )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (void buf= %d, int count= %d, MPI_Datatype datatype= %d, int source= %d, int tag= %d, MPI_Comm comm= %d, MPI_Status status= %d, )\n", buf, *count, DT_size, *source, *tag, *comm, status);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Recv( buf,  * count,  * datatype,  * source,  * tag,  * comm, status);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Recv");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Recv, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Recv */



extern int MPI_Recv ( void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Recv( &jbuf, buf,  & count,  & datatype,  & source,  & tag,  & comm, status );

return rc;
} /* MPI_Recv */


extern void F77_MPI_RECV(void  *buf, int  * count, MPI_Fint  * datatype, int  * source, int  * tag, MPI_Fint  * comm, MPI_Status  *status , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Recv( &jbuf, buf, count, &c_datatype, source, tag, &c_comm, status );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_recv */



/* --------------- MPI_Recv_init --------------- */

static int mpiPif_MPI_Recv_init( jmp_buf * base_jbuf, void  *buf, int  * count, MPI_Datatype  * datatype, int  * source, int  * tag, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Recv_init\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( void buf, int* count, MPI_Datatype* datatype, int* source, int* tag, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (void buf= %d, int count= %d, MPI_Datatype datatype= %d, int source= %d, int tag= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", buf, *count, DT_size, *source, *tag, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Recv_init( buf,  * count,  * datatype,  * source,  * tag,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Recv_init");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Recv_init, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Recv_init */



extern int MPI_Recv_init ( void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Recv_init( &jbuf, buf,  & count,  & datatype,  & source,  & tag,  & comm, request );

return rc;
} /* MPI_Recv_init */


extern void F77_MPI_RECV_INIT(void  *buf, int  * count, MPI_Fint  * datatype, int  * source, int  * tag, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Recv_init( &jbuf, buf, count, &c_datatype, source, tag, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_recv_init */



/* --------------- MPI_Reduce --------------- */

static int mpiPif_MPI_Reduce( jmp_buf * base_jbuf, mpip_const_void_t  *sendbuf, void  *recvbuf, int  * count, MPI_Datatype  * datatype, MPI_Op  * op, int  * root, MPI_Comm  * comm)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Reduce\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t sendbuf, void recvbuf, int* count, MPI_Datatype* datatype, MPI_Op* op, int* root, MPI_Comm* comm )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t sendbuf= %d, void recvbuf= %d, int count= %d, MPI_Datatype datatype= %d, MPI_Op op= %d, int root= %d, MPI_Comm comm= %d, )\n", sendbuf, recvbuf, *count, DT_size, *op, *root, *comm);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Reduce( sendbuf, recvbuf,  * count,  * datatype,  * op,  * root,  * comm);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Reduce");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Reduce, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Reduce, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Reduce */



extern int MPI_Reduce ( mpip_const_void_t *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Reduce( &jbuf, sendbuf, recvbuf,  & count,  & datatype,  & op,  & root,  & comm );

return rc;
} /* MPI_Reduce */


extern void F77_MPI_REDUCE(mpip_const_void_t  *sendbuf, void  *recvbuf, int  * count, MPI_Fint  * datatype, MPI_Fint  * op, int  * root, MPI_Fint  * comm , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Op c_op;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_op = MPI_Op_f2c(*op);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Reduce( &jbuf, sendbuf, recvbuf, count, &c_datatype, &c_op, root, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_reduce */



/* --------------- MPI_Reduce_scatter --------------- */

static int mpiPif_MPI_Reduce_scatter( jmp_buf * base_jbuf, mpip_const_void_t  *sendbuf, void  *recvbuf, mpip_const_int_t  *recvcnts, MPI_Datatype  * datatype, MPI_Op  * op, MPI_Comm  * comm)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Reduce_scatter\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t sendbuf, void recvbuf, mpip_const_int_t recvcnts, MPI_Datatype* datatype, MPI_Op* op, MPI_Comm* comm )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t sendbuf= %d, void recvbuf= %d, mpip_const_int_t recvcnts= %d, MPI_Datatype datatype= %d, MPI_Op op= %d, MPI_Comm comm= %d, )\n", sendbuf, recvbuf, recvcnts, DT_size, *op, *comm);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Reduce_scatter( sendbuf, recvbuf, recvcnts,  * datatype,  * op,  * comm);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Reduce_scatter");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Reduce_scatter, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Reduce_scatter, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Reduce_scatter */



extern int MPI_Reduce_scatter ( mpip_const_void_t *sendbuf, void *recvbuf, mpip_const_int_t *recvcnts, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Reduce_scatter( &jbuf, sendbuf, recvbuf, recvcnts,  & datatype,  & op,  & comm );

return rc;
} /* MPI_Reduce_scatter */


extern void F77_MPI_REDUCE_SCATTER(mpip_const_void_t  *sendbuf, void  *recvbuf, mpip_const_int_t  *recvcnts, MPI_Fint  * datatype, MPI_Fint  * op, MPI_Fint  * comm , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Op c_op;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_op = MPI_Op_f2c(*op);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Reduce_scatter( &jbuf, sendbuf, recvbuf, recvcnts, &c_datatype, &c_op, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_reduce_scatter */



/* --------------- MPI_Request_free --------------- */

static int mpiPif_MPI_Request_free( jmp_buf * base_jbuf, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Request_free\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Request request )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Request request= %d, )\n", request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Request_free( request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Request_free");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Request_free, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Request_free */



extern int MPI_Request_free ( MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Request_free( &jbuf, request );

return rc;
} /* MPI_Request_free */


extern void F77_MPI_REQUEST_FREE(MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Request c_request;

c_request = MPI_Request_f2c(*request);

rc = mpiPif_MPI_Request_free( &jbuf, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_request_free */



/* --------------- MPI_Rget --------------- */

static int mpiPif_MPI_Rget( jmp_buf * base_jbuf, void  *origin_addr, int  * origin_count, MPI_Datatype  * origin_datatype, int  * target_rank, MPI_Aint  * target_disp, int  * target_count, MPI_Datatype  * target_datatype, MPI_Win  * win, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Rget\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( void origin_addr, int* origin_count, MPI_Datatype* origin_datatype, int* target_rank, MPI_Aint* target_disp, int* target_count, MPI_Datatype* target_datatype, MPI_Win* win, MPI_Request request )\n");
MPI_Type_size(*origin_datatype, &DT_size);
MPI_Type_size(*target_datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (void origin_addr= %d, int origin_count= %d, MPI_Datatype origin_datatype= %d, int target_rank= %d, MPI_Aint target_disp= %d, int target_count= %d, MPI_Datatype target_datatype= %d, MPI_Win win= %d, MPI_Request request= %d, )\n", origin_addr, *origin_count, DT_size, *target_rank, *target_disp, *target_count, DT_size, *win, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Rget( origin_addr,  * origin_count,  * origin_datatype,  * target_rank,  * target_disp,  * target_count,  * target_datatype,  * win, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

PMPI_Type_size(*origin_datatype, &tsize);
rmaSize = (double)(tsize * *origin_count);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Rget");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Rget, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Rget */



extern int MPI_Rget ( void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Rget( &jbuf, origin_addr,  & origin_count,  & origin_datatype,  & target_rank,  & target_disp,  & target_count,  & target_datatype,  & win, request );

return rc;
} /* MPI_Rget */


extern void F77_MPI_RGET(void  *origin_addr, int  * origin_count, MPI_Fint  * origin_datatype, int  * target_rank, MPI_Aint  * target_disp, int  * target_count, MPI_Fint  * target_datatype, MPI_Win  * win, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_origin_datatype;
MPI_Datatype c_target_datatype;
MPI_Request c_request;

c_origin_datatype = MPI_Type_f2c(*origin_datatype);
c_target_datatype = MPI_Type_f2c(*target_datatype);
c_request = MPI_Request_f2c(*request);

rc = mpiPif_MPI_Rget( &jbuf, origin_addr, origin_count, &c_origin_datatype, target_rank, target_disp, target_count, &c_target_datatype, win, &c_request );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_rget */



/* --------------- MPI_Rget_accumulate --------------- */

static int mpiPif_MPI_Rget_accumulate( jmp_buf * base_jbuf, mpip_const_void_t  *origin_addr, int  * origin_count, MPI_Datatype  * origin_datatype, void  *result_addr, int  * result_count, MPI_Datatype  * result_datatype, int  * target_rank, MPI_Aint  * target_disp, int  * target_count, MPI_Datatype  * target_datatype, MPI_Op  * op, MPI_Win  * win, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Rget_accumulate\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t origin_addr, int* origin_count, MPI_Datatype* origin_datatype, void result_addr, int* result_count, MPI_Datatype* result_datatype, int* target_rank, MPI_Aint* target_disp, int* target_count, MPI_Datatype* target_datatype, MPI_Op* op, MPI_Win* win, MPI_Request request )\n");
MPI_Type_size(*origin_datatype, &DT_size);
MPI_Type_size(*result_datatype, &DT_size);
MPI_Type_size(*target_datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t origin_addr= %d, int origin_count= %d, MPI_Datatype origin_datatype= %d, void result_addr= %d, int result_count= %d, MPI_Datatype result_datatype= %d, int target_rank= %d, MPI_Aint target_disp= %d, int target_count= %d, MPI_Datatype target_datatype= %d, MPI_Op op= %d, MPI_Win win= %d, MPI_Request request= %d, )\n", origin_addr, *origin_count, DT_size, result_addr, *result_count, DT_size, *target_rank, *target_disp, *target_count, DT_size, *op, *win, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Rget_accumulate( origin_addr,  * origin_count,  * origin_datatype, result_addr,  * result_count,  * result_datatype,  * target_rank,  * target_disp,  * target_count,  * target_datatype,  * op,  * win, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

PMPI_Type_size(*target_datatype, &tsize);
rmaSize = (double)(tsize * *target_count);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Rget_accumulate");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Rget_accumulate, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Rget_accumulate */



extern int MPI_Rget_accumulate ( mpip_const_void_t *origin_addr, int origin_count, MPI_Datatype origin_datatype, void *result_addr, int result_count, MPI_Datatype result_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Rget_accumulate( &jbuf, origin_addr,  & origin_count,  & origin_datatype, result_addr,  & result_count,  & result_datatype,  & target_rank,  & target_disp,  & target_count,  & target_datatype,  & op,  & win, request );

return rc;
} /* MPI_Rget_accumulate */


extern void F77_MPI_RGET_ACCUMULATE(mpip_const_void_t  *origin_addr, int  * origin_count, MPI_Fint  * origin_datatype, void  *result_addr, int  * result_count, MPI_Fint  * result_datatype, int  * target_rank, MPI_Aint  * target_disp, int  * target_count, MPI_Fint  * target_datatype, MPI_Fint  * op, MPI_Win  * win, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_origin_datatype;
MPI_Datatype c_result_datatype;
MPI_Datatype c_target_datatype;
MPI_Op c_op;
MPI_Request c_request;

c_origin_datatype = MPI_Type_f2c(*origin_datatype);
c_result_datatype = MPI_Type_f2c(*result_datatype);
c_target_datatype = MPI_Type_f2c(*target_datatype);
c_op = MPI_Op_f2c(*op);
c_request = MPI_Request_f2c(*request);

rc = mpiPif_MPI_Rget_accumulate( &jbuf, origin_addr, origin_count, &c_origin_datatype, result_addr, result_count, &c_result_datatype, target_rank, target_disp, target_count, &c_target_datatype, &c_op, win, &c_request );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_rget_accumulate */



/* --------------- MPI_Rput --------------- */

static int mpiPif_MPI_Rput( jmp_buf * base_jbuf, mpip_const_void_t  *origin_addr, int  * origin_count, MPI_Datatype  * origin_datatype, int  * target_rank, MPI_Aint  * target_disp, int  * target_count, MPI_Datatype  * target_datatype, MPI_Win  * win, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Rput\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t origin_addr, int* origin_count, MPI_Datatype* origin_datatype, int* target_rank, MPI_Aint* target_disp, int* target_count, MPI_Datatype* target_datatype, MPI_Win* win, MPI_Request request )\n");
MPI_Type_size(*origin_datatype, &DT_size);
MPI_Type_size(*target_datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t origin_addr= %d, int origin_count= %d, MPI_Datatype origin_datatype= %d, int target_rank= %d, MPI_Aint target_disp= %d, int target_count= %d, MPI_Datatype target_datatype= %d, MPI_Win win= %d, MPI_Request request= %d, )\n", origin_addr, *origin_count, DT_size, *target_rank, *target_disp, *target_count, DT_size, *win, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Rput( origin_addr,  * origin_count,  * origin_datatype,  * target_rank,  * target_disp,  * target_count,  * target_datatype,  * win, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

PMPI_Type_size(*origin_datatype, &tsize);
rmaSize = (double)(tsize * *origin_count);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Rput");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Rput, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Rput */



extern int MPI_Rput ( mpip_const_void_t *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Rput( &jbuf, origin_addr,  & origin_count,  & origin_datatype,  & target_rank,  & target_disp,  & target_count,  & target_datatype,  & win, request );

return rc;
} /* MPI_Rput */


extern void F77_MPI_RPUT(mpip_const_void_t  *origin_addr, int  * origin_count, MPI_Fint  * origin_datatype, int  * target_rank, MPI_Aint  * target_disp, int  * target_count, MPI_Fint  * target_datatype, MPI_Win  * win, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_origin_datatype;
MPI_Datatype c_target_datatype;
MPI_Request c_request;

c_origin_datatype = MPI_Type_f2c(*origin_datatype);
c_target_datatype = MPI_Type_f2c(*target_datatype);
c_request = MPI_Request_f2c(*request);

rc = mpiPif_MPI_Rput( &jbuf, origin_addr, origin_count, &c_origin_datatype, target_rank, target_disp, target_count, &c_target_datatype, win, &c_request );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_rput */



/* --------------- MPI_Rsend --------------- */

static int mpiPif_MPI_Rsend( jmp_buf * base_jbuf, mpip_const_void_t  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * tag, MPI_Comm  * comm)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Rsend\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t buf, int* count, MPI_Datatype* datatype, int* dest, int* tag, MPI_Comm* comm )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t buf= %d, int count= %d, MPI_Datatype datatype= %d, int dest= %d, int tag= %d, MPI_Comm comm= %d, )\n", buf, *count, DT_size, *dest, *tag, *comm);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Rsend( buf,  * count,  * datatype,  * dest,  * tag,  * comm);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Rsend");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Rsend, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_pt2pt_stats_report) { mpiPi_update_pt2pt_stats(hndl, mpiPi_MPI_Rsend, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Rsend */



extern int MPI_Rsend ( mpip_const_void_t *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Rsend( &jbuf, buf,  & count,  & datatype,  & dest,  & tag,  & comm );

return rc;
} /* MPI_Rsend */


extern void F77_MPI_RSEND(mpip_const_void_t  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * tag, MPI_Fint  * comm , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Rsend( &jbuf, buf, count, &c_datatype, dest, tag, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_rsend */



/* --------------- MPI_Rsend_init --------------- */

static int mpiPif_MPI_Rsend_init( jmp_buf * base_jbuf, mpip_const_void_t  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * tag, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Rsend_init\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t buf, int* count, MPI_Datatype* datatype, int* dest, int* tag, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t buf= %d, int count= %d, MPI_Datatype datatype= %d, int dest= %d, int tag= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", buf, *count, DT_size, *dest, *tag, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Rsend_init( buf,  * count,  * datatype,  * dest,  * tag,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Rsend_init");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Rsend_init, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Rsend_init */



extern int MPI_Rsend_init ( mpip_const_void_t *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Rsend_init( &jbuf, buf,  & count,  & datatype,  & dest,  & tag,  & comm, request );

return rc;
} /* MPI_Rsend_init */


extern void F77_MPI_RSEND_INIT(mpip_const_void_t  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * tag, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Rsend_init( &jbuf, buf, count, &c_datatype, dest, tag, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_rsend_init */



/* --------------- MPI_Scan --------------- */

static int mpiPif_MPI_Scan( jmp_buf * base_jbuf, mpip_const_void_t  *sendbuf, void  *recvbuf, int  * count, MPI_Datatype  * datatype, MPI_Op  * op, MPI_Comm  * comm)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Scan\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t sendbuf, void recvbuf, int* count, MPI_Datatype* datatype, MPI_Op* op, MPI_Comm* comm )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t sendbuf= %d, void recvbuf= %d, int count= %d, MPI_Datatype datatype= %d, MPI_Op op= %d, MPI_Comm comm= %d, )\n", sendbuf, recvbuf, *count, DT_size, *op, *comm);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Scan( sendbuf, recvbuf,  * count,  * datatype,  * op,  * comm);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Scan");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Scan, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Scan */



extern int MPI_Scan ( mpip_const_void_t *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Scan( &jbuf, sendbuf, recvbuf,  & count,  & datatype,  & op,  & comm );

return rc;
} /* MPI_Scan */


extern void F77_MPI_SCAN(mpip_const_void_t  *sendbuf, void  *recvbuf, int  * count, MPI_Fint  * datatype, MPI_Fint  * op, MPI_Fint  * comm , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Op c_op;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_op = MPI_Op_f2c(*op);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Scan( &jbuf, sendbuf, recvbuf, count, &c_datatype, &c_op, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_scan */



/* --------------- MPI_Scatter --------------- */

static int mpiPif_MPI_Scatter( jmp_buf * base_jbuf, mpip_const_void_t  *sendbuf, int  * sendcnt, MPI_Datatype  * sendtype, void  *recvbuf, int  * recvcnt, MPI_Datatype  * recvtype, int  * root, MPI_Comm  * comm)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Scatter\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t sendbuf, int* sendcnt, MPI_Datatype* sendtype, void recvbuf, int* recvcnt, MPI_Datatype* recvtype, int* root, MPI_Comm* comm )\n");
MPI_Type_size(*sendtype, &DT_size);
MPI_Type_size(*recvtype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t sendbuf= %d, int sendcnt= %d, MPI_Datatype sendtype= %d, void recvbuf= %d, int recvcnt= %d, MPI_Datatype recvtype= %d, int root= %d, MPI_Comm comm= %d, )\n", sendbuf, *sendcnt, DT_size, recvbuf, *recvcnt, DT_size, *root, *comm);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Scatter( sendbuf,  * sendcnt,  * sendtype, recvbuf,  * recvcnt,  * recvtype,  * root,  * comm);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *sendtype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*sendtype, &tsize);
messSize = (double)(tsize * *sendcnt);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Scatter");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Scatter, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Scatter, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Scatter */



extern int MPI_Scatter ( mpip_const_void_t *sendbuf, int sendcnt, MPI_Datatype sendtype, void *recvbuf, int recvcnt, MPI_Datatype recvtype, int root, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Scatter( &jbuf, sendbuf,  & sendcnt,  & sendtype, recvbuf,  & recvcnt,  & recvtype,  & root,  & comm );

return rc;
} /* MPI_Scatter */


extern void F77_MPI_SCATTER(mpip_const_void_t  *sendbuf, int  * sendcnt, MPI_Fint  * sendtype, void  *recvbuf, int  * recvcnt, MPI_Fint  * recvtype, int  * root, MPI_Fint  * comm , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Scatter( &jbuf, sendbuf, sendcnt, &c_sendtype, recvbuf, recvcnt, &c_recvtype, root, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_scatter */



/* --------------- MPI_Scatterv --------------- */

static int mpiPif_MPI_Scatterv( jmp_buf * base_jbuf, mpip_const_void_t  *sendbuf, mpip_const_int_t  *sendcnts, mpip_const_int_t  *displs, MPI_Datatype  * sendtype, void  *recvbuf, int  * recvcnt, MPI_Datatype  * recvtype, int  * root, MPI_Comm  * comm)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Scatterv\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t sendbuf, mpip_const_int_t sendcnts, mpip_const_int_t displs, MPI_Datatype* sendtype, void recvbuf, int* recvcnt, MPI_Datatype* recvtype, int* root, MPI_Comm* comm )\n");
MPI_Type_size(*sendtype, &DT_size);
MPI_Type_size(*recvtype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t sendbuf= %d, mpip_const_int_t sendcnts= %d, mpip_const_int_t displs= %d, MPI_Datatype sendtype= %d, void recvbuf= %d, int recvcnt= %d, MPI_Datatype recvtype= %d, int root= %d, MPI_Comm comm= %d, )\n", sendbuf, sendcnts, displs, DT_size, recvbuf, *recvcnt, DT_size, *root, *comm);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Scatterv( sendbuf, sendcnts, displs,  * sendtype, recvbuf,  * recvcnt,  * recvtype,  * root,  * comm);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Scatterv");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Scatterv, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_collective_stats_report) { mpiPi_update_collective_stats(hndl, mpiPi_MPI_Scatterv, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Scatterv */



extern int MPI_Scatterv ( mpip_const_void_t *sendbuf, mpip_const_int_t *sendcnts, mpip_const_int_t *displs, MPI_Datatype sendtype, void *recvbuf, int recvcnt, MPI_Datatype recvtype, int root, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Scatterv( &jbuf, sendbuf, sendcnts, displs,  & sendtype, recvbuf,  & recvcnt,  & recvtype,  & root,  & comm );

return rc;
} /* MPI_Scatterv */


extern void F77_MPI_SCATTERV(mpip_const_void_t  *sendbuf, mpip_const_int_t  *sendcnts, mpip_const_int_t  *displs, MPI_Fint  * sendtype, void  *recvbuf, int  * recvcnt, MPI_Fint  * recvtype, int  * root, MPI_Fint  * comm , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Scatterv( &jbuf, sendbuf, sendcnts, displs, &c_sendtype, recvbuf, recvcnt, &c_recvtype, root, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_scatterv */



/* --------------- MPI_Send --------------- */

static int mpiPif_MPI_Send( jmp_buf * base_jbuf, mpip_const_void_t  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * tag, MPI_Comm  * comm)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Send\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t buf, int* count, MPI_Datatype* datatype, int* dest, int* tag, MPI_Comm* comm )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t buf= %d, int count= %d, MPI_Datatype datatype= %d, int dest= %d, int tag= %d, MPI_Comm comm= %d, )\n", buf, *count, DT_size, *dest, *tag, *comm);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Send( buf,  * count,  * datatype,  * dest,  * tag,  * comm);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Send");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Send, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_pt2pt_stats_report) { mpiPi_update_pt2pt_stats(hndl, mpiPi_MPI_Send, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Send */



extern int MPI_Send ( mpip_const_void_t *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Send( &jbuf, buf,  & count,  & datatype,  & dest,  & tag,  & comm );

return rc;
} /* MPI_Send */


extern void F77_MPI_SEND(mpip_const_void_t  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * tag, MPI_Fint  * comm , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Send( &jbuf, buf, count, &c_datatype, dest, tag, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_send */



/* --------------- MPI_Send_init --------------- */

static int mpiPif_MPI_Send_init( jmp_buf * base_jbuf, mpip_const_void_t  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * tag, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Send_init\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t buf, int* count, MPI_Datatype* datatype, int* dest, int* tag, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t buf= %d, int count= %d, MPI_Datatype datatype= %d, int dest= %d, int tag= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", buf, *count, DT_size, *dest, *tag, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Send_init( buf,  * count,  * datatype,  * dest,  * tag,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Send_init");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Send_init, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Send_init */



extern int MPI_Send_init ( mpip_const_void_t *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Send_init( &jbuf, buf,  & count,  & datatype,  & dest,  & tag,  & comm, request );

return rc;
} /* MPI_Send_init */


extern void F77_MPI_SEND_INIT(mpip_const_void_t  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * tag, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Send_init( &jbuf, buf, count, &c_datatype, dest, tag, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_send_init */



/* --------------- MPI_Sendrecv --------------- */

static int mpiPif_MPI_Sendrecv( jmp_buf * base_jbuf, mpip_const_void_t  *sendbuf, int  * sendcount, MPI_Datatype  * sendtype, int  * dest, int  * sendtag, void  *recvbuf, int  * recvcount, MPI_Datatype  * recvtype, int  * source, int  * recvtag, MPI_Comm  * comm, MPI_Status  *status)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Sendrecv\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t sendbuf, int* sendcount, MPI_Datatype* sendtype, int* dest, int* sendtag, void recvbuf, int* recvcount, MPI_Datatype* recvtype, int* source, int* recvtag, MPI_Comm* comm, MPI_Status status )\n");
MPI_Type_size(*sendtype, &DT_size);
MPI_Type_size(*recvtype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t sendbuf= %d, int sendcount= %d, MPI_Datatype sendtype= %d, int dest= %d, int sendtag= %d, void recvbuf= %d, int recvcount= %d, MPI_Datatype recvtype= %d, int source= %d, int recvtag= %d, MPI_Comm comm= %d, MPI_Status status= %d, )\n", sendbuf, *sendcount, DT_size, *dest, *sendtag, recvbuf, *recvcount, DT_size, *source, *recvtag, *comm, status);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Sendrecv( sendbuf,  * sendcount,  * sendtype,  * dest,  * sendtag, recvbuf,  * recvcount,  * recvtype,  * source,  * recvtag,  * comm, status);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *sendtype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*sendtype, &tsize);
messSize = (double)(tsize * *sendcount);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Sendrecv");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Sendrecv, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_pt2pt_stats_report) { mpiPi_update_pt2pt_stats(hndl, mpiPi_MPI_Sendrecv, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Sendrecv */



extern int MPI_Sendrecv ( mpip_const_void_t *sendbuf, int sendcount, MPI_Datatype sendtype, int dest, int sendtag, void *recvbuf, int recvcount, MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm, MPI_Status *status )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Sendrecv( &jbuf, sendbuf,  & sendcount,  & sendtype,  & dest,  & sendtag, recvbuf,  & recvcount,  & recvtype,  & source,  & recvtag,  & comm, status );

return rc;
} /* MPI_Sendrecv */


extern void F77_MPI_SENDRECV(mpip_const_void_t  *sendbuf, int  * sendcount, MPI_Fint  * sendtype, int  * dest, int  * sendtag, void  *recvbuf, int  * recvcount, MPI_Fint  * recvtype, int  * source, int  * recvtag, MPI_Fint  * comm, MPI_Status  *status , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Sendrecv( &jbuf, sendbuf, sendcount, &c_sendtype, dest, sendtag, recvbuf, recvcount, &c_recvtype, source, recvtag, &c_comm, status );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_sendrecv */



/* --------------- MPI_Sendrecv_replace --------------- */

static int mpiPif_MPI_Sendrecv_replace( jmp_buf * base_jbuf, void  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * sendtag, int  * source, int  * recvtag, MPI_Comm  * comm, MPI_Status  *status)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Sendrecv_replace\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( void buf, int* count, MPI_Datatype* datatype, int* dest, int* sendtag, int* source, int* recvtag, MPI_Comm* comm, MPI_Status status )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (void buf= %d, int count= %d, MPI_Datatype datatype= %d, int dest= %d, int sendtag= %d, int source= %d, int recvtag= %d, MPI_Comm comm= %d, MPI_Status status= %d, )\n", buf, *count, DT_size, *dest, *sendtag, *source, *recvtag, *comm, status);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Sendrecv_replace( buf,  * count,  * datatype,  * dest,  * sendtag,  * source,  * recvtag,  * comm, status);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Sendrecv_replace");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Sendrecv_replace, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_pt2pt_stats_report) { mpiPi_update_pt2pt_stats(hndl, mpiPi_MPI_Sendrecv_replace, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Sendrecv_replace */



extern int MPI_Sendrecv_replace ( void *buf, int count, MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag, MPI_Comm comm, MPI_Status *status )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Sendrecv_replace( &jbuf, buf,  & count,  & datatype,  & dest,  & sendtag,  & source,  & recvtag,  & comm, status );

return rc;
} /* MPI_Sendrecv_replace */


extern void F77_MPI_SENDRECV_REPLACE(void  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * sendtag, int  * source, int  * recvtag, MPI_Fint  * comm, MPI_Status  *status , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Sendrecv_replace( &jbuf, buf, count, &c_datatype, dest, sendtag, source, recvtag, &c_comm, status );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_sendrecv_replace */



/* --------------- MPI_Ssend --------------- */

static int mpiPif_MPI_Ssend( jmp_buf * base_jbuf, mpip_const_void_t  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * tag, MPI_Comm  * comm)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Ssend\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t buf, int* count, MPI_Datatype* datatype, int* dest, int* tag, MPI_Comm* comm )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t buf= %d, int count= %d, MPI_Datatype datatype= %d, int dest= %d, int tag= %d, MPI_Comm comm= %d, )\n", buf, *count, DT_size, *dest, *tag, *comm);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Ssend( buf,  * count,  * datatype,  * dest,  * tag,  * comm);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Ssend");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Ssend, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);

if (mpiPi.do_pt2pt_stats_report) { mpiPi_update_pt2pt_stats(hndl, mpiPi_MPI_Ssend, dur, (double)messSize, comm); }
}

return rc;
} /* MPI_Ssend */



extern int MPI_Ssend ( mpip_const_void_t *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Ssend( &jbuf, buf,  & count,  & datatype,  & dest,  & tag,  & comm );

return rc;
} /* MPI_Ssend */


extern void F77_MPI_SSEND(mpip_const_void_t  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * tag, MPI_Fint  * comm , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Ssend( &jbuf, buf, count, &c_datatype, dest, tag, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_ssend */



/* --------------- MPI_Ssend_init --------------- */

static int mpiPif_MPI_Ssend_init( jmp_buf * base_jbuf, mpip_const_void_t  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * tag, MPI_Comm  * comm, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Ssend_init\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t buf, int* count, MPI_Datatype* datatype, int* dest, int* tag, MPI_Comm* comm, MPI_Request request )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t buf= %d, int count= %d, MPI_Datatype datatype= %d, int dest= %d, int tag= %d, MPI_Comm comm= %d, MPI_Request request= %d, )\n", buf, *count, DT_size, *dest, *tag, *comm, request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Ssend_init( buf,  * count,  * datatype,  * dest,  * tag,  * comm, request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Ssend_init");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Ssend_init, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Ssend_init */



extern int MPI_Ssend_init ( mpip_const_void_t *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Ssend_init( &jbuf, buf,  & count,  & datatype,  & dest,  & tag,  & comm, request );

return rc;
} /* MPI_Ssend_init */


extern void F77_MPI_SSEND_INIT(mpip_const_void_t  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * tag, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Ssend_init( &jbuf, buf, count, &c_datatype, dest, tag, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_ssend_init */



/* --------------- MPI_Start --------------- */

static int mpiPif_MPI_Start( jmp_buf * base_jbuf, MPI_Request  *request)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Start\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Request request )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Request request= %d, )\n", request);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Start( request);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Start");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Start, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Start */



extern int MPI_Start ( MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Start( &jbuf, request );

return rc;
} /* MPI_Start */


extern void F77_MPI_START(MPI_Fint  *request , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Request c_request;

c_request = MPI_Request_f2c(*request);

rc = mpiPif_MPI_Start( &jbuf, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_start */



/* --------------- MPI_Startall --------------- */

static int mpiPif_MPI_Startall( jmp_buf * base_jbuf, int  * count, MPI_Request  *array_of_requests)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Startall\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( int* count, MPI_Request array_of_requests )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (int count= %d, MPI_Request array_of_requests= %d, )\n", *count, array_of_requests);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Startall(  * count, array_of_requests);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Startall");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Startall, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Startall */



extern int MPI_Startall ( int count, MPI_Request *array_of_requests )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Startall( &jbuf,  & count, array_of_requests );

return rc;
} /* MPI_Startall */


extern void F77_MPI_STARTALL(int  * count, MPI_Fint  *array_of_requests , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Request *c_array_of_requests;

c_array_of_requests = (MPI_Request*)malloc(sizeof(MPI_Request)*(*count));
if ( c_array_of_requests == NULL ) mpiPi_abort("Failed to allocate memory in MPI_Startall");
{
  int i; 
  for (i = 0; i < *count; i++) { 
    c_array_of_requests[i] = MPI_Request_f2c(array_of_requests[i]);
  }
}

rc = mpiPif_MPI_Startall( &jbuf, count, c_array_of_requests );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
{
  int i; 
  for (i = 0; i < *count; i++) { 
    array_of_requests[i] = MPI_Request_c2f(c_array_of_requests[i]);
  }
}
}
free(c_array_of_requests);
return;
} /* mpi_startall */



/* --------------- MPI_Test --------------- */

static int mpiPif_MPI_Test( jmp_buf * base_jbuf, MPI_Request  *request, int  *flag, MPI_Status  *status)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Test\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Request request, int flag, MPI_Status status )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Request request= %d, int flag= %d, MPI_Status status= %d, )\n", request, flag, status);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Test( request, flag, status);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Test");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Test, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Test */



extern int MPI_Test ( MPI_Request *request, int *flag, MPI_Status *status )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Test( &jbuf, request, flag, status );

return rc;
} /* MPI_Test */


extern void F77_MPI_TEST(MPI_Fint  *request, int  *flag, MPI_Status  *status , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Request c_request;

c_request = MPI_Request_f2c(*request);

rc = mpiPif_MPI_Test( &jbuf, &c_request, flag, status );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_test */



/* --------------- MPI_Testall --------------- */

static int mpiPif_MPI_Testall( jmp_buf * base_jbuf, int  * count, MPI_Request  *array_of_requests, int  *flag, MPI_Status  *array_of_statuses)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Testall\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( int* count, MPI_Request array_of_requests, int flag, MPI_Status array_of_statuses )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (int count= %d, MPI_Request array_of_requests= %d, int flag= %d, MPI_Status array_of_statuses= %d, )\n", *count, array_of_requests, flag, array_of_statuses);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Testall(  * count, array_of_requests, flag, array_of_statuses);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Testall");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Testall, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Testall */



extern int MPI_Testall ( int count, MPI_Request *array_of_requests, int *flag, MPI_Status *array_of_statuses )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Testall( &jbuf,  & count, array_of_requests, flag, array_of_statuses );

return rc;
} /* MPI_Testall */


extern void F77_MPI_TESTALL(int  * count, MPI_Fint  *array_of_requests, int  *flag, MPI_Status  *array_of_statuses , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Request *c_array_of_requests;

c_array_of_requests = (MPI_Request*)malloc(sizeof(MPI_Request)*(*count));
if ( c_array_of_requests == NULL ) mpiPi_abort("Failed to allocate memory in MPI_Testall");
{
  int i; 
  for (i = 0; i < *count; i++) { 
    c_array_of_requests[i] = MPI_Request_f2c(array_of_requests[i]);
  }
}

rc = mpiPif_MPI_Testall( &jbuf, count, c_array_of_requests, flag, array_of_statuses );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
{
  int i; 
  for (i = 0; i < *count; i++) { 
    array_of_requests[i] = MPI_Request_c2f(c_array_of_requests[i]);
  }
}
}
free(c_array_of_requests);
return;
} /* mpi_testall */



/* --------------- MPI_Testany --------------- */

static int mpiPif_MPI_Testany( jmp_buf * base_jbuf, int  * count, MPI_Request  *array_of_requests, int  *index, int  *flag, MPI_Status  *status)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Testany\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( int* count, MPI_Request array_of_requests, int index, int flag, MPI_Status status )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (int count= %d, MPI_Request array_of_requests= %d, int index= %d, int flag= %d, MPI_Status status= %d, )\n", *count, array_of_requests, index, flag, status);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Testany(  * count, array_of_requests, index, flag, status);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Testany");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Testany, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Testany */



extern int MPI_Testany ( int count, MPI_Request *array_of_requests, int *index, int *flag, MPI_Status *status )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Testany( &jbuf,  & count, array_of_requests, index, flag, status );

return rc;
} /* MPI_Testany */


extern void F77_MPI_TESTANY(int  * count, MPI_Fint  *array_of_requests, int  *index, int  *flag, MPI_Status  *status , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Request *c_array_of_requests;

c_array_of_requests = (MPI_Request*)malloc(sizeof(MPI_Request)*(*count));
if ( c_array_of_requests == NULL ) mpiPi_abort("Failed to allocate memory in MPI_Testany");
{
  int i; 
  for (i = 0; i < *count; i++) { 
    c_array_of_requests[i] = MPI_Request_f2c(array_of_requests[i]);
  }
}

rc = mpiPif_MPI_Testany( &jbuf, count, c_array_of_requests, index, flag, status );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
array_of_requests[*index] = MPI_Request_c2f(c_array_of_requests[*index]);
if ( *index >= 0 ) (*index)++;
}
free(c_array_of_requests);
return;
} /* mpi_testany */



/* --------------- MPI_Testsome --------------- */

static int mpiPif_MPI_Testsome( jmp_buf * base_jbuf, int  * incount, MPI_Request  *array_of_requests, int  *count, int  *array_of_indices, MPI_Status  *array_of_statuses)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Testsome\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( int* incount, MPI_Request array_of_requests, int count, int array_of_indices, MPI_Status array_of_statuses )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (int incount= %d, MPI_Request array_of_requests= %d, int count= %d, int array_of_indices= %d, MPI_Status array_of_statuses= %d, )\n", *incount, array_of_requests, count, array_of_indices, array_of_statuses);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Testsome(  * incount, array_of_requests, count, array_of_indices, array_of_statuses);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Testsome");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Testsome, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Testsome */



extern int MPI_Testsome ( int incount, MPI_Request *array_of_requests, int *count, int *array_of_indices, MPI_Status *array_of_statuses )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Testsome( &jbuf,  & incount, array_of_requests, count, array_of_indices, array_of_statuses );

return rc;
} /* MPI_Testsome */


extern void F77_MPI_TESTSOME(int  * incount, MPI_Fint  *array_of_requests, int  *count, int  *array_of_indices, MPI_Status  *array_of_statuses , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Request *c_array_of_requests;

c_array_of_requests = (MPI_Request*)malloc(sizeof(MPI_Request)*(*incount));
if ( c_array_of_requests == NULL ) mpiPi_abort("Failed to allocate memory in MPI_Testsome");
{
  int i; 
  for (i = 0; i < *incount; i++) { 
    c_array_of_requests[i] = MPI_Request_f2c(array_of_requests[i]);
  }
}

rc = mpiPif_MPI_Testsome( &jbuf, incount, c_array_of_requests, count, array_of_indices, array_of_statuses );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
{
  int i; 
  for (i = 0; i < *incount; i++) { 
    array_of_requests[i] = MPI_Request_c2f(c_array_of_requests[i]);
  }
}
{ int i; for ( i = 0; i < *count; i++)  array_of_indices[i]++;}
}
free(c_array_of_requests);
return;
} /* mpi_testsome */



/* --------------- MPI_Topo_test --------------- */

static int mpiPif_MPI_Topo_test( jmp_buf * base_jbuf, MPI_Comm  * comm, int  *top_type)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Topo_test\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Comm* comm, int top_type )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Comm comm= %d, int top_type= %d, )\n", *comm, top_type);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Topo_test(  * comm, top_type);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Topo_test");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Topo_test, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Topo_test */



extern int MPI_Topo_test ( MPI_Comm comm, int *top_type )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Topo_test( &jbuf,  & comm, top_type );

return rc;
} /* MPI_Topo_test */


extern void F77_MPI_TOPO_TEST(MPI_Fint  * comm, int  *top_type , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Topo_test( &jbuf, &c_comm, top_type );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_topo_test */



/* --------------- MPI_Type_commit --------------- */

static int mpiPif_MPI_Type_commit( jmp_buf * base_jbuf, MPI_Datatype  *datatype)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Type_commit\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Datatype datatype )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Datatype datatype= %d, )\n", DT_size);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Type_commit( datatype);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Type_commit");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Type_commit, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Type_commit */



extern int MPI_Type_commit ( MPI_Datatype *datatype )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Type_commit( &jbuf, datatype );

return rc;
} /* MPI_Type_commit */


extern void F77_MPI_TYPE_COMMIT(MPI_Fint  *datatype , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;

c_datatype = MPI_Type_f2c(*datatype);

rc = mpiPif_MPI_Type_commit( &jbuf, &c_datatype );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*datatype = MPI_Type_c2f(c_datatype);
}
return;
} /* mpi_type_commit */



/* --------------- MPI_Type_free --------------- */

static int mpiPif_MPI_Type_free( jmp_buf * base_jbuf, MPI_Datatype  *datatype)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Type_free\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Datatype datatype )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Datatype datatype= %d, )\n", DT_size);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Type_free( datatype);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Type_free");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Type_free, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Type_free */



extern int MPI_Type_free ( MPI_Datatype *datatype )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Type_free( &jbuf, datatype );

return rc;
} /* MPI_Type_free */


extern void F77_MPI_TYPE_FREE(MPI_Fint  *datatype , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;

c_datatype = MPI_Type_f2c(*datatype);

rc = mpiPif_MPI_Type_free( &jbuf, &c_datatype );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*datatype = MPI_Type_c2f(c_datatype);
}
return;
} /* mpi_type_free */



/* --------------- MPI_Type_get_contents --------------- */

static int mpiPif_MPI_Type_get_contents( jmp_buf * base_jbuf, MPI_Datatype  * datatype, int  * max_integers, int  * max_addresses, int  * max_datatypes, int  *array_of_integers, MPI_Aint  *array_of_addresses, MPI_Datatype  *array_of_datatypes)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Type_get_contents\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Datatype* datatype, int* max_integers, int* max_addresses, int* max_datatypes, int array_of_integers, MPI_Aint array_of_addresses, MPI_Datatype array_of_datatypes )\n");
MPI_Type_size(*datatype, &DT_size);
MPI_Type_size(*array_of_datatypes, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Datatype datatype= %d, int max_integers= %d, int max_addresses= %d, int max_datatypes= %d, int array_of_integers= %d, MPI_Aint array_of_addresses= %d, MPI_Datatype array_of_datatypes= %d, )\n", DT_size, *max_integers, *max_addresses, *max_datatypes, array_of_integers, array_of_addresses, DT_size);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Type_get_contents(  * datatype,  * max_integers,  * max_addresses,  * max_datatypes, array_of_integers, array_of_addresses, array_of_datatypes);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Type_get_contents");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Type_get_contents, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Type_get_contents */



extern int MPI_Type_get_contents ( MPI_Datatype datatype, int max_integers, int max_addresses, int max_datatypes, int *array_of_integers, MPI_Aint *array_of_addresses, MPI_Datatype *array_of_datatypes )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Type_get_contents( &jbuf,  & datatype,  & max_integers,  & max_addresses,  & max_datatypes, array_of_integers, array_of_addresses, array_of_datatypes );

return rc;
} /* MPI_Type_get_contents */


extern void F77_MPI_TYPE_GET_CONTENTS(MPI_Fint  * datatype, int  * max_integers, int  * max_addresses, int  * max_datatypes, int  *array_of_integers, MPI_Aint  *array_of_addresses, MPI_Fint  *array_of_datatypes , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Datatype *c_array_of_datatypes;

c_array_of_datatypes = (MPI_Datatype*)malloc(sizeof(MPI_Datatype)*(*max_integers));
if ( c_array_of_datatypes == NULL ) mpiPi_abort("Failed to allocate memory in MPI_Type_get_contents");
c_datatype = MPI_Type_f2c(*datatype);

rc = mpiPif_MPI_Type_get_contents( &jbuf, &c_datatype, max_integers, max_addresses, max_datatypes, array_of_integers, array_of_addresses, c_array_of_datatypes );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
{
  int i; 
  for (i = 0; i < *max_integers; i++) { 
    array_of_datatypes[i] = MPI_Type_c2f(c_array_of_datatypes[i]);
  }
}
}
free(c_array_of_datatypes);
return;
} /* mpi_type_get_contents */



/* --------------- MPI_Type_get_envelope --------------- */

static int mpiPif_MPI_Type_get_envelope( jmp_buf * base_jbuf, MPI_Datatype  * datatype, int  *num_integers, int  *num_addresses, int  *num_datatypes, int  *combiner)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Type_get_envelope\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Datatype* datatype, int num_integers, int num_addresses, int num_datatypes, int combiner )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Datatype datatype= %d, int num_integers= %d, int num_addresses= %d, int num_datatypes= %d, int combiner= %d, )\n", DT_size, num_integers, num_addresses, num_datatypes, combiner);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Type_get_envelope(  * datatype, num_integers, num_addresses, num_datatypes, combiner);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Type_get_envelope");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Type_get_envelope, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Type_get_envelope */



extern int MPI_Type_get_envelope ( MPI_Datatype datatype, int *num_integers, int *num_addresses, int *num_datatypes, int *combiner )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Type_get_envelope( &jbuf,  & datatype, num_integers, num_addresses, num_datatypes, combiner );

return rc;
} /* MPI_Type_get_envelope */


extern void F77_MPI_TYPE_GET_ENVELOPE(MPI_Fint  * datatype, int  *num_integers, int  *num_addresses, int  *num_datatypes, int  *combiner , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;

c_datatype = MPI_Type_f2c(*datatype);

rc = mpiPif_MPI_Type_get_envelope( &jbuf, &c_datatype, num_integers, num_addresses, num_datatypes, combiner );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_type_get_envelope */



/* --------------- MPI_Unpack --------------- */

static int mpiPif_MPI_Unpack( jmp_buf * base_jbuf, mpip_const_void_t  *inbuf, int  * insize, int  *position, void  *outbuf, int  * count, MPI_Datatype  * datatype, MPI_Comm  * comm)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Unpack\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( mpip_const_void_t inbuf, int* insize, int position, void outbuf, int* count, MPI_Datatype* datatype, MPI_Comm* comm )\n");
MPI_Type_size(*datatype, &DT_size);
fprintf(mpiPi.recfile, "Trace: Paravalues: = (mpip_const_void_t inbuf= %d, int insize= %d, int position= %d, void outbuf= %d, int count= %d, MPI_Datatype datatype= %d, MPI_Comm comm= %d, )\n", inbuf, *insize, position, outbuf, *count, DT_size, *comm);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Unpack( inbuf,  * insize, position, outbuf,  * count,  * datatype,  * comm);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Unpack");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Unpack, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Unpack */



extern int MPI_Unpack ( mpip_const_void_t *inbuf, int insize, int *position, void *outbuf, int count, MPI_Datatype datatype, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Unpack( &jbuf, inbuf,  & insize, position, outbuf,  & count,  & datatype,  & comm );

return rc;
} /* MPI_Unpack */


extern void F77_MPI_UNPACK(mpip_const_void_t  *inbuf, int  * insize, int  *position, void  *outbuf, int  * count, MPI_Fint  * datatype, MPI_Fint  * comm , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Unpack( &jbuf, inbuf, insize, position, outbuf, count, &c_datatype, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_unpack */



/* --------------- MPI_Wait --------------- */

static int mpiPif_MPI_Wait( jmp_buf * base_jbuf, MPI_Request  *request, MPI_Status  *status)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Wait\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Request request, MPI_Status status )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Request request= %d, MPI_Status status= %d, )\n", request, status);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Wait( request, status);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Wait");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Wait, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Wait */



extern int MPI_Wait ( MPI_Request *request, MPI_Status *status )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Wait( &jbuf, request, status );

return rc;
} /* MPI_Wait */


extern void F77_MPI_WAIT(MPI_Fint  *request, MPI_Status  *status , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Request c_request;

c_request = MPI_Request_f2c(*request);

rc = mpiPif_MPI_Wait( &jbuf, &c_request, status );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_wait */



/* --------------- MPI_Waitall --------------- */

static int mpiPif_MPI_Waitall( jmp_buf * base_jbuf, int  * count, MPI_Request  *array_of_requests, MPI_Status  *array_of_statuses)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Waitall\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( int* count, MPI_Request array_of_requests, MPI_Status array_of_statuses )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (int count= %d, MPI_Request array_of_requests= %d, MPI_Status array_of_statuses= %d, )\n", *count, array_of_requests, array_of_statuses);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Waitall(  * count, array_of_requests, array_of_statuses);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Waitall");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Waitall, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Waitall */



extern int MPI_Waitall ( int count, MPI_Request *array_of_requests, MPI_Status *array_of_statuses )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Waitall( &jbuf,  & count, array_of_requests, array_of_statuses );

return rc;
} /* MPI_Waitall */


extern void F77_MPI_WAITALL(int  * count, MPI_Fint  *array_of_requests, MPI_Status  *array_of_statuses , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Request *c_array_of_requests;

c_array_of_requests = (MPI_Request*)malloc(sizeof(MPI_Request)*(*count));
if ( c_array_of_requests == NULL ) mpiPi_abort("Failed to allocate memory in MPI_Waitall");
{
  int i; 
  for (i = 0; i < *count; i++) { 
    c_array_of_requests[i] = MPI_Request_f2c(array_of_requests[i]);
  }
}

rc = mpiPif_MPI_Waitall( &jbuf, count, c_array_of_requests, array_of_statuses );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
{
  int i; 
  for (i = 0; i < *count; i++) { 
    array_of_requests[i] = MPI_Request_c2f(c_array_of_requests[i]);
  }
}
}
free(c_array_of_requests);
return;
} /* mpi_waitall */



/* --------------- MPI_Waitany --------------- */

static int mpiPif_MPI_Waitany( jmp_buf * base_jbuf, int  * count, MPI_Request  *array_of_requests, int  *index, MPI_Status  *status)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Waitany\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( int* count, MPI_Request array_of_requests, int index, MPI_Status status )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (int count= %d, MPI_Request array_of_requests= %d, int index= %d, MPI_Status status= %d, )\n", *count, array_of_requests, index, status);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Waitany(  * count, array_of_requests, index, status);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Waitany");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Waitany, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Waitany */



extern int MPI_Waitany ( int count, MPI_Request *array_of_requests, int *index, MPI_Status *status )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Waitany( &jbuf,  & count, array_of_requests, index, status );

return rc;
} /* MPI_Waitany */


extern void F77_MPI_WAITANY(int  * count, MPI_Fint  *array_of_requests, int  *index, MPI_Status  *status , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Request *c_array_of_requests;

c_array_of_requests = (MPI_Request*)malloc(sizeof(MPI_Request)*(*count));
if ( c_array_of_requests == NULL ) mpiPi_abort("Failed to allocate memory in MPI_Waitany");
{
  int i; 
  for (i = 0; i < *count; i++) { 
    c_array_of_requests[i] = MPI_Request_f2c(array_of_requests[i]);
  }
}

rc = mpiPif_MPI_Waitany( &jbuf, count, c_array_of_requests, index, status );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
array_of_requests[*index] = MPI_Request_c2f(c_array_of_requests[*index]);
if ( *index >= 0 ) (*index)++;
}
free(c_array_of_requests);
return;
} /* mpi_waitany */



/* --------------- MPI_Waitsome --------------- */

static int mpiPif_MPI_Waitsome( jmp_buf * base_jbuf, int  * incount, MPI_Request  *array_of_requests, int  *count, int  *array_of_indices, MPI_Status  *array_of_statuses)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Waitsome\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( int* incount, MPI_Request array_of_requests, int count, int array_of_indices, MPI_Status array_of_statuses )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (int incount= %d, MPI_Request array_of_requests= %d, int count= %d, int array_of_indices= %d, MPI_Status array_of_statuses= %d, )\n", *incount, array_of_requests, count, array_of_indices, array_of_statuses);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Waitsome(  * incount, array_of_requests, count, array_of_indices, array_of_statuses);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Waitsome");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Waitsome, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Waitsome */



extern int MPI_Waitsome ( int incount, MPI_Request *array_of_requests, int *count, int *array_of_indices, MPI_Status *array_of_statuses )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Waitsome( &jbuf,  & incount, array_of_requests, count, array_of_indices, array_of_statuses );

return rc;
} /* MPI_Waitsome */


extern void F77_MPI_WAITSOME(int  * incount, MPI_Fint  *array_of_requests, int  *count, int  *array_of_indices, MPI_Status  *array_of_statuses , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Request *c_array_of_requests;

c_array_of_requests = (MPI_Request*)malloc(sizeof(MPI_Request)*(*incount));
if ( c_array_of_requests == NULL ) mpiPi_abort("Failed to allocate memory in MPI_Waitsome");
{
  int i; 
  for (i = 0; i < *incount; i++) { 
    c_array_of_requests[i] = MPI_Request_f2c(array_of_requests[i]);
  }
}

rc = mpiPif_MPI_Waitsome( &jbuf, incount, c_array_of_requests, count, array_of_indices, array_of_statuses );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
{
  int i; 
  for (i = 0; i < *incount; i++) { 
    array_of_requests[i] = MPI_Request_c2f(c_array_of_requests[i]);
  }
}
{ int i; for ( i = 0; i < *count; i++)  array_of_indices[i]++;}
}
free(c_array_of_requests);
return;
} /* mpi_waitsome */



/* --------------- MPI_Win_allocate --------------- */

static int mpiPif_MPI_Win_allocate( jmp_buf * base_jbuf, MPI_Aint  * size, int  * disp_unit, MPI_Info  * info, MPI_Comm  * comm, void  *baseptr, MPI_Win  *win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_allocate\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Aint* size, int* disp_unit, MPI_Info* info, MPI_Comm* comm, void baseptr, MPI_Win win )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Aint size= %d, int disp_unit= %d, MPI_Info info= %d, MPI_Comm comm= %d, void baseptr= %d, MPI_Win win= %d, )\n", *size, *disp_unit, *info, *comm, baseptr, win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_allocate(  * size,  * disp_unit,  * info,  * comm, baseptr, win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_allocate");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_allocate, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_allocate */



extern int MPI_Win_allocate ( MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_allocate( &jbuf,  & size,  & disp_unit,  & info,  & comm, baseptr, win );

return rc;
} /* MPI_Win_allocate */


extern void F77_MPI_WIN_ALLOCATE(MPI_Aint  * size, int  * disp_unit, MPI_Fint  * info, MPI_Fint  * comm, void  *baseptr, MPI_Win  *win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Info c_info;
MPI_Comm c_comm;

c_info = MPI_Info_f2c(*info);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Win_allocate( &jbuf, size, disp_unit, &c_info, &c_comm, baseptr, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_allocate */



/* --------------- MPI_Win_allocate_shared --------------- */

static int mpiPif_MPI_Win_allocate_shared( jmp_buf * base_jbuf, MPI_Aint  * size, int  * disp_unit, MPI_Info  * info, MPI_Comm  * comm, void  *baseptr, MPI_Win  *win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_allocate_shared\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Aint* size, int* disp_unit, MPI_Info* info, MPI_Comm* comm, void baseptr, MPI_Win win )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Aint size= %d, int disp_unit= %d, MPI_Info info= %d, MPI_Comm comm= %d, void baseptr= %d, MPI_Win win= %d, )\n", *size, *disp_unit, *info, *comm, baseptr, win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_allocate_shared(  * size,  * disp_unit,  * info,  * comm, baseptr, win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_allocate_shared");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_allocate_shared, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_allocate_shared */



extern int MPI_Win_allocate_shared ( MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_allocate_shared( &jbuf,  & size,  & disp_unit,  & info,  & comm, baseptr, win );

return rc;
} /* MPI_Win_allocate_shared */


extern void F77_MPI_WIN_ALLOCATE_SHARED(MPI_Aint  * size, int  * disp_unit, MPI_Fint  * info, MPI_Fint  * comm, void  *baseptr, MPI_Win  *win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Info c_info;
MPI_Comm c_comm;

c_info = MPI_Info_f2c(*info);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Win_allocate_shared( &jbuf, size, disp_unit, &c_info, &c_comm, baseptr, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_allocate_shared */



/* --------------- MPI_Win_attach --------------- */

static int mpiPif_MPI_Win_attach( jmp_buf * base_jbuf, MPI_Win  * win, void  *base, MPI_Aint  * size)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_attach\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Win* win, void base, MPI_Aint* size )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Win win= %d, void base= %d, MPI_Aint size= %d, )\n", *win, base, *size);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_attach(  * win, base,  * size);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_attach");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_attach, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_attach */



extern int MPI_Win_attach ( MPI_Win win, void *base, MPI_Aint size )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_attach( &jbuf,  & win, base,  & size );

return rc;
} /* MPI_Win_attach */


extern void F77_MPI_WIN_ATTACH(MPI_Win  * win, void  *base, MPI_Aint  * size , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Win_attach( &jbuf, win, base, size );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_attach */



/* --------------- MPI_Win_complete --------------- */

static int mpiPif_MPI_Win_complete( jmp_buf * base_jbuf, MPI_Win  * win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_complete\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Win* win )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Win win= %d, )\n", *win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_complete(  * win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_complete");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_complete, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_complete */



extern int MPI_Win_complete ( MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_complete( &jbuf,  & win );

return rc;
} /* MPI_Win_complete */


extern void F77_MPI_WIN_COMPLETE(MPI_Win  * win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Win_complete( &jbuf, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_complete */



/* --------------- MPI_Win_create --------------- */

static int mpiPif_MPI_Win_create( jmp_buf * base_jbuf, void  *base, MPI_Aint  * size, int  * disp_unit, MPI_Info  * info, MPI_Comm  * comm, MPI_Win  *win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_create\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( void base, MPI_Aint* size, int* disp_unit, MPI_Info* info, MPI_Comm* comm, MPI_Win win )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (void base= %d, MPI_Aint size= %d, int disp_unit= %d, MPI_Info info= %d, MPI_Comm comm= %d, MPI_Win win= %d, )\n", base, *size, *disp_unit, *info, *comm, win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_create( base,  * size,  * disp_unit,  * info,  * comm, win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_create");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_create, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_create */



extern int MPI_Win_create ( void *base, MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, MPI_Win *win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_create( &jbuf, base,  & size,  & disp_unit,  & info,  & comm, win );

return rc;
} /* MPI_Win_create */


extern void F77_MPI_WIN_CREATE(void  *base, MPI_Aint  * size, int  * disp_unit, MPI_Fint  * info, MPI_Fint  * comm, MPI_Win  *win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Info c_info;
MPI_Comm c_comm;

c_info = MPI_Info_f2c(*info);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Win_create( &jbuf, base, size, disp_unit, &c_info, &c_comm, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_create */



/* --------------- MPI_Win_create_dynamic --------------- */

static int mpiPif_MPI_Win_create_dynamic( jmp_buf * base_jbuf, MPI_Info  * info, MPI_Comm  * comm, MPI_Win  *win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_create_dynamic\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Info* info, MPI_Comm* comm, MPI_Win win )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Info info= %d, MPI_Comm comm= %d, MPI_Win win= %d, )\n", *info, *comm, win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_create_dynamic(  * info,  * comm, win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_create_dynamic");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_create_dynamic, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_create_dynamic */



extern int MPI_Win_create_dynamic ( MPI_Info info, MPI_Comm comm, MPI_Win *win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_create_dynamic( &jbuf,  & info,  & comm, win );

return rc;
} /* MPI_Win_create_dynamic */


extern void F77_MPI_WIN_CREATE_DYNAMIC(MPI_Fint  * info, MPI_Fint  * comm, MPI_Win  *win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Info c_info;
MPI_Comm c_comm;

c_info = MPI_Info_f2c(*info);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Win_create_dynamic( &jbuf, &c_info, &c_comm, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_create_dynamic */



/* --------------- MPI_Win_detach --------------- */

static int mpiPif_MPI_Win_detach( jmp_buf * base_jbuf, MPI_Win  * win, mpip_const_void_t  *base)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_detach\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Win* win, mpip_const_void_t base )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Win win= %d, mpip_const_void_t base= %d, )\n", *win, base);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_detach(  * win, base);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_detach");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_detach, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_detach */



extern int MPI_Win_detach ( MPI_Win win, mpip_const_void_t *base )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_detach( &jbuf,  & win, base );

return rc;
} /* MPI_Win_detach */


extern void F77_MPI_WIN_DETACH(MPI_Win  * win, mpip_const_void_t  *base , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Win_detach( &jbuf, win, base );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_detach */



/* --------------- MPI_Win_fence --------------- */

static int mpiPif_MPI_Win_fence( jmp_buf * base_jbuf, int  * assert, MPI_Win  * win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_fence\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( int* assert, MPI_Win* win )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (int assert= %d, MPI_Win win= %d, )\n", *assert, *win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_fence(  * assert,  * win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_fence");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_fence, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_fence */



extern int MPI_Win_fence ( int assert, MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_fence( &jbuf,  & assert,  & win );

return rc;
} /* MPI_Win_fence */


extern void F77_MPI_WIN_FENCE(int  * assert, MPI_Win  * win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Win_fence( &jbuf, assert, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_fence */



/* --------------- MPI_Win_flush --------------- */

static int mpiPif_MPI_Win_flush( jmp_buf * base_jbuf, int  * rank, MPI_Win  * win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_flush\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( int* rank, MPI_Win* win )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (int rank= %d, MPI_Win win= %d, )\n", *rank, *win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_flush(  * rank,  * win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_flush");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_flush, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_flush */



extern int MPI_Win_flush ( int rank, MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_flush( &jbuf,  & rank,  & win );

return rc;
} /* MPI_Win_flush */


extern void F77_MPI_WIN_FLUSH(int  * rank, MPI_Win  * win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Win_flush( &jbuf, rank, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_flush */



/* --------------- MPI_Win_flush_all --------------- */

static int mpiPif_MPI_Win_flush_all( jmp_buf * base_jbuf, MPI_Win  * win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_flush_all\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Win* win )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Win win= %d, )\n", *win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_flush_all(  * win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_flush_all");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_flush_all, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_flush_all */



extern int MPI_Win_flush_all ( MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_flush_all( &jbuf,  & win );

return rc;
} /* MPI_Win_flush_all */


extern void F77_MPI_WIN_FLUSH_ALL(MPI_Win  * win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Win_flush_all( &jbuf, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_flush_all */



/* --------------- MPI_Win_flush_local --------------- */

static int mpiPif_MPI_Win_flush_local( jmp_buf * base_jbuf, int  * rank, MPI_Win  * win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_flush_local\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( int* rank, MPI_Win* win )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (int rank= %d, MPI_Win win= %d, )\n", *rank, *win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_flush_local(  * rank,  * win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_flush_local");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_flush_local, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_flush_local */



extern int MPI_Win_flush_local ( int rank, MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_flush_local( &jbuf,  & rank,  & win );

return rc;
} /* MPI_Win_flush_local */


extern void F77_MPI_WIN_FLUSH_LOCAL(int  * rank, MPI_Win  * win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Win_flush_local( &jbuf, rank, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_flush_local */



/* --------------- MPI_Win_flush_local_all --------------- */

static int mpiPif_MPI_Win_flush_local_all( jmp_buf * base_jbuf, MPI_Win  * win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_flush_local_all\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Win* win )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Win win= %d, )\n", *win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_flush_local_all(  * win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_flush_local_all");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_flush_local_all, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_flush_local_all */



extern int MPI_Win_flush_local_all ( MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_flush_local_all( &jbuf,  & win );

return rc;
} /* MPI_Win_flush_local_all */


extern void F77_MPI_WIN_FLUSH_LOCAL_ALL(MPI_Win  * win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Win_flush_local_all( &jbuf, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_flush_local_all */



/* --------------- MPI_Win_free --------------- */

static int mpiPif_MPI_Win_free( jmp_buf * base_jbuf, MPI_Win  *win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_free\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Win win )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Win win= %d, )\n", win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_free( win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_free");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_free, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_free */



extern int MPI_Win_free ( MPI_Win *win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_free( &jbuf, win );

return rc;
} /* MPI_Win_free */


extern void F77_MPI_WIN_FREE(MPI_Win  *win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Win_free( &jbuf, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_free */



/* --------------- MPI_Win_get_group --------------- */

static int mpiPif_MPI_Win_get_group( jmp_buf * base_jbuf, MPI_Win  * win, MPI_Group  *group)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_get_group\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Win* win, MPI_Group group )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Win win= %d, MPI_Group group= %d, )\n", *win, group);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_get_group(  * win, group);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_get_group");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_get_group, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_get_group */



extern int MPI_Win_get_group ( MPI_Win win, MPI_Group *group )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_get_group( &jbuf,  & win, group );

return rc;
} /* MPI_Win_get_group */


extern void F77_MPI_WIN_GET_GROUP(MPI_Win  * win, MPI_Fint  *group , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Group c_group;

c_group = MPI_Group_f2c(*group);

rc = mpiPif_MPI_Win_get_group( &jbuf, win, &c_group );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_get_group */



/* --------------- MPI_Win_get_info --------------- */

static int mpiPif_MPI_Win_get_info( jmp_buf * base_jbuf, MPI_Win  * win, MPI_Info  *info_used)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_get_info\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Win* win, MPI_Info info_used )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Win win= %d, MPI_Info info_used= %d, )\n", *win, info_used);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_get_info(  * win, info_used);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_get_info");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_get_info, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_get_info */



extern int MPI_Win_get_info ( MPI_Win win, MPI_Info *info_used )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_get_info( &jbuf,  & win, info_used );

return rc;
} /* MPI_Win_get_info */


extern void F77_MPI_WIN_GET_INFO(MPI_Win  * win, MPI_Fint  *info_used , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Info c_info_used;

c_info_used = MPI_Info_f2c(*info_used);

rc = mpiPif_MPI_Win_get_info( &jbuf, win, &c_info_used );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_get_info */



/* --------------- MPI_Win_lock --------------- */

static int mpiPif_MPI_Win_lock( jmp_buf * base_jbuf, int  * lock_type, int  * rank, int  * assert, MPI_Win  * win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_lock\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( int* lock_type, int* rank, int* assert, MPI_Win* win )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (int lock_type= %d, int rank= %d, int assert= %d, MPI_Win win= %d, )\n", *lock_type, *rank, *assert, *win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_lock(  * lock_type,  * rank,  * assert,  * win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_lock");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_lock, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_lock */



extern int MPI_Win_lock ( int lock_type, int rank, int assert, MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_lock( &jbuf,  & lock_type,  & rank,  & assert,  & win );

return rc;
} /* MPI_Win_lock */


extern void F77_MPI_WIN_LOCK(int  * lock_type, int  * rank, int  * assert, MPI_Win  * win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Win_lock( &jbuf, lock_type, rank, assert, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_lock */



/* --------------- MPI_Win_lock_all --------------- */

static int mpiPif_MPI_Win_lock_all( jmp_buf * base_jbuf, int  * assert, MPI_Win  * win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_lock_all\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( int* assert, MPI_Win* win )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (int assert= %d, MPI_Win win= %d, )\n", *assert, *win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_lock_all(  * assert,  * win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_lock_all");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_lock_all, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_lock_all */



extern int MPI_Win_lock_all ( int assert, MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_lock_all( &jbuf,  & assert,  & win );

return rc;
} /* MPI_Win_lock_all */


extern void F77_MPI_WIN_LOCK_ALL(int  * assert, MPI_Win  * win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Win_lock_all( &jbuf, assert, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_lock_all */



/* --------------- MPI_Win_post --------------- */

static int mpiPif_MPI_Win_post( jmp_buf * base_jbuf, MPI_Group  * group, int  * assert, MPI_Win  * win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_post\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Group* group, int* assert, MPI_Win* win )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Group group= %d, int assert= %d, MPI_Win win= %d, )\n", *group, *assert, *win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_post(  * group,  * assert,  * win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_post");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_post, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_post */



extern int MPI_Win_post ( MPI_Group group, int assert, MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_post( &jbuf,  & group,  & assert,  & win );

return rc;
} /* MPI_Win_post */


extern void F77_MPI_WIN_POST(MPI_Fint  * group, int  * assert, MPI_Win  * win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Group c_group;

c_group = MPI_Group_f2c(*group);

rc = mpiPif_MPI_Win_post( &jbuf, &c_group, assert, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_post */



/* --------------- MPI_Win_set_info --------------- */

static int mpiPif_MPI_Win_set_info( jmp_buf * base_jbuf, MPI_Win  * win, MPI_Info  * info)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_set_info\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Win* win, MPI_Info* info )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Win win= %d, MPI_Info info= %d, )\n", *win, *info);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_set_info(  * win,  * info);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_set_info");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_set_info, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_set_info */



extern int MPI_Win_set_info ( MPI_Win win, MPI_Info info )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_set_info( &jbuf,  & win,  & info );

return rc;
} /* MPI_Win_set_info */


extern void F77_MPI_WIN_SET_INFO(MPI_Win  * win, MPI_Fint  * info , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Info c_info;

c_info = MPI_Info_f2c(*info);

rc = mpiPif_MPI_Win_set_info( &jbuf, win, &c_info );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_set_info */



/* --------------- MPI_Win_shared_query --------------- */

static int mpiPif_MPI_Win_shared_query( jmp_buf * base_jbuf, MPI_Win  * win, int  * rank, MPI_Aint  *size, int  *disp_unit, void  *baseptr)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_shared_query\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Win* win, int* rank, MPI_Aint size, int disp_unit, void baseptr )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Win win= %d, int rank= %d, MPI_Aint size= %d, int disp_unit= %d, void baseptr= %d, )\n", *win, *rank, size, disp_unit, baseptr);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_shared_query(  * win,  * rank, size, disp_unit, baseptr);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_shared_query");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_shared_query, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_shared_query */



extern int MPI_Win_shared_query ( MPI_Win win, int rank, MPI_Aint *size, int *disp_unit, void *baseptr)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_shared_query( &jbuf,  & win,  & rank, size, disp_unit, baseptr );

return rc;
} /* MPI_Win_shared_query */


extern void F77_MPI_WIN_SHARED_QUERY(MPI_Win  * win, int  * rank, MPI_Aint  *size, int  *disp_unit, void  *baseptr , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Win_shared_query( &jbuf, win, rank, size, disp_unit, baseptr );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_shared_query */



/* --------------- MPI_Win_start --------------- */

static int mpiPif_MPI_Win_start( jmp_buf * base_jbuf, MPI_Group  * group, int  * assert, MPI_Win  * win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_start\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Group* group, int* assert, MPI_Win* win )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Group group= %d, int assert= %d, MPI_Win win= %d, )\n", *group, *assert, *win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_start(  * group,  * assert,  * win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_start");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_start, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_start */



extern int MPI_Win_start ( MPI_Group group, int assert, MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_start( &jbuf,  & group,  & assert,  & win );

return rc;
} /* MPI_Win_start */


extern void F77_MPI_WIN_START(MPI_Fint  * group, int  * assert, MPI_Win  * win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;
MPI_Group c_group;

c_group = MPI_Group_f2c(*group);

rc = mpiPif_MPI_Win_start( &jbuf, &c_group, assert, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_start */



/* --------------- MPI_Win_sync --------------- */

static int mpiPif_MPI_Win_sync( jmp_buf * base_jbuf, MPI_Win  * win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_sync\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Win* win )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Win win= %d, )\n", *win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_sync(  * win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_sync");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_sync, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_sync */



extern int MPI_Win_sync ( MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_sync( &jbuf,  & win );

return rc;
} /* MPI_Win_sync */


extern void F77_MPI_WIN_SYNC(MPI_Win  * win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Win_sync( &jbuf, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_sync */



/* --------------- MPI_Win_test --------------- */

static int mpiPif_MPI_Win_test( jmp_buf * base_jbuf, MPI_Win  * win, int  *flag)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_test\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Win* win, int flag )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Win win= %d, int flag= %d, )\n", *win, flag);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_test(  * win, flag);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_test");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_test, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_test */



extern int MPI_Win_test ( MPI_Win win, int *flag)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_test( &jbuf,  & win, flag );

return rc;
} /* MPI_Win_test */


extern void F77_MPI_WIN_TEST(MPI_Win  * win, int  *flag , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Win_test( &jbuf, win, flag );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_test */



/* --------------- MPI_Win_unlock --------------- */

static int mpiPif_MPI_Win_unlock( jmp_buf * base_jbuf, int  * rank, MPI_Win  * win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_unlock\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( int* rank, MPI_Win* win )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (int rank= %d, MPI_Win win= %d, )\n", *rank, *win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_unlock(  * rank,  * win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_unlock");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_unlock, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_unlock */



extern int MPI_Win_unlock ( int rank, MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_unlock( &jbuf,  & rank,  & win );

return rc;
} /* MPI_Win_unlock */


extern void F77_MPI_WIN_UNLOCK(int  * rank, MPI_Win  * win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Win_unlock( &jbuf, rank, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_unlock */



/* --------------- MPI_Win_unlock_all --------------- */

static int mpiPif_MPI_Win_unlock_all( jmp_buf * base_jbuf, MPI_Win  * win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_unlock_all\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Win* win )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Win win= %d, )\n", *win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_unlock_all(  * win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_unlock_all");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_unlock_all, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_unlock_all */



extern int MPI_Win_unlock_all ( MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_unlock_all( &jbuf,  & win );

return rc;
} /* MPI_Win_unlock_all */


extern void F77_MPI_WIN_UNLOCK_ALL(MPI_Win  * win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Win_unlock_all( &jbuf, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_unlock_all */



/* --------------- MPI_Win_wait --------------- */

static int mpiPif_MPI_Win_wait( jmp_buf * base_jbuf, MPI_Win  * win)
{
 int DT_size=0;
 double start_from_begin, end_from_begin;
 int rc, enabledState;
 double dur;
 int tsize;
 double messSize = 0.;
 double ioSize = 0.;
 double rmaSize =0.;
 mpiPi_TIME start, end;
 void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };
 mpiPi_mt_stat_tls_t *hndl;

 hndl = mpiPi_stats_mt_gettls(&mpiPi.task_stats);

if (mpiPi_stats_mt_is_on(hndl)) {
mpiPi_GETTIME (&start);
if ( mpiPi.reportStackDepth > 0 ) mpiPi_RecordTraceBack((*base_jbuf), call_stack, mpiPi.fullStackDepth);
fprintf(mpiPi.recfile, "Trace: Rank=%d Function: MPI_Win_wait\n", mpiPi.rank);
fprintf(mpiPi.recfile, "Trace: Parameters: = ( MPI_Win* win )\n");
fprintf(mpiPi.recfile, "Trace: Paravalues: = (MPI_Win win= %d, )\n", *win);
start_from_begin = mpiPi_GETTIMEDIFF (&start, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Starttime = [ %.0lf ]\n",start_from_begin);
}

mpiPi_stats_mt_enter(hndl);

rc = PMPI_Win_wait(  * win);

mpiPi_stats_mt_exit(hndl);
if (mpiPi_stats_mt_is_on(hndl)) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);
end_from_begin = mpiPi_GETTIMEDIFF (&end, &mpiPi.time_begin);
fprintf(mpiPi.recfile, "Trace: Endtime = [ %.0lf ]\n",end_from_begin);
fprintf(mpiPi.recfile, "Trace: Durtime = [ %.0lf ]\n",dur);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_wait");
else
  mpiPi_update_callsite_stats(hndl, mpiPi_MPI_Win_wait, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_wait */



extern int MPI_Win_wait ( MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_wait( &jbuf,  & win );

return rc;
} /* MPI_Win_wait */


extern void F77_MPI_WIN_WAIT(MPI_Win  * win , MPI_Fint *ierr) {
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Win_wait( &jbuf, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_wait */


/* eof */
