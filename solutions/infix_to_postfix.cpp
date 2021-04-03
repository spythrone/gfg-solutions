// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// The main function to convert infix expression
//to postfix expression

int get_precedence(char x){
    set<char> s1 = {'^'};
    set<char> s2 = {'*', '/'};
    set<char> s3 = {'+', '-'};
    if(s1.count(x)!=0) return 2;
    else if(s2.count(x)!=0) return 3;
    else if(s3.count(x)!=0) return 4;
}

int check_precedence(char a, char b){
    int x = get_precedence(a);
    int y = get_precedence(b);
    if(y<x) return 0;
    else if(y==x) return 3;
    else return 2;
}

class Solution
{
    public:
    string infixToPostfix(string s)
    {
        string st = "";
        stack<char> p;
        for(int i=0; i<s.size(); i++){
            if(isalpha(s[i])){
                st = st + s[i];
            }
            else if(s[i]=='(') p.push(s[i]);
            else if(s[i]==')'){
                while(!p.empty() && p.top()!='('){
                    char k = p.top();
                    st = st + k;
                    p.pop();                   
                }
                if(!p.empty())
                    
                    p.pop();
            }
            else{
                if(p.empty()){
                    p.push(s[i]);
                }
                else{
                    while(!p.empty() && check_precedence(p.top(), s[i])){
                        char k = p.top();
                        if(k!='(')
                            st = st + k;
                        p.pop();
                    }
                    p.push(s[i]);
                }
            }
        }
        while(!p.empty()){
            char k = p.top();
            if(k!='(')    
                st = st + k;
            p.pop();
        }
        return st;
    }
};


// { Driver Code Starts.
//Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string exp;
        cin>>exp;
        Solution ob;
        cout<<ob.infixToPostfix(exp)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
