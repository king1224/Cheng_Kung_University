#include <stdio.h>
#include <stdlib.h>

void sametree(int* edge2, int node[], int node_num,int tree_index,int row);

int main()
{
	int node_num;
	FILE *fp;
	fp=fopen("1.txt","r");
	if (!fp) {
        printf("�ɮ׶}�ҥ���...\n");
        exit(1);
    }
    else
    fscanf(fp, "%d", &node_num);
    //edge1�Ψ��x�s�䪺�v���Aedge2�Ψ��x�s�O�_���L�o����Anode�Ψ��x�stree�Aarray�ȧYroot 
    int edge1[node_num][node_num],edge2[node_num][node_num],node[node_num];
    for(int i=0;i<node_num;i++)
    {
    	for(int j=0;j<node_num;j++)
    	{
    		edge1[i][j]=edge2[i][j]=0;
		}
		node[i]=0;
	}
	
	
	//Ū�� 
	for(int i=0;i<node_num;i++)
    {
    	for(int j=0;j<node_num;j++)
    	{
    		fscanf(fp,"%d",&edge1[i][j]);
		}
	}
	
	fclose(fp);
	
	//�C�Ӹ`�I���@�ʾ�A�]���L�V�A������C�C�ΨC���̤p�ȡA��L����O���bedge2 
	//edge_min������e���쪺�̤p�v����Amin_row,min_col�����̤p�v���䪺��C(�Y�䪺�_�I���I)�Ahavvedge�Y�����ĳ̤p�� 
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
	
	
	
	//�qedge2�̭�����A�ӧ�X�֩M�֦P�@�ʾ�A�s�bnode�}�C�̭��A�P�@�ʾ����}�C�Ȥ@��
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
	//�A�N�U�ʾ��_��
	//�Hnode���ƶq�}�l�ӼаO�s����A�Ҧp10��node�A���Ĥ@�ʾ�array�Ȭ�10�A�ĤG�ʾ�array�Ȭ�11......... 
	//count�p���etree�����X��node�A����node_num���ɭԪ�ܥ������P�@��tree�F�Achange_index�x�s�n�Q�X�֪�tree node 
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






