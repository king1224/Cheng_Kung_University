#include <stdio.h>
#include <math.h>
//先宣告32個bit-field為1的struct裡的變數 
typedef struct A{
	unsigned int s1:1;	unsigned int s2:1;
	unsigned int s3:1;	unsigned int s4:1;
	unsigned int s5:1;	unsigned int s6:1;
	unsigned int s7:1;	unsigned int s8:1;
	unsigned int s9:1;	unsigned int s10:1;
	unsigned int s11:1;	unsigned int s12:1;
	unsigned int s13:1;	unsigned int s14:1;
	unsigned int s15:1;	unsigned int s16:1;
	unsigned int s17:1;	unsigned int s18:1;
	unsigned int s19:1;	unsigned int s20:1;
	unsigned int s21:1;	unsigned int s22:1;
	unsigned int s23:1;	unsigned int s24:1;
	unsigned int s25:1;	unsigned int s26:1;
	unsigned int s27:1;	unsigned int s28:1;
	unsigned int s29:1;	unsigned int s30:1;
	unsigned int s31:1;	unsigned int s32:1;
}a;
//先宣告64個bit-field為1的struct裡的變數 
typedef struct D{
	unsigned int s1:1;	unsigned int s2:1;
	unsigned int s3:1;	unsigned int s4:1;
	unsigned int s5:1;	unsigned int s6:1;
	unsigned int s7:1;	unsigned int s8:1;
	unsigned int s9:1;	unsigned int s10:1;
	unsigned int s11:1;	unsigned int s12:1;
	unsigned int s13:1;	unsigned int s14:1;
	unsigned int s15:1;	unsigned int s16:1;
	unsigned int s17:1;	unsigned int s18:1;
	unsigned int s19:1;	unsigned int s20:1;
	unsigned int s21:1;	unsigned int s22:1;
	unsigned int s23:1;	unsigned int s24:1;
	unsigned int s25:1;	unsigned int s26:1;
	unsigned int s27:1;	unsigned int s28:1;
	unsigned int s29:1;	unsigned int s30:1;
	unsigned int s31:1;	unsigned int s32:1;
	unsigned int s33:1;	unsigned int s34:1;
	unsigned int s35:1;	unsigned int s36:1;
	unsigned int s37:1;	unsigned int s38:1;
	unsigned int s39:1;	unsigned int s40:1;
	unsigned int s41:1;	unsigned int s42:1;
	unsigned int s43:1;	unsigned int s44:1;
	unsigned int s45:1;	unsigned int s46:1;
	unsigned int s47:1;	unsigned int s48:1;
	unsigned int s49:1;	unsigned int s50:1;
	unsigned int s51:1;	unsigned int s52:1;
	unsigned int s53:1;	unsigned int s54:1;
	unsigned int s55:1;	unsigned int s56:1;
	unsigned int s57:1;	unsigned int s58:1;
	unsigned int s59:1;	unsigned int s60:1;
	unsigned int s61:1;	unsigned int s62:1;
	unsigned int s63:1;	unsigned int s64:1;
}d;
//將32個bit-field為1的struct與float做union起來 
typedef union B{
	float f;
	a c;
}b;
//將64個bit-field為1的struct與double做union起來 
typedef union C{
	double f;
	d c;
}c;

