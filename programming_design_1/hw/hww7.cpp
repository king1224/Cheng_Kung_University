#include <stdio.h>

int bitrow=0;

int bucket_union(char bucket[][1000], char tmp[], int pos, int maxn, int n, int bitmap[][1000]);
int new_mapping(int bestrow, int bitrow, char ttmmpp[], char bucket[][1000], int bitmap[][1000]);
void print_result();
int countsame(char ttmmpp[],char bucket[][1000], int row);
int insert(char ttmmpp[],char bucket[][1000], int row);
int countspace(char bucket[][1000], int row, int n);
int findbestrow(char bucket[][1000], int n, int ttmmppnum, char ttmmpp[]);



int main()
{
	int maxn=0,tmpn=0,max_num2=1,read_pos=0;//max_num2用來計算有幾列數據 
	int i,j,k;
	FILE *fop;
	char in[1024];
    char tmp[8192];
	
	for(k=0;k<8192;k++) tmp[k]=0;
	for(k=0;k<1024;k++) in[k]=0;
	
    fop=fopen("buckets.in.txt","r");
    
    if (fop==NULL){
        printf( "Open failure" );
        return 1;
    }else{
        while(fgets(in, 1024, fop)!=NULL)
        {
        	i=0;
        	while(in[i]!=0)
        	{
        		tmp[read_pos]=in[i];
        		read_pos++;
        		in[i]=0;
        		i++;
			}
		}
	}
	i=0;
	while(tmp[i]!=0)//計算n值至少要是多少，遇到空白tmpn就加一，遇到換行tmpn就歸零，算出每一行的數據有幾組，最大的存到maxn 
	{
		if(tmp[i]==32||tmp[i]==10)
		{tmpn++;} 
		if(tmp[i]==10&&tmpn>=maxn)
		{max_num2++;maxn=tmpn;tmpn=0;}
		else if(tmp[i]==10&&tmpn<maxn)
		{max_num2++;tmpn=0;}
		i++;
	}
	
	if(tmpn>maxn) maxn=tmpn+1;
	
	printf("請輸入n值(n應該要大於等於%d)：",maxn);
	scanf("%d",&tmpn);
	
	if(tmpn<maxn){printf("wrong input."); return 0;}//輸入的n值錯誤要重來 
	
	
	
	char bucket[max_num2][1000];//輸入有幾列，bucket至多就有幾列  
	int bitmap[max_num2][1000];//輸入有幾列，bitmap就有幾列 
	int buckex,bitmap_pos1,bitmap_pos2,tmp_pos=0;
	for(j=0;j<max_num2;j++)
	for(k=0;k<1000;k++)
	{bucket[j][k]=bitmap[j][k]=0;}
	
	while(tmp[tmp_pos]!=0)
	{
		tmp_pos+=bucket_union(bucket,tmp,tmp_pos,maxn,tmpn,bitmap);	
	}
    fclose(fop);
	
    FILE *fip1;
    fip1=fopen("buckets.out.txt","w");
	i=j=0;
	while(bucket[i][0]!=0)
	{
		while(bucket[i][j+1]!=0)
		{
			if(bucket[i][j]==32) fprintf(fip1," ");
			else if(bucket[i][j]>=48&&bucket[i][j]<=57)
			{
				bucket[i][j]=bucket[i][j]-48;
				fprintf(fip1,"%d",bucket[i][j]);
			}
			j++;
		}
		if(bucket[i+1][0]!=0)fprintf(fip1,"\n");
		i++;
		j=0;
	}
	fclose(fip1);
for(k=0;k<40;k++){printf("%d=%d,%d\n",k,bucket[i-1][k],bucket[i-2][k]);}
	FILE *fip2;
    fip2=fopen("mapping.out.txt","w");
    for(i=0;i<max_num2;i++)
    {
    	fprintf(fip2,"%d ",bitmap[i][0]);
    	for(j=1;j<=tmpn;j++)
    	{
    		fprintf(fip2,"%d",bitmap[i][j]);
		}
		putc('\n',fip2);
	}
    
	
	fclose(fip2);
	return 0;
}


