#include<bits/stdc++.h>
using namespace std;

int getsol(int n, vector<int> &v){
	if(n<0)
		return 0;
	if(n==0)
		return 1;
	if(v[n]>0)
		return v[n];
	int a = getsol(n-1, v);
	int b = getsol(n-2, v);
	v[n] = a+b;
	return v[n];
}

int main(){
	int n;
	cin>>n;
	vector<int> v(n+1, 0);
	int s = getsol(n, v);
	cout<<s<<endl;
	for(auto x:v)
		cout<<x<<" ";
	return 0;
}
