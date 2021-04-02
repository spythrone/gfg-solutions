#include<bits/stdc++.h>
using namespace std;


class Solution{
  public:
    bool ispar(string x)
    {
        stack<char> s;
        for(int i=0; i<x.size(); i++){
            if(s.empty() || x[i]=='{' || x[i]=='(' || x[i]=='['){
                s.push(x[i]);
            }
            else{
                if((s.top()=='{' && x[i]=='}') || (s.top()=='[' && x[i]==']') || (s.top()=='(' && x[i]==')'))
                    s.pop();
                else{
                    break;
                }
            }
        }
        return s.empty();
    }

};

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
