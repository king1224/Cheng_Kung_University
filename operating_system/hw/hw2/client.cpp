#include <cstdio>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <string>
#include <map>
#include <iostream>
#include "Mailbox.h"

using namespace std;

int main(){
	int flag;			//use to non-blocking io 
	int room_number;	//chatroom number switch to
	char action[100];	//the command input
	bool isusing=true;	//user is using
	bool choosing;		//choosing command
	bool chatrooming;	//in chatroom
	bool client_used[100];	//the id has been used or not
	bool chating;		//keep sending message
	bool whispering;	//whisper to someone
	memset(client_used,false,sizeof(client_used));	//no user take any
	string client_name[100];	//the i-th id's user name
	map<string,int> m;	//to find user's id
	string user;		//the one is using
	string input;		//get user name
	mail_t client_mail,recv_mail;	//mail for send and recv
	mailbox_t mailbox[100];	//can 100 user at one time
	mailbox[0] = mailbox_open(0);	//server
	mailbox[99] = mailbox_open(99);	//store the number of total user in here

REUSER:
	flag = fcntl(STDIN_FILENO,F_GETFL,0);		//non blocking io
	fcntl(STDIN_FILENO,F_SETFL,flag&(~O_NONBLOCK));
	flag = fcntl(STDOUT_FILENO,F_GETFL,0);
	fcntl(STDOUT_FILENO,F_SETFL,flag&(~O_NONBLOCK));
	
	//scanf user name
	user.assign("NON");
	printf("Please enter your user name:\n");
	while(user=="NON"){
		cin >> input;
		if(!input.empty()){
			user.assign(input);
		}
	}

	//check if user has register before
	//and open the mailbox to him
	if(m.find(user)==m.end()){
		mailbox_recv(mailbox[99],&recv_mail);
		mailbox_send(mailbox[99],&recv_mail);

		client_mail.from=recv_mail.from+1;
		client_mail.type=REGISTER;
		sprintf(client_mail.sstr,"%s",user.c_str());
		mailbox_send(mailbox[0],&client_mail);

		for(int i=1;i<recv_mail.from+1;++i){
			client_used[i]=true;
		}
		client_name[recv_mail.from+1]=user;
		m[client_name[recv_mail.from+1]]=recv_mail.from+1;
		mailbox[recv_mail.from+1]=mailbox_open(recv_mail.from+1);
	}
	else{
		client_mail.from=m.find(user)->second;
		sprintf(client_mail.sstr,"%s",user.c_str());
	}
	sprintf(client_mail.lstr,"fake");

	//start using
	while(isusing){
RECHOOSE:
		flag = fcntl(STDIN_FILENO,F_GETFL,0);
		fcntl(STDIN_FILENO,F_SETFL,flag&(~O_NONBLOCK));
		flag = fcntl(STDOUT_FILENO,F_GETFL,0);
		fcntl(STDOUT_FILENO,F_SETFL,flag&(~O_NONBLOCK));

		printf("\nChoose one action.(Enter the letter)\n");
		printf("(A)Join Chatroom\t(B)Exit Without Close Others\t(C)Change User\t(D)Exit\n");
		choosing=true;
		action[0]=10;
		while(choosing){
			fgets(action,sizeof(action),stdin);
			if(action[0]!=10){
				choosing=false;
			}
		}
		switch(action[0]){
			//goind to chatroom
			case 'a':
			case 'A':
//				printf("[debugclient]Send_Join\n");
				client_mail.type=JOIN;
				mailbox_send(mailbox[0],&client_mail);
				chatrooming=true;
				break;
			//close the program
			case 'b':
			case 'B':
				client_mail.type=EXIT_ONE;
				mailbox_send(mailbox[0],&client_mail);
				return 0;
				break;
			//back to log-in page
			case 'c':
			case 'C':
//				printf("[debugclient]Changeuser\n");
				goto REUSER;
				break;
			//close the program and close any other program
			case 'd':
			case 'D':
				isusing=false;
				client_mail.type=EXIT;
				mailbox_unlink(client_mail.from);
				mailbox_send(mailbox[0],&client_mail);
//				printf("[debugclient]Send_Exit\n");
				return 0;
				break;
			default:
				printf("Can't recognize this action\n");
				goto RECHOOSE;
		}

		//non blocking io
CHATROOM:
		chating=false;
		whispering=false;
		flag = fcntl(STDIN_FILENO,F_GETFL,0);
		fcntl(STDIN_FILENO,F_SETFL,flag|O_NONBLOCK);
		flag = fcntl(STDOUT_FILENO,F_GETFL,0);
		fcntl(STDOUT_FILENO,F_SETFL,flag|O_NONBLOCK);
		printf("\nChoose one action.(Enter the letter)\n");
		printf("(A)Broadcast\t(B)Whisper\t(C)Change chatroom\t(D)List users\t(E)Leave\n");
		action[0]=10;
		chatrooming=true;

		//recv message first
RECVMSG:
		while(!mailbox_check_empty(mailbox[m.find(user)->second])){
			mailbox_recv(mailbox[m.find(user)->second],&recv_mail);
			switch(recv_mail.type){
				case JOIN:
					printf("\n[System]Vip 8{Child King}: %s has join in chatroom.\nLet's welcome he/she.\n",recv_mail.sstr);
					break;
				case BROADCAST:
					printf("\n[Broadcast]%s:%s\n",recv_mail.sstr,recv_mail.lstr);
					break;
				case LEAVE:
					printf("\n[System]Vip 8{Child King}: %s has leave in chatroom.\nLet's cry two seconds for his/her leaving.\n",recv_mail.sstr);
					break;
				case LIST:
					printf("\nThe user in this chatroom:\n");
					puts(recv_mail.lstr);
					break;
				case WHISPER:
					printf("\n[Whisper] >w< {Your Lover}%s:%s\n",recv_mail.sstr,recv_mail.lstr);
					break;
				case EXIT:
					mailbox_unlink(client_mail.from);
					return 0;
				default:
					printf("RECVMSG_error\n");
			}
		}
		
		//if recv message while whispering to someone
		//after recv , back to whisper
		if(whispering)
			goto WHISPERING;
			
		//if recv massage while broadcast to all user
		//after recv , back to chating
		if(chating)
			goto CHATING;

		//get the command in line 136
		while(chatrooming){
			sleep(1);
			fgets(action,sizeof(action),stdin);
			if(action[0]!=10)
				chatrooming=false;
			else
				goto RECVMSG;
		}
		
		switch(action[0]){
			//broadcasting
			case 'a':
			case 'A':
				printf("\nEniter the content you want to say.(Enter E for leave)\n");
				client_mail.type = BROADCAST;
				chating=true;
CHATING:				
				//keeping chating until enter E to stop
				while(1){
					while(!fgets(client_mail.lstr,sizeof(client_mail.lstr),stdin)){
						sleep(1);
						goto RECVMSG;
					}
					if(client_mail.lstr[0]=='e' || client_mail.lstr[0]=='E'){
						if(client_mail.lstr[1]=='\n' && client_mail.lstr[2]=='\0'){
							chating=false;
							break;
						}
						mailbox_send(mailbox[0],&client_mail);
					}
					else
						mailbox_send(mailbox[0],&client_mail);
				}
				goto CHATROOM;
				break;
			//whispering
			case 'b':
			case 'B':
				//choose one you want to whisper to
				//list all users in this chatroom
				//so the user can choose one to whisper
				printf("\nChoose one you want to send whisper:\n");
				client_mail.type=LIST;
				mailbox_send(mailbox[0],&client_mail);
				whispering=true;
				sleep(2);
				mailbox_recv(mailbox[m.find(user)->second],&recv_mail);
				puts(recv_mail.lstr);
				action[0]=10;
				//get the one user want to
				while(1){
					sleep(1);
					fgets(action,sizeof(action),stdin);
					if(action[0]!=10)
						break;
				}
				//start send message
				client_mail.type=WHISPER;
				sprintf(client_mail.sstr,"To");
				sprintf(client_mail.lstr,"%s",action);
				mailbox_send(mailbox[0],&client_mail);
				sprintf(client_mail.sstr,"%s",user.c_str());
				printf("\nStart whisper:(Enter E for leave)\n");
WHISPERING:
				//keep talking until enter E for leave
				while(1){
					while(!fgets(client_mail.lstr,sizeof(client_mail.lstr),stdin)){
						sleep(1);
						goto RECVMSG;
					}
					if(client_mail.lstr[0]=='e' || client_mail.lstr[0]=='E'){
						if(client_mail.lstr[1]=='\n' && client_mail.lstr[2]=='\0'){
							whispering=false;
							break;
						}
						mailbox_send(mailbox[0],&client_mail);
					}
					else
						mailbox_send(mailbox[0],&client_mail);
				}
				goto CHATROOM;
				break;
			//have ten chatroom to choose
			case 'c':
			case 'C':
				client_mail.type=CHANGEROOM;
				printf("\nWhich chatroom you want to in?\nPlease enter 1~10.\n");
				action[0]=10;
				while(1){
					fgets(action,sizeof(action),stdin);
					if(action[0]!=10){
						sscanf(action,"%d",&room_number);
						break;
					}
				}
//				printf("[Debug] Room_number=%d\n\n",room_number);
				sprintf(client_mail.lstr,"%d",room_number);
				mailbox_send(mailbox[0],&client_mail);
				break;
			//list all users only in this chatroom
			case 'd':
			case 'D':
				client_mail.type=LIST;
				mailbox_send(mailbox[0],&client_mail);
				break;
			//leave chatroom, can't get message but not delete the account
			case 'e':
			case 'E':
//				printf("[debugclient]Send_Leave\n");
				client_mail.type=LEAVE;
				mailbox_send(mailbox[0],&client_mail);
				chatrooming=false;
				goto RECHOOSE;
				break;
			default:
				printf("Can't recognize this action\n");
				break;
		}
		goto CHATROOM;
	}
}
