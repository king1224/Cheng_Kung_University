Program Enviroment:

OS: win8
Compiler: devcpp

輸入兩個矩陣後輸出相乘

Program Description:	***a,b最後一行有0就會出錯...，非稀疏矩陣才可正確ˊ口ˋ***

先宣告很多個架構


matrixPointer newNode(void)用來創造新的node


matrixPointer mult(matrixPointer a,matrixPointer b)將矩陣相乘
	三層for迴圈：最內層用來計算某列乘某行
		 　　第二層用來紀錄當前行 b矩陣的第0行到第col-1行
		　　 最外層用來記錄當前列 a矩陣的第0列到第row-1列


matrixPointer mread1(void);分別用來讀取a,b矩陣
matrixPointer mread2(void);用兩個for迴圈紀錄紀錄行列位置，取代課本的直接輸入