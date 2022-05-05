#include<bits/stdc++.h>
using namespace std;

void selectionSort(int A[],int n)
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        j=i;
        for(k=i;k<n;k++)
        {
            if(A[j]>A[k])
            {
                j=k;
            }
        }
        swap(A[i],A[j]);
    }
}

int main ()
{
    int n=6;
    int A[]={71,23,87,444,3,6};
    selectionSort(A,n);
    for(int i=0;i<n;i++)
        cout<<A[i]<<endl;

    return 0;
}
