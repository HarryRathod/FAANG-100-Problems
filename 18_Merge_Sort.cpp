#include<bits/stdc++.h>
using namespace std;

void merge(int A[],int l,int mid,int h)
{
    int B[h];
    int i,j,k;
    i=k=l;
    j=mid+1;
    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    for( ;i<=mid;i++)
        B[k++]=A[i];
    for( ;j<=h;j++)
        B[k++]=A[j];

    for(i=l;i<=h;i++)
        A[i]=B[i];
}

void mergeSort(int A[],int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        mergeSort(A,l,mid);
        mergeSort(A,mid+1,h);
        merge(A,l,mid,h);
    }
}

int main()
{
    int n=6;
    int A[]={2,6,1,78,43,12};
    mergeSort(A,0,n-1);

    for(int i=0;i<n;i++)
        cout<<A[i]<<endl;

    return 0;
}
