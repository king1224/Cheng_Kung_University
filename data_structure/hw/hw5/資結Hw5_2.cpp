#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int findparent(int equ[], int out[],int ii);

int main()
{
	int a[100],temp=0,rec=0,count_word=1,equ[5000],out[5000],num=0,pos=0,com1,com2,treepos[100];
//a�ΨӼȦs��J���`�I�Atemp�ΨӼȦs�@�ռƦr(�Ҧp��12�H1*10+2�s���Q�G)�Arec�ΨӰO���@�ռƦr���סAcount_word�ΨӰO�����X�ռƦr�Aequ���ҥ�249����5.40�����Ӱ}�C
//out���@�ʾ�@�ʾ�ƧǦn���ۦL�X���}�C�Anum�����`�I�ơApos�ΨӼȦs�@�Ǧ�m�Acom1�Bcom2�����ԭz�ɥ��k�Ʀr���Ȧs�Atreepos�Ȧs��U�h�`�I�� 
	int i,ii,j,n;
	char inp[99];
	
	for(i=0;i<5000;i++) {equ[i]=-1000; out[i]=-1000;}//�]���`�I�|��0�A�ҥH��l�ȳ]��-1000 
	
	i=1; 
	do//�N��J���`�I���x�s�_�� 
	{
		a[0]=getchar()-'0';
		if(0<=a[0]&&a[0]<=9)
		{
			a[i]=a[0];
			i++;
			rec++;
		}
		else if(a[0]==-16)
		{
				for(j=i-1;j>=i-rec;j--)
				{
						n=rec-j+count_word-1;
						temp=temp+a[j]*pow(10,n);
				}
				
				count_word++;
				i=count_word;
				a[j+1]=temp;
				rec=0;
				temp=0;
		}

	}while(a[0] != 35);
	for(j=i-1;j>=i-rec;j--)
		{	n=rec-j+count_word-1;
			temp=temp+a[j]*pow(10,n);
			
		}
			a[j+1]=temp;
	
	
	if(temp==0) equ[0]=-1;
	i=1;
	while((a[i]!=0||a[i+1]!=0)&&(num!=count_word))//�N�x�s�ba�̭����`�I���bequ���]��-1 
	{
		equ[a[i]]=-1;
		i++;
		num++;
	}

	for(i=0;i<100;i++) inp[i]=65;//�|��0�`�I�A��l�ȳ]��65 
	scanf("%s",inp);
	while(inp[0]!='E')//��J����E�N�~��s�������ԭz 
	{
		for(i=0;i<99;i++) {if(inp[i]==61) {rec=i;break;} }//��쵥����m 
		for(i=0;i<98;i++) {if(inp[i]==65)  {pos=i-1;break;} }//��쵥����Ʀr��������m 
		for(i=0;i<99;i++) {if(inp[i]!=65) inp[i]-=48; else break;}

		com1=0;
		for(i=rec-1;i>=0;i--)	com1=com1+inp[i]*pow(10,rec-i-1);//�����e���Ʀr�s��com1 
		com2=0;
		for(i=pos-1;i>rec;i--)	com2=com2+inp[i]*pow(10,pos-i-1);//�����᪺�Ʀr�s��com2 
		//equ[com1]�Pequ[com2]��j�p�A�`�I�֪�����`�I�h���U���A�`�I�ۦP�ɼƦr�j������Ʀr�p���U�� 
		while(equ[com1]>=0) {com1=equ[com1];}
		while(equ[com2]>=0) {com2=equ[com2];}
		if(equ[com1]>equ[com2]||(equ[com1]==equ[com2]&&com1>com2)) {equ[com2]+=equ[com1];equ[com1]=com2;}
		if(equ[com1]<equ[com2]||(equ[com1]==equ[com2]&&com1<com2)) {equ[com1]+=equ[com2];equ[com2]=com1;}

		for(i=0;i<100;i++) inp[i]=65;
		scanf("%s",inp);
	}
	
	ii=0;pos=0,rec=0,j=0;
	while(out[num-1]==-1000)//��num�Ӽ� �x��num-1�Ӧ�m 
	{

		while(equ[ii]>=0||equ[ii]==-1000) ii++;//�p�G���O��root�N���L 
		out[rec]=ii;//���root��s�iout 
		treepos[j++]=1;//root�o�h�u��1�Ӹ`�I 
		pos=findparent(equ,out,out[rec++]);//�N�L���l��q�q��X�� 
		treepos[j++]=pos;//�L���l��pos�Ӹ`�I 
		ii++;
		while(treepos[j-1]!=0)//�}�l��out[1]���l��Aout[2]���l��Aout[3]���l��...... 
		{
			pos=0;
			for(n=0;n<treepos[j-1];n++)  pos=pos+findparent(equ,out,out[rec++]);
			treepos[j++]=pos;
		}
	}
	
	j=0;pos=0;
	while(treepos[j]!=0||treepos[j+1]!=0)//�qout�L�X��A�qtreepos���o�@�h���X�Ӹ`�I�n�L�b�@�_�Atreepos��0�ɴ��s�� 
	{	if(treepos[j+1]!=0)
		{
			printf("(");
			while(treepos[j]!=0)
			{	
				if(treepos[j+1]!=0)
				{
					printf("(");
					for(n=0;n<treepos[j]-1;n++) printf("%d,",out[pos++]);
					printf("%d),",out[pos++]);
					j++;
				}
				else
				{
					printf("(");
					for(n=0;n<treepos[j]-1;n++) printf("%d,",out[pos++]);
					printf("%d)",out[pos++]);
					j++;
				}
			}
			if(treepos[j]==0&&treepos[j+1]!=0)
			{j++;}
			printf(")\n");
		}
		else
		{
			while(treepos[j]!=0)
			{	printf("(");
				for(n=0;n<treepos[j]-1;n++) printf("%d,",out[pos++]);
				printf("%d)",out[pos++]);
				j++;
			}
			if(treepos[j]==0&&treepos[j+1]!=0)
			{j++;}
			printf("\n");
		}
	}
	
	return 0;
}


int findparent(int equ[], int out[],int ii)//���ƭȬ�ii���`�I���l��A�̧ǩ�iout 
{
	int i,pos;
	int num=0;
	for(i=0;i<5000;i++)	{if(out[i]==-1000){pos=i; break;}}
	for(i=0;i<5000;i++) if(equ[i]==ii) {out[pos++]=i; num++;}
	return num;
} 
