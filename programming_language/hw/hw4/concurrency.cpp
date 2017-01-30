#include <cstdio>
#include <vector>
#include <thread>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream> 
#include <ctime>

using namespace std;

vector< vector<int> > A,B,C;
thread t[7];
int twospow[32];

void ini(){
	twospow[0]=1;
	for(int i=1;i<32;++i){
		twospow[i]=twospow[i-1]*2;
	}
}


void matadd(int n,const vector< vector<int> > & a,const vector< vector<int> > & b,vector< vector<int> > & c){
	c.clear();
	for(int i=0;i<n;++i){
		vector<int> tmp;
		for(int j=0;j<n;++j){
			tmp.push_back(a[i][j] + b[i][j]);
		}
		c.push_back(tmp);
	}
}




void matsub(int n,const vector< vector<int> > & a,const vector< vector<int> > & b,vector< vector<int> > & c){
	c.clear();
	for(int i=0;i<n;++i){
		vector<int> tmp;
		for(int j=0;j<n;++j){
			tmp.push_back( a[i][j] - b[i][j] );
		}
		c.push_back(tmp);
	}
}



void Strassen_T(int n,const vector< vector<int> > & a,const vector< vector<int> > & b,vector< vector<int> > & c){
	if(n==2){
		for(int i=0;i<2;++i){
			vector<int> tmp;
			for(int j=0;j<2;++j){
				tmp.push_back(0);
				for(int t=0;t<2;++t){
					tmp[j] += a[i][t]*b[t][j];
				}
			}
			c.push_back(tmp);
		}
		return ;
	}

	vector< vector<int> > a11,a12,a21,a22;
	vector< vector<int> > b11,b12,b21,b22;
	vector< vector<int> > c11,c12,c21,c22;
	vector< vector<int> > m1,m2,m3,m4,m5,m6,m7;
	vector< vector<int> > aa,bb;
	
	for(int i=0;i<n/2;++i){
		vector<int> tmp[8];
		for(int j=0;j<n/2;++j){
			tmp[0].push_back( a[i][j] );
			tmp[1].push_back( a[i][j+n/2] );
			tmp[2].push_back( a[i+n/2][j] );
			tmp[3].push_back( a[i+n/2][j+n/2] );

			tmp[4].push_back( b[i][j] );
			tmp[5].push_back( b[i][j+n/2] );
			tmp[6].push_back( b[i+n/2][j] );
			tmp[7].push_back( b[i+n/2][j+n/2] );
		}
		a11.push_back( tmp[0] );
		a12.push_back( tmp[1] );
		a21.push_back( tmp[2] );
		a22.push_back( tmp[3] );
		b11.push_back( tmp[4] );
		b12.push_back( tmp[5] );
		b21.push_back( tmp[6] );
		b22.push_back( tmp[7] );
	}
	

	matadd(n/2,a11,a22,aa);
	matadd(n/2,b11,b22,bb);
	Strassen_T(n/2,aa,bb,m1);

	matadd(n/2,a21,a22,aa);
	Strassen_T(n/2,aa,b11,m2);

	matsub(n/2,b12,b22,bb);
	Strassen_T(n/2,a11,bb,m3);
	
	matsub(n/2,b21,b11,bb);
	Strassen_T(n/2,a22,bb,m4);

	matadd(n/2,a11,a12,aa);
	Strassen_T(n/2,aa,b22,m5);

	matsub(n/2,a21,a11,aa);
	matadd(n/2,b11,b12,bb);
	Strassen_T(n/2,aa,bb,m6);

	matsub(n/2,a12,a22,aa);
	matadd(n/2,b21,b22,bb);
	Strassen_T(n/2,aa,bb,m7);

	matadd(n/2,m1,m4,aa);
	matsub(n/2,m7,m5,bb);
	matadd(n/2,aa,bb,c11);

	matadd(n/2,m3,m5,c12);
	
	matadd(n/2,m2,m4,c21);

	matsub(n/2,m1,m2,aa);
	matadd(n/2,m3,m6,bb);
	matadd(n/2,aa,bb,c22);	


	for(int i=0;i<n/2;++i){
		for(int j=0;j<n/2;++j){
			c11[i].push_back(c12[i][j]);
		}
		c.push_back(c11[i]);
	}
	for(int i=0;i<n/2;++i){
		for(int j=0;j<n/2;++j){
			c21[i].push_back(c22[i][j]);
		}
		c.push_back(c21[i]);
	}
}


		
void Strassen(int n,const vector< vector<int> > * aaa,const vector< vector<int> > * bbb,vector< vector<int> > * ccc){
	vector< vector<int> > a,b,c;
	a=*aaa;
	b=*bbb;

	if(n==2){
		for(int i=0;i<2;++i){
			vector<int> tmp;
			for(int j=0;j<2;++j){
				tmp.push_back(0);
				for(int t=0;t<2;++t){
					tmp[j] += a[i][t]*b[t][j];
				}
			}
			c.push_back(tmp);
		}
		*ccc=c;
		return ;
	}

	vector< vector<int> > a11,a12,a21,a22;
	vector< vector<int> > b11,b12,b21,b22;
	vector< vector<int> > c11,c12,c21,c22;
	vector< vector<int> > m1,m2,m3,m4,m5,m6,m7;
	vector< vector<int> > aa,bb;

	vector< vector<int> > *ita11=&a11,*ita12=&a12,*ita21=&a21,*ita22=&a22;
	vector< vector<int> > *itb11=&b11,*itb12=&b12,*itb21=&b21,*itb22=&b22;
	vector< vector<int> > *itc11=&c11,*itc12=&c12,*itc21=&c21,*itc22=&c22;
	vector< vector<int> > *itm1=&m1,*itm2=&m2,*itm3=&m3,*itm4=&m4,*itm5=&m5,*itm6=&m6,*itm7=&m7;
	vector< vector<int> > *itaa=&aa,*itbb=&bb;
	
	for(int i=0;i<n/2;++i){
		vector<int> tmp[8];
		for(int j=0;j<n/2;++j){
			tmp[0].push_back( a[i][j] );
			tmp[1].push_back( a[i][j+n/2] );
			tmp[2].push_back( a[i+n/2][j] );
			tmp[3].push_back( a[i+n/2][j+n/2] );

			tmp[4].push_back( b[i][j] );
			tmp[5].push_back( b[i][j+n/2] );
			tmp[6].push_back( b[i+n/2][j] );
			tmp[7].push_back( b[i+n/2][j+n/2] );
		}
		a11.push_back( tmp[0] );
		a12.push_back( tmp[1] );
		a21.push_back( tmp[2] );
		a22.push_back( tmp[3] );
		b11.push_back( tmp[4] );
		b12.push_back( tmp[5] );
		b21.push_back( tmp[6] );
		b22.push_back( tmp[7] );
	}

	//P1
	matadd(n/2,a11,a22,aa);
	matadd(n/2,b11,b22,bb);
	Strassen_T(n/2,aa,bb,m1);
	//P2
	matadd(n/2,a21,a22,aa);
	Strassen_T(n/2,aa,b11,m2);
	//P3
	matsub(n/2,b12,b22,bb);
	Strassen_T(n/2,a11,bb,m3);
	//P4
	matsub(n/2,b21,b11,bb);
	Strassen_T(n/2,a22,bb,m4);
	//P5
	matadd(n/2,a11,a12,aa);
	Strassen_T(n/2,aa,b22,m5);
	//P6
	matsub(n/2,a21,a11,aa);
	matadd(n/2,b11,b12,bb);
	Strassen_T(n/2,aa,bb,m6);
	//P7
	matsub(n/2,a12,a22,aa);
	matadd(n/2,b21,b22,bb);
	Strassen_T(n/2,aa,bb,m7);

	matadd(n/2,m1,m4,aa);
	matsub(n/2,m7,m5,bb);
	matadd(n/2,aa,bb,c11);

	matadd(n/2,m3,m5,c12);
	
	matadd(n/2,m2,m4,c21);

	matsub(n/2,m1,m2,aa);
	matadd(n/2,m3,m6,bb);
	matadd(n/2,aa,bb,c22);

	for(int i=0;i<n/2;++i){
		for(int j=0;j<n/2;++j){
			c11[i].push_back(c12[i][j]);
		}
		c.push_back(c11[i]);
	}
	for(int i=0;i<n/2;++i){
		for(int j=0;j<n/2;++j){
			c21[i].push_back(c22[i][j]);
		}
		c.push_back(c21[i]);
	}
	
	*ccc=c;
}



