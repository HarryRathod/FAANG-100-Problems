#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:
    bool isTerminal;
    TrieNode *child[26];

    TrieNode()
    {
        isTerminal=false;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};

void add(string word,TrieNode *Trie)
{
    int n=word.size();
    for(int i=0;i<n;i++)
    {
        if(Trie->child[word[i]-'A']==NULL)
        {
            Trie->child[word[i]-'A']=new TrieNode;
        }
        Trie=Trie->child[word[i]-'A'];
    }
    Trie->isTerminal=true;
}

bool search(string word,TrieNode *Trie)
{
    int n=word.size();
    for(int i=0;i<n;i++)
    {
        if(Trie->child[word[i]-'A']==NULL)
            return false;
        Trie=Trie->child[word[i]-'A'];
    }
    return Trie->isTerminal;
}

int main()
{
    vector<string> dict;
    dict.push_back("ARE");
    dict.push_back("AS");
    dict.push_back("DO");
    dict.push_back("DOT");
    dict.push_back("NEW");
    dict.push_back("NEWS");
    dict.push_back("NO");
    dict.push_back("NOT");

    TrieNode *root=new TrieNode;
    for(int i=0;i<dict.size();i++){
        add(dict[i],root);
    }

    cout<<search("NEW",root)<<endl;
    cout<<search("NEWS",root)<<endl;
    cout<<search("NO",root)<<endl;
    cout<<search("NOT",root)<<endl;
    cout<<search("NEXT",root)<<endl;
    cout<<search("WIN",root)<<endl;
    cout<<search("MOVE",root)<<endl;

    return 0;
}