#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    int getsol(string s, string t, int n, int m, vector<vector<int>> &v){
        if(n==0)
            return m;
        if(m==0)
            return n;
        if(v[n][m] > -1)
            return v[n][m];
        if(s[n-1] == t[m-1])
            return getsol(s, t, n-1, m-1, v);
        v[n][m] = 1 + min(getsol(s, t, n, m-1, v), min(getsol(s, t, n-1, m, v), getsol(s, t, n-1, m-1, v)));
    
        return v[n][m];
    }
  
    int editDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> v(n+1, vector<int>(m+1, -1));
        int sol = getsol(s, t, n, m, v);
        return sol;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
