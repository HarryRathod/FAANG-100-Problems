#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int> > &grid)
{
    int m=grid.size();
    int n=grid[0].size();
    vector<int> indegree;
    vector<int> ans;

    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<m;j++)
        {
            if(grid[j][i]==1)
                sum++;
        }
        indegree.push_back(sum);
    }

    // for(int i=0;i<indegree.size();i++)
    // {
    //     cout<<i<<"-"<<indegree[i]<<endl;
    // }

    queue<int> q;
    for(int i=0;i<indegree.size();i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    while (!q.empty())
    {
        int cv=q.front();
        q.pop();
        ans.push_back(cv);

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==1)
            {
                indegree[j]--;
                if(indegree[j]==0)
                    q.push(j);
            }
        }
    }

    }
    
    return ans;
}

int main()
{
    vector<vector<int> > grid{{0,0,0,1,0,0},
                              {0,0,1,0,0,0},
                              {0,0,0,0,1,0},
                              {0,0,0,0,1,1},
                              {0,0,0,0,0,1},
                              {0,0,0,0,0,0}};

    vector<int> indegree=topologicalSort(grid);
    for(int i=0;i<indegree.size();i++)
    {
        cout<<indegree[i]<<endl;
    }

    return 0;
}