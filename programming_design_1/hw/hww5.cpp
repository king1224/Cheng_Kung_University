#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int giveanswer(short int ans[],int P,int N);
int countH(short int input[],short int ans[],int* H,short int match1[],short int match2[],int N);
int countX(int N,int* X,short input[],short ans[],short match1[],short match2[]);
int ansmatch(short ans[],short input[],short num[],int count,int N,int P,short match1[],short match2[],short int answer[]);

short hisans[50][10]={0};		//用來儲存題目及猜過的數

int main(int argc, char* argv[])
{
        int N=0 , P=0 , H=0 , X=0 , count=-1 , tag=0;
        int i=0,j=0,k=0;
//count用來儲存猜過幾次答案，第一次時count為0
        N = *argv[1] - '0';
        P = *argv[2] - '0';

        if(N>9||N<1||P>9||P<1||N>P)	//檢查範圍是否輸入錯誤 
        {
        printf("the input should make 1<=N<=9 , 1<=P<=9 , N>=P\n");
        return 0;
        system("PAUSE");
        }

		short num[100];		//用來儲存每次的幾H幾X結果
        short answer[10];	//從hisans拿取此次核對需要的數字組
        short input[10];	//儲存電腦亂數猜的答案
        short match1[10];	//檢查是否被算過H、X
        short match2[10];	//檢查是否被算過H、X
        
        
		srand((unsigned)time(NULL));
        
        giveanswer(answer,P,N);	//產生題目

        printf("answer=");  //印出答案 
        for(i=0;i<N;i++)
        printf("%d",answer[i]);
        printf("\n");
        for(i=0;i<N;i++)	//將題目存在hisans第0列
		hisans[0][i]=answer[i];

		//猜答案 猜到全H為止 
        do{
        	do{
        		giveanswer(input,P,N);	//猜答案
				tag = ansmatch(answer,input,num,count,N,P,match1,match2,answer); //與歷史答案核對，與歷史答案皆符合時ansmatch會return 1
        	}while(tag==0);

        H=X=0;
	//前面ansmatch確定好可以猜這組答案後，印出
				printf("Computer guuee_%d=",count+2);
				for(i=0;i<N;i++){
       			printf("%d",input[i]);}
       			printf("\t");
		//與正確的題目再做一次配對
		countH(input,answer,&H,match1,match2,N);
		countX(N,&X,input,answer,match1,match2); 
		for(i=0;i<N;i++){
        match1[i]=0;
        match2[i]=0;
    	}
		count++;	//猜過一次count就+1
        num[2*count]=H;	//將幾H幾X存進num矩陣
		num[2*count+1]=X;
        printf("%dH%dX\n",H,X);
		
		for(i=0;i<N;i++)      //將本次所猜存進hisans
		hisans[count+1][i]=input[i];
        }while(H!=N);
        printf("Congratulation!! The answer is right\n");

        return 0;

}

//隨機產生題目、答案
int giveanswer(short int ans[],int P,int N)
{
	int i,j,x,k;
	do{
        x=0;
        for (i=0;i<N;i++)
        ans[i] = rand()% P + 1;

        for(j=0;j<P-1;j++)	//確保題目沒有相同數字
                for(k=j+1;k<N;k++)
                if(ans[j]==ans[k])
                x=1;
        }while(x==1);
}

//計算有幾個H，若有配對match標記會+1
int countH(short int input[],short int ans[],int* H,short int match1[],short int match2[],int N)
{
	int i;
	for(i=0;i<N;i++)
        if(input[i]==ans[i]){
        *H=*H+1;
        match1[i]++;
        match2[i]++;
		}
}

//計算有幾個X，若有配對match標記會+1
int countX(int N,int* X,short input[],short ans[],short match1[],short match2[])
{
	int i,j;
	for(i=0;i<N;i++)
        for(j=0;j<N;j++)
        if(input[i]==ans[j] && match1[i]==0 && match2[j]==0){
        *X = *X+1;
        match1[i]++;
        match2[j]++;}
}


//與歷史答案做核對
int ansmatch(short ans[],short input[],short num[],int count,int N,int P,short match1[],short match2[],short int answer[])
{
	int i;
	int H=0,X=0;//初始化所有變數
	for(i=0;i<N;i++){
        match1[i]=0;
        match2[i]=0;
    }
    for(i=0;i<N;i++)//本次需要與第count+1次的答案做核對
    answer[i]=hisans[count+1][i];
	//計算幾H幾X
		countH(input,answer,&H,match1,match2,N);
		countX(N,&X,input,answer,match1,match2);
		for(i=0;i<N;i++){
        match1[i]=0;
        match2[i]=0;
    	}
		
	if(count==-1) return 1;//count==-1時，即全部核對完畢
//else if 與當初猜的幾H幾X符合時，往前一次猜的答案做核對。
	else if(num[2*count]==H&&num[2*count+1]==X)
	{ansmatch(answer,input,num,count-1,N,P,match1,match2,answer);}
	else {return 0;}//還沒核對完，但與某次歷史答案配對錯誤，這組答案不可能是正確答案，return 0讓迴圈重跑。
}

