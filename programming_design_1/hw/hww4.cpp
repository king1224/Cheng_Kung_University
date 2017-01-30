/******************************************
* �Ǹ��GC14031162
* �m�W�G�x����
* �sĶ�覡�Ggcc -o hw4 hw4.c
* ����覡�G./hw4 [how many numbers] [integer or float]
* �{���\��G�N�@�ռƦr�Ѥj��p�ƧǡA�i��ƩΤp��
* ��s����G2015/11/10
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);

 
int main(int argc, char* argv[])
{
	int N,P,i;	//N�n�ƴX�ӼƦr�AP�M�w�Ʀr�O��ƩίB�I�� 
	srand((unsigned)time(NULL));
	
	N = atoi(argv[1]);	//��J�`��� 
	P = *argv[2] - '0';	//��ܾ�ƩίB�I�� 
	
	int s[N];			//�x�s��� 
	double s_f[N];		//�x�s�B�I�� 
    
    if(P==0)			//��ƪ����p 
    {
    	for (i = 0; i < N; i++)	s[i]=(rand()%10001);	//����N��0~10000���Ʀr 
  		quicksort(s, 0, N - 1);			//�Ѥj��p�Ƨ� 
  		
  		printf("In sorted order:\n");	//�L�X���G 
 		for (i = 0; i < N; i++)
    	printf("%d\n", s[i]);
	}
	else if(P==1)		//�B�I�ƪ����p 
	{
		for (i = 0; i < N; i++)	s[i]=(rand()%1000000001);	//����N��1~10^9���Ʀr 
  		quicksort(s, 0, N - 1);			//�Ѥj��p�� 
		
		printf("In sorted order:\n");	//�N�U�ӼƦr��10^5�A�M����ܵ��G 
 		for (i = 0; i < N; i++)
		{
			s_f[i]=s[i]*0.00001;
			printf("%f\n", s_f[i]);
    	}
	}
	else	//���� 
	{
		printf("You can only input 0 or 1 to select the integer or the float.");
		return 0;
	}
	
	
	return 0;
}

void quicksort(int a[], int high, int low)	//�Ѥj��p�� 
{
	int middle;
	if (high >= low) return;
	middle = split(a, high, low);			//�N��Ĥ@��Ʀr�j����@��A���p����t�~�@��A�O�������I 
	quicksort(a, high, middle - 1);			//�N�����L�����b�A���@�˪��� 
	quicksort(a, middle + 1, low);			//�N�����L���k�b�A���@�˪��� 
}

int split(int a[], int high, int low)	//�ഫ���B�J 
{
	int part_element = a[high];

	for (;;)
	 {
		while (high < low && part_element >= a[low])	//�Y�k��Ʀr���j�A��쥪�� 
    	low--;
		if (high >= low) break;
		a[high++] = a[low];

		while (high < low && a[high] >= part_element)	//�Y����Ʀr���p�A���k�� 
    	high++;
		if (high >= low) break;
		a[low--] = a[high];
	}

	a[low] = part_element;	//�N�Ĥ@����S�w��m 
	return low;
}
