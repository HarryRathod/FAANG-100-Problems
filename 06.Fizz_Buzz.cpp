#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int n;
    vector<string> v;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(i%3==0 && i%5==0)
            v.push_back("FizzBuzz");
        else if(i%3==0)
            v.push_back("Fizz");
        else if(i%5==0)
            v.push_back("Buzz");
        else
            v.push_back(to_string(i));
    }
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;
    return 0;
}
