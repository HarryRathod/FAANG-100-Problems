#include<bits/stdc++.h>
using namespace std;

vector<int> primAlgorithm(vector<vector<int> > graph,int s)
{
    int m=graph.size();
    vector<int> vertices(m,0);
    vector<int> parent(m,-1);
    vector<int> wts(m,INT_MAX);
    vector<bool> visited(m,false);

    wts[s]=0;

    for(int i=0;i<m;i++)
    {
        vertices[i]=i;
    }

    priority_queue<int,vector<int>,greater<int> > q;
    for(int i=0;i<m;i++)
    {
        q.push(vertices[i]);
    }

    while (!q.empty())
    {
        int cv=q.top();
        q.pop();
        visited[cv]=true;

        for(int i=0;i<m;i++)
        {
            if(visited[i]==false && graph[cv][i]!=0)
            {
                if(graph[cv][i]<wts[i])
                {
                    wts[i]=graph[cv][i];
                    parent[i]=cv;
                }
            }
        }
    }

    return wts;
}

int main()
{
    vector<vector<int> > matrix{{0,4,8,0,11},
                                {4,0,2,6,0},
                                {8,2,0,3,9},
                                {0,6,3,0,5},
                                {0,0,9,5,0}};

    vector<int> wts=primAlgorithm(matrix,0);

    int sum=0;
    for(int i=0;i<wts.size();i++)
        sum+=wts[i];
    cout<<sum<<endl;

    return 0;
}