#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	int N,M;
	vector<int> v;
	cin >> N;
	while(N--){
		cin >> M;
		v.push_back(M);
	}
	sort(v.begin(),v.end(),cmp);
	cout << v[0]+v[1]+v[2]+v[3]+v[4] << endl;
	return 0;
}
