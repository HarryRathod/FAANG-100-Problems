#include<bits/stdc++.h>
using namespace std;

int mooreVotingAlgorithm(int A[],int n)
{
    int major=A[0];
    int k=1;

    for(int i=1;i<n;i++)
    {
        if(A[i]==major)
            k++;
        else
        {
            if(k==1)
                major=A[i];
            else
                k--;
        }
    }
    return major;
}

int main()
{
    int n=8;
    int A[]={1,2,2,4,2,6,2,2};
    cout<<"Majority Element is : "<<mooreVotingAlgorithm(A,n)<<endl;

    return 0;
}
