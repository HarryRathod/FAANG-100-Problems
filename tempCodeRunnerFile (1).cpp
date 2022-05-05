// cout<<shortestPrefix("dog",root)<<endl;
//     cout<<shortestPrefix("dove",root)<<endl;
//     cout<<shortestPrefix("duck",root)<<endl;

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s="8459761203";
    string num="5439";
    int j=0;
    int ans=0;
    int x;
    unordered_map<char,int> m;
    
    for(int i=0;i<s.size();i++)
    {
        m[s[i]]=i;
    }

    for(int i=0;i<num.size();i++)
    {
        if(m.find(num[i])==m.end())
            continue;
        else{
            x=abs(m[num[i]]-j);
            ans+=x;
            j=m[num[i]];
        }
    }

    cout<<ans<<endl;
    

    return 0;
}