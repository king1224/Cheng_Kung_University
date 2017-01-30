#include <cstdio>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include "Sudoku.h"

using namespace std;



Sudoku::Sudoku(){
	for(int i=0;i<sudokuSize;++i){
		map[i]=0;
	}
}



Sudoku::Sudoku(const int init_map[]){
	for(int i=0;i<sudokuSize;++i)
		map[i]=init_map[i];
}



void Sudoku::setMap(const int set_map[]){
	for(int i=0;i<sudokuSize;++i)
		map[i]=set_map[i];
}



int Sudoku::getElement(int index){
	return map[index];
}



void Sudoku::outMap(){
	for(int i=0;i<sudokuSize;++i){
		printf("%d%c",map[i],(i+1)%9==0?'\n':' ');
	}
}



bool Sudoku::isCorrect(){
	for(int i=0;i<9;++i){
		if(!checkRow(i)) return false;
		if(!checkCol(i)) return false;
		if(!checkCell(i)) return false;
	}
	return true;
}



bool Sudoku::checkRow(int row){
	bool check[10];
	memset(check,false,sizeof(check));
	for(int i=0;i<9;++i){
		check[map[row*9+i]]=true;
	}
	printf("\n");
	for(int i=1;i<10;++i){
		if(!check[i]){
			return false;
		}
	}
	return true;
}



bool Sudoku::checkCol(int col){
	bool check[10];
	memset(check,false,sizeof(check));
	for(int i=0;i<9;++i){
		check[map[col+9*i]]=true;
	}
	for(int i=1;i<10;++i){
		if(!check[i]){
			return false;
		}
	}
	return true;
}



bool Sudoku::checkCell(int cell){
	bool check[10];
	memset(check,false,sizeof(check));
	int row=cell/3;
	int col=cell%3;
	
	for(int i=row*3;i<row*3+3;++i){
		for(int j=col*3;j<col*3+3;++j){
			check[map[i*9+j]]=true;
		}
	}

	for(int i=1;i<10;++i){
		if(!check[i]){
			return false;
		}
	}
	return true;
}



bool Sudoku::isUnity(){
	for(int i=0;i<9;++i){
		if(!isUnityrow(i)) return false;
		if(!isUnitycol(i)) return false;
		if(!isUnitycell(i)) return false;
	}
	return true;
}



bool Sudoku::isUnityrow(int row){
	int check[10];
	memset(check,0,sizeof(check));
	for(int i=0;i<9;++i){
		++check[question_map[row*9+i]];
	}
	for(int i=1;i<10;++i){
		if(check[i]>1){
			return false;
		}
	}
	return true;
}



bool Sudoku::isUnitycol(int col){
	int check[10];
	memset(check,0,sizeof(check));
	for(int i=0;i<9;++i){
		++check[question_map[col+9*i]];
	}
	for(int i=1;i<10;++i){
		if(check[i]>1){
			return false;
		}
	}
	return true;
}



bool Sudoku::isUnitycell(int cell){
	int check[10];
	memset(check,0,sizeof(check));
	int row=cell/3;
	int col=cell%3;

	for(int i=row*3;i<row*3+3;++i){
		for(int j=col*3;j<col*3+3;++j){
			++check[question_map[i*9+j]];
		}
	}
	for(int i=1;i<10;++i){
		if(check[i]>1){
			return false;
		}
	}
	return true;
}



void Sudoku::giveQuestion(){
	int cs;
	cs=-1;
	srand(time(NULL)+(++cs));

	switch(rand()%5){
	//全空
		case 0 :
			memset(question_map,0,sizeof(question_map));
			break;
	//隨便出的
		case 1 :
haha:
			memset(question_map,0,sizeof(question_map));
			for(int i=0;i<9;++i){
				bool v[9];
				for(int z=0;z<9;++z) v[z]=true;
				for(int j=0;j<4;++j){
					int tmp=rand()%9+1;
					if(v[tmp]){
						v[tmp]=false;
						question_map[i*9+rand()%9]=tmp;
					}
				}
			}
			if(!isUnity()) goto haha;
			break;
	//可以解的
		default :
			memset(question_map,0,sizeof(question_map));
			question_map[2]=5;
			question_map[3]=3;
			question_map[9]=8;
			question_map[16]=2;
			question_map[19]=7;
			question_map[22]=1;
			question_map[24]=5;
			question_map[27]=4;
			question_map[32]=5;
			question_map[33]=3;
			question_map[37]=1;
			question_map[40]=7;
			question_map[44]=6;
			question_map[47]=3;
			question_map[48]=2;
			question_map[52]=8;
			question_map[55]=6;
			question_map[57]=5;
			question_map[62]=9;
			question_map[65]=4;
			question_map[70]=3;
			question_map[77]=9;
			question_map[78]=7;
	}
	//最後印出
	for(int i=0;i<sudokuSize;++i){
		map[i]=question_map[i];
		printf("%d%c",question_map[i],(i+1)%9==0?'\n':' ');
	}
}



