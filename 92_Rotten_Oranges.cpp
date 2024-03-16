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

//More efficient Method due to two reasons:
//1. No need of Visited matrix because we are changing rotten orange value from 1 to 2.
//2. Used pair<pair<int,int>,int> which is very fast compare to struct node.
int rottenOranges2(vector<vector<int>>& grid) 
{
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        int dx[4]={1,0,-1,0};
        int dy[4]={0,-1,0,1};
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2) q.push({{i,j},0});
            }
        }
        while(!q.empty()){
            pair<pair<int,int>,int> f=q.front();q.pop();
            ans=max(ans,f.second);
            for(int i=0;i<4;i++){
                int nx=f.first.first+dx[i], ny=f.first.second+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                    q.push({{nx,ny},f.second+1});
                    grid[nx][ny]=2;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) if(grid[i][j]==1) return -1;
        }
        return ans;
}

int main()
{
    vector<vector<int> > grid{{2,1,0},
                              {1,1,0},
                              {2,1,0}};

    cout<<rottenOranges(grid)<<endl;

    return 0;
}
