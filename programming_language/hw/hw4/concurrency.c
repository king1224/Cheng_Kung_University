#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>
#include<omp.h>
#define MAX 100

typedef struct __ARG{
	int a,b;
}arg;

int ans[MAX][MAX],ans1[MAX][MAX],ans2[MAX][MAX];
int A[MAX][MAX],B[MAX][MAX];
int n,m;

void mul(void* args){
	arg *data = (arg*) args;
	int tmp = 0;
	int i , j;
	for(j=0;j<m;j++)
		tmp += A[(*data).a][j] * B[j][(*data).b];
		ans[(*data).a][(*data).b] = tmp;
}
void mul1(int a, int b){
    int tmp = 0;
    int i , j;
    for(j=0;j<m;j++)
	tmp += A[a][j] * B[j][b];
    ans2[a][b] = tmp;
}

int main(){
	int i,j;

	FILE *input_file = fopen("input.txt","r");
	if(input_file==NULL){
		printf("file not exists");
		exit(-1);
	}
	fscanf(input_file,"%d %d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			fscanf(input_file,"%d", &A[i][j]);		
		}	
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			fscanf(input_file,"%d",&B[i][j]);		
		}	
	}
 	fclose(input_file);

    /*Multiply matrix*/
	time_t start=time(NULL);
	pthread_t THREAD[n][n];
	arg data[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
		data[i][j].a = i;
		data[i][j].b = j;
		pthread_create(&THREAD[i][j],NULL,(void*)mul,(void*)&data[i][j]);
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			pthread_join(THREAD[i][j],NULL);
		}
	}
	time_t end=time(NULL);
	/*single */
	int temp1=0;
	int k;

	time_t start_1=time(NULL);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			for(k=0;k<m;k++){
			temp1+=A[i][k]*B[k][j];
			}
			ans1[i][j]=temp1;
			temp1=0;
		}
	}
	time_t end_1=time(NULL);
	time_t start_2=time(NULL);
	/*openmp*/
	#pragma omp parallel for num_threads(100)
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			mul1(i,j); 
		}
	}
	time_t end_2=time(NULL);

	FILE *output_file = fopen("output.txt","w");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			fprintf(output_file,"%d ",ans[i][j]);
		}
		fprintf(output_file,"\n");
	}
	fclose(output_file);
	double ex_time=(double)(end-start);
	double ex_time1=(double)(end_1-start_1);
	double ex_time2=(double)(end_2-start_1);
	printf("time (with concurrency)= %.3f s\n",ex_time);
	printf("time (without concurrency)= %.3f s\n",ex_time1);
	printf("time (with OpenMP concurrency)=%.3f s\n",ex_time2);
	int c1,c2;
	printf("Enter the element (i,j) want to show:");
	scanf("%d %d",&c1,&c2);
	printf("the element of (i,j) is %d\n",ans[c1-1][c2-1]);

}   

