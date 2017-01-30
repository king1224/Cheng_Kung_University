Program Enviroment:

OS: win8
Compiler: devcpp

Program Description:

<Main>

輸入行數列數後
for(i=0;i<row;i++),for(j=0;j<col;j++)：輸入各個元素 若不為0則存起來
for(i=0;i<col;i++)：輸出矩陣 若元素為0則printf("0")


<fastTranspose>

if(numTerms>0)：確保矩陣不為0

for(i=1;i<=numTerms;i++)
row_pos[(a[i].col)]++       ：設定各列元素個數

下一個迴圈for(i=0;i<=numCols;i++)：設定各列起始位置

for(i=1;i<=numTerms;i++):轉置ｔｉｍｅ