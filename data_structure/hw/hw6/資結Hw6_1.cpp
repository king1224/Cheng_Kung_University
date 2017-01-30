#include <stdio.h>
#include <stdlib.h>

void sametree(int* edge2, int node[], int node_num,int tree_index,int row);

int main()
{
	int node_num;
	FILE *fp;
	fp=fopen("1.txt","r");
	if (!fp) {
        printf("檔案開啟失敗...\n");
        exit(1);
    }
    else
    fscanf(fp, "%d", &node_num);
    //edge1用來儲存邊的權重，edge2用來儲存是否取過這個邊，node用來儲存tree，array值即root 
    int edge1[node_num][node_num],edge2[node_num][node_num],node[node_num];
    for(int i=0;i<node_num;i++)
    {
    	for(int j=0;j<node_num;j++)
    	{
    		edge1[i][j]=edge2[i][j]=0;
		}
		node[i]=0;
	}
	
	
	//讀檔 
	for(int i=0;i<node_num;i++)
    {
    	for(int j=0;j<node_num;j++)
    	{
    		fscanf(fp,"%d",&edge1[i][j]);
		}
	}
	
	fclose(fp);
	
	//每個節點為一棵樹，因為無向，直接對每列或每行找最小值，找過的邊記錄在edge2 
	//edge_min紀錄當前取到的最小權重邊，min_row,min_col紀錄最小權重邊的行列(即邊的起點終點)，havvedge即有有效最小邊 
	int edge_min,min_row,min_col,haveedge;
	
	for(int i=0;i<node_num;i++)
    {
    	edge_min=99999999;min_row=min_col=haveedge=0;
    	for(int j=0;j<node_num;j++)
    	{
    		if(edge1[i][j]>0&&edge1[i][j]<edge_min)
    		{
				edge_min=edge1[i][j];
				min_row=i; min_col=j;
				haveedge=1;
			}
		}
		if(haveedge)
		edge2[min_row][min_col]=edge2[min_col][min_row]=-1;
		
	}
	
	
	
	//從edge2裡面的邊，來找出誰和誰同一棵樹，存在node陣列裡面，同一棵樹讓陣列值一樣
	int tree_index=node_num; 
	for(int k=0;k<node_num;k++)
	{
		if(node[k]==0)
		{
			node[k]=tree_index;
			sametree(&edge2[0][0],node,node_num,tree_index,k);
			tree_index++;
		}
	}
	//再將各棵樹串起來
	//以node的數量開始來標記編號樹，例如10個node，那第一棵樹的array值為10，第二棵樹array值為11......... 
	//count計算當前tree中有幾個node，等於node_num的時候表示全部都同一棵tree了，change_index儲存要被合併的tree node 
	int count,change_index;
	for(int i=0;i<node_num;i++) if(node[i]==node_num) count++;
	while(count!=node_num)
	{
		for(int z=node_num;z<tree_index;z++)
		{
			count=0,edge_min=99999999,haveedge=0,change_index=0;
			
			for(int i=0;i<node_num;i++)
			{
				if(node[i]==z)
				{
					for(int j=0;j<node_num;j++)
					{
						if(edge1[i][j]<edge_min&&edge1[i][j]>0&&edge2[i][j]!=-1)
						{
							edge_min=edge1[i][j];
							min_row=i; min_col=j;
							haveedge=1;
						}
					}
				}
			}
			if(haveedge)
			{
				edge2[min_row][min_col]=edge2[min_col][min_row]=-1;
				change_index=node[min_col];
				for(int k=0;k<node_num;k++)
				{
					if(node[k]==change_index)
					node[k]=z;
				}
			}
			for(int i=0;i<node_num;i++) if(node[i]==z) count++;
			if(count==node_num) break;
		}
	} 
	
	
	for(int z=0;z<node_num-1;z++)
	{
		edge_min=99999999;
		for(int i=0;i<node_num;i++)
		{
			for(int j=i+1;j<node_num;j++)
			{
				if(edge2[i][j]==-1&&edge1[i][j]<edge_min)
				{
					edge_min=edge1[i][j];
					min_row=i; min_col=j;
				}
			}
		}
		printf("(%d,%d)=%d\n",min_row,min_col,edge_min);
		edge2[min_row][min_col]=edge2[min_col][min_row]=0;
	}
	
	return 0;
} 



void sametree(int*edge2, int node[],int node_num,int tree_index,int row)
{
	int* tmp=edge2;
	edge2=edge2+node_num*(row);
	for(int i=0;i<node_num;i++)
	{
		if(*edge2==-1&&node[i]==0) 
		{
			node[i]=tree_index;
			row=i;
			sametree( tmp, node,node_num,tree_index,row);
		}
		edge2++;
	}
}






