#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int giveanswer(short int ans[],int P,int N);
int countH(short int input[],short int ans[],int* H,short int match1[],short int match2[],int N);
int countX(int N,int* X,short input[],short ans[],short match1[],short match2[]);
int ansmatch(short ans[],short input[],short num[],int count,int N,int P,short match1[],short match2[],short int answer[]);

short hisans[50][10]={0};		//�Ψ��x�s�D�ؤβq�L����

int main(int argc, char* argv[])
{
        int N=0 , P=0 , H=0 , X=0 , count=-1 , tag=0;
        int i=0,j=0,k=0;
//count�Ψ��x�s�q�L�X�����סA�Ĥ@����count��0
        N = *argv[1] - '0';
        P = *argv[2] - '0';

        if(N>9||N<1||P>9||P<1||N>P)	//�ˬd�d��O�_��J���~ 
        {
        printf("the input should make 1<=N<=9 , 1<=P<=9 , N>=P\n");
        return 0;
        system("PAUSE");
        }

		short num[100];		//�Ψ��x�s�C�����XH�XX���G
        short answer[10];	//�qhisans���������ֹ�ݭn���Ʀr��
        short input[10];	//�x�s�q���üƲq������
        short match1[10];	//�ˬd�O�_�Q��LH�BX
        short match2[10];	//�ˬd�O�_�Q��LH�BX
        
        
		srand((unsigned)time(NULL));
        
        giveanswer(answer,P,N);	//�����D��

        printf("answer=");  //�L�X���� 
        for(i=0;i<N;i++)
        printf("%d",answer[i]);
        printf("\n");
        for(i=0;i<N;i++)	//�N�D�ئs�bhisans��0�C
		hisans[0][i]=answer[i];

		//�q���� �q���H���� 
        do{
        	do{
        		giveanswer(input,P,N);	//�q����
				tag = ansmatch(answer,input,num,count,N,P,match1,match2,answer); //�P���v���׮ֹ�A�P���v���׬ҲŦX��ansmatch�|return 1
        	}while(tag==0);

        H=X=0;
	//�e��ansmatch�T�w�n�i�H�q�o�յ��׫�A�L�X
				printf("Computer guuee_%d=",count+2);
				for(i=0;i<N;i++){
       			printf("%d",input[i]);}
       			printf("\t");
		//�P���T���D�ئA���@���t��
		countH(input,answer,&H,match1,match2,N);
		countX(N,&X,input,answer,match1,match2); 
		for(i=0;i<N;i++){
        match1[i]=0;
        match2[i]=0;
    	}
		count++;	//�q�L�@��count�N+1
        num[2*count]=H;	//�N�XH�XX�s�inum�x�}
		num[2*count+1]=X;
        printf("%dH%dX\n",H,X);
		
		for(i=0;i<N;i++)      //�N�����Ҳq�s�ihisans
		hisans[count+1][i]=input[i];
        }while(H!=N);
        printf("Congratulation!! The answer is right\n");

        return 0;

}

//�H�������D�ءB����
int giveanswer(short int ans[],int P,int N)
{
	int i,j,x,k;
	do{
        x=0;
        for (i=0;i<N;i++)
        ans[i] = rand()% P + 1;

        for(j=0;j<P-1;j++)	//�T�O�D�بS���ۦP�Ʀr
                for(k=j+1;k<N;k++)
                if(ans[j]==ans[k])
                x=1;
        }while(x==1);
}

//�p�⦳�X��H�A�Y���t��match�аO�|+1
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

//�p�⦳�X��X�A�Y���t��match�аO�|+1
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


//�P���v���װ��ֹ�
int ansmatch(short ans[],short input[],short num[],int count,int N,int P,short match1[],short match2[],short int answer[])
{
	int i;
	int H=0,X=0;//��l�ƩҦ��ܼ�
	for(i=0;i<N;i++){
        match1[i]=0;
        match2[i]=0;
    }
    for(i=0;i<N;i++)//�����ݭn�P��count+1�������װ��ֹ�
    answer[i]=hisans[count+1][i];
	//�p��XH�XX
		countH(input,answer,&H,match1,match2,N);
		countX(N,&X,input,answer,match1,match2);
		for(i=0;i<N;i++){
        match1[i]=0;
        match2[i]=0;
    	}
		
	if(count==-1) return 1;//count==-1�ɡA�Y�����ֹ粒��
//else if �P���q���XH�XX�ŦX�ɡA���e�@���q�����װ��ֹ�C
	else if(num[2*count]==H&&num[2*count+1]==X)
	{ansmatch(answer,input,num,count-1,N,P,match1,match2,answer);}
	else {return 0;}//�٨S�ֹ粒�A���P�Y�����v���װt����~�A�o�յ��פ��i��O���T���סAreturn 0���j�魫�]�C
}

