#include <iostream>
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

bool detectCycle(struct node *p)
{
    struct node *slow=p, *fast=p;

    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;

        if(slow==fast)
            return true;

    }
    return false;
}

int main()
{
    int A[]={2,4,6,8,9};
    int n=5;

    createLL1(A,n);
    ///RDisplay(first);

    cout<<"Cycle Status: "<<detectCycle(first)<<endl;

    return 0;
}

