#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>

#define sem_name1 "sem_numbers"
#define sem_name2 "sem_stores"

typedef struct Node{	//domain name with IP
	char domain_name[30][100];
	size_t IP[4];
	size_t dirty;
}Domain;

typedef struct Node2{	//parameter struct
	int fd;
}arg;

int domain_numbers;		//how many domain beed stored
static sem_t *sem_numbers=NULL;	//semaphore for change the domain_numbers
static sem_t *sem_stores=NULL;	//semaphore for change the domain information

Domain domain_store[3000];	//store data with max 3000

void *handle_request(void *fd);

int main(void){
	size_t sockfd;
	arg arge;
	struct addrinfo hints, *servinfo, *p;
	struct sockaddr_storage their_addr;
	socklen_t sin_size;
	struct sigaction sa;
	size_t yes=1,num=0;
	char s[10000];
	size_t rv;
	size_t i;
	memset(&hints,0,sizeof(hints));
	memset(domain_store,0,sizeof(domain_store));
	for(i=0;i<3000;++i)	domain_store[i].dirty=-1;	//dirty==1 means havn't been used
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = 0;
	domain_numbers = 0;
	//create two semaphore
	sem_numbers = sem_open(sem_name1,O_RDWR|O_CREAT,00777,1);
	sem_stores = sem_open(sem_name2,O_RDWR|O_CREAT,00777,1);

	//set for pthread
	pthread_t tid[10000];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setscope(&attr,PTHREAD_SCOPE_SYSTEM);
	pthread_attr_setschedpolicy(&attr,SCHED_OTHER);

	//get addrinfo
	if((rv = getaddrinfo("127.0.0.1", "12345", &hints, &servinfo)) != 0){
		printf("getaddrerror\n");
		return 1;
	}

	//open socket
	for(p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype,p->ai_protocol)) == -1) {
				perror("server: socket");
				continue;
		}

		if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes,sizeof(int)) == -1) {
			perror("setsockopt");
			exit(1);
		}
	
		if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			perror("server: bind");
			continue;
		}

		break;
	}

	if(p==NULL){
		printf("getError\n");
		return 0;
	}

	freeaddrinfo(servinfo);

	//listen
	if(listen(sockfd,1000)==-1){
		printf("listen error\n");
		exit(1);
	}
	
	//loop for wait connection
	while(1){
		sin_size=sizeof(their_addr);
		arge.fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
		if(arge.fd==-1){
			continue;
		}

		//show connection from where
		inet_ntop(their_addr.ss_family,&(((struct sockaddr_in*)&their_addr)->sin_addr),s,sizeof(s));
		printf("server:got connection %s\n",s);
		
		//create a thread for handle request for this client
		pthread_create(&tid[num++],&attr,handle_request,(void *)&arge);
	}


	return 0;
}



