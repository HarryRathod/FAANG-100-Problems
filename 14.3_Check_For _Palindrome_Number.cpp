#include<bits/stdc++.h>
using namespace std;

bool IsPalindrome(int A[],int n,int l)
{
    if(l<n-1)
    {
        if(A[l]==A[n-1])
            return IsPalindrome(A,n-1,l+1);
        else
            return false;
    }
    return true;
}

int main()
{
    int A[]={1,2,3,4,4,3,2,1};
    int n=8;
    bool ans=IsPalindrome(A,n,0);
    if(ans==true)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}
