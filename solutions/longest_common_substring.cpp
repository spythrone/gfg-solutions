#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    int getsol(string &S1, string &S2, int n, int m, int mx, vector<vector<int>> &v){
        if(n==0 || m==0) return 0;
        if(v[n][m]!=-1) return v[n][m];
        if(S1[n-1] == S2[m-1]){
            mx = 1+getsol(S1, S2, n-1, m-1, mx, v);
            v[n][m] = mx;
            return v[n][m];
        }
        int t = getsol(S1, S2, n-1, m, INT_MIN, v);
        int l = getsol(S1, S2, n, m-1, INT_MIN, v);
        v[n][m] = max(t, max(l, mx));
        return v[n][m];
    }
    
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int mx = INT_MIN;
        vector<vector<int>> v(n+1, vector<int>(m+1, -1));
        int sol = getsol(S1, S2, n, m, mx, v);
        return sol;
    }
};


int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
