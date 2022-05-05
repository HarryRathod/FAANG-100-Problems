#include<bits/stdc++.h>
using namespace std;

int Sum(int A[],int n)
{
    if(n>0)
    {
        return (A[0]+Sum(A+1,n-1));
    }
    return 0;
}

int main()
{
    int A[]={2,4,6,8,12};
    int n=5;
    int sum=Sum(A,n);
    cout<<sum<<endl;

    return 0;
}

