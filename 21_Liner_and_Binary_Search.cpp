#include<iostream>
using namespace std;

int linerSearch(int A[],int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(A[i]==key)
            return i;
    }
    return -1;
}

int binarySearch(int A[],int l,int h,int key)
{
    int mid;

    while(l<h)
    {
        mid=h-(h-l)/2;
        if(A[mid]==key)
            return mid;
        else if(A[mid]>key)
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

int main()
{
    int A[6]={4,8,15,67,89,100};

    cout<<"By Linear Search : "<<linerSearch(A,6,67)<<endl;
    cout<<"By Binary Search : "<<binarySearch(A,0,5,67)<<endl;

    return 0;
}
