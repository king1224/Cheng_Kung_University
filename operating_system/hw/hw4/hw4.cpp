#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef struct Node{
	long long PFN;
	char in_use;
	char Present;
}Page;

int main(){
	char buf[1000];
	char *token;
	char policy[100];
	int type;
	long long N,M,ref_num,victim;
	long long psy_count=0;
	long long total=0,fault=0;
	long long block_count,cur_count=0,tmp;
	bool full=false;
	fgets(buf,sizeof(buf),stdin);
	token = strtok(buf,": ");
	token = strtok(NULL,": ");
	sscanf(token,"%s",policy);
	fgets(buf,sizeof(buf),stdin);
	sscanf(buf,"%*s %*s %*s %*s %lld",&N);
	fgets(buf,sizeof(buf),stdin);
	sscanf(buf,"%*s %*s %*s %*s %lld",&M);
	fgets(buf,sizeof(buf),stdin);

	Page page[N+5];
	bool block[N+5];
	long long PFN[M+5];
	long long current_used[M+5];

	memset(page,0,sizeof(page));
	memset(block,false,sizeof(page));
	memset(PFN,-1,sizeof(page));
	
	if(policy[0]=='F' && policy[1]=='I' && policy[2]=='F' && policy[3]=='O')	type=0;
	else if(policy[0]=='L' && policy[1]=='R' && policy[2]=='U')	type=1;
	else if(policy[0]=='R' && policy[1]=='a' && policy[2]=='n' && policy[3]=='d' && policy[4]=='o' && policy[5]=='m')	type=2;
	else	type=-1;

	switch(type){
		case 0:
			while(fgets(buf,sizeof(buf),stdin)!=NULL){
				sscanf(buf,"%*s %lld",&ref_num);
				if(page[ref_num].Present==1){
					total++;
					printf("Hit, %lld=>%lld\n",ref_num,page[ref_num].PFN);
				}
				else{
					total++;
					fault++;	
					if(psy_count>=M){
						for(int i=0;i<N;++i){
							if(!block[i]){
								block_count=i;
								break;
							}
						}
						printf("Miss, %lld, %lld>>%lld, %lld<<%lld\n",psy_count%M,PFN[psy_count%M],block_count,ref_num,page[ref_num].in_use==1?page[ref_num].PFN:-1);
						block[block_count]=true;
						page[PFN[psy_count%M]].PFN=block_count;
						page[PFN[psy_count%M]].Present=0;
						if(page[ref_num].in_use==1)
							block[page[ref_num].PFN]=false;
						page[ref_num].PFN=psy_count%M;
						page[ref_num].Present=1;
						page[ref_num].in_use=1;
					}
					else{
						printf("Miss, %lld, -1>>-1, %lld<<-1\n",psy_count,ref_num);
						page[ref_num].PFN=psy_count%M;
						page[ref_num].Present=1;
						page[ref_num].in_use=1;
					}
					PFN[psy_count%M]=ref_num;
					psy_count = (psy_count+1 > 2*M) ? psy_count+1-M : psy_count+1;
				}
			}
			break;
		case 1:
			while(fgets(buf,sizeof(buf),stdin)!=NULL){
				sscanf(buf,"%*s %lld",&ref_num);
				if(page[ref_num].Present==1){
					total++;
					printf("Hit, %lld=>%lld\n",ref_num,page[ref_num].PFN);
					for(tmp=0;tmp<cur_count;++tmp)
						if(current_used[tmp]==ref_num)	break;
					current_used[cur_count]=current_used[tmp];
					for(;tmp<cur_count;++tmp)
						current_used[tmp]=current_used[tmp+1];
				}
				else{
					total++;
					fault++;	
					if(full){
						for(int i=0;i<N;++i){
							if(!block[i]){
								block_count=i;
								break;
							}
						}
						tmp = current_used[0];
						printf("Miss, %lld, %lld>>%lld, %lld<<%lld\n",page[tmp].PFN,tmp,block_count,ref_num,page[ref_num].in_use==1?page[ref_num].PFN:-1);
						block[block_count]=true;
						if(page[ref_num].in_use==1)
							block[page[ref_num].PFN]=false;
						page[ref_num].PFN=page[tmp].PFN;
						page[ref_num].Present=1;
						page[ref_num].in_use=1;
						page[tmp].PFN=block_count;
						page[tmp].Present=0;

						current_used[cur_count]=ref_num;
						for(tmp=0;tmp<cur_count;++tmp)
							current_used[tmp] = current_used[tmp+1];
					}
					else{
						printf("Miss, %lld, -1>>-1, %lld<<-1\n",psy_count,ref_num);
						page[ref_num].PFN=psy_count;
						page[ref_num].Present=1;
						page[ref_num].in_use=1;
						current_used[cur_count++]=ref_num;
						++psy_count;
						if(psy_count==M)	full=true;
					}
					PFN[psy_count]=ref_num;
				}
			}
			break;
		case 2:
			srand(time(NULL));
			while(fgets(buf,sizeof(buf),stdin)!=NULL){
				sscanf(buf,"%*s %lld",&ref_num);
				if(page[ref_num].Present==1){
					total++;
					printf("Hit, %lld=>%lld\n",ref_num,page[ref_num].PFN);
				}
				else{
					total++;
					fault++;	
					if(full){
						for(int i=0;i<N;++i){
							if(!block[i]){
								block_count=i;
								break;
							}
						}
						victim = rand() % M;
						printf("Miss, %lld, %lld>>%lld, %lld<<%lld\n",victim,PFN[victim],block_count,ref_num,page[ref_num].in_use==1?page[ref_num].PFN:-1);
						block[block_count]=true;
						if(page[ref_num].in_use==1)
							block[page[ref_num].PFN]=false;
						page[ref_num].PFN=page[PFN[victim]].PFN;
						page[ref_num].Present=1;
						page[ref_num].in_use=1;
						page[PFN[victim]].PFN=block_count;
						page[PFN[victim]].Present=0;
						psy_count=victim;
						PFN[psy_count]=ref_num;
					}
					else{
						printf("Miss, %lld, -1>>-1, %lld<<-1\n",psy_count,ref_num);
						page[ref_num].PFN=psy_count%M;
						page[ref_num].Present=1;
						page[ref_num].in_use=1;
						PFN[psy_count]=ref_num;
						++psy_count;
						if(psy_count==M)	full=true;
					}
				}
			}
			break;
		dafault:
			break;
	}
	printf("Page Fault Rate: %.3f\n",(double)fault/(double)total);
	return 0;
}
