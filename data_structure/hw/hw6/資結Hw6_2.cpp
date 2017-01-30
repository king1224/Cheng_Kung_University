#include <stdio.h>
#include <stdlib.h> 

int main()
{
	
	int node_num,edge_num=0;//節點數和邊(活動)數 
	FILE *fp;
	fp=fopen("Sample_input2.txt","r");
	if (!fp) {
        printf("檔案開啟失敗...\n");
        exit(1);
    }
    else
    fscanf(fp, "%d", &node_num);
    //edge紀錄有向圖的matrix表示，node紀錄串的順序，ee最早開始時間，ee最慢要開始的時間 
    //edge1紀錄邊的權重，edge2紀錄某個node指向誰，node，ee,le用來計算最早最晚時間，index紀錄暫時交換的node位置 
    int edge1[node_num][node_num],edge2[node_num][node_num],node[node_num],ee[node_num],le[node_num],index[node_num];
    for(int i=0;i<node_num;i++)
    {
    	for(int j=0;j<node_num;j++)
    	{
    		edge1[i][j]=edge2[i][j]=0;
		}
		node[i]=ee[i]=le[i]=0;
		index[i]=i;
	}
	
	
	//讀檔 
	for(int i=0;i<node_num;i++)
    {
    	for(int j=0;j<node_num;j++)
    	{
    		fscanf(fp,"%d",&edge1[i][j]);
    		if(edge1[i][j]!=0)
    		edge_num++;
		}
	}
	
	fclose(fp);
	
	//node兩兩互換，試圖轉成上三角矩陣，最多做1+2+...+node_num次，直接檢查node_num平方次 
	int change_tmp;
	for(int rr=0;rr<node_num*node_num;rr++)
	{
		for(int i=0;i<node_num;i++)
		for(int j=0;j<i;j++)//檢查下三角中是否有元素 
		if(edge1[i][j]!=0)//若下三角有元素 
		{
			for(int k=0;k<node_num;k++)//此元素的起點終點行行互換 
			{
				change_tmp=edge1[i][k];
				edge1[i][k]=edge1[j][k];
				edge1[j][k]=change_tmp;
			}
			for(int k=0;k<node_num;k++)//此元素的起點終點列列互換 
			{
				change_tmp=edge1[k][i];
				edge1[k][i]=edge1[k][j];
				edge1[k][j]=change_tmp;
			}
			change_tmp=index[i];//兩個node已交換，以index紀錄此交換，最後印出要恢復原狀 
			index[i]=index[j];
			index[j]=change_tmp;
		}
	}
	
	//檢查若下三角矩陣還有元素，代表無法完全轉成上三角，一定有迴圈 
	for(int i=0;i<node_num;i++)
	for(int j=0;j<i;j++)
	if(edge1[i][j]!=0)
	{
		printf("Not irreflexive.\n");
		return 0;
	}
	
	
	//將路徑用edge2儲存好，將指向的邊分別儲存在edge2[][0],edge2[][1]...... 
	int pos;
	for(int i=0;i<node_num;i++)
	{
		pos=0;
		for(int j=i+1;j<node_num;j++)
		{
			if(edge1[i][j]!=0) edge2[i][pos++]=j;
		}
	}
	
	
	//開始計算ee[i]
	for(int k=0;k<node_num;k++)
	{
		for(int i=0;i<node_num;i++)
		{
			for(int j=0;j<node_num;j++)
			{
				if(edge2[i][j]==k)
				{
					if((ee[i]+edge1[i][k])>ee[k])
					ee[k]=ee[i]+edge1[i][k];
				}
			}
		} 
	}
	
	
	
	//開始計算le[i]
	le[node_num-1]=ee[node_num-1];
	
	int next_count;
	for(int k=node_num-1;k>=0;k--)
	{
		next_count=0;
		for(int i=0;i<node_num;i++)
		{
			if(edge2[k][i]!=0) next_count++;
		}
		if(next_count>0) le[k]=ee[node_num-1];
		for(int i=0;i<next_count;i++)
		{
			if((le[edge2[k][i]]-edge1[k][edge2[k][i]])<le[k])
			le[k]=(le[edge2[k][i]]-edge1[k][edge2[k][i]]);
		}
	}
	
		printf("activity\tearly time\tlate time\tslack\n");
		for(int i=0;i<node_num;i++)
		{
			for(int j=0;j<node_num;j++)
			{
				if(edge2[i][j]!=0)
				printf(" (%d,%d) ：\t   %d\t\t   %d\t\t  %d\n",index[i],index[edge2[i][j]],ee[i],le[edge2[i][j]]-edge1[i][edge2[i][j]],le[edge2[i][j]]-edge1[i][edge2[i][j]]-ee[i]);
			}
		}
	 
	
	return 0;
} 
