#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int ff[32],dd[64];		//儲存32,64bit的binary number輸入 
	float x1;	//儲存輸入的32bit浮點數 
	unsigned int *p=(unsigned int*) &x1;	//int指標指向float浮點數 
	int i;
	float temp1=0;	//32bit二進制轉10進制時的暫存 
	printf("Input the float number：");
	scanf("%f",&x1);
	
	unsigned int oldValue;	//這邊是將int指標轉成二進制輸出 
	oldValue = *p;
	for( i = 1; i <= 32; i++) {	//32bit所以做32次 
	*p = *p << 1; 				//先將*p向左移一個 
	if(*p >= oldValue)	putchar('0');	//如果後來的*p大於原來的*p(oldValue)，代表原來的*p最左邊應為0，左移後沒有損失數字，反而使總值乘2了，故後來*p大於原來*p時，印出0 
	else	putchar('1');		//反之，最左邊為1，左移後為扣掉2的最高次方數後再乘2，因2的最高次方大於後面所有數加總，故扣掉大於一半的*p後再乘2，會小於原來的*p，故後來*p小於原來*p時。印出1 
	oldValue=*p;	//新值變舊值，進行下一次比較 
	}
	printf("\n");
	
	printf("Input binary number to convert float number：\n");
	for(i=0;i<32;i++)		//將32bit binary number先儲存起來 
	scanf("%1d",&ff[i]);
	for(i=0;i<32;i++)		//二進制換10進制，儲存在temp1 
	{temp1=temp1+ff[i]*pow(2,31-i);}
	*p=temp1;				//將*p的值改為temp1 
	printf("%f\n",x1);
	
	
	double x2;		//儲存輸入的64bit浮點數  
	unsigned int *pp=(unsigned int*) &x2;	//int指標指向double浮點數 
	printf("Input the double number：");
	scanf("%lf",&x2);
	
	//轉換為二進制方式同上，因int指標為32bit，double為64bit，故須用*(pp+1)先印出前32bit，再用*pp印出後32bit 
	oldValue = *(pp+1);
	for(i = 1; i <= 32; i++) {
	*(pp+1) = *(pp+1) << 1; 
	if(*(pp+1) >= oldValue)	putchar('0');
	else	putchar('1');
	oldValue=*(pp+1);
	}
	oldValue = *pp;
	for(i = 1; i <= 32; i++) {
	*pp = *pp << 1; 
	if(*pp >= oldValue)	putchar('0');
	else	putchar('1');
	oldValue=*pp;
	}
	printf("\n");
	
	printf("Input binary number to convert double number：\n");
	temp1=0;
	
	for(i=0;i<63;i++)	//將64bit binary number先儲存 
	scanf("%1d",&dd[i]);
	//因為double是64bit，int指標是32bit，故也要分兩次for迴圈來轉換成10進制 
	for(i=0;i<31;i++)
	{temp1=temp1+dd[i]*pow(2,31-i);}
	*(pp+1)=temp1;
	
	temp1=0;
	
	for(i=0;i<31;i++)
	{temp1=temp1+dd[i+32]*pow(2,31-i);}
	*pp=temp1;
	
	printf("%lf",x2);

	return 0;
}
//1.175494350822287507968736537222245677818665556772087521508751706278417259454727172851560500000000000000000000000000000000e-38f;

