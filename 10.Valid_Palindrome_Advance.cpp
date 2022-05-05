#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cout<<"Enter the String : "<<endl;
    getline(cin,s);
    int i,j,count=0;
    for(i=0,j=s.size()-1;i<j;i++,j--)
    {
        if(s[i]==s[j])
            continue;
       else if(s[i]!=s[j] && count==0)
        {
            if(s[i+1]==s[j])
            {
                i=i+1;
                count=1;
            }
            else if(s[i]==s[j-1])
            {
                j=j-1;
                count=1;
            }
            else
                break;
        }
    }
    if(i>=j)
        cout<<"String is Palindrome "<<endl;
    else
        cout<<"String is not Palindrome "<<endl;

    return 0;

}
