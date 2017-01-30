#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <mpi.h>
#include <omp.h>


int main(int argc, char* argv[]){
//	if(argc!=8){
//		printf("Not correct parameter: %d\n",argc);
//		exit(0);
//	}
	struct{
		int cost;
		int rank;
	}loc_data,global_data;

	int thread_count = strtol(argv[1],NULL,10);	//thread_numbers
	int m = strtol(argv[2],NULL,10);			//ants
	int n = strtol(argv[3],NULL,10);			//cities
	int alpha = strtol(argv[4],NULL,10);
	int beta = strtol(argv[5],NULL,10);
	int Q = strtol(argv[6],NULL,10);
	int evaporation = strtol(argv[7],NULL,10);	//in persentage
	float eva_rate = (float)1-((float)evaporation/(float)100);
	int i,j,k,t;
	int edges[n+5][n+5];
	int best_tour[n+5];
	int recv_tour[n+5];
	int sz,myid;
	double pheromone[n+5][n+5];

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&sz);
	MPI_Comm_rank(MPI_COMM_WORLD,&myid);

	if(myid==0){
	//the cost between edges
		for(i=0;i<n;++i){
			for(j=0;j<n;++j){
				scanf("%d",&edges[i][j]);
				pheromone[i][j] = 1/(double)edges[i][j];
				if(edges[i][j]==0)
					pheromone[i][j]=0;
			}
		}
	}

	MPI_Bcast(&edges,(n+5)*(n+5),MPI_INT,0,MPI_COMM_WORLD);
	MPI_Bcast(&pheromone,(n+5)*(n+5),MPI_DOUBLE,0,MPI_COMM_WORLD);


	srand(time(NULL));

	//init global tour
	global_data.cost=0xffffff;
	global_data.rank=-1;

	loc_data.cost=0xffffff;
	loc_data.rank=-1;

	double p[n+5][n+5];
	int visit[m+5][n+5];
	int tour[m+5][n+5];

	if(myid!=0 || sz==1){
#pragma omp parallel num_threads(thread_count)\
	default(none) shared(p,loc_data,edges,myid,global_data,pheromone \
			,alpha,visit,beta,Q,eva_rate,m,n,best_tour,tour)\
	private(i,j,k,t)
		for(t=0;t<100;++t){
			memset(visit,-1,sizeof(visit));
			memset(tour,-1,sizeof(tour));
			//calculate the probility of each city
//		printf("myid=%d edge11=%d %d\n",myid,edges[0][0],edges[1][0]);
#pragma omp for
			for(i=0;i<n;++i){
				for(j=0;j<n;++j){
					if(edges[i][j]!=0){
						double x = pow(pheromone[i][j],alpha);
						double y = pow((double)1/(double)edges[i][j],beta);
#pragma omp critical
						{
							p[i][j] = x * y;
							if(t==0) p[i][j]=0.001;
						}
					}
					else
#pragma omp critical
						p[i][j]=-1.0;
				}
			}
		
			//put m ants in ramdon city
#pragma omp for
			for(i=0;i<m;++i){
				tour[i][0]= rand()%n;
				visit[i][tour[i][0]]=1;
			}

#pragma omp barrier
			//let m ants travel n cities
			for(i=1;i<n;++i){
//				printf("%d\n",omp_get_thread_num());
#pragma omp for
				for(k=0;k<m;++k){
					//calc probolity
					double sum = 0.0;
					double tmp_p[n+5];
					int now_city = tour[k][i-1];
					for(j=0;j<n;++j){
						if(visit[k][j]==-1 && edges[now_city][j]!=0){
							sum+=p[now_city][j];
						}
					}
					for(j=0;j<n;++j){
						if(visit[k][j]==-1 && edges[now_city][j]!=0){
							tmp_p[j] = p[now_city][j] / sum;
						}
						else
							tmp_p[j]=0;
						if(j)
							tmp_p[j]+=tmp_p[j-1];
					}
				
					//the next city
					double go = rand()/RAND_MAX;
					for(j=0;j<n;++j){
						if(visit[k][j]==-1 && edges[now_city][j]!=0){
							if(go > tmp_p[j]) break;
						}
					}
					if(j) --j;
					for(;j>0;--j){
						if(tmp_p[j] != tmp_p[j-1] && edges[now_city][j]!=0 && visit[k][j]==-1){
							break;
						}
					}
#pragma omp critical
					{
						tour[k][i]=j;
						visit[k][j]=1;
					}
				}
#pragma omp barrier
			}

		//calc tour distance
			int tour_sum[m+5];
#pragma omp for
			for(k=0;k<m;++k){
				tour_sum[k]=0;
				for(j=1;j<n;++j){
					tour_sum[k] += edges[tour[k][j-1]][tour[k][j]];
				}
				tour_sum[k] += edges[tour[k][n-1]][tour[k][0]];

				if(tour_sum[k] < loc_data.cost){
#pragma omp critical
					if(tour_sum[k] < loc_data.cost){
						loc_data.cost = tour_sum[k];
						loc_data.rank = myid;
						for(j=0;j<n;++j){
							best_tour[j]=tour[k][j];
						}
					}
				}
			}

			//update the pheromone
#pragma omp barrier
#pragma omp for
			for(k=0;k<n;++k)
				for(j=0;j<n;++j)
					pheromone[k][j] *= eva_rate;

#pragma omp barrier
#pragma omp for
			for(k=0;k<m;++k){
				for(j=1;j<n;++j){
#pragma omp critical
					pheromone[tour[k][j-1]][tour[k][j]] += (double)Q/(double)tour_sum[k];
				}
#pragma omp critical
				pheromone[tour[k][n]][tour[k][0]] += (double)Q/(double)tour_sum[k];
			}

#pragma omp barrier
		}
	}
	if(sz!=1){
		if(myid==0){
			global_data.rank=-1;
			global_data.cost=0xfffffff;
			for(i=1;i<sz;++i){
				MPI_Recv(&loc_data,1,MPI_2INT,i,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
				MPI_Recv(&recv_tour,n+5,MPI_INT,i,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
				if(loc_data.cost<global_data.cost){
					global_data.cost=loc_data.cost;
					global_data.rank=loc_data.rank;
					for(j=0;j<n;++j){
						best_tour[j] = recv_tour[j];
					}
				}
			}
		}
		else{
			MPI_Send(&loc_data,1,MPI_2INT,0,0,MPI_COMM_WORLD);
			MPI_Send(&best_tour,n+5,MPI_INT,0,0,MPI_COMM_WORLD);
		}
	}
	else{
		global_data.cost=loc_data.cost;
		global_data.rank=loc_data.rank;
	}

	if(myid==0){
		printf("Tour_cost: %d from process %d\n",global_data.cost,global_data.rank);
		for(i=0;i<n;++i){
			printf("%d ",best_tour[i]);
		}
		printf("%d\n",best_tour[0]);
	}
	MPI_Finalize();

	return 0;
}
