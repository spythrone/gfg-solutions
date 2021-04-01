// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


class Solution{
    public:
    
    int getsol(int height[], int width[], int length[], int n, int bx, int by){
        int sol=0;
        if(n<0) return 0;
        if(){
            cout<<"------BX---"<<bx<<endl;
            cout<<"-------BY----"<<by<<endl;
            int j = height[n] + getsol(height, width, length, n, width[n], length[n]);
            cout<<"--------J----"<<j<<endl;
            int k = width[n] + getsol(height, width, length, n, height[n], length[n]);
            cout<<"--------K----"<<k<<endl;
            int l = length[n] + getsol(height, width, length, n, width[n], height[n]);
            cout<<"--------L----"<<l<<endl;
            int m = getsol(height, width, length, n-1, bx, by);
            sol = max(j, max(k, max(l, m)));
        }
        else{
            return getsol(height, width, length, n-1, bx, by);
        }
        cout<<"---------5--"<<endl;
        return sol;
    }

    int maxHeight(int height[],int width[],int length[],int n)
    {
        int bx = INT_MAX;
        int by = INT_MAX;
        int sol = getsol(height, width, length, n-1, bx, by);
        return sol;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	

 	int A[105],B[105],C[105];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
	}Solution ob;
	cout<<ob.maxHeight(A,B,C,n)<<endl;
}
 
}