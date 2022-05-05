#include<bits/stdc++.h>
using namespace std;

int Staircase(int n)
{
    if(n==0 || n==1)
        return 1;
    if(n==2)
        return 2;
    ///OR
    /*if(n<0)
        return 0;
    */
    return Staircase(n-1)+Staircase(n-2)+Staircase(n-3);  ///Remember you can take a jump of 1,2 or 3.here, max is 3.that's why considered 3 terms.
}

int main()
{
    int n;
    cin>>n;

    cout<<Staircase(n)<<endl;

    return 0;
}
