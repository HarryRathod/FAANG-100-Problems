#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
} *first = NULL;

void createLL1(int A[], int n)
{
    struct node *t = new node;
    struct node *p;
    t->data = A[0];
    t->next = NULL;
    first = t;
    p = t;
    struct node *l=NULL;

    for (int i = 1; i < n; i++)
    {
        struct node *t = new node;
        t->data = A[i];
        t->next = NULL;
        if(i==2){
            l=t;
        }
        p->next = t;
        p = t;
    }
    p->next=l;
}

void RDisplay(struct node *p)
{
    if(p){
        cout<<p->data<<"->";
        RDisplay(p->next);
    }
}

struct node * findingStartingPoint(struct node *p)
{
    unordered_map<struct node *,bool> mymap;
    while (p)
    {
        if(mymap.count(p)){
            return p;
        }
        mymap[p]=true;
        p=p->next;
    }
    return NULL;
    
}

struct node * findingStartingPoint2(struct node *p)
{
    struct node *slow=p, *fast=p;

    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;

        if(slow==fast)
            break;

    }
    slow=p;
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}

int main()
{
     int A[]={2,4,6,8,9};
    int n=5;

    createLL1(A,n);
    ///RDisplay(first);

    struct node *ans=findingStartingPoint(first);   ///this method have order of space O[n]
    cout<<"Cycle Start from :"<<ans->data<<endl;

    struct node *ans2=findingStartingPoint2(first);      ///this method have order of space O[1] (Optimized Solution)
    cout<<"Cycle Start (By Optimized Method) from :"<<ans2->data<<endl;

    return 0;
}