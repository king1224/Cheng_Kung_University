/******************************************
* 學號：C14031162
* 姓名：洪正皇
* 編譯方式：gcc -o hw3 hw3.c
* 執行方式：./hw3 [the max number want to guess] [the length of number]
* 程式功能：Master Mind , a guess number game
* 更新日期：2015/11/2
*******************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int giveanswer(short int ans[],int N,int P);
int countH(short int input[],short int ans[],int* H,short int match1[],short int match2[],int P);
int countX(int P,int* X,short input[],short ans[],short match1[],short match2[]);

int main(int argc, char* argv[])
{
        int N=0 , P=0 , H=0 , X=0;
        int i=0,j=0,k=0;

        N = *argv[1] - '0';
        P = *argv[2] - '0';

        if(N>9||N<1||P>9||P<1||N<P)	//檢查範圍是否輸入錯誤 
        {
        printf("the input should make 1<=N<=9 , 1<=P<=9 , N>=P\n");
        return 0;
        system("PAUSE");
        }

        short answer[10];
        short input[10];
        short match1[10];
        short match2[10];
        srand((unsigned)time(NULL));
        
        giveanswer(answer,N,P);

        printf("answer=");  //印出答案 
        for(i=0;i<P;i++)
        printf("%d",answer[i]);
        printf("\n");


		//猜答案 猜到全H為止 
        do{
        printf("Guess %d number between 1-%d ",P,N);

        for(i=0;i<P;i++){
        match1[i]=0;
        match2[i]=0;
        scanf("%1d",&input[i]);}

        for(i=0;i<P;i++)
        if(input[i]>N||input[i]<1)
        {printf("each input number should >=1 & <=%d\n",N);
        return 0;}

        H=X=0;

		countH(input,answer,&H,match1,match2,P);
		countX(P,&X,input,answer,match1,match2); 
        
        printf("%dH%dX\n",H,X);

        }while(H!=P);
        printf("Congratulation!! The answer is right\n");

        return 0;

}

//隨機產生題目 
int giveanswer(short int ans[],int N,int P)
{
	int i,j,x,k;
	do{
        x=0;
        for (i=0;i<P;i++)
        ans[i] = rand()% N + 1;

        for(j=0;j<P-1;j++)
                for(k=j+1;k<P;k++)
                if(ans[j]==ans[k])
                x=1;
        }while(x==1);
}

//計算有幾個H 
int countH(short int input[],short int ans[],int* H,short int match1[],short int match2[],int P)
{
	int i;
	for(i=0;i<P;i++)
        if(input[i]==ans[i]){
        *H=*H+1;
        match1[i]++;
        match2[i]++;
		}
}

//計算有幾個X 
int countX(int P,int* X,short input[],short ans[],short match1[],short match2[])
{
	int i,j;
	for(i=0;i<P;i++)
        for(j=0;j<P;j++)
        if(input[i]==ans[j] && match1[i]==0 && match2[j]==0){
        *X = *X+1;
        match1[i]++;
        match2[j]++;}
}
