#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int A[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        int index=0;
        for(j=0;j<n-i;j++)
        {
            if(A[j]>A[index])
                index=j;
        }
        swap(A[index],A[j-1]);
    }
}

void bubbleSort2(int A[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        int flag=0;
        for(j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                swap(A[j],A[j+1]);
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}

int main()
{
    int n=6;
    int A[]={23,12,56,4,2,8};

    sort(A,A+n);  ///this is Inbuilt Sort for which must add #include<algorithm> header file.

    for(int i=0;i<n;i++)
        cout<<A[i]<<endl;

    return 0;
}
