#include<bits/stdc++.h>
using namespace std;

void RemoveCharacter(char A[])
{
    if(A[0]=='\0')
        return;
    if(A[0]!='B')
        RemoveCharacter(A+1);
    else{
        for(int i=0;A[i]!='\0';i++)
            A[i]=A[i+1];
        RemoveCharacter(A);
    }
}

int main()
{
    char A[]="ABCDBB BOB The Big";
    RemoveCharacter(A);

    cout<<A<<endl;

    return 0;
}