int main(){
	int inp,index,MAX;
	int n1,n2,m1,m2;
	ini();
	
	ifstream iF("input.txt",ios::in);
	ofstream oF("output.txt",ios::out);
	iF >> n1 >> m1;
	n2=m1;	m2=n1;
	
	for(int i=0;i<n1;++i){
		vector<int> tmp;
		for(int j=0;j<m1;++j){
			iF >> inp;
			tmp.push_back(inp);
		}
		A.push_back(tmp);
	}
	
	for(int i=0;i<n2;++i){
		vector<int> tmp;
		for(int j=0;j<m2;++j){
			iF >> inp;
			tmp.push_back(inp);
		}
		B.push_back(tmp);
	}
	
	if(n2!=m1 || n1<1 || n2<1 || m1<1 || m2<1){
		printf("Can't multiple.\n");
		return 0;
	}
	MAX=n1;
	if(MAX<n2) MAX=n2;
	if(MAX<m1) MAX=m1;
	if(MAX<m2) MAX=m2;
	
	index = lower_bound(twospow,twospow+32,MAX) - twospow;
	int N=twospow[index];
	
	vector<int> tmp;
	for(int i=0;i<N;++i) tmp.push_back(0);
	
	for(int i=0;i<n1;++i){
		for(int j=m1;j<N;++j){
			A[i].push_back(0);
		}
	}
	for(int i=n1;i<N;++i){
		A.push_back(tmp);
	}
	
	for(int i=0;i<n2;++i){
		for(int j=m2;j<N;++j){
			B[i].push_back(0);
		}
	}
	for(int i=n2;i<N;++i){
		B.push_back(tmp);
	}
	
	time_t str=clock();
	
	if(N==1){
		oF <<A[0][0]*B[0][0] << endl;
		cout << "The time not using concurrency is " << (double)(clock()-str)/CLOCKS_PER_SEC << "s" << endl;
	}
	else{
		if(N==2){
			for(int i=0;i<2;++i){
				vector<int> tmp;
				for(int j=0;j<2;++j){
					tmp.push_back(0);
					for(int t=0;t<2;++t){
						tmp[j] += A[i][t]*B[t][j];
					}
				}
				C.push_back(tmp);
			}
		}
		else{
			vector< vector<int> > a11,a12,a21,a22;
			vector< vector<int> > b11,b12,b21,b22;
			vector< vector<int> > c11,c12,c21,c22;
			vector< vector<int> > m1,m2,m3,m4,m5,m6,m7;
			vector< vector<int> > aa1,aa2,aa3,aa4,aa5,aa6,aa7,bb1,bb2,bb3,bb4,bb5,bb6,bb7;
		
			vector< vector<int> > *ita11=&a11,*ita12=&a12,*ita21=&a21,*ita22=&a22;
			vector< vector<int> > *itb11=&b11,*itb12=&b12,*itb21=&b21,*itb22=&b22;	
			vector< vector<int> > *itc11=&c11,*itc12=&c12,*itc21=&c21,*itc22=&c22;
			vector< vector<int> > *itm1=&m1,*itm2=&m2,*itm3=&m3,*itm4=&m4,*itm5=&m5,*itm6=&m6,*itm7=&m7;
			vector< vector<int> > *itaa1=&aa1,*itaa2=&aa2,*itaa3=&aa3,*itaa4=&aa4,*itaa5=&aa5,*itaa6=&aa6,*itaa7=&aa7,*itbb1=&bb1,*itbb2=&bb2,*itbb3=&bb3,*itbb4=&bb4,*itbb5=&bb5,*itbb6=&bb6,*itbb7=&bb7;
			
			
			for(int i=0;i<N/2;++i){
				vector<int> tmp[8];
				for(int j=0;j<N/2;++j){
					tmp[0].push_back( A[i][j] );
					tmp[1].push_back( A[i][j+N/2] );
					tmp[2].push_back( A[i+N/2][j] );
					tmp[3].push_back( A[i+N/2][j+N/2] );
		
					tmp[4].push_back( B[i][j] );
					tmp[5].push_back( B[i][j+N/2] );
					tmp[6].push_back( B[i+N/2][j] );
					tmp[7].push_back( B[i+N/2][j+N/2] );
				}
				a11.push_back( tmp[0] );
				a12.push_back( tmp[1] );
				a21.push_back( tmp[2] );
				a22.push_back( tmp[3] );
				b11.push_back( tmp[4] );
				b12.push_back( tmp[5] );
				b21.push_back( tmp[6] );
				b22.push_back( tmp[7] );
			}
			
			//P1	
			matadd(N/2,a11,a22,aa1);
			matadd(N/2,b11,b22,bb1);
			thread t1(Strassen,N/2,itaa1,itbb1,itm1);
		
			//P2
			matadd(N/2,a21,a22,aa2);
			thread t2(Strassen,N/2,itaa2,itb11,itm2);
	
			//P3
			matsub(N/2,b12,b22,bb2);
			thread t3(Strassen,N/2,ita11,itbb2,itm3);
			
			//P4
			matsub(N/2,b21,b11,bb3);
			thread t4(Strassen,N/2,ita22,itbb3,itm4);
		
			//P5
			matadd(N/2,a11,a12,aa3);
			thread t5(Strassen,N/2,itaa3,itb22,itm5);
		
			//P6
			matsub(N/2,a21,a11,aa4);
			matadd(N/2,b11,b12,bb4);
			thread t6(Strassen,N/2,itaa4,itbb4,itm6);
		
			//P7
			matsub(N/2,a12,a22,aa5);
			matadd(N/2,b21,b22,bb5);
			thread t7(Strassen,N/2,itaa5,itbb5,itm7);
		
			t1.join();
			t2.join();
			t3.join();
			t4.join();
			t5.join();
			t6.join();
			t7.join();
			
			//C11=P1+P4-P5+P7
			matadd(N/2,m1,m4,aa6);
			matsub(N/2,m7,m5,bb6);
			matadd(N/2,aa6,bb6,c11);
		
			//C12=P3+P5
			matadd(N/2,m3,m5,c12);
			
			//C21=P2+P4
			matadd(N/2,m2,m4,c21);
		
			//C22=P1+P3-P2+P6
			matsub(N/2,m1,m2,aa7);
			matadd(N/2,m3,m6,bb7);
			matadd(N/2,aa7,bb7,c22);
		
		
			for(int i=0;i<N/2;++i){
				for(int j=0;j<N/2;++j){
					c11[i].push_back(c12[i][j]);
				}
				C.push_back(c11[i]);
			}
			for(int i=0;i<N/2;++i){
				for(int j=0;j<N/2;++j){
					c21[i].push_back(c22[i][j]);
				}
				C.push_back(c21[i]);
			}
		}		

		for(int i=0;i<n1;++i){
			for(int j=0;j<m2;++j){
				oF << C[i][j] << " ";
			}
			oF << endl;
		}
		cout << "The time not using concurrency is " << (double)(clock()-str)/CLOCKS_PER_SEC << "s" << endl;
	}
	
	C.clear();
	str=clock();
	
	if(N==1){
		oF <<A[0][0]*B[0][0] << endl;
		cout << "The time using concurrency is " << (double)(clock()-str)/CLOCKS_PER_SEC << "s" << endl;
		while(1){
			printf("Enter the element (i,j) want to show, 0 0 to end :\n");
			if(scanf("%d %d",&n2,&m2)!=EOF){
				if(n2==0 || m2==0) return 0;
				if(n2>n1 || m2>n1) printf("No this elements.\n");
				else
				printf("%d\n",C[n2-1][m2-1]);
			}
		}
		return 0;
	}
	else{
		Strassen_T(N,A,B,C);
		for(int i=0;i<n1;++i){
			for(int j=0;j<m2;++j){
				oF << C[i][j] << " ";
			}
			oF << endl;
		}
		cout << "The time using concurrency is " << (double)(clock()-str)/CLOCKS_PER_SEC << "s" << endl;
		while(1){
			printf("Enter the element (i,j) want to show, 0 0 to end :\n");
			if(scanf("%d %d",&n2,&m2)!=EOF){
				if(n2==0 || m2==0) return 0;
				if(n2>n1 || m2>n1) printf("No this elements.\n");
				else
				printf("%d\n",C[n2-1][m2-1]);
			}
		}
	}

	return 0;
}
