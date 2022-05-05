#include<bits/stdc++.h>
using namespace std;

void setZeroMatrix(vector<vector<int> > &matrix)
{
    int m=matrix.size();
    if(m==0) return;

    int n=matrix[0].size();
    if(n==0) return;

    int i,j;
    bool firstRowZero=false;
    bool firstColZero=false;

    for(i=0;i<n;i++)
    {
        if(matrix[0][i]==0){
            firstRowZero=true;
            break;
        }
    }

    for(i=0;i<m;i++)
    {
        if(matrix[i][0]==0){
            firstColZero=true;
            break;
        }
    }

    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
        {
            if(matrix[i][j]==0)
            {
                matrix[0][j]=0;
                matrix[i][0]=0;
            }
        }
    }

    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
        {
            if(matrix[0][j]==0 || matrix[i][0]==0)
                matrix[i][j]=0;
        }
    }

    if(firstRowZero)
    {
     for(i=0;i<n;i++)
            matrix[0][i]=0;
    }

    if(firstColZero){
        for(i=0;i<m;i++)
            matrix[i][0]=0;
    }
}

int main()
{
    vector<vector<int> > v{{0,1,3,0,5},{6,7,8,9,10},{1,2,3,4,5}};
    setZeroMatrix(v);

    int m=v.size();
    int n=v[0].size();
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
