#include<iostream>
using namespace std;

string zigZagConversion(string s,int rowNumber)
{
    if(rowNumber<=1)
        return s;

    string *A=new string[rowNumber];
    int step=1;
    int j=0;

    for(int i=0;s[i]!='\0';i++)
    {
        A[j]=A[j]+s[i];
        if(j==0)
            step=1;
        if(j==rowNumber-1)
            step=-1;

        j=j+step;
    }
    s="";

    for(int i=0;i<rowNumber;i++)
        s=s+A[i];

    return s;
}

int main()
{
    string s="abcdefgh";
    cout<<zigZagConversion(s,3)<<endl;

    return 0;
}
