#include<bits/stdc++.h>
using namespace std;

class priorityQueue
{
    vector<int> pq;

    public:
    priorityQueue(){

    }

    bool isEmpty()
    {
        return pq.size()==0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if(isEmpty())
            return -1;
        return pq[0];
    }

    void insert(int ele)
    {
        pq.push_back(ele);
        int CI=pq.size()-1;
        while (CI>0)
        {
            int PI=(CI-1)/2;
            if(pq[PI]>pq[CI]){
                swap(pq[PI],pq[CI]);
                CI=PI;
            }else{
                break;
            }
        }
        
    }

    int remove()
    {
        if(isEmpty())
            return -1;
        int ans=pq[0];
        swap(pq[0], pq[pq.size()-1]);
        pq.pop_back();

        int CI=0;
        while(true)
        {                    
            int lc=2*CI+1;
            int rc=2*CI+2;
            int mini=CI;

            if(lc<pq.size() && pq[mini]>pq[lc])
            {
                mini=lc;
            }
            if(rc<pq.size() && pq[mini]>pq[rc])
            {
                mini=rc;
            }
            if(mini==CI){
                break;
            }
            swap(pq[CI],pq[mini]);
            CI=mini;
        }
        return ans;
    }
};

void inplaceHeapSort(int A[],int n)
{
    for(int i=1;i<n;i++)
    {
        int ci=i;
        while(ci>0)
        {
            int pi=(ci-1)/2;
            if(A[pi]>A[ci])
            {
                swap(A[pi],A[ci]);
                ci=pi;
            }
            else
            {
                break;
            }
        }
    }

    int size=n;
    while (size>1)
    {
        int pi=0;
        swap(A[pi],A[size-1]);
        size--;
        while (true)
        {
            int lc=2*pi+1;
            int rc=2*pi+2;
            int mini=pi;
            if(lc<size && A[mini]>A[lc])
            {
                mini=lc;
            }
            if(rc<size && A[mini]>A[rc])
            {
                mini=rc;
            }
            if(mini==pi)
            {
                break;
            }
            swap(A[mini],A[pi]);
            pi=mini;
        }
        
    }
    
}

int main()
{
    priorityQueue p;
    p.insert(18);
    p.insert(15);
    p.insert(19);
    p.insert(23);
    p.insert(1);

    cout<<p.getMin()<<endl;
    cout<<p.getSize()<<endl;
    cout<<p.isEmpty()<<endl;

    while (!p.isEmpty())
    {
        cout<<p.remove()<<", ";
    }
    cout<<endl;

    int A[]={9,4,6,2,8};
    int n=5;
    inplaceHeapSort(A,n);
    for(int i=0;i<n;i++)
        cout<<A[i]<<", ";
    cout<<endl;


    ///Inbuilt Priority Queue(Max Heap)
    priority_queue<int> q1(A,A+n);
    cout<<"Max Heap: "<<endl;
    while (!q1.empty())
    {
        cout<<q1.top()<<", ";
        q1.pop();
    }
    cout<<endl;
    
    
    
    
    ///Inbuilt Priority Queue(Min Heap)
    priority_queue<int,vector<int>,greater<int> > q2(A,A+n);
    cout<<"Min Heap: "<<endl;
    while (!q2.empty())
    {
        cout<<q2.top()<<", ";
        q2.pop();
    }
    cout<<endl;


    

    return 0;    
}