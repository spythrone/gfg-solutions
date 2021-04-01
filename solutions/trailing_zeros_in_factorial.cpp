#include<bits/stdc++.h>

using namespace std;

int main(){
	int num;
	cin>>num;
	int cnt = 0;
	vector<int> v(num+1, 0);
	if(num<5) return 0;
	for(int i=5; i<=num; i+=5){
		v[i] = 1 + v[i/5];
	}
	return 0;
}
