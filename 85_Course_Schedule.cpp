#include<bits/stdc++.h>
using namespace std;

bool courseSchedule(vector<vector<int> >&grid,int numCourse)
{
    int m=grid.size();
    int n=grid[0].size();

    vector<int> indegree(numCourse,0);
    unordered_map<int,vector<int> > graph;

    for(int i=0;i<m;i++)
    {
        int first=grid[i][0];
        int second=grid[i][1];

        graph[second].push_back(first);
        indegree[first]++;
    }

    queue<int> q;
    int finished=0;

    for(int i=0;i<indegree.size();i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }

    while (q.size()>0)
    {
        int cv=q.front();
        q.pop();
        finished++;

        vector<int> child=graph[cv];
        for(int i=0;i<child.size();i++)
        {
            indegree[child[i]]--;
            if(indegree[child[i]]==0)
                q.push(child[i]);
        }
    }
    cout<<finished<<endl;
    return (finished==numCourse);
}

int main()
{
    ///vector<vector<int> > grid{{2,1},{3,0},{4,2},{4,3},{5,3},{5,4}};
    vector<vector<int> > grid{{0,1},{1,0}};

    cout<<courseSchedule(grid,5)<<endl;

    return 0;
}