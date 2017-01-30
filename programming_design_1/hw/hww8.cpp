#include <stdio.h>
#include <stdlib.h>
#include <math.h>

inline unsigned long long int rdtsc() {
	unsigned long long int x;
	asm   volatile ("rdtsc" : "=A" (x));
	return x; }

typedef struct node{
          int value[5];
          struct node *next;
        }Node;


int main()
{

    char IP[20];
    int i,j,length,tmp,pos,insert[5];
        Node *one[256];
        Node *two[4096];
        Node *tre[4096];

        for(i=0;i<256;i++) {one[i] = (Node*)malloc(sizeof(Node)); one[i]->next=NULL; }
        for(i=0;i<4096;i++) {two[i] = (Node*)malloc(sizeof(Node)); two[i]->next=NULL; }
        for(i=0;i<4096;i++) {tre[i] = (Node*)malloc(sizeof(Node)); tre[i]->next=NULL; }

        FILE *fp;
        fp=fopen("t.txt","r");
        if (!fp) {
		    printf("檔案開啟失敗...\n");
		    exit(1);
        }
        else
        {
                Node *ptr=NULL;
                Node *new_node;
                for(i=0;i<20;i++) IP[i]=-10;
                fscanf(fp,"%s",&IP);
                while(IP[0]!=-10)
                {
                        i=0;
                        while(IP[i]!=-10)
                        {
                                if(IP[i]<='9'&&IP[i]>='0')
                                IP[i]=IP[i]-'0';
                                i++;
                        }
						
                        IP[i-1]=-10;

                        j=pos=0;
                        while(IP[j]!=-10)
                        {
                                length=tmp=0;
                                i=j;
                                while(IP[i]>=0&&IP[i]<=9)
                                {
                                        length++;
                                        i++;
                                }

                                for(i=j;i<j+length;i++)
                                {
                                        tmp=tmp+(IP[i]*(int)pow(10,j+length-i-1));
                                }
                                insert[pos]=tmp;
                                pos++;
                                j=i+1;
                        }

                        new_node = (Node*)malloc(sizeof(Node));
                        new_node->next=NULL;
                        if(insert[4]>=8&&insert[4]<16)
                        {
                                ptr=one[insert[0]];
                                while(ptr->next!=NULL)
                                {ptr=ptr->next;}
                                ptr->next=new_node;
                        }
                        else if(insert[4]>=16&&insert[4]<25)
                        {
                                ptr=two[insert[0]*16+(int)insert[1]/16];
                                while(ptr->next!=NULL)
                                {ptr=ptr->next;}
                                ptr->next=new_node;
                        }
                        else if(insert[4]>=25&&insert[4]<=32)
                        {
                                ptr=tre[insert[0]*16+(int)insert[1]/16];
                                while(ptr->next!=NULL)
                                {ptr=ptr->next;}
                                ptr->next=new_node;
                        }
                        for(i=0;i<5;i++){
                        new_node->value[i]=insert[i];}
                        for(i=0;i<20;i++) IP[i]=-10;
                        fscanf(fp,"%s",&IP);
                }
        }
        fclose(fp);
        
        
        //搜尋 
        fp=fopen("t3.txt","r");
        if (!fp) {
		    printf("檔案開啟失敗...\n");
		    exit(1);
        }
        else
        {
        	FILE *fop;
        	fop=fopen("result.txt","w");
        	if (!fp) {
		    printf("檔案開啟失敗...\n");
		    exit(1);
        	}
        		int match,print[5];
                Node *ptr=NULL;
                Node *pre_ptr=NULL;
				for(i=0;i<20;i++) IP[i]=-10;
                fscanf(fp,"%s",&IP);
                while(IP[0]!=-10)
                {
						match=0;
                        i=0;
                        while(IP[i]!=-10)
                        {
                                if(IP[i]<='9'&&IP[i]>='0')
                                IP[i]=IP[i]-'0';
                                i++;
                        }
						
                        IP[i-1]=-10;

                        j=pos=0;
                        while(IP[j]!=-10)
                        {
                                length=tmp=0;
                                i=j;
                                while(IP[i]>=0&&IP[i]<=9)
                                {
                                        length++;
                                        i++;
                                }

                                for(i=j;i<j+length;i++)
                                {
                                        tmp=tmp+(IP[i]*(int)pow(10,j+length-i-1));
                                }
                                insert[pos]=tmp;
                                pos++;
                                j=i+1;
                        }
                        
                        for(i=0;i<5;i++) print[i]=0;
                        ptr=tre[insert[0]*16+(int)insert[1]/16];
                        if(match==0&&ptr->next!=NULL)
                        {
                        	while(ptr->next!=NULL)
                        	{
                   		     	ptr=ptr->next;
                   		     	if(ptr->value[0]==insert[0]&&ptr->value[1]==insert[1]&&ptr->value[2]==insert[2]&&(int)(ptr->value[3]/((int)pow(2,32-ptr->value[4])))==(int)(insert[3]/((int)pow(2,32-ptr->value[4]))))
                  	 	     	{
                   		     		match=1;
                   		     		if(ptr->value[4]>print[4])
                   		     		{
                   		     			for(i=0;i<5;i++) print[i]=ptr->value[i];
									}
								}
                        	}
						}
						
						ptr=two[insert[0]*16+(int)insert[1]/16];
                        if(match==0&&ptr->next!=NULL)
                        {
                        	while(ptr->next!=NULL)
                        	{
                   		     	ptr=ptr->next;
                   		     	if(ptr->value[0]==insert[0]&&ptr->value[1]==insert[1]&&(int)(ptr->value[2]/((int)pow(2,24-ptr->value[4])))==(int)(insert[2]/((int)pow(2,24-ptr->value[4]))))
                  	 	     	{
                   		     		match=1;
                   		     		if(ptr->value[4]>print[4])
                   		     		{
                   		     			for(i=0;i<5;i++) print[i]=ptr->value[i];
									}
								}
                        	}
						}
						
						
						ptr=one[insert[0]];
                        if(match==0&&ptr->next!=NULL)
                        {
                        	while(ptr->next!=NULL)
                        	{
                   		     	ptr=ptr->next;
                   		     	if(ptr->value[0]==insert[0]&&(int)(ptr->value[1]/((int)pow(2,16-ptr->value[4])))==(int)(insert[1]/((int)pow(2,16-ptr->value[4]))))
                  	 	     	{
                   		     		match=1;
                   		     		if(ptr->value[4]>print[4])
                   		     		{
                   		     			for(i=0;i<5;i++) print[i]=ptr->value[i];
									}
								}
                        	}
						}
						
						for(i=0;i<3;i++) fprintf(fop,"%d.",print[i]);
                		fprintf(fop,"%d/",print[3]); fprintf(fop,"%d\n",print[4]);
                		for(i=0;i<20;i++) IP[i]=-10;
                        fscanf(fp,"%s",&IP);
				}
		fclose(fop);
        }
        fclose(fp);
        
        
        //刪除 
        fp=fopen("t1.txt","r");
        if (!fp) {
		    printf("檔案開啟失敗...\n");
		    exit(1);
        }
        else
        {
                Node *ptr=NULL;
                Node *pre_ptr=NULL;
                for(i=0;i<20;i++) IP[i]=-10;
                fscanf(fp,"%s",&IP);
                while(IP[0]!=-10)
                {
                        i=0;
                        while(IP[i]!=-10)
                        {
                                if(IP[i]<='9'&&IP[i]>='0')
                                IP[i]=IP[i]-'0';
                                i++;
                        }
						
                        IP[i-1]=-10;

                        j=pos=0;
                        while(IP[j]!=-10)
                        {
                                length=tmp=0;
                                i=j;
                                while(IP[i]>=0&&IP[i]<=9)
                                {
                                        length++;
                                        i++;
                                }

                                for(i=j;i<j+length;i++)
                                {
                                        tmp=tmp+(IP[i]*(int)pow(10,j+length-i-1));
                                }
                                insert[pos]=tmp;
                                pos++;
                                j=i+1;
                        }
                        
                        
                        if(insert[4]>=8&&insert[4]<16)
                        {
                                ptr=one[insert[0]];
                                while(ptr->next!=NULL)
                                {
                                	pre_ptr=ptr;
									ptr=ptr->next;
									if(ptr->value[0]==insert[0]&&ptr->value[1]==insert[1]&&ptr->value[2]==insert[2]&&ptr->value[3]==insert[3]&&ptr->value[4]==insert[4])
									{
										if(ptr->next==NULL)
										{
											pre_ptr->next=NULL;
											free(ptr);
											break;
										}
										else
										{
											pre_ptr->next=ptr->next;
											free(ptr);
											break;
										}
									}
								}
                        }
                        else if(insert[4]>=16&&insert[4]<25)
                        {
                                ptr=two[insert[0]*16+(int)insert[1]/16];
                                while(ptr->next!=NULL)
                                {
                                	pre_ptr=ptr;
									ptr=ptr->next;
									if(ptr->value[0]==insert[0]&&ptr->value[1]==insert[1]&&ptr->value[2]==insert[2]&&ptr->value[3]==insert[3]&&ptr->value[4]==insert[4])
									{
										if(ptr->next==NULL)
										{
											pre_ptr->next=NULL;
											free(ptr);
											break;
										}
										else
										{
											pre_ptr->next=ptr->next;
											free(ptr);
											break;
										}
									}
								}
                        }
                        else if(insert[4]>=25&&insert[4]<=32)
                        {
                                ptr=tre[insert[0]*16+(int)insert[1]/16];
                                while(ptr->next!=NULL)
                                {
                                	pre_ptr=ptr;
									ptr=ptr->next;
									if(ptr->value[0]==insert[0]&&ptr->value[1]==insert[1]&&ptr->value[2]==insert[2]&&ptr->value[3]==insert[3]&&ptr->value[4]==insert[4])
									{
										if(ptr->next==NULL)
										{
											pre_ptr->next=NULL;
											free(ptr);
											break;
										}
										else
										{
											pre_ptr->next=ptr->next;
											free(ptr);
											break;
										}
									}
								}
                        }
                        for(i=0;i<20;i++) IP[i]=-10;
                        fscanf(fp,"%s",&IP);
                }
        }
        fclose(fp);
        
        
        //插入 
        fp=fopen("t2.txt","r");
        if (!fp) {
		    printf("檔案開啟失敗...\n");
		    exit(1);
        }
        else
        {
                Node *ptr=NULL;
                Node *new_node;
                for(i=0;i<20;i++) IP[i]=-10;
                fscanf(fp,"%s",&IP);
                while(IP[0]!=-10)
                {
                        i=0;
                        while(IP[i]!=-10)
                        {
                                if(IP[i]<='9'&&IP[i]>='0')
                                IP[i]=IP[i]-'0';
                                i++;
                        }
						
                        IP[i-1]=-10;

                        j=pos=0;
                        while(IP[j]!=-10)
                        {
                                length=tmp=0;
                                i=j;
                                while(IP[i]>=0&&IP[i]<=9)
                                {
                                        length++;
                                        i++;
                                }

                                for(i=j;i<j+length;i++)
                                {
                                        tmp=tmp+(IP[i]*(int)pow(10,j+length-i-1));
                                }
                                insert[pos]=tmp;
                                pos++;
                                j=i+1;
                        }

                        new_node = (Node*)malloc(sizeof(Node));
                        new_node->next=NULL;
                        if(insert[4]>=8&&insert[4]<16)
                        {
                                ptr=one[insert[0]];
                                while(ptr->next!=NULL)
                                {ptr=ptr->next;}
                                ptr->next=new_node;
                        }
                        else if(insert[4]>=16&&insert[4]<25)
                        {
                                ptr=two[insert[0]*16+(int)insert[1]/16];
                                while(ptr->next!=NULL)
                                {ptr=ptr->next;}
                                ptr->next=new_node;
                        }
                        else if(insert[4]>=25&&insert[4]<=32)
                        {
                                ptr=tre[insert[0]*16+(int)insert[1]/16];
                                while(ptr->next!=NULL)
                                {ptr=ptr->next;}
                                ptr->next=new_node;
                        }
                        for(i=0;i<5;i++){
                        new_node->value[i]=insert[i];}
                        for(i=0;i<20;i++) IP[i]=-10;
                        fscanf(fp,"%s",&IP);
                }
        }
        fclose(fp);

        return 0;
}

