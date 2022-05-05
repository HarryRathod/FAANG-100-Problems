#include<bits/stdc++.h>
using namespace std;

int find(int parent[],int i)
{
    while (parent[i]!=i)
    {
        i=parent[i];
    }
    return i;    
}

bool cmp(vector<int> A,vector<int> B)
{
    return A[2]<B[2];
}

int commutableIslands(vector<vector<int> > edge,int n)
{
    int cost=0;
    int makeSet[n+1];
    for(int i=1;i<=n;i++)
        makeSet[i]=i;

    sort(edge.begin(),edge.end(),cmp);

    for(int i=0;i<edge.size();i++)
    {
        int s=edge[i][0];
        int d=edge[i][1];
        int rs=find(makeSet,s);
        int rd=find(makeSet,d);

        if(rs!=rd)
        {
            cost+=edge[i][2];
            makeSet[rs]=rd;
        }
    }
    return cost;
}

int main()
{
    vector<vector<int> > edge{{1,2,1},
                              {2,3,4},
                              {1,4,3},
                              {4,3,2},
                              {1,3,10}};

    cout<<commutableIslands(edge,4)<<endl;

    return 0;
}