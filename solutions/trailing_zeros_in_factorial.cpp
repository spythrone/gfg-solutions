// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


class Solution
{
public:
    int trailingZeroes(int N)
    {
        int cnt=0;
        if(N<5) return 0;
        for(int i=5; i<=N; i*=5){
            cnt+=N/i;
        }
        return cnt;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans  = ob.trailingZeroes(N);
        cout<<ans<<endl;
    }
    return 0;
}