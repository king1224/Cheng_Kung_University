#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//�@��node�����c 
typedef struct node{
          int value[5];
          struct node *next;
        }Node;


int main()
{
    char IP[20];//IP�Ψӧ�IP�A�@�����@�� 
    int i,j,length,tmp,pos,insert[5];//insert��������O�x�s�p���I�α׽u�j�}�����ռƦr�Alength,tmp�ΨӱNIP�����Ʀr�@�դ@�թ�iinsert�A�Ҧp125=>length=3,tmp=100+20+5,pos�x�sinsert�s����@��C 
	Node *one[256];//�o����ŧi�T�ժ��׽d�򪺰_�I 
    Node *two[4096];
    Node *tre[4096];

    for(i=0;i<256;i++) {one[i] = (Node*)malloc(sizeof(Node)); one[i]->next=NULL; }//�U�_�I��l�� 
    for(i=0;i<4096;i++) {two[i] = (Node*)malloc(sizeof(Node)); two[i]->next=NULL; }
    for(i=0;i<4096;i++) {tre[i] = (Node*)malloc(sizeof(Node)); tre[i]->next=NULL; }

    FILE *fp;//�}�Ҹ�� 
    fp=fopen("IPv4_400k.txt","r");
    if (!fp) {
	    printf("�ɮ׶}�ҥ���...\n");
	    exit(1);
    }
    else
    {
        Node *ptr=NULL;//�ΨӲ��ʥh��A�X��m 
        Node *new_node;//�x�s�s��J��IP��m�᱾�b��쪺ptr�U�� 
        for(i=0;i<20;i++) IP[i]=-10;//��l��-10 
        fscanf(fp,"%s",&IP);//Ū�@��IP 
        while(IP[0]!=-10)//�ɮ׵����e���򱾤WIP�A�@���@�� 
        {
            i=0;
            while(IP[i]!=-10)//�N�r���������T�Ʀr 
            {
                if(IP[i]<='9'&&IP[i]>='0')
                IP[i]=IP[i]-'0';
                i++;
            }

            IP[i-1]=-10;

            j=pos=0;
            while(IP[j]!=-10)//�O���o��IP���U�ռƦr�s�iinsert 
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

            new_node = (Node*)malloc(sizeof(Node));//���s�`�I�@�ӪŶ�
            new_node->next=NULL; 
            //�ˬd����IP�n���b���@�հ}�C�A�Nptr���򩹤U������ݡA���Wnew_node 
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
            for(i=0;i<5;i++){//�NIP�����ռƦr�s�inew_node 
            new_node->value[i]=insert[i];}
            for(i=0;i<20;i++) IP[i]=-10;//��l�ơA�A��@��IP 
            fscanf(fp,"%s",&IP);
        }
    }
    fclose(fp);//Ū�������� 
        
    FILE *fop;//���U�ӭn���j�M�A�}�@��result�ɮ׼g�X 
    fop=fopen("result.txt","w");
    if (!fp) {
	printf("�ɮ׶}�ҥ���...\n");
	exit(1);
    }
         
    //�}�ɷj�M
    fp=fopen("IPv4_search.txt","r");
    if (!fp) {
		printf("�ɮ׶}�ҥ���...\n");
		exit(1);
    }
    else
    {
        int match,print[5];//match�����O�_�����Aprint�x�s�n�L�X��IP 
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
            while(IP[j]!=-10)//�N�@��IP�r����X�����ռƦr 
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
            ptr=tre[insert[0]*16+(int)insert[1]/16];//�q�̪������դ��ն}�l�� 
            if(match==0&&ptr->next!=NULL)//match�N��S���L�A���L�b���٨S�}�l���M�O0�A�᭱��ժ��פ��շ|���� 
            {
                while(ptr->next!=NULL)//�@��search����� 
                {
                   	ptr=ptr->next;
                   	if(ptr->value[0]==insert[0]&&ptr->value[1]==insert[1]&&ptr->value[2]==insert[2]&&(int)(ptr->value[3]/((int)pow(2,32-ptr->value[4])))==(int)(insert[3]/((int)pow(2,32-ptr->value[4]))))
                  	{//���׬O�X�A�N�h�t��Xbit�A�Y�t�����Ȧs�A�~��M��O�_����� 
                   		match=1;
                   		if(ptr->value[4]>print[4])
                   		{
                   		    for(i=0;i<5;i++) print[i]=ptr->value[i];
						}
					}
                }
			}
						
			ptr=two[insert[0]*16+(int)insert[1]/16];//�}�l��ĤG�ժ������� 
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
						
						
			ptr=one[insert[0]];//��̫�@�ժ��פ��� 
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
			//�䧹��N�L�X�� 
			for(i=0;i<3;i++) fprintf(fop,"%d.",print[i]);
            fprintf(fop,"%d/",print[3]); fprintf(fop,"%d\n",print[4]);
            for(i=0;i<20;i++) IP[i]=-10;
            fscanf(fp,"%s",&IP);
		}
		fclose(fop);
        }
        fclose(fp);
        
        
        //�}�ɧR�� 
        fp=fopen("IPv4_delete.txt","r");
        if (!fp) {
		    printf("�ɮ׶}�ҥ���...\n");
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
                        
            //�ˬdIP�����סA�n���b���@�� 
            if(insert[4]>=8&&insert[4]<16)
            {
                ptr=one[insert[0]];
                while(ptr->next!=NULL)
                {
                    pre_ptr=ptr;
					ptr=ptr->next;
					if(ptr->value[0]==insert[0]&&ptr->value[1]==insert[1]&&ptr->value[2]==insert[2]&&ptr->value[3]==insert[3]&&ptr->value[4]==insert[4])
					{//�Y��즹IP�A��W�@��link list���V�U�@�ӡAfree���n�R�����o�� 
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
            }//��ĤG�ժ��� 
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
            }//��ĤT�ժ��� 
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
        
        
        //�}�ɴ��J 
        fp=fopen("IPv4_insert.txt","r");
        if (!fp) {
		    printf("�ɮ׶}�ҥ���...\n");
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
            	//���ŧi�s�`�I�n���J 
                new_node = (Node*)malloc(sizeof(Node));
                new_node->next=NULL;
                if(insert[4]>=8&&insert[4]<16)//�������sIP���� 
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
            	//��IP��J�s�`�I�� 
                for(i=0;i<5;i++){
                new_node->value[i]=insert[i];}
                for(i=0;i<20;i++) IP[i]=-10;
                fscanf(fp,"%s",&IP);
            }
        }
        fclose(fp);

        return 0;
}

