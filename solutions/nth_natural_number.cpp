#include<bits/stdc++.h>
using namespace std;

int main(){
	int num;
	cin>>num;
	int count=0;
	int sum=0;
	while(num){
		sum+=pow(10,count)*(num%9);
		num/=9;
		count++;
	}
	cout<<"Conver is "<<sum<<endl;
	return 0;
}
