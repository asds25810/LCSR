#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;


ifstream fin;
ofstream fout;
typedef vector <string> VS;
VS line;

#define maxn 100001
#define BUF_NUM 1000000
#define BUF_NUM_S 100000
#define REQ_NUM 100000
#define P_NUM 100
#define TAG 1
	
string my_itos(int i)
{
        string r;
        char c[128];

        sprintf(c, "%d\0", i);
        r += c;

        return r;
}


string getPara(const string &a, const string &key)
{
	int start, end;
	
	start= a.find(key);
	end=start;
	while (a[end]!=',')
		end++;
	return a.substr(start, end - start + 1);
}

string getPurePara(const string &a, const string &key)
{
	int start, end;
	
	start= a.find(key);
	end=start;	
	while (a[end]!=',')
		end++;
	while (a[start]!='=')
		start++;
	return a.substr(start+1, end - start - 1);
}


string getTime(const string &a, const string &key)
{
	int start, end;
	
	start= a.find(key);
	end=start;
	while (a[end]!=']')
		end++;
	return a.substr(start, end - start + 1);
}

void readfile()
{
	string s;
	
	getline(fin ,s);
	line.clear();
	while (fin)
	{
		line.push_back(s);
		getline(fin ,s);		
	}
}


void init()
{

	readfile();
}


