#include <stdio.h> 
#include <stdlib.h>



int main()
{
	int board[8][8]={0};
	int ktmove1[8]={-2,-1,1,2,2,1,-1,-2};
	int ktmove2[8]={1,2,2,1,-1,-2,-2,-1};
	int i,j;
	
	//讓使用者輸入起點，及檢查輸入是否在棋盤外 
	printf("Please input the starting position (i,j) for 0<=i,j<=7.\n");
	scanf("%d %d",&i,&j);
	if(i>7||i<0||j>7||j<0){
	printf("wrong input.");
	return 0;	
	}
	
	int nexti[8]={0};					//存放下一個移動點i座標 
	int nextj[8]={0};					//存放下一個移動點j座標 
	int next_nexti[8]={0};				//存放下下一個移動點i座標
	int next_nextj[8]={0};				//存放下下一個移動點j座標
	int m,h,r,x,p,min;					//一大堆拿來用for迴圈的變數 跟min 

	
	for(p=1;p<=63;p++){					//64個格子走64次 
		int npos=0;
		int flag=0;
		int exist[8]={0};				//第一次移動後，能再移動的點個數 
		int match[8]={0};				//檢查是否為合法移動點
		board[i][j]=p;
		for(h=0;h<8;h++){				//這個for找出有幾個可移動的點 
			nexti[h]=i+ktmove1[h];
			nextj[h]=j+ktmove2[h];
			if(nexti[h]<=7&&nexti[h]>=0&&nextj[h]<=7&&nextj[h]>=0&&board[nexti[h]][nextj[h]]==0){
			npos++;
			match[h]=1;
			}}
		if(npos==0){					//若沒有點可以移動，設計錯誤 
			printf("system wrong.\n");
			return 0;
		}
		else if(npos==1){				//若只有一個點可以移動，直接上吧 
			for(h=0;h<8;h++)
				if(match[h]==1){
				min=h;
				i=nexti[min]; j=nextj[min];}}
		else							//有很多個點可以移動的時候，找第二次可走的點最少的 
		for(m=0;m<8;m++){
		if(match[m]==1) {				//當第一次移動的點是合法點才走第二次 
		for(h=0;h<8;h++){
			next_nexti[h]=nexti[m]+ktmove1[h];
			next_nextj[h]=nextj[m]+ktmove2[h];
			if(next_nexti[h]<=7 && next_nexti[h]>=0 && next_nextj[h]<=7 && next_nextj[h]>=0 && board[next_nexti[h]][next_nextj[h]]==0)
			exist[m]++;					//標記第二次可走多少點 
		}}}
		for(x=1;x<9;x++){ 				//統計完各個第一次移動點的第二次走法後，找最小，若第二次出口相同，依順時針優先順序 
			if(flag==1) break;
			for(h=0;h<8;h++){
				if(flag==1)	break;
					if(board[nexti[h]][nextj[h]]==0){
						if(exist[h]==x){
							min=h;
							flag=1;
		}}}}
		i=nexti[min]; j=nextj[min];		//確定移動到下一個點 
	}
	printf("    ");
	for(i=0;i<8;i++){					//最後印出棋盤ㄅㄅㄅ 
	for(j=0;j<8;j++){
		if(board[i][j]<=9)
		printf(" %d ",board[i][j]);
		else
		printf("%d ",board[i][j]);}
	printf("\n    ");}
	return 0;
}
