
///Print As well as Also Store all the Substrings of String.

#include<bits/stdc++.h>
using namespace std;

void Print_SubStings(string input,string output,vector<string> &v)
{
    if(input.length()==0)
    {
        cout<<output<<endl;
        v.push_back(output);
        return;
    }
    Print_SubStings(input.substr(1),output,v);  ///Exclude
    Print_SubStings(input.substr(1),output+input[0],v);   ///Include
}

void Print_SubStings2(char input[],char output[],int i)
{
    if(input[0]=='\0')
    {
        output[i]='\0';
        cout<<output<<endl;
        return;
    }
    Print_SubStings2(input+1,output,i);///Exclude

    output[i]=input[0];
    Print_SubStings2(input+1,output,i+1);///Include
}

int main()
{
    string input;
    cin>>input;
    string output="";
    vector<string> v;

    Print_SubStings(input,output,v);

    cout<<"Print by Vector : "<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }

    cout<<endl<<"Print for Character Array: "<<endl;

    char in[10];
    char out[10];
    cin>>in;
    Print_SubStings2(in,out,0);

    return 0;
}
