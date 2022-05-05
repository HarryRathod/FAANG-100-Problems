#include<bits/stdc++.h>
using namespace std;

/*class node
{
    public:
    bool isTerminal;
    int count;
    node *child[26];

    node(){
        isTerminal=false;
        count=0;
        for(int i=0;i<26;i++)
            child[i]=NULL;
    }
};

void add(string s,node *trie)
{
    for(int i=0;i<s.size();i++)
    {
        trie->count++;
        if(trie->child[s[i]-'a']==NULL)
        {
            trie->child[s[i]-'a']=new node;
        }
        trie=trie->child[s[i]-'a'];
    }
    trie->isTerminal=true;
}

string shortestPrefix(string s,node *trie)
{
    string ans="";
    for(int i=0;i<s.size();i++)
    {
        if(trie!=NULL){
        if(trie->count==1 || trie->isTerminal==true)
        {
            return ans;
        }
        }
        ans+=s[i];
        trie=trie->child[s[i]-'a'];
    }
}

bool search(string s,node *trie)
{
    for(int i=0;i<s.size();i++)
    {
        if(trie->child[s[i]-'a']==NULL)
            return false;
        trie=trie->child[s[i]-'a'];
    }
    return trie->isTerminal;
}

int main()
{
    node *root=new node;
    vector<string> dict{"zebra","dog","dove","duck"};

    for(int i=0;i<dict.size();i++)
        add(dict[i],root);
    
    //cout<<search("zebra",root)<<endl;
    cout<<shortestPrefix("zebra",root)<<endl;
    cout<<shortestPrefix("dog",root)<<endl;
    cout<<shortestPrefix("dove",root)<<endl;
    cout<<shortestPrefix("duck",root)<<endl;
    

    return 0;

}*/

/// Another Method

class node
{
    public:
    bool isTerminal;
    node *child[26];

    node(){
        isTerminal=true;
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
        {
            trie->child[s[i]-'a']=new node;
        }
        else
            trie->child[s[i]-'a']->isTerminal=false;
        
        trie=trie->child[s[i]-'a'];
    }
    trie->isTerminal=true;
}

bool search(string s,node *trie)
{
    for(int i=0;i<s.size();i++)
    {
        if(trie->child[s[i]-'a']==NULL)
            return false;
        
        trie=trie->child[s[i]-'a'];
    }
    return trie->isTerminal;
}

string shortestPrefix(string s,node *trie)
{
    string ans="";
    for(int i=0;i<s.size();i++)
    {
        if(trie!=NULL){
        if(trie->isTerminal==true)
        {
            return ans;
        }
        }
        ans+=s[i];
        trie=trie->child[s[i]-'a'];
    }
}

int main()
{
    node *root=new node;
    root->isTerminal=false;
    vector<string> dict{"zebra","dog","dove","duck"};

    for(int i=0;i<dict.size();i++)
        add(dict[i],root);
    
    //cout<<search("zebra",root)<<endl;
    cout<<shortestPrefix("zebra",root)<<endl;
    cout<<shortestPrefix("dog",root)<<endl;
    cout<<shortestPrefix("dove",root)<<endl;
    cout<<shortestPrefix("duck",root)<<endl;
    

    return 0;

}