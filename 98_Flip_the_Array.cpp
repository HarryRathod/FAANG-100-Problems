#include<bits/stdc++.h>
using namespace std;

vector<int> flipTheArray(string &s)
{
    int left=0;
    int right=0;
    vector<int> ans(2,-1);

    int currSum=0;
    int maxSum=INT_MIN;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')
            currSum+=1;
        else
            currSum-=1;

        if(maxSum<currSum)
        {
            maxSum=currSum;
            right=i+1;
            ans[0]=left+1;
            ans[1]=right;
        }
        if(currSum<0)
        {
            currSum=0;
            left=i+1;
        }
    }
    if(maxSum==-1)
    {
        ans.clear();
    }
    
    return ans;
}

int main()
{
    string s="0001";

    vector<int> ans=flipTheArray(s);

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;

    return 0;
}