#include<iostream>
using namespace std;

int jumpGame2(int A[],int n)
{
    if(n==1) return 0;
    if(A[0]==0) return -1;

    int ladder=A[0];
    int stair=A[0];
    int jump=1;
    for(int i=1;i<n;i++)
    {
        if(i==n-1)
            return jump;

        if(i+A[i] > ladder)
            ladder=i+A[i];

        stair--;

        if(stair==0){
            jump++;
        stair=ladder-i;
        if(stair<=0)
            return -1;
        }
    }
    return -1;
}

int main()
{
    int n=6;
    int A[]={2,3,1,2,0,4};

    cout<<jumpGame2(A,n)<<endl;

    return 0;
}
