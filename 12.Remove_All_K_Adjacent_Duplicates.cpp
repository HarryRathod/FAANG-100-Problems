#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    string s;
    string ans="";
    cout<<"Enter the string: "<<endl;
    cin>>s;
    cout<<"Enter the value of k: "<<endl;
    cin>>k;
    cout<<s<<endl;
    stack<pair<char,int> > st;
    for(int i=0;s[i]!='\0';i++)
    {
        if(st.empty() || s[i]!=st.top().first)
        {
            st.push(make_pair(s[i],1));
        }
        else
        {
            if(st.top().second==k-1)
                st.pop();
            else
            {
                st.top().second++;
            }
        }
    }
    while(!st.empty())
    {
        while(st.top().second--)
            ans+=st.top().first;
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}
