#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

int main (int argc, char *argv[]) {

        int myid,sz;
        int tmp=1;
        int i,q;
        long long recv_x,toss,number_in_circle = 0,global_count=0;
        long long number_of_tosses;
        double pi_estimate = 0.0;
        double x=0.0,y=0.0;

        srand(time(NULL));

        MPI_Init(NULL,NULL);
        MPI_Comm_size(MPI_COMM_WORLD,&sz);
        MPI_Comm_rank(MPI_COMM_WORLD,&myid);

        if(myid==0){
                printf("Please input the total number of tosses: ");
                scanf("%lld",&number_of_tosses);
        }

        while(tmp<sz) tmp=tmp*2;

        for(i=tmp;i>1;i=i/2){
                q=i/2;
                if(myid%i==q){
                        MPI_Recv(&number_of_tosses,1,MPI_LONG_LONG,myid-q,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
                }
                else if(myid%i==0 && (myid+q)<sz){
                        MPI_Send(&number_of_tosses,1,MPI_LONG_LONG,myid+q,0,MPI_COMM_WORLD);
                }
        }
        
        for(toss=0;toss<number_of_tosses;++toss){
                x=(double)(((double)rand()/RAND_MAX)*2.0-1);
                y=(double)(((double)rand()/RAND_MAX)*2.0-1);
                if(x*x+y*y<=1) ++number_in_circle;
        }

        for(i=2;i<sz*2;i=i*2){
                q=i/2;
                if(myid%i==q){
                        MPI_Send(&number_in_circle,1,MPI_LONG_LONG,myid-q,0,MPI_COMM_WORLD);
                }
                else if(myid%i==0 && (myid+q)<sz){
                        MPI_Recv(&recv_x,1,MPI_LONG_LONG,myid+q,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
                        number_in_circle+=recv_x;
                }
        }

        if(myid==0){
                global_count=number_in_circle;
                printf("The estimate of pi computed by Monte Carlo method is %lf\n",(double)4*(double)global_count/number_of_tosses/(double)sz);
        }

        MPI_Finalize();
        return 0;
}
