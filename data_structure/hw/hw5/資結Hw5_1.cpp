#include <stdio.h>
#include <math.h>

void check(int pos,int a,int tree[]);
void dele(int pos,int tree[]);
void move(int tree[],char rl,int pos,int num);
int find(int num,int count,int tree[]);



int main()
{

	int c,pos=0,count=0,temp=0,rec=0,count_word=1;
	//c���ӼȦs�n�x�s�ΧR�����`�I�Apos,rec�����@�ǹB��ɪ���m�Acount�����`�I�ӼơAcount_word������J�F�X�ռƦr 
	int i,j,n;
	int tree[3000],a[3000];//tree�����x�slevel order tree�Aa�ΨӼȦs�Ҧ���J���`�I�B�Ҧ��n�R�����`�I 
	for(i=0;i<3000;i++){tree[i]=-10; a[i]=-10;}//�]���`�I��J�i�ର0�A��l�ȳ]-10 
	printf("Input�G\n");
	i=1;
	do//���j����N�r�������_�ӡA�Y�J��ťթδ���h�N�e�����s��Ʀr�����@�աC 
	{
		a[0]=getchar()-'0';
		if(0<=a[0]&&a[0]<=9)
		{
			a[i]=a[0];
			i++;
			rec++;
		}
		else if(a[0]==-16)
		{
				for(j=i-1;j>=i-rec;j--)
				{
						n=rec-j+count_word-1;
						temp=temp+a[j]*pow(10,n);
				}
				
				count_word++;
				i=count_word;
				a[j+1]=temp;
				rec=0;
				temp=0;
		}

	}while(a[0] != 20);
	for(j=i-1;j>=i-rec;j--)
		{	n=rec-j+count_word-1;
			temp=temp+a[j]*pow(10,n);
		}
			a[j+1]=temp;
			a[j+2]=-10;
	i=1;
	do//�N�`�I�s�ba����A�̧ǥHlevel order�覡��itree���Y(��check�禡) 
	{
			c=a[i++];
			pos=0;
			check(pos,c,tree);
			count++;
		
	}while(c!=-10);
	
	
	for(i=0;i<3000;i++) a[i]=-10; temp=0; rec=0; count_word=1; i=1;//�n�O���R�����`�I�A���N��ƪ�l�� 
	
	do//��W���x�s��J�`�I�@�ˡA�N�n�R�����`�I�����x�s�ba 
	{
		a[0]=getchar()-'0';
		if(0<=a[0]&&a[0]<=9)
		{
			a[i]=a[0];
			i++;
			rec++;
		}
		else if(a[0]==-16)
		{
				for(j=i-1;j>=i-rec;j--)
				{
						n=rec-j+count_word-1;
						temp=temp+a[j]*pow(10,n);
				}
				
				count_word++;
				i=count_word;
				a[j+1]=temp;
				rec=0;
				temp=0;
		}

	}while(a[0] != 21);
	for(j=i-1;j>=i-rec;j--)
		{	n=rec-j+count_word-1;
			temp=temp+a[j]*pow(10,n);
		}
			a[j+1]=temp;
			a[j+2]=-10;
	i=1;

	do//�N�x�s�ba���`�I�̧ǧR���A��dele�禡 
	{
		c=a[i++];
		if(c!=-10)
		dele(find(c,count,tree),tree);
		count--;
	}while(c!=-10);
	
	printf("Output�G\n");
	i=0;
	while(count!=0)//��`�I��(count)�٤���0�A�N����L�X 
	{
		if(tree[i]==-10)	printf("X");
		else {printf("%d",tree[i]);  count--;}
		if(count!=0)
		printf(",");
		i++;
	}
	
	return 0;
} 



	
void check(int pos,int a,int tree[])//�ˬd�n���J���`�I�P��e��m(��e��m�D�ŧY!=-10)�֤j�֤p�A���j�h���k�l��A���p�h�����l�� 
{
	if(a<tree[pos]&&tree[pos]!=-10)
	{check(2*pos+1,a,tree);}
	else if(a>tree[pos]&&tree[pos]!=-10)
	{check(2*pos+2,a,tree);}
	else if(tree[pos]==-10)
	{tree[pos]=a;}
}


int find(int num,int count,int tree[])//���S�w���`�I��m�A�P��e��m����A���j�h���k�l��A���p�h�����l��A�Y�L�֤j�֤p�Y���F�A�Ǧ^��m 
{
	int i,pos=0;
	for(i=0;i<count;i++)
	{
		if (num>tree[pos]) pos=2*pos+2;
		else if (num<tree[pos]) pos=2*pos+1;
		else return pos;
	}
}


void dele(int pos,int tree[]) 
{
	int start=pos;
	int tmp;
	if(tree[2*pos+2]!=-10&&tree[2*pos+1]==-10)//�Y�u�����l��A������ʷh�W��
		move(tree,pos+2,2*pos+2,1);
	else if(tree[2*pos+2]==-10&&tree[2*pos+1]!=-10)//�Y�u���k�l��A������ʷh�W�� 
		move(tree,pos+1,2*pos+1,1);
	else if(tree[2*pos+2]!=-10&&tree[2*pos+1]!=-10)//�Y�����k�l��A�������l��̤j���W�Ӹɭn�R�����I�A�A���U����A�Y���ŦXlevel order�h�洫��m�A���U�� 
	{
		pos=2*pos+1;
		while(tree[2*pos+2]!=-10)
		{pos=2*pos+2;}
		tree[start]=tree[pos];
		tree[pos]=-10;
		if(tree[2*pos+1]!=10)
		move(tree,pos+1,2*pos+1,1);
		pos=start;
		while(tree[pos]>tree[2*pos+2]&&tree[2*pos+2]!=-10)
		{tmp=tree[pos];tree[pos]=tree[2*pos+2];tree[2*pos+2]=tmp; pos=2*pos+2;}
	}
	else//�Y�S���l��A�����R�� 
		tree[pos]=0;
}

void move(int tree[],char rl,int pos,int num)//���ʾ�ʾ�A�[���o�{�n���ʪ��I�A�C�@�h���e�@�h���⭿�A�n���ʪ�index�]�O�e�@�h���⭿ 
{//�Ĥ@�h�u���@�ӭn���� num��1�A�U�@�h��2*num�A�U�@�h�A���G..........�A rl���n��֪�index�A�C�@�h����W�@�h�h�⭿ 
	int t;
	int count=0;
	
	for(t=0;t<num;t++)//�����h���@��Ӿ�� 
	{
		tree[pos-rl+t]=tree[pos+t];
		if(tree[pos+t]==-10)
		count++;
	}
	
	if(count!=num)	
	move(tree,2*rl,2*pos+1,2*num);//��e�h�����h���A�~�I�s�U�@�h 
}
