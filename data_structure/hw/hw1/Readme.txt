Program Enviroment:

OS: win8
Compiler: devcpp

Program Description:

<Main>
讓使用者輸入初始n,k

<iterative function的部分>
if：檢查n是否大於等於k
第一個else：檢查n!<13! 若大於13!系統無法正確運算
第二個else：用三個for迴圈先分別做n!,k!,(n-k)! 然後帶入公式


<recursive function的部分>
if：檢查n是否大於等於k
else：因為C(n取0)都等於1，設初始值為1，觀察得C(n,k)=C(n,k-1)*(n-k+1)/k