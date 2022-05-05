#include<bits/stdc++.h>
using namespace std;

struct  cell
{
    int x;
    int y;
    int moves;
};

int knight(int m,int n,int sx,int sy,int tx,int ty)
{
    vector<vector<bool> > visited(m+1,vector<bool>(n+1,false));
    int dx[8]={-1,1,2,2,1,-1,-2,-2};
    int dy[8]={-2,-2,-1,1,2,2,1,-1};
    queue<cell> q;
    q.push({sx,sy,0});

    while (!q.empty())
    {
        cell t=q.front();
        q.pop();

        if(t.x==tx && t.y==ty)
            return t.moves;

        for(int i=0;i<8;i++)
        {
            int x=t.x+dx[i];
            int y=t.y+dy[i];
            if(x>=1 && x<=m && y>=1 && y<=n && visited[x][y]==false)
            {
                q.push({x,y,t.moves+1});
                visited[x][y]=true;
            }
        }
    }
   return -1; 
}

int main()
{
    cout<<knight(8,8,1,1,8,8)<<endl;

    return 0;
}
