#include<bits/stdc++.h>
using namespace std;

int helper(string s1,int i,string s2,int j)
{
    if(i==s1.size() || j==s2.size())
    {
        return 0;
    }

    if(s1[i]==s2[j])
    {
        return 1+helper(s1,i+1,s2,j+1);
    }

    return max(helper(s1,i+1,s2,j),helper(s1,i,s2,j+1));
}

int LongestCommonSequence(string s1,string s2)
{
    //NOTE-Due to recursive Solution Time Limit will Exceed on Leetcode.
    //To Solve this we have to use Dynamic Programming.
    return helper(s1,0,s2,0);
}

int LongestCommonSequence2(string s1,string s2)
{
    int m=s1.size();
    int n=s2.size();

    int dp[m+1][n+1];

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;

            else if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];

            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[m][n];
}

int main()
{
    string s1="acbde";
    string s2="cxayb";

    cout<<LongestCommonSequence(s1,s2)<<endl;
    cout<<LongestCommonSequence2(s1,s2)<<endl;

    return 0;
}