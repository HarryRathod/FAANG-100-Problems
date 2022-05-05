#include<bits/stdc++.h>
using namespace std;

int helper(vector<int> price,vector<int> wts,int W,int n)
{
    if(n==0 || W==0)
        return 0;

    if(wts[n-1]>W)
    {
        return helper(price,wts,W,n-1);
    }
    else{
        int inc=price[n-1]+helper(price,wts,W-wts[n-1],n-1);
        int exc=helper(price,wts,W,n-1);
        return max(inc,exc);
    }
}

int knapsack(vector<int> price,vector<int> wts,int W)
{
    //NOTE-Due to recursive Solution Time Limit will Exceed on Leetcode.
    //To Solve this we have to use Dynamic Programming.

    return helper(price,wts,W,wts.size());
}

int knapsack2(vector<int> price,vector<int> wts,int W) ///solve by using Dynamic Programming.
{
    int n=price.size();
    int dp[n+1][W+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(wts[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else{
                int inc=price[i-1]+dp[i-1][j-wts[i-1]];
                int exc=dp[i-1][j];
                dp[i][j]=max(inc,exc);
            }
        }
    }
    return dp[n][W];
}

int main()
{
    vector<int> price{25,10,20,60};
    vector<int> wts{4,3,5,6};
    int W=10;

    cout<<knapsack2(price,wts,W)<<endl;
    cout<<knapsack(price,wts,W)<<endl;

    return 0;
}