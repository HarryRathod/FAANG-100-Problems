#include<iostream>
using namespace std;

int main()
{
    int i,j;
    int m,n;
    int sr,sc,er,ec;
    cout<<"Enter the dimension of Matrix"<<endl;
    cin>>m>>n;
    int A[m][n];

    cout<<"Enter the elements of Matrix row wise"<<endl;

    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            cin>>A[i][j];

        for(i=0;i<m;i++){
            for(j=0;j<n;j++)
                cout<<A[i][j]<<" ";
        cout<<endl;
        }

    cout<<endl<<"Matrix will be Displayed in Spiral form below: "<<endl;
    sr=sc=0;
    er=m-1;
    ec=n-1;

    while(sr<=er && sc<=ec)
    {
        for(i=sc;i<=ec;i++)
            cout<<A[sr][i]<<" ";
        sr++;

        for(i=sr;i<=er;i++)
            cout<<A[i][ec]<<" ";
        ec--;

        for(i=ec;i>=sc;i--)
            cout<<A[er][i]<<" ";
        er--;

        for(i=er;i>=sr;i--)
            cout<<A[i][sc]<<" ";
        sc++;
    }


    return 0;
}
