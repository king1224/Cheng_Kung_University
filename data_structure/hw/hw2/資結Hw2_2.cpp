#include <stdio.h> 
#include <stdlib.h>



int main()
{
	int board[8][8]={0};
	int ktmove1[8]={-2,-1,1,2,2,1,-1,-2};
	int ktmove2[8]={1,2,2,1,-1,-2,-2,-1};
	int i,j;
	
	//���ϥΪ̿�J�_�I�A���ˬd��J�O�_�b�ѽL�~ 
	printf("Please input the starting position (i,j) for 0<=i,j<=7.\n");
	scanf("%d %d",&i,&j);
	if(i>7||i<0||j>7||j<0){
	printf("wrong input.");
	return 0;	
	}
	
	int nexti[8]={0};					//�s��U�@�Ӳ����Ii�y�� 
	int nextj[8]={0};					//�s��U�@�Ӳ����Ij�y�� 
	int next_nexti[8]={0};				//�s��U�U�@�Ӳ����Ii�y��
	int next_nextj[8]={0};				//�s��U�U�@�Ӳ����Ij�y��
	int m,h,r,x,p,min;					//�@�j�﮳�ӥ�for�j�骺�ܼ� ��min 

	
	for(p=1;p<=63;p++){					//64�Ӯ�l��64�� 
		int npos=0;
		int flag=0;
		int exist[8]={0};				//�Ĥ@�����ʫ�A��A���ʪ��I�Ӽ� 
		int match[8]={0};				//�ˬd�O�_���X�k�����I
		board[i][j]=p;
		for(h=0;h<8;h++){				//�o��for��X���X�ӥi���ʪ��I 
			nexti[h]=i+ktmove1[h];
			nextj[h]=j+ktmove2[h];
			if(nexti[h]<=7&&nexti[h]>=0&&nextj[h]<=7&&nextj[h]>=0&&board[nexti[h]][nextj[h]]==0){
			npos++;
			match[h]=1;
			}}
		if(npos==0){					//�Y�S���I�i�H���ʡA�]�p���~ 
			printf("system wrong.\n");
			return 0;
		}
		else if(npos==1){				//�Y�u���@���I�i�H���ʡA�����W�a 
			for(h=0;h<8;h++)
				if(match[h]==1){
				min=h;
				i=nexti[min]; j=nextj[min];}}
		else							//���ܦh���I�i�H���ʪ��ɭԡA��ĤG���i�����I�̤֪� 
		for(m=0;m<8;m++){
		if(match[m]==1) {				//��Ĥ@�����ʪ��I�O�X�k�I�~���ĤG�� 
		for(h=0;h<8;h++){
			next_nexti[h]=nexti[m]+ktmove1[h];
			next_nextj[h]=nextj[m]+ktmove2[h];
			if(next_nexti[h]<=7 && next_nexti[h]>=0 && next_nextj[h]<=7 && next_nextj[h]>=0 && board[next_nexti[h]][next_nextj[h]]==0)
			exist[m]++;					//�аO�ĤG���i���h���I 
		}}}
		for(x=1;x<9;x++){ 				//�έp���U�ӲĤ@�������I���ĤG�����k��A��̤p�A�Y�ĤG���X�f�ۦP�A�̶��ɰw�u������ 
			if(flag==1) break;
			for(h=0;h<8;h++){
				if(flag==1)	break;
					if(board[nexti[h]][nextj[h]]==0){
						if(exist[h]==x){
							min=h;
							flag=1;
		}}}}
		i=nexti[min]; j=nextj[min];		//�T�w���ʨ�U�@���I 
	}
	printf("    ");
	for(i=0;i<8;i++){					//�̫�L�X�ѽL�t�t�t 
	for(j=0;j<8;j++){
		if(board[i][j]<=9)
		printf(" %d ",board[i][j]);
		else
		printf("%d ",board[i][j]);}
	printf("\n    ");}
	return 0;
}
