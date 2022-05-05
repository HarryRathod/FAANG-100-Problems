#include<bits/stdc++.h>
using namespace std;

void reverseWord(char s[])
{
    int j= strlen(s);
    char ans[j];
    int m=0;

    for(int i=strlen(s)-1;i>=0;i--)
    {
        if(s[i]==' ' || i==0)
        {

            for(int k=i==0?i:i+1;k<j;k++)
                ans[m++]=s[k];

            if(i!=0)
                ans[m++]=' ';
            j=i;
        }
    }
    ans[m]='\0';
    for(int i=0;ans[i]!='\0';i++)
        s[i]=ans[i];
}

void swapWord(string &s,int i,int e)
{
    while(i<e)
    {
        swap(s[i],s[e]);
        i++;
        e--;
    }
}

string reverseWord2(string &s)
{
    int i=0;
    int e=0;
    int n=s.size();
    while(e<n)
    {
       if (s[e]==' ')
       {
          swapWord(s,i,e-1);
          e++;
          i=e;
       }
       else
        e++;
    }
    swapWord(s,i,n-1);
    swapWord(s,0,n-1);

    string help;

    i=0;
        while(s[i]==' ')
            i++;
    while(i<s.size()){
        if(s[i]==' ')
        {
            help.push_back(s[i]);
            i++;
            while(s[i]==' ')
                i++;
        }
        else
        {
            help.push_back(s[i]);
            i++;
        }
    }
    if(s[n-1]==' ')
        help.pop_back();

    return help;
}

int main()
{
    string s="    hello world    this is harendra       ";

    cout<<reverseWord2(s)<<endl;

    return 0;
}