int main()
{
	int ff[32]={0},dd[64]={0},i;	//ff用來暫存32 or 64 bit binary number輸入
	float temp1=0;		//用來暫存二進制轉十進制的總值 
	b input1;			//宣告一個包含float的union 
	printf("Input the float number：");
	scanf("%f",&input1.f);	//輸入float值之後，因空間共用所以從一個一個1bit的變數印出
	 
	printf("%d",input1.c.s32);	printf("%d",input1.c.s31);
	printf("%d",input1.c.s30);	printf("%d",input1.c.s29);
	printf("%d",input1.c.s28);	printf("%d",input1.c.s27);
	printf("%d",input1.c.s26);	printf("%d",input1.c.s25);
	printf("%d",input1.c.s24);	printf("%d",input1.c.s23);
	printf("%d",input1.c.s22);	printf("%d",input1.c.s21);
	printf("%d",input1.c.s20);	printf("%d",input1.c.s19);
	printf("%d",input1.c.s18);	printf("%d",input1.c.s17);
	printf("%d",input1.c.s16);	printf("%d",input1.c.s15);
	printf("%d",input1.c.s14);	printf("%d",input1.c.s13);
	printf("%d",input1.c.s12);	printf("%d",input1.c.s11);
	printf("%d",input1.c.s10);	printf("%d",input1.c.s9);
	printf("%d",input1.c.s8);	printf("%d",input1.c.s7);
	printf("%d",input1.c.s6);	printf("%d",input1.c.s5);
	printf("%d",input1.c.s4);	printf("%d",input1.c.s3);
	printf("%d",input1.c.s2);	printf("%d",input1.c.s1);
	printf("\n");
	
	input1.f=0;//初始化 
	printf("Input binary number to convert float number：\n");
	for(i=0;i<32;i++)	//先暫存32bit binary number輸入 
	scanf("%1d",&ff[i]);
	//一個一個填到1bit的變數中 
	input1.c.s32=ff[0];		input1.c.s31=ff[1];
	input1.c.s30=ff[2];		input1.c.s29=ff[3];
	input1.c.s28=ff[4];		input1.c.s27=ff[5];
	input1.c.s26=ff[6];		input1.c.s25=ff[7];
	input1.c.s24=ff[8];		input1.c.s23=ff[9];
	input1.c.s22=ff[10];	input1.c.s21=ff[11];
	input1.c.s20=ff[12];	input1.c.s19=ff[13];
	input1.c.s18=ff[14];	input1.c.s17=ff[15];
	input1.c.s16=ff[16];	input1.c.s15=ff[17];
	input1.c.s14=ff[18];	input1.c.s13=ff[19];
	input1.c.s12=ff[20];	input1.c.s11=ff[21];
	input1.c.s10=ff[22];	input1.c.s9=ff[23];
	input1.c.s8=ff[24];		input1.c.s7=ff[25];
	input1.c.s6=ff[26];		input1.c.s5=ff[27];
	input1.c.s4=ff[28];		input1.c.s3=ff[29];
	input1.c.s2=ff[30];		input1.c.s1=ff[31];
	printf("%0.100e\n",input1.f);//印出float 
	
	c input2;	//宣告含有double的union 
	printf("Input the double number：");
	scanf("%lf",&input2.f);		//輸入double值 
	
	//一個一個bit輸出 
	printf("%d",input2.c.s64);	printf("%d",input2.c.s63);
	printf("%d",input2.c.s62);	printf("%d",input2.c.s61);
	printf("%d",input2.c.s60);	printf("%d",input2.c.s59);
	printf("%d",input2.c.s58);	printf("%d",input2.c.s57);
	printf("%d",input2.c.s56);	printf("%d",input2.c.s55);
	printf("%d",input2.c.s54);	printf("%d",input2.c.s53);
	printf("%d",input2.c.s52);	printf("%d",input2.c.s51);
	printf("%d",input2.c.s50);	printf("%d",input2.c.s49);
	printf("%d",input2.c.s48);	printf("%d",input2.c.s47);
	printf("%d",input2.c.s46);	printf("%d",input2.c.s45);
	printf("%d",input2.c.s44);	printf("%d",input2.c.s43);
	printf("%d",input2.c.s42);	printf("%d",input2.c.s41);
	printf("%d",input2.c.s40);	printf("%d",input2.c.s39);
	printf("%d",input2.c.s38);	printf("%d",input2.c.s37);
	printf("%d",input2.c.s36);	printf("%d",input2.c.s35);
	printf("%d",input2.c.s34);	printf("%d",input2.c.s33);
	printf("%d",input2.c.s32);	printf("%d",input2.c.s31);
	printf("%d",input2.c.s30);	printf("%d",input2.c.s29);
	printf("%d",input2.c.s28);	printf("%d",input2.c.s27);
	printf("%d",input2.c.s26);	printf("%d",input2.c.s25);
	printf("%d",input2.c.s24);	printf("%d",input2.c.s23);
	printf("%d",input2.c.s22);	printf("%d",input2.c.s21);
	printf("%d",input2.c.s20);	printf("%d",input2.c.s19);
	printf("%d",input2.c.s18);	printf("%d",input2.c.s17);
	printf("%d",input2.c.s16);	printf("%d",input2.c.s15);
	printf("%d",input2.c.s14);	printf("%d",input2.c.s13);
	printf("%d",input2.c.s12);	printf("%d",input2.c.s11);
	printf("%d",input2.c.s10);	printf("%d",input2.c.s9);
	printf("%d",input2.c.s8);	printf("%d",input2.c.s7);
	printf("%d",input2.c.s6);	printf("%d",input2.c.s5);
	printf("%d",input2.c.s4);	printf("%d",input2.c.s3);
	printf("%d",input2.c.s2);	printf("%d",input2.c.s1);
	printf("\n");
	
	input2.f=0;//初始化 
	printf("Input binary number to convert double number：\n");
	for(i=0;i<64;i++)	//先暫存64bit binary number 
	scanf("%1d",&dd[i]);
	//一個一個指派給1bit的變數 
	input2.c.s64=dd[0];		input2.c.s63=dd[1];
	input2.c.s62=dd[2];		input2.c.s61=dd[3];
	input2.c.s60=dd[4];		input2.c.s59=dd[5];
	input2.c.s58=dd[6];		input2.c.s57=dd[7];
	input2.c.s56=dd[8];		input2.c.s55=dd[9];
	input2.c.s54=dd[10];	input2.c.s53=dd[11];
	input2.c.s52=dd[12];	input2.c.s51=dd[13];
	input2.c.s50=dd[14];	input2.c.s49=dd[15];
	input2.c.s48=dd[16];	input2.c.s47=dd[17];
	input2.c.s46=dd[18];	input2.c.s45=dd[19];
	input2.c.s44=dd[20];	input2.c.s43=dd[21];
	input2.c.s42=dd[22];	input2.c.s41=dd[23];
	input2.c.s40=dd[24];	input2.c.s39=dd[25];
	input2.c.s38=dd[26];	input2.c.s37=dd[27];
	input2.c.s36=dd[28];	input2.c.s35=dd[29];
	input2.c.s34=dd[30];	input2.c.s33=dd[31];
	input2.c.s32=dd[32];	input2.c.s31=dd[33];
	input2.c.s30=dd[34];	input2.c.s29=dd[35];
	input2.c.s28=dd[36];	input2.c.s27=dd[37];
	input2.c.s26=dd[38];	input2.c.s25=dd[39];
	input2.c.s24=dd[40];	input2.c.s23=dd[41];
	input2.c.s22=dd[42];	input2.c.s21=dd[43];
	input2.c.s20=dd[44];	input2.c.s19=dd[45];
	input2.c.s18=dd[46];	input2.c.s17=dd[47];
	input2.c.s16=dd[48];	input2.c.s15=dd[49];
	input2.c.s14=dd[50];	input2.c.s13=dd[51];
	input2.c.s12=dd[52];	input2.c.s11=dd[53];
	input2.c.s10=dd[54];	input2.c.s9=dd[55];
	input2.c.s8=dd[56];		input2.c.s7=dd[57];
	input2.c.s6=dd[58];		input2.c.s5=dd[59];
	input2.c.s4=dd[60];		input2.c.s3=dd[61];
	input2.c.s2=dd[62];		input2.c.s1=dd[63];
	printf("%0.100e\n",input2.f);	//印出double 
	return 0;
} 
