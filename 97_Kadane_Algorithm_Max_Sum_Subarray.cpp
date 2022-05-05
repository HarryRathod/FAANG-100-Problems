#include<bits/stdc++.h>
using namespace std;

int maxSum(vector<int> &arr)
{
    int maxSum=INT_MIN;
    int currSum=0;
    for(int i=0;i<arr.size();i++)
    {
        currSum+=arr[i];
        if(maxSum<currSum)
            maxSum=currSum;
        if(currSum<0)
            currSum=0;
    }
    return maxSum;
}

int main()
{
    vector<int> v{5,4,-1,7,8};

    cout<<maxSum(v)<<endl;

    return 0;
}