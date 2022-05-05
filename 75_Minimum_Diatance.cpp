#include<bits/stdc++.h>
using namespace std;

int helper(string s1,int m,string s2,int n)
{
    if(m==0)
    {
        return n;
    }
    if(n==0)
        return m;

    if(s1[m-1]==s2[n-1])
        return helper(s1,m-1,s2,n-1);

    int i=helper(s1,m,s2,n-1);
    int d=helper(s1,m-1,s2,n);
    int r=helper(s1,m-1,s2,n-1);

    return 1+min(i,min(d,r));
}

int minDiastance(string s1,string s2)
{
    //NOTE-Due to recursive Solution Time Limit will Exceed on Leetcode.
    //To Solve this we have to use Dynamic Programming.

    return helper(s1,s1.size(),s2,s2.size());
}


int minDiastance2(string s1,string s2)
{
    int m=s1.size();
    int n=s2.size();

    int dp[m+1][n+1];

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else{
                int insert=dp[i][j-1];
                int del=dp[i-1][j];
                int replace=dp[i-1][j-1];
                dp[i][j]=1+min(insert,min(del,replace));
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string s1="horse";
    string s2="ros";

    cout<<minDiastance2(s1,s2)<<endl;
    cout<<minDiastance(s1,s2)<<endl;

    return 0;
}