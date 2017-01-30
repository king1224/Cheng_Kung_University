#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define SIZE_OF_ARRAY 50000

int main(int argc, char* argv[]){
	int thread_count = strtol(argv[1], NULL, 10);
	int i,j,count;
	int a[SIZE_OF_ARRAY];
	int n=SIZE_OF_ARRAY;
	time_t start_t,end_t;
	
	srand(time(&start_t));
	int *tmp = malloc(n*sizeof(int));

	for(i=0;i<n;++i){
		a[i]=rand()%30;
	}


	#pragma omp parallel num_threads(thread_count) \
		default(none) shared(a,n,tmp) private(i,j,count)
	#pragma omp for
	for(i=0;i<n;++i){
		count = 0;
		for(j=0;j<n;++j){
			if(a[i]>a[j])
				++count;
			else if(a[j]==a[i] && j<i)
				++count;
		}
		tmp[count] = a[i];
	}
	#pragma omp barrier

	memcpy(a, tmp, n*sizeof(int));
	free(tmp);

	time(&end_t);
	
	printf("The excution time=%d\n",end_t-start_t);

	return 0;
}
