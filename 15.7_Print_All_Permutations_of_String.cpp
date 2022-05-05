#include<bits/stdc++.h>
using namespace std;

void StringPermu(char s[],int j=0)
{
    if(s[j]=='\0')
    {
        cout<<s<<endl;
        return;
    }
    for(int i=j;s[i]!='\0';i++)
    {
        swap(s[j],s[i]);
        StringPermu(s,j+1);
        swap(s[j],s[i]);
    }
}

int main()
{
    char s[]="ABC";
    StringPermu(s);

    return 0;
}
