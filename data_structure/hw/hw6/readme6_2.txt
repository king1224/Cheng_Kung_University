開發平台(Development Platform):		Win10

使用開發環境(Development environment):	DEV-C++ 5.8.3

程式功能(Program Functions): 		
計算AOE network的early time跟late time跟slack


程式設計(Program design):		

in main
19-26 　初始化
45-67 　經過觀察後，若此AOE沒有迴圈的話，一定可以轉成上三角矩陣
	因此先試著轉成上三角矩陣，要交換node的時候將兩行兩列交換即可
70-76 　檢查是否有迴圈
81-88 　將路徑用edge2儲存起來，假設node 0指向 6跟9
	edge[0][0]=6 edge[0][1]=9
92-105  從node0開始做到全部的node，計算ee
	找所有能到達的路經中最大的(利用課本公式)
110-126 計算le，找每個node的最慢完成時間(利用課本公式)
128-136 印出結果