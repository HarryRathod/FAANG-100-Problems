#include<iostream>
using namespace std;


int main()
{
    string s;
    getline(cin,s);
    int n=s.size();
    int i,j;
    for(i=0,j=n-1;i<=n/2;i++,j--)
    {
        swap(s[i],s[j]);
    }
    cout<<s<<endl;

    return 0;
}
