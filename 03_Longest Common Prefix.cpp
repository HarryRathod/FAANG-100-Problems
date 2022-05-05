#include<iostream>
using namespace std;
void givePrefix(string const &s1,string const &s2)
{
    int i=0,j=0;
    string prefix;
    while(s1[i]!='\0' && s2[i]!='\0' ){
        if(s1[i]==s2[i]){
            prefix[j++]=s1[i++];
        }
        else
            break;
    }
    prefix[j]='\0';
    for ( i = 0; prefix[i]!='\0'   ; i++)
    {
        cout<<prefix[i];
    }

}

int main()
{
    string s1="professor";
    string s2="proplayer";
    cout<<s1<<endl;
    givePrefix(s1,s2);


    return 1;
}