void Sudoku::readIn(){
	for(int i=0;i<sudokuSize;++i){
		scanf("%d",&map[i]);
		question_map[i]=map[i];
	}
}



void Sudoku::rotate(int angle){
	int rotate_map[sudokuSize];
	angle = angle % 4 ;

	switch(angle){
	
		//180度
	case 2 :
		for(int i=0;i<sudokuSize;++i){
			rotate_map[i]=map[sudokuSize-1-i];
		}
		break;

		//90度
	case 3 :
		for(int i=1;i<=4;++i){
			for(int j=0;j<2*i;++j){
				rotate_map[(8*i)+40-(9*j)] = map[40-(i*10)+j];
				rotate_map[40+(10*i-j)] = map[40+(i*8)-(9*j)];
				rotate_map[40-(8*i)+(9*j)] = map[40+(10*i)-j];
				rotate_map[40-(i*10)+j] = map[40-(8*i)+(9*j)];
			}
		}
		break;

		//270度
	case 1 :
		for(int i=0;i<=4;++i){
			for(int j=0;j<2*i;++j){
				rotate_map[40-(i*10)+j] = map[40+(8*i)-(9*j)];
				rotate_map[40+(8*i)-(9*j)] = map[40+(10*i)-j];
				rotate_map[40+(10*i)-j] = map[40-(8*i)+(9*j)];
				rotate_map[40-(8*i)+(9*j)] = map[40-(i*10)+j];
			}
		}
		break;
		
	default :
		return;
	}
	
	rotate_map[40]=map[40];
	for(int i=0;i<sudokuSize;++i){
		map[i]=rotate_map[i];
	}
}



void Sudoku::changeNum(int a,int b){
	if(a>=1&&a<=9&&b>=1&&b<=9){
		for(int i=0;i<sudokuSize;++i){
			if(map[i]==a){
				map[i]=b;
			}
			else if(map[i]==b){
				map[i]=a;
			}
		}
	}
	else{
		srand(time(NULL));
		int tmp=rand()%10;
		for(int i=0;i<sudokuSize;++i){
			map[i]=(map[i]+tmp)%9+1;
		}
	}
}



void Sudoku::changeRow(int a,int b){
	++a;++b;
	if(a>=1&&a<=3&&b>=1&&b<=3){
		int tmp;
		for(int i=0;i<27;++i){
			tmp=map[(a-1)*27+i];
			map[(a-1)*27+i]=map[(b-1)*27+i];
			map[(b-1)*27+i]=tmp;
		}
	}
	else{
		int tmp;
		for(int i=0;i<27;++i){
			tmp=map[i];
			map[i]=map[i+27];
			map[i+27]=map[i+54];
			map[i+54]=tmp;
		}
	}
}



void Sudoku::changeCol(int a,int b){
	++a;++b;
	if(a>=1&&a<=3&&b>=1&&b<=3){
		int tmp;
		for(int i=0;i<27;++i){
			tmp=map[(a-1)*3+(i%3)+(i/3)*9];
			map[(a-1)*3+(i%3)+(i/3)*9]=map[(b-1)*3+(i%3)+(i/3)*9];
			map[(b-1)*3+(i%3)+(i/3)*9]=tmp;
		}
	}
	else{
		int tmp;
		for(int i=0;i<27;++i){
			tmp=map[(i%3)+(i/3)*9];
			map[(i%3)+(i/3)*9]=map[3+(i%3)+(i/3)*9];
			map[3+(i%3)+(i/3)*9]=map[6+(i%3)+(i/3)*9];
			map[6+(i%3)+(i/3)*9]=tmp;
		}
	}
}



