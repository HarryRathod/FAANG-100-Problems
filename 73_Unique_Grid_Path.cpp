#include<bits/stdc++.h>
using namespace std;

int grid(int m,int n)  //Recursive Solution - O[2^N].
{
    if(m<0 || n<0) return 0;
    if(m==0 && n==0) return 1;

    return grid(m-1,n)+grid(m,n-1);
}

int uniqueGrid(int m,int n)
{
    int a[m][n];

    for(int i=0;i<n;i++)
        a[0][i]=1;
    
    for(int i=0;i<m;i++)
        a[i][0]=1;

    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            a[i][j]=a[i-1][j]+a[i][j-1];
        }
    }
    return a[m-1][n-1];
}

int uniqueGrid2(int m,int n)
{
    long long ans=1;
    for(int i=n;i<=n+m-2;i++)
    {
        ans=ans*i;
        ans=ans/(i-n+1);
    }
    return (int)ans;
}

int main()
{
    int m=3;
    int n=3;
    
    cout<<grid(m-1,n-1)<<endl; //working on 0 based indexing. that's why subtracted 1 from both.
    cout<<uniqueGrid(m,n)<<endl;
    cout<<uniqueGrid2(m,n)<<endl;

    return 0;
}
