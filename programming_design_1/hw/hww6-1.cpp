#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int ff[32],dd[64];		//�x�s32,64bit��binary number��J 
	float x1;	//�x�s��J��32bit�B�I�� 
	unsigned int *p=(unsigned int*) &x1;	//int���Ы��Vfloat�B�I�� 
	int i;
	float temp1=0;	//32bit�G�i����10�i��ɪ��Ȧs 
	printf("Input the float number�G");
	scanf("%f",&x1);
	
	unsigned int oldValue;	//�o��O�Nint�����ন�G�i���X 
	oldValue = *p;
	for( i = 1; i <= 32; i++) {	//32bit�ҥH��32�� 
	*p = *p << 1; 				//���N*p�V�����@�� 
	if(*p >= oldValue)	putchar('0');	//�p�G��Ӫ�*p�j���Ӫ�*p(oldValue)�A�N���Ӫ�*p�̥�������0�A������S���l���Ʀr�A�ϦӨ��`�ȭ�2�F�A�G���*p�j����*p�ɡA�L�X0 
	else	putchar('1');		//�Ϥ��A�̥��䬰1�A�����ᬰ����2���̰�����ƫ�A��2�A�]2���̰�����j��᭱�Ҧ��ƥ[�`�A�G�����j��@�b��*p��A��2�A�|�p���Ӫ�*p�A�G���*p�p����*p�ɡC�L�X1 
	oldValue=*p;	//�s�����­ȡA�i��U�@����� 
	}
	printf("\n");
	
	printf("Input binary number to convert float number�G\n");
	for(i=0;i<32;i++)		//�N32bit binary number���x�s�_�� 
	scanf("%1d",&ff[i]);
	for(i=0;i<32;i++)		//�G�i�10�i��A�x�s�btemp1 
	{temp1=temp1+ff[i]*pow(2,31-i);}
	*p=temp1;				//�N*p���ȧאּtemp1 
	printf("%f\n",x1);
	
	
	double x2;		//�x�s��J��64bit�B�I��  
	unsigned int *pp=(unsigned int*) &x2;	//int���Ы��Vdouble�B�I�� 
	printf("Input the double number�G");
	scanf("%lf",&x2);
	
	//�ഫ���G�i��覡�P�W�A�]int���Ь�32bit�Adouble��64bit�A�G����*(pp+1)���L�X�e32bit�A�A��*pp�L�X��32bit 
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
	
	printf("Input binary number to convert double number�G\n");
	temp1=0;
	
	for(i=0;i<63;i++)	//�N64bit binary number���x�s 
	scanf("%1d",&dd[i]);
	//�]��double�O64bit�Aint���ЬO32bit�A�G�]�n���⦸for�j����ഫ��10�i�� 
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