void *handle_request(void *fd){
	arg *rec = (arg*)fd;
	int new_fd = rec->fd;
	size_t length=0;
	size_t IP[4];
	size_t IP_count;
	size_t domain_count;
	char s[10000];
	Domain tmp;
	char *recv_type;
	char *recv_name;
	char *recv_IP;
	char *token;
	size_t i,j,k,r;
	size_t notFound=0;

	while(1){
		//read length of request
		if(read(new_fd,s,sizeof(s))==-1){
			printf("read length error\n");
			pthread_exit(0);
		}
		length=s[0];
		//read request
		if(read(new_fd,s,sizeof(s))==-1){
			printf("read error\n");
			pthread_exit(0);
		}
		s[length]='\0';
		//print what recv
		//if s is not update means recv nothing, client is close
		printf("I read this! %s\n",s);
		if((s[0]=='2' && s[1]=='0' && s[2]=='0')
		|| (s[0]=='4' && s[1]=='0' && s[2]=='0')
		|| (s[0]=='4' && s[1]=='0' && s[2]=='4')
		|| (s[0]=='4' && s[1]=='0' && s[2]=='5')
		|| s==NULL) break;

		//partition the request
		token=strtok(s," \n");
		recv_type=token;
		token=strtok(NULL," \n");
		recv_name=token;
		token=strtok(NULL," \n");
		recv_IP=token;
		
		//Big-case to Little-case
		if(recv_name!=NULL){
			for(i=0;i<strlen(recv_name);++i){
				if(recv_name[i]>=65 && recv_name[i]<=90)
					recv_name[i]+=32;
			}
		}

		//take each label
		domain_count=0;
		for(token=strtok(recv_name,". ");token!=NULL;token=strtok(NULL,". ")){
			sprintf(tmp.domain_name[domain_count++],"%s",token);
		}
		//end of label, set -1
		tmp.domain_name[domain_count][0]=-1;
		tmp.domain_name[domain_count][1]=-1;
		tmp.domain_name[domain_count][2]=-1;
		tmp.domain_name[domain_count][3]=-1;
		tmp.domain_name[domain_count][4]=-1;

		switch(s[0]){
			case 'S':		//may SET
				if(recv_IP!=NULL)
					IP_count = sscanf(recv_IP,"%d.%d.%d.%d",&IP[0],&IP[1],&IP[2],&IP[3]);
				else
					IP_count = 0;
				if(s[1]!='E'||s[2]!='T'){
					length=24;
					sprintf(s,"405 \"METHOD NOT ALLOWED\"");
				}
				//no domain_name, no IP, wrong domain_name, wrong IP address
				else if(domain_count <= 1 || recv_name==NULL || recv_IP==NULL || IP_count!=4 || IP[0]<0 || IP[0]>255 || IP[1]<0 || IP[1]>255 || IP[2]<0 || IP[2]>255 || IP[3]<0 || IP[3]>255){
					length=17;
					sprintf(s,"400 \"BAD REQUIST\"");
				}
				else{		//find or create a domain information, and set it's IP address
					//only one thread can read/write domain_store at the same time
					sem_wait(sem_stores);
					//where to store this domain, 0~99 for a, 100~199 for b.......
					j=(tmp.domain_name[0][0]-'a')*100;
					for(i=j;domain_store[i].dirty!=-1;++i){//if this space has been used, check it's domain_name is as same as now we want to set
						notFound=0;
						//for each label
						for(k=0;k<domain_count;++k){
							//if length different or label name different, notFound = true , then check next domain we stored
							if(strlen(tmp.domain_name[k])==strlen(domain_store[i].domain_name[k])){
								for(r=0;r<strlen(tmp.domain_name[k]);++r){
									if(tmp.domain_name[k][r]!=domain_store[i].domain_name[k][r]){
										notFound=1;
										break;
									}
								}
							}
							else{
								notFound=1;
								break;
							}
							if(notFound==1)	break;
						}
						if(notFound==0){
							break;
						}
					}
					//if not found the same domain, i is position for new space to store this domain
					if(domain_store[i].dirty==-1){
						domain_store[i].dirty=1;
						//lock when want to change global domain_numbers
						sem_wait(sem_numbers);
						domain_numbers++;						
						sem_post(sem_numbers);
					}
					//copy this new domain to new space
					//if found the same domain, just cover it with the same name
					for(j=0;j<domain_count;++j){
						sprintf(domain_store[i].domain_name[j],"%s",tmp.domain_name[j]);
					}
					//update it's IP address
					domain_store[i].IP[0]=IP[0];
					domain_store[i].IP[1]=IP[1];
					domain_store[i].IP[2]=IP[2];
					domain_store[i].IP[3]=IP[3];
					length=8;
					sprintf(s,"200 \"OK\"");
					//signal semaphore
					sem_post(sem_stores);
				}
				
				break;
				
			case 'G':		//may GET
				if(s[1]!='E'||s[2]!='T'){
					length=24;
					sprintf(s,"405 \"METHOD NOT ALLOWED\"");
				}
				//if enter IP address, no domain_name, wrong domain_name
				else if(domain_count <=1 || recv_name==NULL || recv_IP!=NULL){
					length=17;
					sprintf(s,"400 \"BAD REQUIST\"");
				}
				else{
					//start to find the same domain_name
					//just like SET
					sem_wait(sem_stores);
					j=(tmp.domain_name[0][0]-'a')*100;
					for(i=j;domain_store[i].dirty!=-1;++i){
						notFound=0;
						for(k=0;k<domain_count;++k){
							if(strlen(tmp.domain_name[k])==strlen(domain_store[i].domain_name[k])){
								for(r=0;r<strlen(tmp.domain_name[k]);++r){
									if(tmp.domain_name[k][r]!=domain_store[i].domain_name[k][r]){
										notFound=1;
										break;
									}
								}
							}
							else{
								notFound=1;
								break;
							}
							if(notFound==1)	break;
						}
						if(notFound==0){
							break;
						}
					}
					//find one position that store this domain
					if(domain_store[i].dirty==1){
						length=sprintf(s,"200 \"OK\" %d.%d.%d.%d",domain_store[i].IP[0],domain_store[i].IP[1],domain_store[i].IP[2],domain_store[i].IP[3]);
					}
					else{ //else Not Found
						length=15;
						sprintf(s,"404 \"NOT FOUND\"");
					}
					sem_post(sem_stores);
				}
				break;
			case 'I':		//may INFO
				if(s[1]!='N'||s[2]!='F'||s[3]!='O'){
					length=24;
					sprintf(s,"405 \"METHOD NOT ALLOWED\"");
					break;
				}
				else{
					sem_wait(sem_numbers);
					length=sprintf(s,"200 \"OK\" %d",domain_numbers);
					sem_post(sem_numbers);
				}
				break;
			default:		//not SET, GET, INFO
					length=24;
					sprintf(s,"405 \"METHOD NOT ALLOWED\"");
				break;
		}
		//write back response
		write(new_fd,&length,sizeof(size_t));
		write(new_fd,s,length);
		sleep(1);
	}
	//finish request, close this connection and thread
	close(new_fd);
	pthread_exit(0);
}
