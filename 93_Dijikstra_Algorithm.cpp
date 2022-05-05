#include<bits/stdc++.h>
using namespace std;

void dijikstraAlgorithm(vector<vector<int> > &grid,int s,int dist[])
{
    int m=grid.size();
    dist[s]=0;

    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    vector<bool> visited(m,false);

    q.push({0,s});

    while (!q.empty())
    {
        pair<int,int> p=q.top();
        q.pop();
        visited[p.second]=true;

        for(int i=1;i<m;i++)
        {
            if(grid[p.second][i]!=0 && dist[p.second]+grid[p.second][i]<dist[i] && visited[i]==false)
            {
                dist[i]=dist[p.second]+grid[p.second][i];
                q.push({dist[i],i});
            }
        }
    }
    
}

int main()
{
    vector<vector<int> > grid{{0,0,0,0,0},
                              {0,0,7,4,1},
                              {0,7,0,2,0},
                              {0,4,2,0,1},
                              {0,1,0,1,0}};

    int m=grid.size();
    int dist[m];
    for(int i=0;i<m;i++)
        dist[i]=INT_MAX;

    dijikstraAlgorithm(grid,1,dist);

    for(int i=1;i<m;i++)
        cout<<"1 to "<<i<<" - "<<dist[i]<<endl;
    

    return 0;
}