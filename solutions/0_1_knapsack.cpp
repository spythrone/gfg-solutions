#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    
    int getsol(int W, int wt[], int val[], int n, vector<vector<int>> &v){
        if(n==0 || W==0) 
            return 0;
        if(wt[n-1]>W)
            return getsol(W, wt, val, n-1, v);
        if (v[n][W]>0)
            return v[n][W];
        int ans = max(val[n-1] + getsol(W-wt[n-1], wt, val, n-1, v), getsol(W, wt, val, n-1, v));
        v[n][W] = ans;
        return v[n][W];
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> v(n+1, vector<int>(W+1, 0));
       int ans = getsol(W, wt, val, n, v);
       return ans;
    }
};

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
