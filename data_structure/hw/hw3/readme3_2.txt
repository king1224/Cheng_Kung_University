Program Enviroment:

OS: win8
Compiler: devcpp

Program Description:

<Main>
for(j=length-1;j>=0;j--)：一個一個輸入字元取，取後照swich方式排好
switch(in[j])：	case們利用stack使運算子依照指定方式排好，
		運算子優先權比stack[top]優先權高時可繼續存入，否則取出stack[top]
		default是case以外，即運算元，直接儲存進postfix
while(top>0)：將stack內剩的運算子拿出來放
if(count!=0)：若有遇到括弧(整筆資料會存太後面，因括弧後來沒存進去)，將資料往前平移，
		並設定終點postfix[length-count]=0
for(i=0;postfix[i]!=0;i++)：還沒碰到終點就持續印出

<order的部分>
給予運算子優先權 2>1