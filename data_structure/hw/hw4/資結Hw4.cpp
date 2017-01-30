#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX_SIZE 50
#define MALLOC(p,s)\
	if(!((p)=(typeof(p))malloc(s))){\
		fprintf(stderr,"Insufficient mdmory");\
		exit(EXIT_FAILURE);\
	}







typedef enum{head,entry} tagfield;
typedef struct matrixNode *matrixPointer;

typedef struct entryNode{
	int row;
	int col;
	int value;
};
typedef struct matrixNode{
	matrixPointer down;
	matrixPointer right;
	tagfield tag;
	union{
		matrixPointer next;
		entryNode entry;
	} u;
};



matrixPointer hdnode1[MAX_SIZE],hdnode2[MAX_SIZE];







matrixPointer newNode(void)
{
    matrixPointer a;
    MALLOC(a, sizeof(*a));
    return (a);
}








matrixPointer mult(matrixPointer a,matrixPointer b)
{	int row1,row2,col1,col2,i,j,k,l,m,exist,existcol,existrow,sum;
	matrixPointer temp1,temp2;
	row1=a->u.entry.row; row2=b->u.entry.row;
	col1=a->u.entry.col; col2=b->u.entry.col;
	if(col1!=row2){printf("input wrong.");return 0;}
	for(k=0;k<row1;k++)
	{printf("\n");
		for(l=0;l<col2;l++)
		{
			sum=0;
			for(i=0;i<col1;i++)
			{	temp1=a;	temp2=b;
				for(m=0;m<=i;m++){
					if (m==0){temp1=temp1->right;}
					else {temp1=temp1->u.next;}
				}

				temp1=temp1->down;
				existrow=temp1->u.entry.col;
				while(temp1->u.entry.row!=k&&temp1->u.entry.col==existrow)
				{
					temp1=temp1->down;
				}
				exist=temp1->u.entry.row;
				if(exist==k)
				{
					for(m=0;m<=l;m++){
						if (m==0){temp2=temp2->right;}
						else {temp2=temp2->u.next;}
					}
				temp2=temp2->down;
				existcol=temp2->u.entry.col;
				while(temp2->u.entry.row!=temp1->u.entry.col&&temp2->u.entry.col==existcol)
				{
					temp2=temp2->down;
				}
					exist=temp2->u.entry.col;
					if(exist==l)
					{
						sum=sum+(temp1->u.entry.value) * (temp2->u.entry.value);
					}
				}
				
			}printf(" %d",sum);
		}
	}
	
}




matrixPointer mread1(void);
matrixPointer mread2(void);






int main(void)
{	
	matrixPointer a,b,c;
	a=mread1(); b=mread2();

	c=mult(a,b);
	return 0;
} 








matrixPointer mread1(void)
{
	int numRows,numCols,numHeads,i,j;
	int value,currentRow;
	matrixPointer temp,last,node;
	
	
	scanf("%d%d",&numRows,&numCols);
	numHeads = (numCols > numRows) ? numCols : numRows;
	node=newNode();
	node->tag=entry;
	node->u.entry.row=numRows;
	node->u.entry.col=numCols;
	
	if(!numHeads) node->right=node;
	else{
		for(i=0;i<numHeads;i++)	{
			temp=newNode();
			hdnode1[i]=temp; hdnode1[i]->tag=head;
			hdnode1[i]->right=temp; hdnode1[i]->u.next=temp;
		}
	currentRow=0;
	last=hdnode1[0];
		for(j=0;j<numRows;j++)
		for(i=0;i<numCols;i++)
		{
			scanf("%d",&value);
			if(value==0) continue;
			
			if(j>currentRow){
				last->right=hdnode1[currentRow];
				currentRow=j; last=hdnode1[j];
			}
			MALLOC(temp,sizeof(*temp));
			temp->tag=entry; temp->u.entry.row=j;
			temp->u.entry.col=i;
			temp->u.entry.value=value;
			last->right=temp;
			last=temp;
			hdnode1[i]->u.next->down=temp;
			hdnode1[i]->u.next=temp;
		}
		last->right=hdnode1[currentRow];
		for(i=0;i<numCols;i++)
			hdnode1[i]->u.next->down=hdnode1[i+1];
		for(i=0;i<numHeads-1;i++)
			hdnode1[i]->u.next=hdnode1[i+1];
		hdnode1[numHeads-1]->u.next=node;
		node->right=hdnode1[0];
	}
	return node;
}









matrixPointer mread2(void)
{
	int numRows,numCols,numHeads,i,j;
	int value,currentRow;
	matrixPointer temp,last,node;
	
	
	scanf("%d%d",&numRows,&numCols);
	numHeads = (numCols > numRows) ? numCols : numRows;
	node=newNode();
	node->tag=entry;
	node->u.entry.row=numRows;
	node->u.entry.col=numCols;
	
	if(!numHeads) node->right=node;
	else{
		for(i=0;i<numHeads;i++)	{
			temp=newNode();
			hdnode2[i]=temp; hdnode2[i]->tag=head;
			hdnode2[i]->right=temp; hdnode2[i]->u.next=temp;
		}
	currentRow=0;
	last=hdnode2[0];
		for(j=0;j<numRows;j++)
		for(i=0;i<numCols;i++)
		{
			scanf("%d",&value);
			if(value==0) continue;
			
			else if(j>currentRow){
				last->right=hdnode2[currentRow];
				currentRow=j; last=hdnode2[j];
			}
			MALLOC(temp,sizeof(*temp));
			temp->tag=entry; temp->u.entry.row=j;
			temp->u.entry.col=i;
			temp->u.entry.value=value;
			last->right=temp;
			last=temp;
			hdnode2[i]->u.next->down=temp;
			hdnode2[i]->u.next=temp;
		}
		last->right=hdnode2[currentRow];
		for(i=0;i<numCols;i++)
			hdnode2[i]->u.next->down=hdnode2[i+1];
		for(i=0;i<numHeads-1;i++)
			hdnode2[i]->u.next=hdnode2[i+1];
		hdnode2[numHeads-1]->u.next=node;
		node->right=hdnode2[0];
	}
	return node;
}
