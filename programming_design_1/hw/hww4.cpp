/******************************************
* 學號：C14031162
* 姓名：洪正皇
* 編譯方式：gcc -o hw4 hw4.c
* 執行方式：./hw4 [how many numbers] [integer or float]
* 程式功能：將一組數字由大到小排序，可整數或小數
* 更新日期：2015/11/10
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);

 
int main(int argc, char* argv[])
{
	int N,P,i;	//N要排幾個數字，P決定數字是整數或浮點數 
	srand((unsigned)time(NULL));
	
	N = atoi(argv[1]);	//輸入總格數 
	P = *argv[2] - '0';	//選擇整數或浮點數 
	
	int s[N];			//儲存整數 
	double s_f[N];		//儲存浮點數 
    
    if(P==0)			//整數的情況 
    {
    	for (i = 0; i < N; i++)	s[i]=(rand()%10001);	//產生N個0~10000的數字 
  		quicksort(s, 0, N - 1);			//由大到小排序 
  		
  		printf("In sorted order:\n");	//印出結果 
 		for (i = 0; i < N; i++)
    	printf("%d\n", s[i]);
	}
	else if(P==1)		//浮點數的情況 
	{
		for (i = 0; i < N; i++)	s[i]=(rand()%1000000001);	//產生N個1~10^9的數字 
  		quicksort(s, 0, N - 1);			//由大到小排 
		
		printf("In sorted order:\n");	//將各個數字除10^5，然後顯示結果 
 		for (i = 0; i < N; i++)
		{
			s_f[i]=s[i]*0.00001;
			printf("%f\n", s_f[i]);
    	}
	}
	else	//偵錯 
	{
		printf("You can only input 0 or 1 to select the integer or the float.");
		return 0;
	}
	
	
	return 0;
}

void quicksort(int a[], int high, int low)	//由大到小排 
{
	int middle;
	if (high >= low) return;
	middle = split(a, high, low);			//將比第一格數字大的放一邊，較小的放另外一邊，記錄分界點 
	quicksort(a, high, middle - 1);			//將剛剛分過的左半，做一樣的事 
	quicksort(a, middle + 1, low);			//將剛剛分過的右半，做一樣的事 
}

int split(int a[], int high, int low)	//轉換的步驟 
{
	int part_element = a[high];

	for (;;)
	 {
		while (high < low && part_element >= a[low])	//若右邊數字較大，放到左邊 
    	low--;
		if (high >= low) break;
		a[high++] = a[low];

		while (high < low && a[high] >= part_element)	//若左邊數字較小，放到右邊 
    	high++;
		if (high >= low) break;
		a[low--] = a[high];
	}

	a[low] = part_element;	//將第一格放到特定位置 
	return low;
}
