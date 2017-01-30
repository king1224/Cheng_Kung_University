#ifndef MAILBOX_H
#define MAILBOX_H

#define OPEN_FLAG O_CREAT|O_RDWR
#define OPEN_MODE 00777
#define FILE_SIZE 4096*100
#define SIZE_OF_SHORT_STRING 64
#define SIZE_OF_LONG_STRING 512
#define EXIT 10						//very much command type
#define REGISTER 20					//and some server sype
#define LIST 30
#define EXIT_ONE 40
#define JOIN 100
#define BROADCAST 200
#define LEAVE 300
#define WHISPER 400
#define CHANGEROOM 500

#include <cstdlib>
#include <cstdio>
#include <sys/mman.h>
#include <cstring>
#include <sys/file.h>

using namespace std;

typedef struct __MAIL{
	int from;
	int type;
	char sstr[SIZE_OF_SHORT_STRING];
	char lstr[SIZE_OF_LONG_STRING];
}mail_t;

typedef void* mailbox_t;

//open a memory in OS and return the mailbox name 
mailbox_t mailbox_open(int id){
	char *name = (char*)malloc(20*sizeof(char));
	char buf[FILE_SIZE];
	int fd,mail_cnt;

	sprintf(name,"__mailbox_%d",id);

	fd = shm_open(name,OPEN_FLAG,OPEN_MODE);
	ftruncate(fd,FILE_SIZE);

	mailbox_t addr = mmap(NULL,FILE_SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,fd,SEEK_SET);

	memcpy(buf,addr,FILE_SIZE);

	if(sscanf(buf,"%d",&mail_cnt)!=1 || mail_cnt>=60 || mail_cnt<0){
		sprintf(buf,"00\n");
	}

	memcpy(addr,buf,FILE_SIZE);
	munmap(addr,FILE_SIZE);

//	printf("[OPEN]Creat %d\n",id);
	return name;
}

//remove the mailbox memory
int mailbox_unlink(int id){
	char name[20];

	sprintf(name,"__mailbox_%d",id);

	shm_unlink(name);

	return 0;
}

//close the reference to this mailbox but not delete memory
int mailbox_close(mailbox_t box){
	box=NULL;
	return 0;
}

//send mail to one mailbox
int mailbox_send(mailbox_t box,mail_t *mail){
	char buf[FILE_SIZE];
	int fd,mail_cnt;

	fd = shm_open((char*)box,OPEN_FLAG,OPEN_MODE);
	ftruncate(fd,FILE_SIZE);
	mailbox_t addr = mmap(NULL,FILE_SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,fd,SEEK_SET);

	//first,take the all mail in this mailbox
	memcpy(buf,addr,FILE_SIZE);
	
	//put new mail in the end of the last mail
	if(sscanf(buf,"%d",&mail_cnt)!=0 && mail_cnt<99 && mail_cnt>=0){
		char *tmp;
		tmp=&buf[strlen(buf)];
		sprintf(tmp,"%d\t",(*mail).from);
		tmp=&buf[strlen(buf)];
		sprintf(tmp,"%d\t",(*mail).type);
		tmp=&buf[strlen(buf)];
		sprintf(tmp,"%s\t",(*mail).sstr);
		tmp=&buf[strlen(buf)];
		sprintf(tmp,"%s\n",(*mail).lstr);

		//updating the total mail number in this mailbox
		if(mail_cnt%10==9){
			buf[0]+=1;
			buf[1]-=9;
		}
		else{
			buf[1]+=1;
		}
//		printf("[Send]After Send\n");
//		printf("%s:\n",(char*)box);
//		printf("%s\n",buf);
//		printf("[Send]After_Send_end\n");
	}
	else{
		printf("mail_cnt=%d\n",mail_cnt);
		printf("sned_wrong\n");
		return -1;
	}

	memcpy(addr,buf,FILE_SIZE);

	munmap(addr,FILE_SIZE);

	return 0;
}

//recv a mail from one mailbox
int mailbox_recv(mailbox_t box,mail_t *mail){
	char buf1[FILE_SIZE],buf2[FILE_SIZE];
	int fd,mail_cnt;

	fd = shm_open((char*)box,OPEN_FLAG,OPEN_MODE);
	ftruncate(fd,FILE_SIZE);
	mailbox_t addr = mmap(NULL,FILE_SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,fd,SEEK_SET);

	//read the all mail in this mailbox
	memcpy(buf1,addr,FILE_SIZE);

	//take the first mail
	if(sscanf(buf1,"%d",&mail_cnt)!=0 && mail_cnt<99 && mail_cnt>=0){
		sscanf(buf1,"%*d %d %d %[^\t] %[^\n]",&(*mail).from,&(*mail).type,(*mail).sstr,(*mail).lstr);

		char *token = strtok(buf1,"\t\n");
		sprintf(buf2,"%s\n",token);
		token=strtok(NULL,"\t\n");		//delete the first mail by not to store
		token=strtok(NULL,"\t\n");
		token=strtok(NULL,"\t\n");
		token=strtok(NULL,"\t\n");
		token=strtok(NULL,"\t\n");
		//store any other mails to buf2
		while(token!=NULL){
			for(int i=0;i<4;++i){
				char *tmp;
				tmp = &buf2[strlen(buf2)];

				if(i==3)
					sprintf(tmp,"%s\n",token);
				else
					sprintf(tmp,"%s\t",token);

				token = strtok(NULL,"\t\n");
			}
		}
		//the updating mailbox is in buf1 now
		strcpy(buf1,buf2);

		if(mail_cnt%10){
			buf1[1]-=1;
		}
		else{
			buf1[1]+=9;
			buf1[0]-=1;
		}

//		printf("[Recv]after_recv\n");
//		printf("%s:\n",(char*)box);
//		printf("%s\n",buf1);
//		printf("[Recv]after_recv_end\n");
	}
	else{
		printf("recv_wrong\n");
		return -1;
	}
	
	//write buf1 back to mailbox
	memcpy(addr,buf1,FILE_SIZE);

	munmap(addr,FILE_SIZE);

	return 0;
}

int mailbox_check_empty(mailbox_t box){
	int fd;
	fd = shm_open((char*)box,OPEN_FLAG,OPEN_MODE);
	ftruncate(fd,FILE_SIZE);
	mailbox_t addr = mmap(NULL,FILE_SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,fd,SEEK_SET);
	char buf[5];
	int mail_cnt=-1;
	memcpy(buf,addr,5);
	munmap(addr,FILE_SIZE);
	//the first two char is the number of mail
	if(sscanf(buf,"%d",&mail_cnt)!=0 && mail_cnt<60 &&mail_cnt>=0){
		if(mail_cnt==0)
			return 1;
		return 0;
	}
	else{
		printf("cheak_empty_error %d\n",mail_cnt);
		return -1;
	}
}

int mailbox_check_full(mailbox_t box){
	int fd;
	fd = shm_open((char*)box,OPEN_FLAG,OPEN_MODE);
	ftruncate(fd,FILE_SIZE);
	mailbox_t addr = mmap(NULL,FILE_SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,fd,SEEK_SET);
	char buf[5];
	int mail_cnt;
	memcpy(buf,addr,5);
	munmap(addr,5);
	//the first two char is the number of mail
	if(sscanf(buf,"%d",&mail_cnt)!=0 && mail_cnt<60 &&mail_cnt>=0){
		if(mail_cnt>98)
			return 1;
		return 0;
	}
	else{
		printf("cheak_empty_error\n");
		return -1;
	}
}

#endif
