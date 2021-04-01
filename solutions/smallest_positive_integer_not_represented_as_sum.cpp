#include<stdio.h>

using namespace std;

int main(){

	int n;
	cin>>n;
	vector<int> v;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	int res=1;
	for(int i=0; i<v.size(); i++){
		if(v[i]<=res)
			res=res+v[i];
	}
	return res;
}
