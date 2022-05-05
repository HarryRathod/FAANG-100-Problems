#include<bits/stdc++.h>
using namespace std;

int ConertStoI(string s,int n)
{
    if(n==0)
        return 0;
    int smallAnswer=ConertStoI(s,n-1);
    int lastDigit=s[n-1]-'0';
    int ans=smallAnswer*10+lastDigit;
    return ans;
}

int main()
{
    string s="123";

    cout<<ConertStoI(s,3)<<endl;

    return 0;
}
