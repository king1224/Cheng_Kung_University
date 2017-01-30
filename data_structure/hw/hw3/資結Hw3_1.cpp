#include <stdio.h>
#include <math.h>

int main()
{

	int i,j,n,k,pos=1,rec=0,temp=0,count_word=1,opr[100]={0};
	//opr區分運算子 運算元   count_word用來儲存共有幾組運算元+運算子 
	//rec用來暫存各組運算元長度   temp用來儲存此組運算元合在一起時的值 
	//pos為在做運算時對應的位置 
	int a[100]={0};		//存input 
	int b[100]={0};		//做運算暫存用 
	
	printf("Please input a prefix expression.\n");
	
	i=1;

	do{		//抓字元到輸入不為0 
	a[0]=getchar()-'0';
	if(0<=a[0]&&a[0]<=9)		//數字一個存一格存
	{
		a[i]=a[0];
		i++;
		rec++;
	}
	else if(a[0]==-16)			//若遇到空格 將空格前一組數字存到同一格 
	{
			for(j=i-1;j>=i-rec;j--)
			{
					n=rec-j+count_word-1;
					temp=temp+a[j]*pow(10,n);	//計算個位數 十位數 百位數.... 
			}
			
			count_word++;
			i=count_word;
			a[j+1]=temp;
			rec=0;
			temp=0;
	}
	else if(a[0]!=-38)	//數字及空格以外 又非換行 即運算子	直接存 
	{
		a[i]=a[0]+'0';
		opr[i]++;		//紀錄此格為運算子 
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
		if(opr[i]==0)		//opr==0代表是運算元 
		{
			b[pos]=a[i];
			pos++;
		}
		else				//運算子做對應運算 
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

	printf("answer=%d  ",b[1]);		//答案存在b[1] 

	return 0;
	
} 
