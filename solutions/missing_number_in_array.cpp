#include<bits/stdc++.h>

using namespace std;

int getsol(int num, vector<int> n){
	int sum =0;
	int sum_num = num*(num+1)/2;
	for(int i=0; i<n.size(); i++){
		sum+=n[i];
	}
	return sum_num - sum;
}


int main(){
	int num;
	vector<int> n;
	cout<<"Enter the number: ";
	cin>>num;
	cout<<"Enter the array elements: "<<endl;
	for(int i=0; i<num-1; i++){
		int temp;
		cin>>temp;
		n.push_back(temp);
	}
	cout<<"ANswer is: "<<getsol(num, n);
	return 0;
}
