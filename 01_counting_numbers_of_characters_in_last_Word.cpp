#include<iostream>
using namespace std;
int main()
{
    char A[]="Hi Harry     Rathod";
    int i,count=0;
    for(i=0;A[i]!='\0';i++)
    {
        if(A[i]==' ' && (A[i+1]!=' ' && A[i+1]!='\0'))
            count=0;
        else if(A[i]==' ')
            count;
        else
            count++;
    }
    cout<<count<<endl;

    return 0;
}
