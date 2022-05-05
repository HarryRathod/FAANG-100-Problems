#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int EvalPostfix(vector<string> &v)
{
    stack<int> s;
    int a,b;

    for(int i=0;i<v.size();i++)
    {
        if(v[i]=="+" || v[i]=="-" || v[i]=="*" || v[i]=="/")
        {
            b=s.top();
            s.pop();
            a=s.top();
            s.pop();
            if(v[i]=="+")
                s.push(a+b);
            else if(v[i]=="-")
                s.push(a-b);
            else if(v[i]=="*")
                s.push(a*b);
            else if(v[i]=="/")
                s.push(a/b);
        }
        else
            s.push(atoi(v[i].c_str()));
    }
    return s.top();
}
int main()
{
    vector<string> v;
    v.push_back("15");
    v.push_back("5");
    v.push_back("/");
    v.push_back("10");
    v.push_back("+");
    v.push_back("2");
    v.push_back("-");
    v.push_back("2");
    v.push_back("*");

    ///ans is 22

    int ans=EvalPostfix(v);
    cout<<ans<<endl;
    return 0;
}
