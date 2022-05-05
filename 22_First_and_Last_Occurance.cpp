#include<iostream>
#include<vector>
using namespace std;

int getFirstIndex(vector<int> v,int pivot)
{
    int min=-1;
    int l=0;
    int h=v.size()-1;
    for(int i=0;i<v.size();i++)
    {
        int mid=l+(h-l)/2;
        if(pivot==v[mid])
        {
            min=mid;
            h=mid-1;
        }
        else if(v[mid]<pivot){
                l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return min;
}

int getLastIndex(vector<int> v,int pivot)
{
    int max;
    int l=0;
    int h=v.size()-1;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(v[mid]==pivot)
        {
            max=mid;
            l=mid+1;
        }
        else if(v[mid]>pivot)
            h=mid-1;
        else
            l=mid+1;
    }

    return max;
}

int getIndex(vector<int> v,int key,bool takeFirstIndex)
{
    ///this function can be used to get both first and last index value.
    int ans=-1;
    int l=0;
    int h=v.size()-1;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(v[mid]==key)
        {
            ans=mid;
            if(takeFirstIndex)
                h=mid-1;
            else
                l=mid+1;
        }
        else if(v[mid]<key)
            l=mid+1;
        else
            h=mid-1;
    }
    return ans;
}

int main()
{
    vector<int> v{2,3,4,5,5,6,8,10,10,10};
    int min=getIndex(v,10,true);
    int max=getIndex(v,10,false);


    /*int n=8;
    int A[]={4,3,4,5,6,7,8,4};
    int key=4;
    int min,max;


    min=max=-1;
    for(int i=0;i<n;i++)
    {
        if(A[i]==key)
        {
            if(min==-1)
                min=i;
            max=i;
        }
    }*/

    cout<<"First Occurance at Index : "<<min<<" and Last Occurence at Index : "<<max<<endl;

    return 0;
}
