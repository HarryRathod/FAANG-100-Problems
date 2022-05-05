#include <bits/stdc++.h>
using namespace std;
/*int main()
{
    string s;
    cout<<"Enter the String :"<<endl;
    cin>>s;
    string A="";
    stack<char> st;
    for(int i=0;s[i]!='\0';i++)
    {
        if(st.empty() || s[i]!=st.top())
        {
            st.push(s[i]);
        }
        else{
            st.pop();
        }

    }
    int i=0;
    while(!st.empty())
    {
       A+=st.top();
       st.pop();
    }
    reverse(A.begin(),A.end());
    for(i=0;i<A.size();i++)
        cout<<A[i];
    return 0;
}
*/
///2nd Logic with Order of Space O[1] while above code has O[n] and Order of Time both the Methods have same i.e. O[n]

int main()
{
    string s;
    cout<<"Enter the String: "<<endl;
    cin>>s;
    int ptr=-1;
    for(int i=0;s[i]!='\0';i++)
    {
        if(ptr==-1 || s[ptr]!=s[i]){
            ptr++;
        s[ptr]=s[i];
        }
        else{
            ptr--;
        }
    }
    for(int i=0;i<=ptr;i++)
    {
        cout<<s[i];
    }
    return 0;
}
