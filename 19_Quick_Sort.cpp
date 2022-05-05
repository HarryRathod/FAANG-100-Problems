#include<bits/stdc++.h>
using namespace std;

int pivotIndexReturn(int A[],int l,int h)
{
    int pivot = A[l];
    int i=l;
    int j=h;
    do
    {
        while(A[i]<=pivot)
        i++;
        while(A[j]>pivot)
            j--;
        if(i<j)
            swap(A[i],A[j]);
    }while(i<=j);
    swap(A[j],A[l]);
    return j;
}

void quickSort(int A[],int l,int h)
{
    int j;
    if(l<h)
    {
        j=pivotIndexReturn(A,l,h);
        quickSort(A,l,j);
        quickSort(A,j+1,h);
    }
}

int main()
{
    int n=6;
    int A[]={2,78,21,45,33,1};

    quickSort(A,0,n-1);

    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";

    return 0;
}