void Sudoku::flip(int a){
	int tmp;
	if(a==0){
		for(int i=0;i<4;++i){
			for(int j=0;j<9;++j){
				tmp=map[i*9+j];
				map[i*9+j]=map[(8-i)*9+j];
				map[(8-i)*9+j]=tmp;
			}
		}
	}
	else{
		for(int i=0;i<4;++i){
			for(int j=0;j<9;++j){
				tmp=map[j*9+i];
				map[j*9+i]=map[j*9+(8-i)];
				map[j*9+(8-i)]=tmp;
			}
		}
	}
}



void Sudoku::solve(){

	int Nodenum=325,Rownum=0;
	int countnum=0;
	bool iscorrect=false;
	isonly=true;


	R[0]=1; L[0]=324; D[0]=U[0]=0;
	COLNUM[0]=0;	ANS[0]=-1;
	for(int i=1;i<82;++i){
		U[i]=D[i]=COL[i]=i;
		L[i]=i-1;
		R[i]=i+1;
		COLNUM[i]=0;
		ANS[i]=-1;
	}
	for(int i=82;i<324;++i){
		U[i]=D[i]=COL[i]=i;
		L[i]=i-1;
		R[i]=i+1;
		COLNUM[i]=0;
	}
	COLNUM[324]=R[324]=0; U[324]=D[324]=324; L[324]=323;


	for(int i=0;i<sudokuSize;++i){
		ans_map[i]=map[i];
		if(map[i]==0){
			for(int j=0;j<9;++j){
				++Rownum;
				solve_map[Rownum].row=i/9;
				solve_map[Rownum].col=i%9;
				solve_map[Rownum].num=j+1;

				COL[Nodenum]=i+1;
				ROW[Nodenum]=Rownum;
				++COLNUM[i+1];
				D[Nodenum]=i+1;
				U[Nodenum]=U[i+1];
				D[U[Nodenum]]=Nodenum;
				U[D[Nodenum]]=Nodenum;
				L[Nodenum]=Nodenum+3;
				R[Nodenum]=Nodenum+1;


				COL[Nodenum+1]=(i/9)*9+j+82;
				COL[Nodenum+2]=(i%9)*9+j+163;
				COL[Nodenum+3]=( ((i/9)/3)*3 + (i%9)/3 )*9 +j+244;
				ROW[Nodenum+1]=ROW[Nodenum+2]=ROW[Nodenum+3]=Rownum;
				D[Nodenum+1]=COL[Nodenum+1];
				U[Nodenum+1]=U[COL[Nodenum+1]];
				D[Nodenum+2]=COL[Nodenum+2];
				U[Nodenum+2]=U[COL[Nodenum+2]];
				D[Nodenum+3]=COL[Nodenum+3];
				U[Nodenum+3]=U[COL[Nodenum+3]];
				D[U[Nodenum+1]]=Nodenum+1;
				U[D[Nodenum+1]]=Nodenum+1;
				D[U[Nodenum+2]]=Nodenum+2;
				U[D[Nodenum+2]]=Nodenum+2;
				D[U[Nodenum+3]]=Nodenum+3;
				U[D[Nodenum+3]]=Nodenum+3;
				L[Nodenum+1]=Nodenum;
				L[Nodenum+2]=Nodenum+1;
				L[Nodenum+3]=Nodenum+2;
				R[Nodenum+1]=Nodenum+2;
				R[Nodenum+2]=Nodenum+3;
				R[Nodenum+3]=Nodenum;

				++COLNUM[COL[Nodenum+1]];
				++COLNUM[COL[Nodenum+2]];
				++COLNUM[COL[Nodenum+3]];



				Nodenum+=4;
			}
		}
		else{
				++Rownum;
				solve_map[Rownum].row=i/9;
				solve_map[Rownum].col=i%9;
				solve_map[Rownum].num=map[i];
				
				COL[Nodenum]=i+1;
				ROW[Nodenum]=Rownum;
				++COLNUM[i+1];
				D[Nodenum]=i+1;
				U[Nodenum]=U[i+1];
				D[U[Nodenum]]=Nodenum;
				U[D[Nodenum]]=Nodenum;
				L[Nodenum]=Nodenum+3;
				R[Nodenum]=Nodenum+1;


				COL[Nodenum+1]=(i/9)*9+map[i]+81;
				COL[Nodenum+2]=(i%9)*9+map[i]+162;
				COL[Nodenum+3]=( ((i/9)/3)*3 + (i%9)/3 )*9 +map[i]+243;
				ROW[Nodenum+1]=ROW[Nodenum+2]=ROW[Nodenum+3]=Rownum;
				D[Nodenum+1]=COL[Nodenum+1];
				U[Nodenum+1]=U[COL[Nodenum+1]];
				D[Nodenum+2]=COL[Nodenum+2];
				U[Nodenum+2]=U[COL[Nodenum+2]];
				D[Nodenum+3]=COL[Nodenum+3];
				U[Nodenum+3]=U[COL[Nodenum+3]];
				D[U[Nodenum+1]]=Nodenum+1;
				U[D[Nodenum+1]]=Nodenum+1;
				D[U[Nodenum+2]]=Nodenum+2;
				U[D[Nodenum+2]]=Nodenum+2;
				D[U[Nodenum+3]]=Nodenum+3;
				U[D[Nodenum+3]]=Nodenum+3;
				L[Nodenum+1]=Nodenum;
				L[Nodenum+2]=Nodenum+1;
				L[Nodenum+3]=Nodenum+2;
				R[Nodenum+1]=Nodenum+2;
				R[Nodenum+2]=Nodenum+3;
				R[Nodenum+3]=Nodenum;

				++COLNUM[COL[Nodenum+1]];
				++COLNUM[COL[Nodenum+2]];
				++COLNUM[COL[Nodenum+3]];
			

				Nodenum+=4;

				++countnum;
		}
	}


	if(countnum<17){
		printf("%d\n",isUnity()?2:0);
		return;
	}
	else{

		iscorrect=Dlx(0);

		if(iscorrect){
			printf("2\n");
			return;
		}
		else if(isonly){
			printf("0\n");
			return;
		}
		else{
			//onlyone
			printf("1\n");
			for(int z=0;z<sudokuSize;++z){
				printf("%d%c",ans_map[z],(z+1)%9==0?'\n':' ');
			}
			return;
		}
	}
	printf("Mom,I print nothing. Crying\n\n\n");

}



