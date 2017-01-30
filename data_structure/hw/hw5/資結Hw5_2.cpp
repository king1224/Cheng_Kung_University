#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int findparent(int equ[], int out[],int ii);

int main()
{
	int a[100],temp=0,rec=0,count_word=1,equ[5000],out[5000],num=0,pos=0,com1,com2,treepos[100];
//a用來暫存輸入的節點，temp用來暫存一組數字(例如把12以1*10+2存成十二)，rec用來記錄一組數字長度，count_word用來記錄有幾組數字，equ為課本249頁圖5.40的那個陣列
//out為一棵樹一棵樹排序好等著印出的陣列，num紀錄節點數，pos用來暫存一些位置，com1、com2等價敘述時左右數字的暫存，treepos暫存樹各層節點數 
	int i,ii,j,n;
	char inp[99];
	
	for(i=0;i<5000;i++) {equ[i]=-1000; out[i]=-1000;}//因為節點會有0，所以初始值設為-1000 
	
	i=1; 
	do//將輸入的節點都儲存起來 
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
	while((a[i]!=0||a[i+1]!=0)&&(num!=count_word))//將儲存在a裡面的節點都在equ中設為-1 
	{
		equ[a[i]]=-1;
		i++;
		num++;
	}

	for(i=0;i<100;i++) inp[i]=65;//會有0節點，初始值設為65 
	scanf("%s",inp);
	while(inp[0]!='E')//輸入不為E就繼續存取等價敘述 
	{
		for(i=0;i<99;i++) {if(inp[i]==61) {rec=i;break;} }//找到等號位置 
		for(i=0;i<98;i++) {if(inp[i]==65)  {pos=i-1;break;} }//找到等號後數字結束的位置 
		for(i=0;i<99;i++) {if(inp[i]!=65) inp[i]-=48; else break;}

		com1=0;
		for(i=rec-1;i>=0;i--)	com1=com1+inp[i]*pow(10,rec-i-1);//等號前的數字存到com1 
		com2=0;
		for(i=pos-1;i>rec;i--)	com2=com2+inp[i]*pow(10,pos-i-1);//等號後的數字存到com2 
		//equ[com1]與equ[com2]比大小，節點少的掛到節點多的下面，節點相同時數字大的掛到數字小的下面 
		while(equ[com1]>=0) {com1=equ[com1];}
		while(equ[com2]>=0) {com2=equ[com2];}
		if(equ[com1]>equ[com2]||(equ[com1]==equ[com2]&&com1>com2)) {equ[com2]+=equ[com1];equ[com1]=com2;}
		if(equ[com1]<equ[com2]||(equ[com1]==equ[com2]&&com1<com2)) {equ[com1]+=equ[com2];equ[com2]=com1;}

		for(i=0;i<100;i++) inp[i]=65;
		scanf("%s",inp);
	}
	
	ii=0;pos=0,rec=0,j=0;
	while(out[num-1]==-1000)//有num個數 儲到num-1個位置 
	{

		while(equ[ii]>=0||equ[ii]==-1000) ii++;//如果不是樹的root就跳過 
		out[rec]=ii;//找到root後存進out 
		treepos[j++]=1;//root這層只有1個節點 
		pos=findparent(equ,out,out[rec++]);//將他的子樹通通找出來 
		treepos[j++]=pos;//他的子樹有pos個節點 
		ii++;
		while(treepos[j-1]!=0)//開始找out[1]的子樹，out[2]的子樹，out[3]的子樹...... 
		{
			pos=0;
			for(n=0;n<treepos[j-1];n++)  pos=pos+findparent(equ,out,out[rec++]);
			treepos[j++]=pos;
		}
	}
	
	j=0;pos=0;
	while(treepos[j]!=0||treepos[j+1]!=0)//從out印出樹，從treepos取得一層有幾個節點要印在一起，treepos為0時換新樹 
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


int findparent(int equ[], int out[],int ii)//找到數值為ii的節點的子樹，依序放進out 
{
	int i,pos;
	int num=0;
	for(i=0;i<5000;i++)	{if(out[i]==-1000){pos=i; break;}}
	for(i=0;i<5000;i++) if(equ[i]==ii) {out[pos++]=i; num++;}
	return num;
} 
