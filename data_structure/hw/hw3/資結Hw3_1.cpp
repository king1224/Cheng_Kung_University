#include <stdio.h>
#include <math.h>

int main()
{

	int i,j,n,k,pos=1,rec=0,temp=0,count_word=1,opr[100]={0};
	//opr�Ϥ��B��l �B�⤸   count_word�Ψ��x�s�@���X�չB�⤸+�B��l 
	//rec�ΨӼȦs�U�չB�⤸����   temp�Ψ��x�s���չB�⤸�X�b�@�_�ɪ��� 
	//pos���b���B��ɹ�������m 
	int a[100]={0};		//�sinput 
	int b[100]={0};		//���B��Ȧs�� 
	
	printf("Please input a prefix expression.\n");
	
	i=1;

	do{		//��r�����J����0 
	a[0]=getchar()-'0';
	if(0<=a[0]&&a[0]<=9)		//�Ʀr�@�Ӧs�@��s
	{
		a[i]=a[0];
		i++;
		rec++;
	}
	else if(a[0]==-16)			//�Y�J��Ů� �N�Ů�e�@�ռƦr�s��P�@�� 
	{
			for(j=i-1;j>=i-rec;j--)
			{
					n=rec-j+count_word-1;
					temp=temp+a[j]*pow(10,n);	//�p��Ӧ�� �Q��� �ʦ��.... 
			}
			
			count_word++;
			i=count_word;
			a[j+1]=temp;
			rec=0;
			temp=0;
	}
	else if(a[0]!=-38)	//�Ʀr�ΪŮ�H�~ �S�D���� �Y�B��l	�����s 
	{
		a[i]=a[0]+'0';
		opr[i]++;		//�������欰�B��l 
		i++;
	}
	else
	{
		for(j=i-1;j>=i-rec;j--)
			{	n=rec-j+count_word-1;
				temp=temp+a[j]*pow(10,n);
			}
			a[j+1]=temp;
	}
	
	}while(a[0] != (10-48));
	
	for(i=count_word;i>=1;i--) 
	{
		if(opr[i]==0)		//opr==0�N��O�B�⤸ 
		{
			b[pos]=a[i];
			pos++;
		}
		else				//�B��l�������B�� 
		{
			switch(a[i])
			{
				case '+':
					b[pos-2]=b[pos-1]+b[pos-2];
					pos=pos-1;
					break;
				case '-':
					b[pos-2]=b[pos-1]-b[pos-2];
					pos=pos-1;
					break;
				case '*':
					b[pos-2]=b[pos-1]*b[pos-2];
					pos=pos-1;
					break;
				case '/':
					b[pos-2]=b[pos-1]/b[pos-2];
					pos=pos-1;
					break;
				case '%':
					b[pos-2]=b[pos-1]%b[pos-2];
					pos=pos-1;
					break;
			}
		}
	}

	printf("answer=%d  ",b[1]);		//���צs�bb[1] 

	return 0;
	
} 
