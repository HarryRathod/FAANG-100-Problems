#include<bits/stdc++.h>
using namespace std;

void Print(char A[])
{

    if(A[0]=='\0')
        return;
    else
    {
        cout<<A[0]<<endl;
        Print(A+1);
        cout<<A[0]<<endl;
    }
}

int main()
{
    char A[]="ABC";
    Print(A);

    return 0;
}
