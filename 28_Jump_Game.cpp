#include<iostream>
#include<vector>
using namespace std;

bool jumpGame(vector<int> v)
{
    int goodIndex=v.size()-1;
    for(int i=v.size()-2;i>=0;i--)
    {
        if(i + v[i] >= goodIndex)
            goodIndex=i;
    }
    if(goodIndex==0) return true;
    else return false;
}

int main()
{
    vector<int> v{2,1,3,0,2,4};

    cout<<jumpGame(v)<<endl;

    return 0;
}

