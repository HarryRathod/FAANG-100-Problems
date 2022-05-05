#include<iostream>
using namespace std;

int minimumElement(int A[],int n)
{
    int l=0;
    int h=n-1;
    int ans=-1;

    if(A[l]<A[h])
        return l;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(l==h)
            return mid;
        if(A[mid]>=A[0]){
            if(A[mid+1]<A[mid])
                return mid+1;
            l=mid+1;
        }
        else{
         if(A[mid]<A[mid-1])
                return mid;
          h=mid-1;
        }
    }
    return ans;
}

int minimumElement2(int A[],int n)
{
    int l=0;
    int h=n-1;

    while(l<=h)
    {
        int mid=l+(h-l)/2;
        int next=(mid+1)%n;
        int prev=(mid-1)%n;

        if(A[mid]<=A[prev] && A[mid]<=A[next])
            return A[mid];
        else if(A[mid]<=A[h])
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;

}

int main()
{
    int n=6;
    int A[]={11,12,4,7,8,10};

    cout<<minimumElement2(A,n)<<endl;

    ///NOTE - if in question it's ask to find no. of Rotations then just find the index of Minimum Number in Rotated Array.

    return 0;
}
