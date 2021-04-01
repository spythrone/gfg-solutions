#include <bits/stdc++.h>
using namespace std;


class Solution{

	public:
	
	int getsol(int coins[], int M, int V, vector<int> &v){
	    if(V==0)
	        return 0;
	    if(V<0)
	        return INT_MAX;
	    if(v[V]>0)
	        return v[V];
	    int x = INT_MAX;
	    for(int i=0; i<M; i++){
	        int t = getsol(coins, M, V-coins[i], v);
	        if(t==INT_MAX)
	            x = min(x, t);
	        else
	            x = min(x, t+1);

	    }
	    v[V] = x;
	    return v[V];
	}
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<int> v(V+1,0);
	    int ans = getsol(coins, M, V, v);
	    if(ans==INT_MAX)
	        return -1;
	    return ans;
	} 
	  
};

int main() 
{  
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
