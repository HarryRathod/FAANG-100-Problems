#include<bits/stdc++.h>
using namespace std;

void rotateMatrixCC90(vector<vector<int> > &matrix)
{
    int m=matrix.size();
    int n=matrix[0].size();

    for(int i=0;i<m;i++)
    {
        for(int j=i;j<n;j++)
            swap(matrix[i][j],matrix[j][i]);
    }

    int  s,e;

    for(int i=0;i<m;i++)
    {
        s=0;
        e=n-1;
        while(s<e)
        {
            swap(matrix[i][s],matrix[i][e]);
            s++;
            e--;
        }
    }
}


int main()
{
    vector<vector<int> > v{{1,2,3},{4,5,6},{7,8,9}};
    int m=v.size();
    int n=v[0].size();

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }

    cout<<"After Rotation: "<<endl;
    rotateMatrixCC90(v);

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }

    /*int m=3,n=3;
    int A[3][3]={{1,2,3},
                {4,5,6},
                {7,8,9}};


    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }



    for(int i=0;i<m;i++)
    {
        for(int j=i;j<n;j++)
            swap(A[i][j],A[j][i]);
    }

    for(int i=0;i<m;i++)
    {
        int l=0;
        int e=n-1;
        while(l<e){
            swap(A[i][l],A[i][e]);
            l++;
            e--;
        }
    }



    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }*/

    return 0;
}
