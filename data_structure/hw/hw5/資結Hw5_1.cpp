#include <stdio.h>
#include <math.h>

void check(int pos,int a,int tree[]);
void dele(int pos,int tree[]);
void move(int tree[],char rl,int pos,int num);
int find(int num,int count,int tree[]);



int main()
{

	int c,pos=0,count=0,temp=0,rec=0,count_word=1;
	//c拿來暫存要儲存或刪除的節點，pos,rec紀錄一些運算時的位置，count紀錄節點個數，count_word紀錄輸入了幾組數字 
	int i,j,n;
	int tree[3000],a[3000];//tree拿來儲存level order tree，a用來暫存所有輸入的節點、所有要刪除的節點 
	for(i=0;i<3000;i++){tree[i]=-10; a[i]=-10;}//因為節點輸入可能為0，初始值設-10 
	printf("Input：\n");
	i=1;
	do//此迴圈先將字元都收起來，若遇到空白或換行則將前面的連續數字視為一組。 
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

	}while(a[0] != 20);
	for(j=i-1;j>=i-rec;j--)
		{	n=rec-j+count_word-1;
			temp=temp+a[j]*pow(10,n);
		}
			a[j+1]=temp;
			a[j+2]=-10;
	i=1;
	do//將節點存在a之後，依序以level order方式放進tree裏頭(用check函式) 
	{
			c=a[i++];
			pos=0;
			check(pos,c,tree);
			count++;
		
	}while(c!=-10);
	
	
	for(i=0;i<3000;i++) a[i]=-10; temp=0; rec=0; count_word=1; i=1;//要記錄刪除的節點，先將資料初始化 
	
	do//跟上面儲存輸入節點一樣，將要刪除的節點都先儲存在a 
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

	}while(a[0] != 21);
	for(j=i-1;j>=i-rec;j--)
		{	n=rec-j+count_word-1;
			temp=temp+a[j]*pow(10,n);
		}
			a[j+1]=temp;
			a[j+2]=-10;
	i=1;

	do//將儲存在a的節點依序刪除，用dele函式 
	{
		c=a[i++];
		if(c!=-10)
		dele(find(c,count,tree),tree);
		count--;
	}while(c!=-10);
	
	printf("Output：\n");
	i=0;
	while(count!=0)//當節點數(count)還不為0，就持續印出 
	{
		if(tree[i]==-10)	printf("X");
		else {printf("%d",tree[i]);  count--;}
		if(count!=0)
		printf(",");
		i++;
	}
	
	return 0;
} 



	
void check(int pos,int a,int tree[])//檢查要插入的節點與當前位置(當前位置非空即!=-10)誰大誰小，較大則往右子樹，較小則往左子樹 
{
	if(a<tree[pos]&&tree[pos]!=-10)
	{check(2*pos+1,a,tree);}
	else if(a>tree[pos]&&tree[pos]!=-10)
	{check(2*pos+2,a,tree);}
	else if(tree[pos]==-10)
	{tree[pos]=a;}
}


int find(int num,int count,int tree[])//找到特定的節點位置，與當前位置比較，較大則往右子樹，較小則往左子樹，若無誰大誰小即找到了，傳回位置 
{
	int i,pos=0;
	for(i=0;i<count;i++)
	{
		if (num>tree[pos]) pos=2*pos+2;
		else if (num<tree[pos]) pos=2*pos+1;
		else return pos;
	}
}


void dele(int pos,int tree[]) 
{
	int start=pos;
	int tmp;
	if(tree[2*pos+2]!=-10&&tree[2*pos+1]==-10)//若只有左子樹，直接整棵搬上來
		move(tree,pos+2,2*pos+2,1);
	else if(tree[2*pos+2]==-10&&tree[2*pos+1]!=-10)//若只有右子樹，直接整棵搬上來 
		move(tree,pos+1,2*pos+1,1);
	else if(tree[2*pos+2]!=-10&&tree[2*pos+1]!=-10)//若有左右子樹，先拿左子樹最大的上來補要刪除的點，再往下比較，若不符合level order則交換位置再往下比 
	{
		pos=2*pos+1;
		while(tree[2*pos+2]!=-10)
		{pos=2*pos+2;}
		tree[start]=tree[pos];
		tree[pos]=-10;
		if(tree[2*pos+1]!=10)
		move(tree,pos+1,2*pos+1,1);
		pos=start;
		while(tree[pos]>tree[2*pos+2]&&tree[2*pos+2]!=-10)
		{tmp=tree[pos];tree[pos]=tree[2*pos+2];tree[2*pos+2]=tmp; pos=2*pos+2;}
	}
	else//若沒有子樹，直接刪除 
		tree[pos]=0;
}

void move(int tree[],char rl,int pos,int num)//移動整棵樹，觀察後發現要移動的點，每一層為前一層的兩倍，要移動的index也是前一層的兩倍 
{//第一層只有一個要移動 num為1，下一層為2*num，下一層再乘二..........， rl為要減少的index，每一層都比上一層多兩倍 
	int t;
	int count=0;
	
	for(t=0;t<num;t++)//直接搬完一整個橫排 
	{
		tree[pos-rl+t]=tree[pos+t];
		if(tree[pos+t]==-10)
		count++;
	}
	
	if(count!=num)	
	move(tree,2*rl,2*pos+1,2*num);//當前層完全搬完，才呼叫下一層 
}
