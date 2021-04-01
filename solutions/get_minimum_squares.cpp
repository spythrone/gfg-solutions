#include<bits/stdc++.h>
using namespace std;

int getsol(int n, int k, vector<int> &v){
	if(n==0) return 0;
	if(v[n]>0)
		return v[n];
	for(int i=1; i<=sqrt(n); i++){
		int a = 1+getsol(n - i*i, k, v);
		k = min(k,a);
	}
	v[n] = k;
	return k;
}

int main(){
	int n;
	cin>>n;
	int k = INT_MAX;
	vector<int> v(n+1, 0);
	int ans = getsol(n, k, v);
	cout<<"ANS "<<ans<<endl;
	for(int i=0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}
