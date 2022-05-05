#include<bits/stdc++.h>
using namespace std;

struct cell
{
    int x;
    int y;
    int count;
};

int shortestPath(vector<vector<int> > &grid)
{
    if(grid[0][0]==1)
        return -1;
    int n=grid.size();
    vector<vector<bool> > visited(n,vector<bool>(n,false));
    queue<cell> q;
    q.push({0,0,1});

    int dx[8]={-1,0,1,-1,1,-1,0,1};
    int dy[8]={-1,-1,-1,0,0,1,1,1};

    while (!q.empty())
    {
        cell t=q.front();
        q.pop();

        if(t.x==n-1 && t.y==n-1)
        {
            return t.count;
        }
        for(int i=0;i<8;i++)
        {
            int x=t.x+dx[i];
            int y=t.y+dy[i];

            if(x>=0 && x<n && y>=0 & y<n && grid[x][y]==0 && visited[x][y]==false)
            {
                q.push({x,y,t.count+1});
                visited[x][y]=true;
            }
        }

    }
    return -1;
}

int main()
{
    vector<vector<int> > grid{{0,0,0},
                              {1,1,0},
                              {1,1,0}};

    cout<<shortestPath(grid)<<endl;

    return 0;
}