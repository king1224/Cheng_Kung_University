#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int x,y,i,j;
	int xx=1,yy=1,zz=1;
	printf("This system will compute your input with (n,k)\=n!/[k!*(n-k)!]\n");
	printf("Please enter n & k\n");
	printf("n=");
	scanf("%d",&x);
	printf("k=");
	scanf("%d",&y);

	//iterative function
	if(x<y)
	printf("Your input can't n>k.\n"); 
	if(x>=13)
	printf("Your n is too big to compute with iterative function\n");
	else
	{
		for(i=1;i<=x;i++)
			xx=xx*i;
		for(i=1;i<=y;i++)
			yy=yy*i;
		for(i=1;i<=(x-y);i++)
			zz=zz*i;
		printf("The value of iterative function is %d\n",(xx/yy/zz));
	} 
	
	
	
	
	//recursive function 
	if(x<y)
	printf("Your input can't n>k.");
	else
	{ 
		j=1;
	for(i=1;i<=y;i++)
		j=j*(x-i+1)/i;
		printf("The value of recursive function is %d\n",j);
 	}
	system ("PAUSE");
		return 0;
}
