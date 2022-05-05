#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    bool isTerminal;
    node *child[26];

    node(){
        isTerminal=false;
        for(int i=0;i<26;i++)
        {
            child[i]=NULL;
        }
    }
};

void add(string s,node *trie)
{
    for(int i=0;i<s.size();i++)
    {
        if(trie->child[s[i]-'a']==NULL)
            trie->child[s[i]-'a']=new node;
        trie=trie->child[s[i]-'a'];
    }
    trie->isTerminal=true;
}

int search(string s,node *trie)
{
    for(int i=0;i<s.size();i++)
    {
        if(trie->child[s[i]-'a']==NULL)
            return 0;
        trie=trie->child[s[i]-'a'];
    }
    return (trie->isTerminal?1:0);
}


int main()
{
    string s="cool_ice_wifi";
    vector<string> v;
    v.push_back("water_is_cool");
    v.push_back("cold_ice_drink");
    v.push_back("cool_wifi_speed");

    node *root=new node;
    string s2="";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='_')
            s2+=s[i];
        else
        {
            add(s2,root);
            s2="";
        }
    }
    add(s2,root);

    vector<pair<int,int> > ans;

    int j;
    for(j=0;j<v.size();j++)
    {
        s2="";
        int x=0;
        for(int i=0;i<v[j].size();i++)
        {
            if(v[j][i]!='_'){
                s2+=v[j][i];
            }  
            else
            {
                x+=search(s2,root);
                s2="";
            }
        }
    x+=search(s2,root);
    ans.push_back({x,j});
    }

    sort(ans.rbegin(),ans.rend());
    //reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i].second<<", ";
    }
    cout<<endl;

     return 0;
}
