#include<iostream>
#include<vector>
using namespace std;

vector<int> findingPermutaion(string s,int n)
{
    vector<int> v;
    int l=1;
    int e=n;

    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='I'){
            v.push_back(l);
            l++;
            }
        if(s[i]=='D'){
            v.push_back(e);
            e--;
        }
    }
    v.push_back(l);

    return v;
}

int main()
{
    string s="IIDIDDDI";
    int n=9;
    vector<int> v;

    v=findingPermutaion(s,n);

    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";

    return 0;
}
