Program Enviroment:

OS: win8
Compiler: devcpp

此程式輸入前敘式 可做出運算
可輸入+-*/% ，超過萬位數
輸入方式：每一項之後請空白 最後一項直接enter

Program Description:

do-while(a[0] != (10-48))：當輸入不是enter的時候 把輸入存起來
	do迴圈內
		if(0<=a[0]&&a[0]<=9)：數字一個存一格
		else if(a[0]==-16)：空格的話，將前面一群數字看成一個數
				(一個符號也是直接存回一格 故不變)
				例如
				輸入 + 23 將 + 一個視為一組 存入一格
					將23 視為二十三存在同一格 即可輸入超過個位數
		else if(a[0]!=-38)：剩下的扣掉enter是運算子 存一格
		else：enter後將最後一組數字也存在同一個

for(i=count_word;i>=1;i--)：如果是運算元直接存，是運算子做對應運算