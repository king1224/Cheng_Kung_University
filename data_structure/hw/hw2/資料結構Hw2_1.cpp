#include <stdio.h>
#include <stdlib.h>


typedef struct
{	int row;
	int col;
	int value;
}term;

void fastTranspose(term a[], term b[]);		//先宣告 

int main(void) 
{
	int row,col;							//宣告行數列數 
	printf("Please input the m n and value of the matrix.\n");
	scanf("%d%d",&row,&col);				//輸入行數列數 
	if(row<=0 || col<=0)					//檢查不為0 
	printf("input wrong.\n");
	
	else{
		term a[(row*col)];					//取用夠大的陣列 
		term b[(row*col)];					//b將是a的轉置 
		a[0].row=row;	b[0].col=a[0].row;
		a[0].col=col;	b[0].row=a[0].col;
		int i,j,inputa,valuea=1;
		for(i=0;i<row;i++){					//輸入各個元素 
			for(j=0;j<col;j++){
				scanf("%d",&inputa);
				if(inputa!=0){
					a[valuea].value=inputa;	//a[]代表各個元素位置和值 
					a[valuea].row=i;
					a[valuea].col=j;
					valuea++;
		}}}
		a[0].value=valuea-1;	b[0].value=a[0].value;	//元素個數 
		fastTranspose(a,b);
		valuea=1;
		printf("Transpose:\n");
		for(i=0;i<col;i++){					//輸出矩陣 
			if(b[valuea].row!=i)			//若這一個元素為0 輸出0 
			printf("0 ");
			for(j=0;j<row;j++){
				if(b[valuea].col!=j)
				printf("0 ");
				else{
					printf("%d ",b[valuea].value);
					valuea++;}
			}
			printf("\n");
		}}
	return 0;
	}
void fastTranspose(term a[], term b[])
{
	int row_pos[a[0].value];					//rowTerms,startingPos簡化為一個陣列 
	int i,j,numCols=a[0].col,numTerms=a[0].value,tempa,tempb;
	b[0].row=numCols;
	b[0].col=a[0].row;
	b[0].value=numTerms;
	if(numTerms>0){						//矩陣不為0 
		for(i=0;i<numCols;i++) 
		row_pos[i]=0; 
		for(i=1;i<=numTerms;i++)
		row_pos[(a[i].col)]++;			//設定好各列的元素個數 
		for(i=0;i<=numCols;i++){		//這個迴圈設定好各列的起始位置 
			if(i==0){
				tempb=row_pos[0];
				row_pos[0]=1;
			}
			else{
				tempa=tempb;
				tempb=row_pos[i];
				row_pos[i]=row_pos[i-1]+tempa;
			}}
		for(i=1;i<=numTerms;i++){		//開始轉囉 
			j=row_pos[a[i].col]++;
			b[j].row=a[i].col;	b[j].col=a[i].row;
			b[j].value=a[i].value;
		}}} 
