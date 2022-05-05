#include<bits/stdc++.h>
using namespace std;

vector<int> distinctNumber(vector<int> v,int B)
{
    vector<int> ans;
    if(v.size()<B)
        return ans;

    unordered_map<int,int> mymap;

    for(int i=0;i<B;i++)
    {
        mymap[v[i]]++;
    }
    ans.push_back(mymap.size());

    for(int i=B;i<v.size();i++)
    {
        mymap[v[i]]++;
        mymap[v[i-B]]--;
        if(mymap[v[i-B]]==0)
            mymap.erase(v[i-B]);

        ans.push_back(mymap.size());
    }

    return ans;
}

int main()
{
    vector<int> v{1,2,1,3,4,3};

    vector<int> ans=distinctNumber(v,3);

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<", ";

    cout<<endl;

    return 0;
}