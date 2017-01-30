#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <omp.h>

char file_word[10000][10000];
char keywords[10000][10000];
char word_buf[10000][100];

int main(int argc, char* argv[]){
	int thread_count = strtol(argv[1], NULL, 10);
	int i,j,k,str_count=-1,end_count=-1,n=0,num_per_line=0,file_number=0;
	int match=0,ready_to_match=0,finish_count=0;
	int keywords_count[10000];
	char buf[10000];
	char filename[100][100];
	char *token,*saveptr1;
	char tmp[10000];
	FILE *p;
	DIR	*pDir;
	struct dirent *pDirent;

	memset(keywords_count,0,sizeof(keywords_count));

	sprintf(tmp,"%s/keyword.txt",argv[2]);
	p = fopen(tmp,"r");
	while(fgets(buf,sizeof(buf),p)!= NULL){
		for(i=0;i<strlen(buf);++i){
			if(buf[i]>='A' && buf[i]<='Z'){
				buf[i] = buf[i] - 'A' + 'a';
			}
		}
		for(token = strtok_r(buf," .,\n\0",&saveptr1); token != NULL ; token = strtok_r(NULL," .,\n\0",&saveptr1)){
			sprintf(keywords[n++],"%s",token);
		}
	}
	fclose(p);

	
	pDir = opendir(argv[2]);
	file_number=0;
	if(pDir==NULL)
		printf("Cannot open : %s\n",argv[2]);

	while((pDirent=readdir(pDir))!=NULL){
		if(strcmp(pDirent->d_name,".")!=0 && strcmp(pDirent->d_name,"..")!=0&& strcmp(pDirent->d_name,"keyword.txt")!=0){
			sprintf(filename[file_number++],"%s/%s",argv[2],pDirent->d_name);
		}
	}
	closedir(pDir);

	for(k=0;k<file_number;++k){

	p = fopen(filename[k],"r");
	if(p==NULL) printf("MDFK\n");

	#pragma omp parallel num_threads(thread_count) \
		default(none) shared(file_word,str_count,finish_count,end_count,keywords,keywords_count,n,p) private(buf,word_buf,token,i,j,num_per_line,saveptr1,ready_to_match)
	
		if(omp_get_thread_num()%3){
			while(finish_count< (omp_get_thread_num()/3 +1) || str_count<end_count){
				#pragma omp critical
				{
					if(str_count<end_count){
						++str_count;
						num_per_line=0;
						for(token = strtok_r(file_word[str_count]," .,\n\0",&saveptr1); token != NULL ; token = strtok_r(NULL," .,\n\0",&saveptr1)){
							sprintf(word_buf[num_per_line++],"%s",token);
						}
						ready_to_match=1;
					}
					else{
						ready_to_match=0;
					}
				}
				if(ready_to_match==1){
					for(j=0;j<num_per_line;++j){
						for(i=0;i<n;++i){
							if(strcmp(keywords[i],word_buf[j])==0){
								#pragma omp critical
								++keywords_count[i];
								break;
							}
						}
					}
				}
			}
		}
		else{
			while(fgets(buf,sizeof(buf),p)!= NULL){
				for(i=0;i<strlen(buf);++i){
					if(buf[i]>='A' && buf[i]<='Z'){
						buf[i] = buf[i] - 'A' + 'a';
					}
				}
				#pragma omp critical
				{
					strcpy(file_word[end_count+1],buf);
					++end_count;
				}
			}
			#pragma omp critical
			++finish_count;
		}
		#pragma omp barrier

		fclose(p);
	}

	#pragma omp single
	for(i=0;i<n;++i)
		printf("%s:%d\n",keywords[i],keywords_count[i]);
	
	return 0;
}