void make()
{
	fout << "#include \"mpi.h\"" << endl;
	fout << "#include <string.h>" << endl;
	fout << "#include <stdio.h>" << endl;
	fout << endl;
	fout << "#define DELAY 1" << endl;
	fout << endl;
	
	fout << "int main(int argc,char *argv[])" << endl;
	fout << "{" << endl;
	fout << "\tint myid, numprocs;" << endl;
	fout << "\tint dst, src;" << endl;
	fout << "\tint outcount,flag;" << endl;
	fout << "\tchar buf[" << BUF_NUM << "];" << endl;
	fout << "\tchar buf2[" << BUF_NUM << "];" << endl;
	fout << "\tint buf3[" << BUF_NUM_S << "];" << endl;
	fout << "\tint displs[" << P_NUM << "];" << endl;
	fout << "\tint displs2[" << P_NUM << "];" << endl;
	fout << "\tMPI_Status status;" << endl;
	fout << "\tMPI_Request request;" << endl;
	fout << "\tMPI_Status arr_status[" << REQ_NUM << "];" << endl;
	fout << "\tMPI_Request arr_request[" << REQ_NUM << "];" << endl;
	
	fout << "\tvolatile int sum_n=0;" << endl;
	fout << endl;
	
	fout << "\tint send_count=0;" << endl; //用这些变量记录各通信函数到底调用多少次，相当于展开循环
	fout << "\tint recv_count=0;" << endl;
	fout << "\tint bcast_count=0;" << endl;
	fout << "\tint allreduce_count=0;" << endl;
	fout << "\tint reduce_count=0;" << endl;
	fout << "\tint test_count=0;" << endl;
	fout << "\tint testsome_count=0;" << endl;
	
	fout << "\tint delay;" << endl;
	fout << "\tlong long delay_sum=0;" << endl; //用来累计所有的delay
	
	fout << "\tint wait_sum=0;" << endl;
	fout <<	"\tint wait_cnt=0;" << endl;
	
	fout << "\tint send_len;" << endl;
	fout << "\tint send_sum=0;" << endl; //用来累计所有send_count的信息
	fout << "\tint recv_len;" << endl;
	fout << "\tint recv_sum=0;" << endl; //用来累计所有recv_count的信息
	fout << "\tint testsome_len;" << endl;
	fout << "\tint testsome_sum=0;" << endl; //用来累计Testsome测试的Request数量
	fout << "\tint allreduce_len;" << endl;
	fout << "\tint allreduce_sum=0;" << endl;
	
	fout << endl;
	
	
	fout << endl;
	
	fout << "\tMPI_Init(&argc,&argv);" << endl;
    fout << "\tMPI_Comm_size(MPI_COMM_WORLD,&numprocs);" << endl;
    fout << "\tMPI_Comm_rank(MPI_COMM_WORLD,&myid);" << endl;
	fout << "\tfprintf(stdout,\"Process %d of %d\\n\",myid, numprocs);" << endl;
	fout << "\tfprintf(stdout,\"Skeleton Program.\\n\");" << endl;
	fout << "\tmemset(displs,0,sizeof(displs));" << endl;
	fout << "\tmemset(displs2,0,sizeof(displs2));" << endl;
	fout << endl;
	
	fout << "\tfor(int i=0;i<10000;i++){" << endl; //用于填充arr_request
	fout << "\tMPI_Isend(buf2,1,MPI_CHAR,myid," << TAG <<", MPI_COMM_WORLD, &arr_request[i]);" << endl;
	fout << "\tMPI_Irecv(buf3,1,MPI_CHAR,myid," << TAG <<", MPI_COMM_WORLD, &arr_request[i]);" << endl;
	fout << "}" << endl;

	{
		string cir;
		string func;
		int i, j, n, cId = 0, cTimes, cLen;
		int nProc;		
		
		n = line.size();
		nProc = atoi(getPurePara(line[0],"same=").c_str());
		
		for (i=0;i<n;i++)
		{
			
			if (line[i].find("FOR TIMES") != string::npos)
			{
				cir = getPara(line[i], "TIMES");
				cTimes = atoi(cir.substr(6,cir.length()-6).c_str());
				cir = getPara(line[i], "CLEN");
				cLen = atoi(cir.substr(4,cir.length()-4).c_str());
				fout << "\tfor(int c" << cId << "=1; c" << cId << "<=" << cTimes << "; c" << cId << "++ ){" << endl;
				cId++;
			}

			
			func = getPurePara(line[i], "func");
			
			
			if (func == "MPI_Send")
			{				
				//int MPI_Send(void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)				
				fout << "\tdst = myid;" << endl;
				fout << "\tMPI_Send(buf2, ";
				fout << getPurePara(line[i], "count") << ", ";
				fout << getPurePara(line[i], "datatype") << ", dst, " << TAG << ", " << "MPI_COMM_WORLD);" << endl;
			}
			
			if (func ==  "MPI_Recv")
			{
				//int MPI_Recv(void* buf, int count, MPI_Datatype datatype, int source, int tag, 
				//	MPI_Comm comm, MPI_Status *status)
				fout << "\tsrc = myid;" << endl;
				fout << "\tMPI_Recv(buf, ";
				fout << getPurePara(line[i], "count") << ", ";
				fout << getPurePara(line[i], "datatype") << ", src, " << TAG << ", " << "MPI_COMM_WORLD, &status);" << endl;
			}
			if (func ==  "MPI_Isend")
			{
				//int MPI_Isend(void* buf, int count, MPI_Datatype datatype, int dest, int tag,
				//	MPI_Comm comm, MPI_Request *request);
				fout << "\tdst = myid;" << endl;
				fout << "\tsend_count++;" << endl;
				fout << "\tsend_len = " << getPurePara(line[i], "count") <<";" << endl;
				fout << "\tsend_sum += send_len;" << endl;
				fout << "\tMPI_Isend(buf2, ";
				fout << "send_len " << ", ";
				fout << getPurePara(line[i], "datatype") << ", dst, " << TAG << ", " << "MPI_COMM_WORLD, &request);" << endl;
			}
			if (func == "MPI_Irecv")
			{
				//int MPI_Irecv(void* buf, int count, MPI_Datatype datatype, int source, int tag,
				//	MPI_Comm comm, MPI_Request *request);
				fout << "\tsrc = myid;" << endl;
				fout << "\trecv_count++;" << endl;
				fout << "\trecv_len = " << getPurePara(line[i], "count") <<";" << endl;
				fout << "\trecv_sum += recv_len;" << endl;
				fout << "\tMPI_Irecv(buf, ";
				fout <<"recv_len " << ", ";
				fout << getPurePara(line[i], "datatype") << ", src, " << TAG << ", " << "MPI_COMM_WORLD, &request);" << endl;
			}
			if (func == "MPI_Wait")
			{
				//int MPI_Wait(MPI_Request *request, MPI_Status *status);
				int dtime=0;
				int maxd=0;
				string tstr = line[i];
				for(int d=0;d<nProc;d++)
				{
					int start=0;
					start = tstr.find("D=");
					sscanf(tstr.substr(start+3,tstr.length()-start-3).c_str(), "%d", &dtime);
					tstr = tstr.substr(start+3,tstr.length()-start-3);
					//cout << dtime << endl;
					if(dtime > maxd) maxd=dtime;
				}
				fout << "\tsum_n=0;" << endl;
				fout << "\tfor(volatile int i=0;i<" << maxd*800 << ";i++){" << endl;
				fout << "\tsum_n+=i;" << endl;
				fout << "\t}" << endl;
				fout << "\twait_sum+=" << maxd << ";" << endl;
				fout << "\twait_cnt++;" << endl;
				fout << "\tMPI_Wait(&arr_request[0], &arr_status[0]);" << endl;
			}
			if (func == "MPI_Waitall")
			{
				//int MPI_Waitall(int count, MPI_Request *array_of_requests, MPI_Status *array_of_statuses);
				int dtime=0;
				int maxd=0;
				string tstr = line[i];
				for(int d=0;d<nProc;d++)
				{
					int start=0;
					start = tstr.find("D=");
					sscanf(tstr.substr(start+3,tstr.length()-start-3).c_str(), "%d", &dtime);
					tstr = tstr.substr(start+3,tstr.length()-start-3);
					//cout << dtime << endl;
					if(dtime > maxd) maxd=dtime;
				}
				fout << "\tfor(int i=0;i<" << maxd*800 << ";i++){};" << endl;
				fout << "\twait_sum+=" << maxd << ";" << endl;
				fout << "\twait_cnt++;" << endl;
				fout << "\tMPI_Wait(&arr_request[0], &arr_status[0]);" << endl;				
				fout << "\tMPI_Waitall(";
				fout << getPurePara(line[i], "count") << ", arr_request, arr_status);" << endl;
			}
			if (func ==  "MPI_Bcast")
			{
				//int MPI_Bcast(void* buffer,int count,MPI_Datatype datatype, int root, MPI_Comm comm);
				fout << "\tbcast_count++;" << endl;
				fout << "\tMPI_Bcast(buf, " << getPurePara(line[i], "count") << ", ";
				fout << getPurePara(line[i], "datatype") << ", ";
				fout << getPurePara(line[i], "root") << ", MPI_COMM_WORLD);" << endl;
			}
			if (func == "MPI_Alltoall")
			{
				//int MPI_Alltoall(void* sendbuf, int sendcount, MPI_Datatype sendtype,
				//	void* recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm);
				fout << "\tMPI_Alltoall(buf, " << getPurePara(line[i], "sendcount") << ", ";
				fout << getPurePara(line[i], "sendtype") << ", buf2, ";
				fout << getPurePara(line[i], "recvcount") << ", ";
				fout << getPurePara(line[i], "recvtype") << ", MPI_COMM_WORLD);" << endl;
			}
			if (func == "MPI_Alltoallv")
			{
				//int MPI_Alltoallv(void* sendbuf, int *sendcounts, int *sdispls,
				//MPI_Datatype sendtype, void* recvbuf, int *recvcounts, int *rdispls,
				//MPI_Datatype recvtype, MPI_Comm comm);				
				fout << "\tMPI_Alltoallv(buf, " << getPurePara(line[i], "sendcounts") << ", displs, ";
				fout << getPurePara(line[i], "sendtype") << ", buf2, ";
				fout << getPurePara(line[i], "recvcounts") << ", displs2, ";
				fout << getPurePara(line[i], "recvtype") << ", MPI_COMM_WORLD);" << endl;
			}
			if (func == "MPI_Reduce")
			{
				//int MPI_Reduce(void* sendbuf, void* recvbuf, int count, MPI_Datatype datatype,
				//	MPI_Op op, int root, MPI_Comm comm);
				fout << "\treduce_count++;" << endl;
				fout << "\tMPI_Reduce(buf, buf2, ";
				fout << getPurePara(line[i], "count") << ", ";
				fout << getPurePara(line[i], "datatype") << ", ";
				fout << getPurePara(line[i], "op") << ", ";
				fout << getPurePara(line[i], "root") << ", MPI_COMM_WORLD);" << endl;
			}
			if (func == "MPI_Allreduce")
			{
				//int MPI_Allreduce(void* sendbuf, void* recvbuf, int count, MPI_Datatype datatype,
				//	MPI_Op op, MPI_Comm comm);
				int dtime=0;
				int maxd=0;
				string tstr = line[i];
				fout << "\tallreduce_count++;" << endl;
				fout << "\tallreduce_len = " << getPurePara(line[i], "count") << ";" << endl;
				fout << "\tallreduce_sum += allreduce_len;" << endl;
				/*for(int d=0;d<nProc;d++)
				{
					int start=0;
					start = tstr.find("D=");
					sscanf(tstr.substr(start+3,tstr.length()-start-3).c_str(), "%d", &dtime);
					tstr = tstr.substr(start+3,tstr.length()-start-3);
					//cout << dtime << endl;
					if(dtime > maxd) maxd=dtime;
				}
				fout << "\tsum_n=0;" << endl;
				fout << "\tfor(volatile int i=0;i<" << maxd << ";i++){" << endl;
				fout << "\tsum_n+=i;" << endl;
				fout << "\t}" << endl;*/
				fout << "\tMPI_Allreduce(buf, buf2, ";

				fout << "allreduce_len" << ", ";
				fout << getPurePara(line[i], "datatype") << ", ";
				fout << getPurePara(line[i], "op") << ", MPI_COMM_WORLD);" << endl;				
			}
			if (func == "MPI_Barrier")
			{
				//int MPI_Barrier(MPI_Comm comm);
				fout << "\tMPI_Barrier(MPI_COMM_WORLD);" << endl;
			}
			if (func == "MPI_Gather")
			{
				//int MPI_Gather(const void *sendbuf, int sendcount, MPI_Datatype sendtype,void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm)
				fout << "\tMPI_Gather(buf, " << getPurePara(line[i], "sendcnt") << ", ";
				fout << getPurePara(line[i], "sendtype") << ", buf2, ";
				fout << getPurePara(line[i], "recvcount") << ", ";
				fout << getPurePara(line[i], "recvtype") << ", ";
				fout << getPurePara(line[i], "root") << ", MPI_COMM_WORLD);" << endl;
			}
			if (func == "MPI_Testsome")
			{
				//int MPI_Testsome(int incount, MPI_Request array_of_requests[], int *outcount, int array_of_indices[], MPI_Status array_of_statuses[])
				fout << "\ttestsome_count++;" << endl;
				fout << "\ttestsome_len=" << getPurePara(line[i],"incount") << ";" << endl;
				fout << "\ttestsome_sum += testsome_len;" << endl;
				//fout << "\tfor(int i = 0;i < " << "testsome_len" << ";i++){" << endl;
				fout << "\tMPI_Testsome(";
				fout << /*getPurePara(line[i], "incount")*/ "testsome_len" << ", " << "arr_request" << ", " ;
				fout << "&outcount, buf3, arr_status);" << endl;
				//fout << "}" << endl;
			}
			if (func == "MPI_Test")
			{
				//int MPI_Test(MPI_Request *request, int *flag, MPI_Status *status)
				fout << "\ttest_count++;" << endl;
				fout << "\tMPI_Test(&request, &flag, &status);" << endl;
			}
			if (func == "MPI_Comm_split")
			{
				;
			}
			if (func == "MPI_Comm_dup")
			{
				;
			}
			//Delay Time
			{
				double t = 0, dt;
				int posi = 0;
				string tstr = line[i];
				for (j=0;j<nProc;j++)
				{	
					posi = tstr.find("Blank");
					sscanf(tstr.substr(posi+7,tstr.length()-posi-7).c_str(), "%lf", &dt);
					//t += dt;
					if(dt>t) t=dt;
					tstr = tstr.substr(posi+7,tstr.length()-posi-7);
					//cout << dt << endl;
				}
				if (dt > 1e-6) 
				{
					t/=nProc;
				}
				else
				{
					;
				}
				cTimes = int(t);
				fout << "\tdelay = " << cTimes*800 << ";" << endl;
				fout << "\tdelay_sum += delay;" << endl; 
				fout << "\t/*Delay*/ for(int d=1; d<= delay; d++ ){}" << endl;				
			}
			
			if (line[i].find("FOR END") != string::npos)
			{
				fout << "\t}" << endl;
			}
			

			
		}
	}
	
	fout << "\tMPI_Finalize();" << endl;
	fout << "printf(\"send count=%d\\n\",send_count);"  << endl;
	fout << "printf(\"recv count=%d\\n\",recv_count);" << endl;
	fout << "printf(\"bcast count=%d\\n\",bcast_count);" << endl;
	fout << "printf(\"allreduce count=%d\\n\",allreduce_count);" << endl;
	fout << "printf(\"reduce count=%d\\n\",reduce_count);" << endl;
	fout << "printf(\"test count=%d\\n\",test_count);" << endl;
	fout << "printf(\"testsome count=%d\\n\",testsome_count);" << endl;
	fout << "printf(\"delay sum=%lld\\n\",delay_sum);" << endl;
	fout << "printf(\"send sum=%d\\n\",send_sum);" << endl;
	fout << "printf(\"recv sum=%d\\n\",recv_sum);" << endl;
	fout << "printf(\"testsome sum=%d\\n\",testsome_sum);" << endl;
	fout << "printf(\"allreduce sum=%d\\n\",allreduce_sum);" << endl;
	fout << "printf(\"wait sum =%d\\n\",wait_sum);" << endl;
	fout << "printf(\"wait count =%d\\n\",wait_cnt);" << endl;
	fout << "\treturn 0;" << endl;
	fout << "}" << endl;
}

int main(int argc,char *argv[])
{
  //  char ts1[16] = "IScircle.txt";
	//char ts2[16] = "ISskeleton.txt";
	
	
	
	
	if (argc != 3)
    {
        cout << "Usage: reconstruct inputfile outputfile\n" << endl;
        return 0;		
    }
	
	
	fin.open(argv[1]);
	//fin.open(ts1);
	fout.open(argv[2]);
	//fout.open(ts2);
	
    init();
	
	fin.close();
	
	make();
	
	fout.close();
    return 0;
}
