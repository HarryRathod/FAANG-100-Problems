#include<bits/stdc++.h>
using namespace std;

int climbStair(int n)
{
    //NOTE-Due to recursive Solution Time Limit will Exceed on Leetcode.
    //To Solve this we have to use Dynamic Programming.

    if(n==0 || n==1)
    {
        return 1;
    }

    return climbStair(n-1)+climbStair(n-2);
}

int climbStair2(int n)  ///solve by using Dynamic Programming.
{
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int climbStair3(int n,int k=2)  ///This is applicable for any value of k.this is Generalised Code.
{
    int dp[n+1];
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        int ans=0;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
                ans+=dp[i-j];
        }
        dp[i]=ans;
    }
    return dp[n];
}

int main()
{
    int n=5;

    cout<<climbStair2(n)<<endl;
    cout<<climbStair3(n)<<endl;
    cout<<climbStair(n)<<endl;

    return 0;
}