bool Sudoku::Dlx(int deep){
	if(R[0]==0){
		if(isonly){
			isonly=false;
			for(int z=0;ANS[z]!=-1;++z){
				ans_map[solve_map[ANS[z]].row*9+solve_map[ANS[z]].col]=solve_map[ANS[z]].num;
			}
			return false;
		}
		return true;
	}

	int min=99999999;
	int col=0;

	for(int h=R[0];h!=0;h=R[h]){
		if(COLNUM[h]<min){
			min=COLNUM[h];
			col=h;
		}
	}
	
	for(int i=D[col];i!=col;i=D[i]){
		for(int j=R[i];j!=i;j=R[j]){
			U[D[j]]=U[j];
			D[U[j]]=D[j];
			--COLNUM[COL[j]];
		}
	}
	R[L[col]]=R[col];
	L[R[col]]=L[col];

	for(int i=D[col];i!=col;i=D[i]){

		ANS[deep]=ROW[i];

		for(int j=R[i];j!=i;j=R[j]){
			for(int k=D[COL[j]];k!=COL[j];k=D[k]){
				for(int r=R[k];r!=k;r=R[r]){
					U[D[r]]=U[r];
					D[U[r]]=D[r];
					--COLNUM[COL[r]];
				}
			}
			R[L[COL[j]]]=R[COL[j]];
			L[R[COL[j]]]=L[COL[j]];
		}
		if(Dlx(deep+1)){
			return true;
		}
		for(int j=L[i];j!=i;j=L[j]){
			for(int k=U[COL[j]];k!=COL[j];k=U[k]){
				for(int r=L[k];r!=k;r=L[r]){
					U[D[r]]=r;
					D[U[r]]=r;
					++COLNUM[COL[r]];
				}
			}
			R[L[COL[j]]]=COL[j];
			L[R[COL[j]]]=COL[j];
		}
	}
	for(int i=U[col];i!=col;i=U[i]){
		for(int j=L[i];j!=i;j=L[j]){
			U[D[j]]=j;
			D[U[j]]=j;
			++COLNUM[COL[j]];
		}
	}
	R[L[col]]=col;
	L[R[col]]=col;

	return false;
}



void Sudoku::transform(){
	outMap();
}









