#include<bits/stdc++.h>
using namespace std;

bool CheckSorted(int A[],int n)
{
    if(n==0 || n==1)
        return true;
    else{
        if(A[n-1]>A[n-2])
            CheckSorted(A,n-1);
        else
            return false;
    }
}

int main()
{
    int A[]={2,4,6,8,10};
    int n=5;
    bool ans=CheckSorted(A,n);
    if(ans==true)
        cout<<"Array is Sorted"<<endl;
    else
        cout<<"Array is not Sorted"<<endl;

        return 0;
}
