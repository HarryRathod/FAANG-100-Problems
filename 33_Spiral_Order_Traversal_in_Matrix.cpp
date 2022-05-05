#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralTraversal(vector<vector<int> > matrix)
{
    vector<int> v;
    int sr=0,sc=0;
    int m=matrix.size();
    int n=matrix[0].size();
    int i,count=0;
    int er=m-1,ec=n-1;

    while(sr<=er && sc<=ec)
    {
        for(i=sc;i<=ec;i++){
            v.push_back(matrix[sr][i]);
            count++;
        }
        sr++;
        if(count==m*n) return v;

        for(i=sr;i<=er;i++){
            v.push_back(matrix[i][ec]);
            count++;
        }
        ec--;
        if(count==m*n) return v;

        for(i=ec;i>=sc;i--){
            v.push_back(matrix[er][i]);
            count++;
        }
        er--;
        if(count==m*n) return v;

        for(i=er;i>=sr;i--){
            v.push_back(matrix[i][sc]);
            count++;
        }
        sc++;
        if(count==m*n) return v;
    }
    return v;
}

int main()
{
    vector<vector<int> >matrix{{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};

    vector<int> v;
    v=spiralTraversal(matrix);

    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";

    return 0;
}
