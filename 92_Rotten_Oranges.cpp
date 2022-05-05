#include<bits/stdc++.h>
using namespace std;

struct cell
{
    int x;
    int y;
    int count;
};

int rottenOranges(vector<vector<int> > grid)
{
    int n=grid.size();
    vector<vector<bool> > visited(n,vector<bool>(n,false));
    int dx[]={0,1,0,-1};
    int dy[]={-1,0,1,0};

    queue<cell> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==2)
            {
                q.push({i,j,0});
                visited[i][j]=true;
            }
        }
    }

    int time=0;
    while (!q.empty())  
    {
        cell t=q.front();
        q.pop();
        time=max(time,t.count);
        
        for(int i=0;i<4;i++)
        {
            int x=t.x+dx[i];
            int y=t.y+dy[i];

            if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==1 && visited[x][y]==false)
            {
                q.push({x,y,t.count+1});
                visited[x][y]=true;
                grid[x][y]=2;
            }
        }        
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==1)
            {
                return -1;
            }
        }
    }

    return time;
}

int main()
{
    vector<vector<int> > grid{{2,1,0},
                              {1,1,0},
                              {2,1,0}};

    cout<<rottenOranges(grid)<<endl;

    return 0;
}