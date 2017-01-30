#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int x;
	while(scanf("%d",&x)!=EOF){
		while(x!=1){
			printf("%d ",x);
			if(x%2) x=3*x+1;
			else x=x/2;
		}
		printf("1\n");
	}
	return 0;
}
