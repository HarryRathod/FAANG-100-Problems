#include<bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin>>T;
        while ((T--))
        {
            int i,j,l,r;
            cin>>l>>r;
        while(l<=r)
            {
                for(j=2;j<=l;j++)
                {
                    if(l%j==0)
                    {
                        if((l/j)%j==0)
                            break;
                    }
                }
                if(j>l)
                    break;
                l++;
            }
            cout<<l<<endl;

        }



    return 0;
}
///2 4 5 5 7 7 4 1 2 3 4
///2 6 10 8 11
