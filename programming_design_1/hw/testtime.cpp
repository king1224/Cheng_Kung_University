#include <stdio.h>
#include <stdlib.h>


int main()
{
	FILE *fp,*fop;
	fop=fopen("2.txt","w");
	fp=fopen("1.txt","r");
	int aa[3000];
	for(int i=0;i<3000;i++) aa[i]=0;
	int i=1;
	fscanf(fp,"%d",&i);
	for(int j=0;j<200;j++)
	if(i<300*(j+1)&&i>300*j)
	aa[j]++;
	while(i!=0)
	{	
		i=0;
		fscanf(fp,"%d",&i);
		for(int j=0;j<200;j++)
		if(i<200*(j+1)&&i>200*j)
		aa[j]++;
	}
	
	for(int i=0;i<200;i++) {fprintf(fop,"%d\n",aa[i]);printf("%d\t",aa[i]);}
	
	fclose(fp);
	fclose(fop);
	
	for(int i=0;i<200;i++) fprintf(fop,"%d\n",200*i+100);
	
	return 0;
}

/*#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp,*fop;
	fop=fopen("2.txt","w");
	fp=fopen("1.txt","r");

	int i=1,count=1;
	fscanf(fp,"%d",&i);
	
	while(i!=0)
	{	
		i=0;
		fscanf(fp,"%d",&i);
		count++;
	}
	
	for(int i=0;i<200;i++) {printf("%d\t",count);}
	
	fclose(fp);
	fclose(fop);
	return 0;
}*/


/*#include <stdio.h>
#include <stdlib.h>
#define count 20000

int main()
{
	FILE *fp,*fop;
	fop=fopen("2.txt","w");
	fp=fopen("1.txt","r");
	double aa=0,bb=0;
	
	int i=1;
	fscanf(fp,"%d",&i);
	aa=i;
	for(int z=0;z<40;z++)
	{
		for(int k=0;k<500;k++)
		{	
		fscanf(fp,"%d",&i);
		aa=aa+i;
		}
	bb=bb+aa/count;
	aa=(double)0;
	}
	printf("aa=%f\n\n",aa);
	
	
	for(int i=0;i<200;i++) {printf("%f\t",bb);}
	
	fclose(fp);
	fclose(fop);
	return 0;
}*/
