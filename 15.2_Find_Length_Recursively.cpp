#include<bits/stdc++.h>
using namespace std;

int FindLength(char A[])
{
    static int count=0;
    if(A[0]!='\0')
    {
        count++;
        FindLength(A+1);
    }
    else
        return count;
}

int main()
{
    char A[]="ABCDEFGH";
    cout<<FindLength(A)<<endl;

    return 0;
}
