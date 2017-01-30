/******************************************
* 學號：C14031162
* 姓名：洪正皇
* 編譯方式：gcc -o hw2 hw2.c
* 執行方式：./hw2 [the max number want to guess] [the length of number]
* 程式功能：Master Mind , a guess number game
* 更新日期：2015/10/26
*******************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char* argv[])
{
        int N=0 , P=0 , H=0 , X=0;
        int i=0,j=0,k=0;
        int x=0;

        N = *argv[1] - '0';
        P = *argv[2] - '0';

        if(N>9||N<1||P>9||P<1||N<P)
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

        do{
        x=0;
        for (i=0;i<P;i++)
        answer[i] = rand()% N + 1;

        for(j=0;j<P-1;j++)
                for(k=j+1;k<P;k++)
                if(answer[j]==answer[k])
                x=1;
        }while(x==1);

        printf("answer=");
        for(i=0;i<P;i++)
        printf("%d",answer[i]);
        printf("\n");

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

        for(i=0;i<P;i++)
        if(input[i]==answer[i]){
        H++;
        match1[i]++;
        match2[i]++;
}

        for(i=0;i<P;i++)
        for(j=0;j<P;j++)
        if(input[i]==answer[j]&&match1[i]==0&&match2[j]==0){
        X++;
        match1[i]++;
        match2[j]++;}

        printf("%dH%dX\n",H,X);

        }while(H!=P);
        printf("Congratulation!! The answer is right\n");

        return 0;

}