#include<iostream>
#include<stack>
using namespace std;

bool validParenthesis(string s)
{
    stack<char> st;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            st.push(s[i]);
        else{
            if(st.empty())
                return false;
            else if(s[i]==')'){
            if(st.top()=='(')
                st.pop();
            else
                return false;
            }
            else if(s[i]=='}'){
            if(st.top()=='{')
                st.pop();
            else
                return false;
            }
            else if(s[i]==']'){
            if(st.top()=='[')
                st.pop();
            else
                return false;
            }
            
    }
    }
    if(!st.empty())
        return false;
    return true;
}

int main()
{
    string s="(s(r)){}[]";
    cout<<"Parenthesis Validation Status: "<<validParenthesis(s)<<endl;

    return 0;
}