int bucket_union(char bucket[][1000], char tmp[], int pos, int maxn, int n, int bitmap[][1000])
{
	char ttmmpp[1000];
	int num=0,row=0,bestrow,ttmmppnum=0;
	int i,j;
	for(i=0;i<1000;i++)ttmmpp[i]=0;
	while(tmp[pos]!=10&&tmp[pos]!=0)
	{
		ttmmpp[num]=tmp[pos];
		num++; pos++;
	}
	ttmmpp[num]=32;
	i=0;
	while(ttmmpp[i]!=0){if(ttmmpp[i]==32) ttmmppnum++; i++;}
	
	bestrow=findbestrow(bucket, n, ttmmppnum, ttmmpp);
	j=insert(ttmmpp,bucket,bestrow);
	bitrow=new_mapping(bestrow,bitrow,ttmmpp,bucket,bitmap);
	return num+1;
}



int countsame(char ttmmpp[],char bucket[][1000], int row)
{
	int pos1=0,pos2=0,z=0,match=0,same=0,length=0;
	while(ttmmpp[pos1]!=0)
	{
		length=0;
		while(ttmmpp[pos1+length]!=32) length++;
		while(bucket[row][pos2]!=0&&match!=length)
		{
			for(z=0;z<length;z++)
			{if(ttmmpp[pos1+z]==bucket[row][pos2+z]) match++;}
				if(match==length) {same+=1;}
				else {match=0;	pos2=pos2+length+1;}
		}
		pos1=pos1+length+1;
		pos2=match=0;
	}
	return same;
}





 
int insert(char ttmmpp[],char bucket[][1000], int row)
{ 
	int pos1=0,pos2=0,z,match=0,nullpos=0,num=0,length=0;
	while(bucket[row][nullpos]!=0) nullpos++;
	while(ttmmpp[pos1]!=0)
	{
		length=0;
		while(ttmmpp[pos1+length]!=32) length++;
		while(match!=length)
		{
			for(z=0;z<length;z++)
			{if(ttmmpp[pos1+z]==bucket[row][pos2+z]) match++;}
			if(match!=length&&bucket[row][pos2+length+1]==0)
			{
				for(z=0;z<length+1;z++){bucket[row][nullpos+z]=ttmmpp[pos1+z];}
				nullpos=nullpos+length+1;
				match=length;
			}
			if(match!=length){pos2=pos2+length+1; match=0;}
			if(match==length) num++;
		}
		pos1=pos1+length+1;
		match=pos2=0;
	}
	return num;
}
 
 


int countspace(char bucket[][1000], int row, int n)
{
	int space=0,i;
	while(bucket[row][i]!=0)
	{if(bucket[row][i]==32) {space++;} i++;}
	space=n-space;
	return space;
}




int findbestrow(char bucket[][1000], int n, int ttmmppnum, char ttmmpp[])
{
	int row=0,ccc,ddd,bestrow=0,bestsame=0,in=0;
	while(bucket[row][0]!=0)
	{
		ccc=countsame(ttmmpp,bucket,row);
		ddd=countspace(bucket,row,n);
		if(ttmmppnum-ccc<ddd&&ccc>=bestsame){bestsame=ccc;	bestrow=row;	in=1;}
		row++;
	}
	if(in==0) bestrow=row;
	
	return bestrow;
}





int new_mapping(int bestrow, int bitrow, char ttmmpp[], char bucket[][1000], int bitmap[][1000])
{
	int samepos=1,pos1=0,pos2=0,match=0,z,length=0;
	bitmap[bitrow][0]=bestrow;
	while(ttmmpp[pos1]!=0)
	{
		length=0;
		while(ttmmpp[pos1+length]!=32) length++;
		while(match!=length&&bucket[bestrow][pos2]!=0)
		{
			for(z=0;z<length;z++)
			{if(ttmmpp[pos1+z]==bucket[bestrow][pos2+z]) match++;}
			if(match!=length){pos2=pos2+length+1; match=0;samepos++;}
			if(match==length) bitmap[bitrow][samepos]=1;
		}
		pos1=pos1+length+1;
		match=pos2=0;
		samepos=1;
	}
	return bitrow+1;
}




