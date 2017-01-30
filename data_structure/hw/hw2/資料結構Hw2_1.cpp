#include <stdio.h>
#include <stdlib.h>


typedef struct
{	int row;
	int col;
	int value;
}term;

void fastTranspose(term a[], term b[]);		//���ŧi 

int main(void) 
{
	int row,col;							//�ŧi��ƦC�� 
	printf("Please input the m n and value of the matrix.\n");
	scanf("%d%d",&row,&col);				//��J��ƦC�� 
	if(row<=0 || col<=0)					//�ˬd����0 
	printf("input wrong.\n");
	
	else{
		term a[(row*col)];					//���ΰ��j���}�C 
		term b[(row*col)];					//b�N�Oa����m 
		a[0].row=row;	b[0].col=a[0].row;
		a[0].col=col;	b[0].row=a[0].col;
		int i,j,inputa,valuea=1;
		for(i=0;i<row;i++){					//��J�U�Ӥ��� 
			for(j=0;j<col;j++){
				scanf("%d",&inputa);
				if(inputa!=0){
					a[valuea].value=inputa;	//a[]�N��U�Ӥ�����m�M�� 
					a[valuea].row=i;
					a[valuea].col=j;
					valuea++;
		}}}
		a[0].value=valuea-1;	b[0].value=a[0].value;	//�����Ӽ� 
		fastTranspose(a,b);
		valuea=1;
		printf("Transpose:\n");
		for(i=0;i<col;i++){					//��X�x�} 
			if(b[valuea].row!=i)			//�Y�o�@�Ӥ�����0 ��X0 
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
	int row_pos[a[0].value];					//rowTerms,startingPos²�Ƭ��@�Ӱ}�C 
	int i,j,numCols=a[0].col,numTerms=a[0].value,tempa,tempb;
	b[0].row=numCols;
	b[0].col=a[0].row;
	b[0].value=numTerms;
	if(numTerms>0){						//�x�}����0 
		for(i=0;i<numCols;i++) 
		row_pos[i]=0; 
		for(i=1;i<=numTerms;i++)
		row_pos[(a[i].col)]++;			//�]�w�n�U�C�������Ӽ� 
		for(i=0;i<=numCols;i++){		//�o�Ӱj��]�w�n�U�C���_�l��m 
			if(i==0){
				tempb=row_pos[0];
				row_pos[0]=1;
			}
			else{
				tempa=tempb;
				tempb=row_pos[i];
				row_pos[i]=row_pos[i-1]+tempa;
			}}
		for(i=1;i<=numTerms;i++){		//�}�l���o 
			j=row_pos[a[i].col]++;
			b[j].row=a[i].col;	b[j].col=a[i].row;
			b[j].value=a[i].value;
		}}} 
