#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if(n==0 || n==1)
        return n;

    return fib(n-1)+fib(n-2);
}

int fib2(int n,int *arr)
{
    if(n==0 || n==1)
        return n;

    if(arr[n]!=0)
        return arr[n];

    int output=fib2(n-1,arr)+fib2(n-2,arr);
    arr[n]=output;
    return output;    
}

int fib3(int n)
{
    if(n==0 || n==1)
        return n;

    int *arr=new int[n+1];
    arr[0]=0;
    arr[1]=1;

    for(int i=2;i<=n;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }

    int output=arr[n];
    delete []arr;
    return output;
}


int minSteps(int n)
{
    if(n<=1)
        return 0;

    int x=minSteps(n-1);
    int y=INT_MAX;
    int z=INT_MAX;

    if(n%2==0)
        y=minSteps(n/2);
    
    if(n%3==0)
        z=minSteps(n/3);

    return min(x,min(y,z))+1;
}

int minSteps2(int n)
{
    if(n<=1)
        return 0;

    int *arr=new int[n+1];
    for(int i=0;i<=n;i++)
        arr[i]=-1;

    if(arr[n]!=-1)
        return arr[n];

    int x=minSteps(n-1);
    int y=INT_MAX;
    int z=INT_MAX;

    if(n%2==0)
        y=minSteps(n/2);
    
    if(n%3==0)
        z=minSteps(n/3);

    int output=min(x,min(y,z))+1;
    arr[n]=output;
    return output;
}

int minSteps3(int n)
{
    if(n<=1)
        return 0;

    int *a=new int[n+1];
    a[0]=0;
    a[1]=0;

    for(int i=2;i<=n;i++)
    {
        int x=a[i-1];
        int y=INT_MAX;
        int z=INT_MAX;

        if(i%2==0)
            y=a[i/2];
        
        if(i%3==0)
            z=a[i/3];

        a[i]=min(x,min(y,z))+1;    
    }

    int output=a[n];
    delete []a;
    return output;
}


int minSteps4(int n)
{
    if(n<=1)
        return 0;

    int *a=new int[n+1];
    a[0]=0;
    a[1]=0;

    for(int i=2;i<=n;i++)
    {
        a[i]=a[i-1]+1;

        if(i%2==0)
            a[i]=min(a[i],a[i/2]+1);
        
        if(i%3==0)
            a[i]=min(a[i],a[i/3]+1);
    
    }

    int output=a[n];
    delete []a;
    return output;
}


int main()
{
    int n=10;
    
    cout<<fib3(n)<<endl;

    int *arr=new int[n+1];
    for(int i=0;i<=n;i++)
        arr[i]=0;

    cout<<fib2(n,arr)<<endl;

    cout<<fib(n)<<endl;

    cout<<"Min Steps Problem: "<<endl;

    cout<<minSteps(11)<<endl;
    cout<<minSteps2(11)<<endl;
    cout<<minSteps3(11)<<endl;
    cout<<minSteps4(11)<<endl;

    return 0;
}
