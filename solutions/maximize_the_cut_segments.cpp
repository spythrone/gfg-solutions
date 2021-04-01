#include<bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z);

int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int x,y,z;
        cin>>x>>y>>z;
        
        cout<<maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}

int getsol(int n, int x, int y, int z, vector<int> &v){
    if(n==0)
        return 0;
    if(n<0)
        return INT_MIN;
    if(v[n]!=-1){
        return v[n];
    }
        
    int j = 1 + getsol(n-x, x, y, z, v);
    int k = 1 + getsol(n-y, x, y, z, v);
    int l = 1 + getsol(n-z, x, y, z, v);
    v[n] = max(j, max(k, l));
    return v[n];
}

int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int> v(n+1, -1);
    int sol = getsol(n, x, y, z, v);
    if(sol<=0)
        return 0;
    return sol;
}
