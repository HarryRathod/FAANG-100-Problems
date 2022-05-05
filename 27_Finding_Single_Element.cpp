#include<iostream>
#include<vector>
using namespace std;

int singleElement(vector<int> v)
{
    int ans=0;
    for(int i=0;i<v.size();i++)
        ans=ans^v[i];

    return ans;
}

int main()
{
    vector<int> v{2,2,5,1,5,7,7};

    cout<<singleElement(v)<<endl;

    return 0;
}
