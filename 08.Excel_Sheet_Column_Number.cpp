#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s="AAA";
    int sum=0;
    int j=1;
    for(int i=s.size()-1;i>=0;i--)
    {
        sum+=(j)*((s[i])-64);
        j=j*26;
    }
    cout<<sum<<endl;
    return 0;
}
