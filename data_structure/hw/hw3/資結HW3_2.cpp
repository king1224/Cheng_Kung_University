#include <stdio.h> 
#include <stdlib.h> 


int order(char);

int main(void) { 
    char in[100]={'\0'};		//�x�s��J 
    char postfix[100]={'\0'};	//�x�s��X 
    char stack[100]={'\0'};		//stack ���s�B��l 
	int i,j,temp,length=0,k=0,top=0,pos=0,count=0;
	//length������J�h��  count�����A���y���h�֪Ŭ}
	//top����stack�s����F  pos������X�s����F 
	printf("Please input infix�G");
    scanf("%s",in);					//��J���Ǧ� 
    for(i=0;in[i]!='\0';i++)		//������J�`���� 
    length++;
	pos=length-1;					//�s��ɪ���m	�˹L�Ӧs �Ҫ��׬�10�� �n�qpostfix[9]�}�l���^�s 
	for(j=length-1;j>=0;j--)
	{
    		switch(in[j]) 
    		{
    			case ')':			//�s�istack�A�ðO���s�b�� 
    				stack[top]=in[j];
					top++;
					temp=top;
					count++;
    				break;
    			case '(':			//���ystack�A�b)����m���e���B��l�����X�� 
    				while(top>temp) 
    				{
    					postfix[pos]=stack[top-1];
    					pos--;
    					top--;
					}
					top--;
					count++;
					break;
				case '+': case '-': case '*': case '/':		//����u���v �ݦs�Jstack�ɬO�_�n���Xstack���F�� 
           			while(order(stack[top-1]) > order(in[j]))
					{
						postfix[pos] = stack[top-1];
						pos--;
						top--;
					}
            			stack[top] = in[j];
            			top++;
            			break; 
            	default:			//�����B�⤸�A�����s 
            		postfix[pos]=in[j];
            		pos--;
			}
	}
	while(top>0)		//�Nstack�Ѿl�B��l���X 
			{
				postfix[pos]=stack[top-1];
				pos--;
				top--;
			}
	if(count!=0)		//�N��ո�Ʃ��e���A�]�A���y�����ů� 
	for(i=count;i<length;i++)
	postfix[i-count]=postfix[i];
	postfix[length-count]=0;
    for(i=0;postfix[i]!=0;i++)		//�L�X�����o 
	printf("%c",postfix[i]);

	return 0; 
} 



int order(char a)		//�����u���v  2>1 
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
