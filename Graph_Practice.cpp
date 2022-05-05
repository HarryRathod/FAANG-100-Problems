#include<bits/stdc++.h>
using namespace std;

void printDFS(vector<vector<int> > v,int sv,vector<bool> visited)
{
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<v.size();i++)
    {
        if(v[sv][i]==1 && visited[i]==false)
            printDFS(v,i,visited);
    }
}

void printBFS(vector<vector<int> >v,int sv)
{
    int n=v.size();
    vector<int> visited(n,0);
    queue<int> q;
    q.push(sv);

    while(!q.empty())
    {
        int cv=q.front();
        q.pop();
        cout<<cv<<endl;
        visited[cv]=1;
        for(int i=0;i<n;i++)
        {
            if(v[cv][i]==1 && visited[i]==0)
            {
                q.push(i);
            }
        }
    }
}

int main()
{
    int n,e;
    cout<<"Enter the number of Vertices and Edges: "<<endl;
    cin>>n>>e;

    vector<vector<int> > matrix(n,vector<int>(n,0));

    for(int i=0;i<e;i++)
    {
        int fv,sv;
        cout<<"Enter the start & end point of Edge: "<<endl;
        cin>>fv>>sv;
        matrix[fv][sv]=1;
        matrix[sv][fv]=1;
    }

    vector<bool> visited(n,false);

    cout<<"Print by DFS: "<<endl;
    printDFS(matrix,6,visited);

    cout<<"Print by BFS: "<<endl;
    printBFS(matrix,6);

    return 0;
}

/// 7 6 1 0 0 2 2 3 3 5 5 6 3 4
