#include <mpi.h>
#include <ctime>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
	int sz,myid;
	int Number,tmp,partner,pos1,pos2,pos3;
	int N;
	//MPI start
	MPI_Init(NULL,NULL);
	MPI_Comm_size(MPI_COMM_WORLD,&sz);
	MPI_Comm_rank(MPI_COMM_WORLD,&myid);

	srand(time(NULL));

	if(myid)
		int output[1];
	else
		int output[2000000];

	int *randNum=(int*)malloc(sizeof(int)*100000);//generate rand num
	int *RecvNum=(int*)malloc(sizeof(int)*100000);//Recv other's num
	int *tmpNum=(int*)malloc(sizeof(int)*100000);//store the merge result
	int *a;//used to swap the new merge result and the pre-result

	//Read total number
	if(myid==0){
		printf("Please enter the number that should be sorted.\n");
		scanf("%d",&N);
		printf("\n");
	}

	MPI_Bcast(&N,1,MPI_INT,0,MPI_COMM_WORLD);

	//every processes generate N/sz+1 numbers
	//if N numbers already, give it RAND_MAX
	if( myid < N%sz )
		Number=N/sz+1;
	else{
		Number=N/sz;
		randNum[Number]=RAND_MAX;
	}

	//generate random number
	for(int i=0;i<Number;++i){
		randNum[i]=(rand()*(myid+5))%200000-30000;
		if(i){
			while(randNum[i]==randNum[i-1]){
				randNum[i]=(rand()*(myid+5))%200000-30000;
			}
		}
	}

	//Local odd-even sort
	for(int phase=0;phase<Number;++phase){
		if(phase%2){
			for(int i=1;i<Number-1;i+=2){
				if(randNum[i]>randNum[i+1]){
					tmp=randNum[i];
					randNum[i]=randNum[i+1];
					randNum[i+1]=tmp;
				}
			}
		}
		else{
			for(int i=1;i<Number;i+=2){
				if(randNum[i-1]>randNum[i]){
					tmp=randNum[i];
					randNum[i]=randNum[i-1];
					randNum[i-1]=tmp;
				}
			}
		}
	}

	//gather every random number to process 0 (excpet thw RAND_MAX)
	int dest=0;
	int rc[sz],disp[sz];
	disp[0]=0;
	for(int i=0;i<sz;++i){
		if(i<N%sz)
			rc[i]=N/sz+1;
		else
			rc[i]=N/sz;
		if(i)
			disp[i]=disp[i-1]+rc[i-1];
	}
	MPI_Gatherv(randNum,Number,MPI_INT,RecvNum,rc,disp,MPI_INT,dest,MPI_COMM_WORLD);

	//print the every local lists
	if(myid==0){
		for(int i=0;i<sz;++i){
			if(i==N) break;
			printf("The number Recv from process %d local list are:\n",i);
			for(int j=disp[i];j<disp[i]+rc[i];++j){
				printf("%d ",RecvNum[j]);
			}
			printf("\n\n");
		}
	}

	//make every processes Number are same
	//It's eayier to send and recv
	Number=N/sz+1;

	//odd-even sort between processes
	//Every processes give it's local list to it's partner
	for(int phase=0;phase<sz;++phase){
		if(phase%2){
			if(myid%2==1 && myid+1<sz){
	//the process with smaller id takes the front half small number
				MPI_Sendrecv(randNum,Number,MPI_INT,myid+1,0,RecvNum,Number,MPI_INT,myid+1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
				pos1=pos2=0;
				//merge number start in the smaller side
				for(int i=0;i<Number;++i){
					if(randNum[pos1]<RecvNum[pos2])
						tmpNum[i]=randNum[pos1++];
					else
						tmpNum[i]=RecvNum[pos2++];
				}
				a=randNum;
				randNum=tmpNum;
				tmpNum=a;
			}
			else if(myid%2==0 && myid-1>=0){
	//the process with bigger id takes the back half small number
				MPI_Sendrecv(randNum,Number,MPI_INT,myid-1,0,RecvNum,Number,MPI_INT,myid-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
				pos1=pos2=Number-1;
				//merge number start in the bigger side
				for(int i=Number-1;i>=0;--i){
					if(randNum[pos1]>RecvNum[pos2])
						tmpNum[i]=randNum[pos1--];
					else
						tmpNum[i]=RecvNum[pos2--];
				}
				a=randNum;
				randNum=tmpNum;
				tmpNum=a;
			}
		}
		else{
			if(myid%2==1 && myid-1>=0){
	//the process with bigger id takes the back half small number
				MPI_Sendrecv(randNum,Number,MPI_INT,myid-1,0,RecvNum,Number,MPI_INT,myid-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
				pos1=pos2=Number-1;
				//merge number start in the bigger side
				for(int i=Number-1;i>=0;--i){
					if(randNum[pos1]>RecvNum[pos2])
						tmpNum[i]=randNum[pos1--];
					else
						tmpNum[i]=RecvNum[pos2--];
				}
				a=randNum;
				randNum=tmpNum;
				tmpNum=a;
			}
			else if(myid%2==0 && myid+1<sz){
	//the process with smaller id takes the front half small number
				MPI_Sendrecv(randNum,Number,MPI_INT,myid+1,0,RecvNum,Number,MPI_INT,myid+1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
				pos1=pos2=0;
				//merge number start in the smaller side
				for(int i=0;i<Number;++i){
					if(randNum[pos1]<RecvNum[pos2])
						tmpNum[i]=randNum[pos1++];
					else
						tmpNum[i]=RecvNum[pos2++];
				}
				a=randNum;
				randNum=tmpNum;
				tmpNum=a;
			}
		}
	}

	for(int i=0;i<sz;++i){
		rc[i]=Number;
		disp[i]=Number*i;
	}

	//every processes send their local list to process 0 again
	MPI_Gatherv(randNum,Number,MPI_INT,RecvNum,rc,disp,MPI_INT,0,MPI_COMM_WORLD);

	//print smaller N numbers.(exclude RAND_MAX)
	if(myid==0){
		printf("The sort result:\n");
		for(int i=0;i<N;++i)
			printf("%d ",RecvNum[i]);
		printf("\n");
	}
	//Finish and free memery
	free(RecvNum);
	free(tmpNum);
	free(randNum);

	MPI_Finalize();

	return 0;
}
