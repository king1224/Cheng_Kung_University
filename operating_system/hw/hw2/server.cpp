#include <cstdio>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include "Mailbox.h"

using namespace std;

int main(){
	int flag;
	bool client_used[100];		//check if user id has been used
	bool working=true;			//the server is working
	char client_name[100][50];	//save at most 100 users name
	int user_position[100];		//save user in which chat room now
	memset(client_used,false,sizeof(client_used));
	int whisper_list[100];		//save who is whisper to who

	map<string,int> m;			//use to find the user's id
	vector<int> room_user[15];	//use to save who in the chatroom[i]

	mailbox_t mailbox[100];		//at most 100 users
	mailbox[0]=mailbox_open(0);	//server
	mailbox[99]=mailbox_open(99);	//store how many user's id has been used

	mail_t server_mail;			//server's mail

	server_mail.type=server_mail.from=0;	//init
	sprintf(server_mail.sstr,"Nothing");
	sprintf(server_mail.lstr,"Nothing");

	mailbox_send(mailbox[99],&server_mail);	//give mailbox[99] that now zero users

	int count=0;
	char *tmp;
	while(working){
		//keep check mailbox to see if any things need to process
		while(mailbox_check_empty(mailbox[0])){
			sleep(1);
		}
		//if non empty , recv the mail
		mailbox_recv(mailbox[0],&server_mail);
//		printf("\n[debugServ][Mail]from=%d\ttype=%d\tsstr=%s\tlstr=%s\t\n\n",server_mail.from,server_mail.type,server_mail.sstr,server_mail.lstr);
		int from=server_mail.from;
		server_mail.from=0;
		bool alreadyin=false;
		int leave_user;
		switch(server_mail.type){
			//exit and close all users and clean the memery
			case EXIT:
//				printf("[DebugServ]EXIT\n");
				for(int i=1;i<100;++i){
					if(client_used[i]){
						mailbox_send(mailbox[i],&server_mail);
//						mailbox_unlink(i);
					}
				}
				mailbox_unlink(0);
				mailbox_unlink(99);
				working=false;
				return 0;
				break;
			//register a user's imformation
			case REGISTER:
//				printf("[DebugServ]Register\n");
				client_used[from]=true;
				sprintf(client_name[from],"%s",server_mail.sstr);
				server_mail.from=from;
				if(m.find(client_name[from])==m.end()){
					m[client_name[from]]=from;
				}
				mailbox[from]=mailbox_open(from);
				mailbox_send(mailbox[99],&server_mail);
				mailbox_recv(mailbox[99],&server_mail);
				break;
			//store all user in this chatroom into mail.lstr and send to client to show
			case LIST:
				server_mail.lstr[0]='\0';
				for(int i=0;i<room_user[user_position[from]].size();++i){
					tmp = &server_mail.lstr[strlen(server_mail.lstr)];
					sprintf(tmp,"%s ",client_name[room_user[user_position[from]].at(i)]);
				}
				mailbox_send(mailbox[from],&server_mail);
				break;
			//send the join message to everyone and add this user to user list
			case JOIN:
//				printf("[DebugServ]Join\n");
				for(int i=0;i<room_user[0].size();++i){
					if(room_user[0].at(i)==from){
						alreadyin=true;
						break;
					}
				}
				if(alreadyin)	break;
				room_user[0].push_back(from);
				user_position[from]=0;
//				printf("[DebugServ]Room_User:\n");
//				for(int i=0;i<room_user.size();++i){
//					printf("at(%d)=%d\t",i,room_user.at(i));
//				}
//				printf("\nRoom_User_END:\n");
				for(int i=0;i<room_user[0].size()-1;++i){
					mailbox_send(mailbox[room_user[0].at(i)],&server_mail);
				}
				break;
			//pass the mail to everyone (the mail owner can see the message he said) 
			case BROADCAST:
//				printf("[DebugServ]Broadcast\n");
				for(int i=0;i<room_user[user_position[from]].size();++i){
//					if(from!=room_user[user_position[from]].at(i))
					mailbox_send(mailbox[room_user[user_position[from]].at(i)],&server_mail);
				}
				break;
			//remove the user from user list and tell everyone his leave
			case LEAVE:
//				printf("[DebugServ]leave\n");
				for(int i=0;i<room_user[user_position[from]].size();++i){
					if(from!=room_user[user_position[from]].at(i))
						mailbox_send(mailbox[room_user[user_position[from]].at(i)],&server_mail);
					else
						leave_user=i;
				}	
				room_user[user_position[from]].erase(room_user[user_position[from]].begin()+leave_user);
				break;
			//send message to only one (the mail owner can see the message he said) 
			case WHISPER:
				if(server_mail.sstr[0]=='T' && server_mail.sstr[1]=='o' && server_mail.sstr[2]=='\0'){
					if(m.find(server_mail.lstr)==m.end()){
						printf("User_not_Found.\n");
					}
					else{
						whisper_list[from]=m.find(server_mail.lstr)->second;
					}
				}
				else{
					mailbox_send(mailbox[whisper_list[from]],&server_mail);
					mailbox_send(mailbox[from],&server_mail);
				}
				break;
			//change user's chatroom list , move user to another list
			case CHANGEROOM:
				for(int i=0;i<room_user[user_position[from]].size();++i){
					if(from==room_user[user_position[from]].at(i)){
						room_user[user_position[from]].erase(room_user[user_position[from]].begin()+i);
						break;
					}
				}
				sscanf(server_mail.lstr,"%d",&user_position[from]);
				printf("[Debug] userposition room=%d\n",user_position[from]);
				room_user[user_position[from]].push_back(from);
				
				break;
			//close one user's program , updating imformation here.
			case EXIT_ONE:
				client_used[from]=false;
				mailbox_unlink(from);
				break;
			default:
				printf("Wrong_mail\n");
		}
	}

	return 0;
}
