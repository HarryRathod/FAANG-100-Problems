#include<bits/stdc++.h>
using namespace std;

void helper(vector<vector<int> > &grid,int i,int j,vector<vector<bool> >&visited)
{
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() )
        return;
    if(visited[i][j]==true)
        return;
    if(grid[i][j]==0)
        return;

    visited[i][j]=true;
    helper(grid,i-1,j,visited);
    helper(grid,i+1,j,visited);
    helper(grid,i,j-1,visited);
    helper(grid,i,j+1,visited);
}

int numberOfIsalands(vector<vector<int> > &grid)
{
    int sv=0;
    int m=grid.size();
    int n=grid[0].size();
    int count=0;

    vector<vector<bool> > visited(m,vector<bool>(n,false));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==1 && visited[i][j]==false)
            {
                helper(grid,i,j,visited);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<int> > grid{{1,1,0,0},
                              {1,0,0,1},
                              {0,0,1,1},
                              {1,1,0,0}};


    cout<<numberOfIsalands(grid)<<endl;
    return 0;
}