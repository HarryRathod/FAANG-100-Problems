#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> v,int target)
{
    vector<int> ans;
    unordered_map<int,int> m;

    for(int i=0;i<v.size();i++)
    {
        int k=target-v[i];
        if(m.find(k)==m.end())
        {
            m[v[i]]=i;
        }
        else{
            ans.push_back(m[k]);
            ans.push_back(i);
            return ans;
        }
    }
    return ans;
}

vector<int> twoSum2(vector<int> v,int target)
{
    vector<int> ans;
    int s=0;
    int e=v.size()-1;

    while(s<=e)
    {
        if(v[s]+v[e]==target)
        {
            ans.push_back(s);
            ans.push_back(e);
            return ans;
        }
        else if(v[s]+v[e]<target)
            s++;
        else
            e--;
    }
    return ans;
}

int main()
{
    vector<int> v{2,4,5,7,9,11};
    vector<int> ans=twoSum(v,12);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ,";
    }
    cout<<endl;

    vector<int> ans2=twoSum(v,12);

    for(int i=0;i<ans2.size();i++)
    {
        cout<<ans2[i]<<" ,";
    }
    cout<<endl;

    return 0;
}