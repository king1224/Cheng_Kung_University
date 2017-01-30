#include <stdio.h>
#include <stdlib.h> 

int main()
{
	
	int node_num,edge_num=0;//�`�I�ƩM��(����)�� 
	FILE *fp;
	fp=fopen("Sample_input2.txt","r");
	if (!fp) {
        printf("�ɮ׶}�ҥ���...\n");
        exit(1);
    }
    else
    fscanf(fp, "%d", &node_num);
    //edge�������V�Ϫ�matrix��ܡAnode�����ꪺ���ǡAee�̦��}�l�ɶ��Aee�̺C�n�}�l���ɶ� 
    //edge1�����䪺�v���Aedge2�����Y��node���V�֡Anode�Aee,le�Ψӭp��̦��̱߮ɶ��Aindex�����Ȯɥ洫��node��m 
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
	
	
	//Ū�� 
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
	
	//node��⤬���A�չ��ন�W�T���x�}�A�̦h��1+2+...+node_num���A�����ˬdnode_num���覸 
	int change_tmp;
	for(int rr=0;rr<node_num*node_num;rr++)
	{
		for(int i=0;i<node_num;i++)
		for(int j=0;j<i;j++)//�ˬd�U�T�����O�_������ 
		if(edge1[i][j]!=0)//�Y�U�T�������� 
		{
			for(int k=0;k<node_num;k++)//���������_�I���I��椬�� 
			{
				change_tmp=edge1[i][k];
				edge1[i][k]=edge1[j][k];
				edge1[j][k]=change_tmp;
			}
			for(int k=0;k<node_num;k++)//���������_�I���I�C�C���� 
			{
				change_tmp=edge1[k][i];
				edge1[k][i]=edge1[k][j];
				edge1[k][j]=change_tmp;
			}
			change_tmp=index[i];//���node�w�洫�A�Hindex�������洫�A�̫�L�X�n��_�쪬 
			index[i]=index[j];
			index[j]=change_tmp;
		}
	}
	
	//�ˬd�Y�U�T���x�}�٦������A�N��L�k�����ন�W�T���A�@�w���j�� 
	for(int i=0;i<node_num;i++)
	for(int j=0;j<i;j++)
	if(edge1[i][j]!=0)
	{
		printf("Not irreflexive.\n");
		return 0;
	}
	
	
	//�N���|��edge2�x�s�n�A�N���V������O�x�s�bedge2[][0],edge2[][1]...... 
	int pos;
	for(int i=0;i<node_num;i++)
	{
		pos=0;
		for(int j=i+1;j<node_num;j++)
		{
			if(edge1[i][j]!=0) edge2[i][pos++]=j;
		}
	}
	
	
	//�}�l�p��ee[i]
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
	
	
	
	//�}�l�p��le[i]
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
				printf(" (%d,%d) �G\t   %d\t\t   %d\t\t  %d\n",index[i],index[edge2[i][j]],ee[i],le[edge2[i][j]]-edge1[i][edge2[i][j]],le[edge2[i][j]]-edge1[i][edge2[i][j]]-ee[i]);
			}
		}
	 
	
	return 0;
} 
