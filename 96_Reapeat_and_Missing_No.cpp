#include<bits/stdc++.h>
using namespace std;

vector<int> repeatAndMissingNumber(vector<int> &arr)
{
    long long sum=0;
    long long sqrsum=0;
    long long temp;
    for(int i=0;i<arr.size();i++)
    {
        temp=arr[i];
        sum+=temp;
        sum-=i+1;
        sqrsum+=(temp*temp);
        sqrsum-=(long long)(i+1)*(long long)(i+1);
    }

    long long sumAB=(sqrsum/sum);
    int A=(sum+sumAB)/2;
    int B=sumAB-A;

    vector<int> ans;
    ans.push_back(A);
    ans.push_back(B);
    
    return ans;
}

int main()
{
    vector<int> v{1,2,3,3,6,5};

    vector<int> ans=repeatAndMissingNumber(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }

    return 0;
}