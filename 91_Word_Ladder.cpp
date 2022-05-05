#include<bits/stdc++.h>
using namespace std;

struct node
{
    string word;
    int count;
};

int wordLadder(string beginWord,string endWord,vector<string> &wordList)
{
    unordered_set<string> validWordList(wordList.begin(),wordList.end());
    unordered_set<string> visited;

    queue<node> q;
    q.push({beginWord,1});
    visited.insert(beginWord);

    while (!q.empty())
    {
        node t=q.front();
        q.pop();

        if(t.word==endWord)
        {
            return t.count;
        }
        for(int i=0;i<t.word.size();i++)
        {
            for(int j=0;j<26;j++)
            {
                string newWord=t.word;
                newWord[i]='a'+j;
                if(validWordList.find(newWord)!=validWordList.end() && visited.find(newWord)==visited.end())
                {
                    q.push({newWord,t.count+1});
                    visited.insert(newWord);
                }
            }
        }
    }
    return 0;
}

int main()
{
    vector<string> s{"hot","dot","dog","lot","log","cog"};

    cout<<wordLadder("hit","cog",s)<<endl;

    return 0;
}