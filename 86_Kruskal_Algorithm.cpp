#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &parent,int i)
{
    while(parent[i]!=i)
    {
        i=parent[i];
    }
    return i;
}

void Union(vector<int> &parent,int x,int y)
{
    int a=find(parent,x);
    int b=find(parent,y);
    parent[a]=b;
}

vector<pair<int,int> > kruskalAlgorithm(vector<vector<int> > matrix)
{
    int m=matrix.size();
    int n=matrix[0].size();
    vector<pair<int,int> > mst;
    
    vector<int> edge;
    for(int i=0;i<m;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(matrix[i][j]!=0)
                edge.push_back(matrix[i][j]);
        }
    }

    vector<int> parent(m,0);
    for(int i=0;i<m;i++)
    {
        parent[i]=i;
    }

    sort(edge.begin(),edge.end());

    for(int k=0;k<edge.size();k++)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(edge[k]==matrix[i][j])
                {
                    matrix[i][j]=0;
                    int x=find(parent,i);
                    int y=find(parent,j);
                    if(x!=y)
                    {
                        mst.push_back({i,j});
                        Union(parent,x,y);
                    }
                }
            }

        }
    }   

    return mst;
}

int main()
{
    vector<vector<int> > matrix{{0,9,5,0,11},
                                {9,0,10,12,0},
                                {5,10,0,7,6},
                                {0,12,7,0,3},
                                {11,0,6,3,0}};

    vector<pair<int,int> > mst=kruskalAlgorithm(matrix);

    for(int i=0;i<mst.size();i++)
    {
            cout<<mst[i].first<<", "<<mst[i].second<<endl;
    }

    cout<<endl;
    return 0;
}