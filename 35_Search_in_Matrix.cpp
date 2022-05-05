#include<iostream>
#include<vector>
using namespace std;

pair<int,int> searchInMatrix(vector<vector<int> > matrix,int key)
{
    pair<int,int> p;
    p.first=-1;
    p.second=-1;
    int m=matrix.size();
    int n=matrix[0].size();

    int i=0;
    int j=n-1;

    while(i<m && j>=0)
    {
        if(matrix[i][j]==key)
        {
            p.first=i;
            p.second=j;
            return p;
        }
        if(matrix[i][j]>key)
        {
           j--;
        }
        else if(matrix[i][j]<key)
            i++;
    }

    return p;
}

int main()
{
    vector<vector<int> > v{{1,2,3,4,5},{6,7,8,9,10},{111,12,13,14,15}};

    pair<int,int> p;
    p=searchInMatrix(v,10);

    cout<<p.first<<"  "<<p.second<<endl;

    return 0;
}
