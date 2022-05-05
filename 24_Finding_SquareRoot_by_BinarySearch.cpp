#include<iostream>
using namespace std;

int squareRootFinder(int num)
{
    if (num==0)
        return 0;
    int l=1;
    int h=num;
    int ans=-1;

    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(mid*mid==num)
            return mid;
        else if(mid*mid<num)
        {
            ans=mid;
            l=mid+1;
        }
        else
            h=mid-1;
    }
    return ans;
}

int main()
{
    cout<<squareRootFinder(200)<<endl;

    return 0;
}
