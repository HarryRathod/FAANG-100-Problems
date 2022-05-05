#include<bits/stdc++.h>
using namespace std;

int helper(vector<vector<int> > &grid,int i,int j,vector<vector<bool> > &visited,int &area)
{
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
        return 0;
    if(grid[i][j]==0)
        return 0;
    if(visited[i][j]==true)
        return 0;

    visited[i][j]=true;
    area++;
    helper(grid,i-1,j,visited,area);
    helper(grid,i+1,j,visited,area);
    helper(grid,i,j-1,visited,area);
    helper(grid,i,j+1,visited,area);

    return area;
}

int maxArea(vector<vector<int> > &grid)
{
    int sv=0;
    int m=grid.size();
    int n=grid[0].size();
    int max=0;

    vector<vector<bool> > visited(m,vector<bool>(n,false));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==1 && visited[i][j]==false)
            {
                int area=0;
                int ans=helper(grid,i,j,visited,area);
                if(ans>max)
                    max=ans;
            }
        }
    }
    return max;
}

int main()
{
    vector<vector<int> > grid{{1,1,0,0},
                              {1,1,0,1},
                              {0,0,1,1},
                              {1,1,0,0}};

    cout<<maxArea(grid)<<endl;

    return 0;
}