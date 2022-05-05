#include<iostream>
using namespace std;

int BinarySearchInRotatedArray(int A[],int n,int key)
{
    int l=0;
    int h=n-1;

    while(l<=h)
    {
        int mid=l+(h-l)/2;

        if(A[mid]==key)
            return mid;
        else if(A[mid]>=A[l])
        {
            if(key>=A[l] && key<=A[mid])
                h=mid-1;
            else
                l=mid+1;
        }
        else
        {
            if(key>=A[mid] && key<=A[h])
                l=mid+1;
            else
                h=mid-1;
        }

    }
    return -1;

}

int main()
{
    int n=6;
    int A[]={4,5,6,1,2,3};

    cout<<BinarySearchInRotatedArray(A,n,6)<<endl;

    return 0;
}
