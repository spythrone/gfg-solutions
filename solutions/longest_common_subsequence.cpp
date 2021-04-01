#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;


class Solution{
    public:
    
        int getsol(int x, int y, string &s1, string &s2, vector<vector<int>> &v){
            if(x==0 || y==0) return 0;
            if(v[x][y]!=-1) return v[x][y];
            if(s1[x-1]==s2[y-1]){
                
                v[x][y] = 1+getsol(x-1, y-1, s1, s2, v);
                return v[x][y];
            }
            v[x][y] = max(getsol(x, y-1, s1, s2, v), getsol(x-1, y, s1, s2, v));
            return v[x][y];
        }
    
        int lcs(int x, int y, string s1, string s2){
        vector<vector<int>> v(x+1, vector<int>(y+1, -1));
        int sol = getsol(x, y, s1, s2, v);
        return sol;
    }
};


int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          
        string s1,s2;
        cin>>s1>>s2;    
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
