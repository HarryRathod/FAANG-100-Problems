#include<bits/stdc++.h>
using namespace std;

int minSteps(vector<int> X,vector<int> Y)
{
    int count=0;
    for (int i = 1; i < X.size(); i++)
    {
        count+=max(abs(X[i]-X[i-1]),abs(Y[i]-Y[i-1]));
    }
    return count;    
}

int main()
{
    vector<int> X{0,1,2};
    vector<int> Y{0,1,2};

    cout<<minSteps(X,Y)<<endl;

    return 0;
}