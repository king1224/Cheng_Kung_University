#include <stdio.h> 
#include <stdlib.h> 


int order(char);

int main(void) { 
    char in[100]={'\0'};		//儲存輸入 
    char postfix[100]={'\0'};	//儲存輸出 
    char stack[100]={'\0'};		//stack 站存運算子 
	int i,j,temp,length=0,k=0,top=0,pos=0,count=0;
	//length紀錄輸入多長  count紀錄括弧造成多少空洞
	//top紀錄stack存到哪了  pos紀錄輸出存到哪了 
	printf("Please input infix：");
    scanf("%s",in);					//輸入中序式 
    for(i=0;in[i]!='\0';i++)		//紀錄輸入總長度 
    length++;
	pos=length-1;					//存放時的位置	倒過來存 例長度為10時 要從postfix[9]開始往回存 
	for(j=length-1;j>=0;j--)
	{
    		switch(in[j]) 
    		{
    			case ')':			//存進stack，並記錄存在哪 
    				stack[top]=in[j];
					top++;
					temp=top;
					count++;
    				break;
    			case '(':			//掃描stack，在)的位置之前的運算子都拿出來 
    				while(top>temp) 
    				{
    					postfix[pos]=stack[top-1];
    					pos--;
    					top--;
					}
					top--;
					count++;
					break;
				case '+': case '-': case '*': case '/':		//比較優先權 看存入stack時是否要拿出stack的東西 
           			while(order(stack[top-1]) > order(in[j]))
					{
						postfix[pos] = stack[top-1];
						pos--;
						top--;
					}
            			stack[top] = in[j];
            			top++;
            			break; 
            	default:			//此為運算元，直接存 
            		postfix[pos]=in[j];
            		pos--;
			}
	}
	while(top>0)		//將stack剩餘運算子拿出 
			{
				postfix[pos]=stack[top-1];
				pos--;
				top--;
			}
	if(count!=0)		//將整組資料往前移，因括弧造成的空缺 
	for(i=count;i<length;i++)
	postfix[i-count]=postfix[i];
	postfix[length-count]=0;
    for(i=0;postfix[i]!=0;i++)		//印出答案囉 
	printf("%c",postfix[i]);

	return 0; 
} 



int order(char a)		//給予優先權  2>1 
{ 
    switch(a)
	{ 
        case '+': return 1;
		case '-': return 1;
        case '*': return 2;
		case '/': return 2;
        default:  return 0;
    } 
}
