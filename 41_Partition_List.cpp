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

    for (int i = 1; i < n; i++)
    {
        struct node *t = new node;
        t->data = A[i];
        t->next = NULL;
        p->next = t;
        p = t;
    }
}

struct node* partition(struct node *p,int x)
{
    struct node *second=NULL;
    struct node *third=NULL;
    struct node *l1=NULL;
    struct node *l2=NULL;
    while(p)
    {
        struct node *t=new node;
        if(p->data<x)
        {
            t->data=p->data;
            t->next=NULL;
            if(second==NULL)
                second=t;
            if(l1)
                l1->next=t;
            l1=t;
        }
        else{
            t->data=p->data;
            t->next=NULL;
            if(third==NULL)
                third=t;
            if(l2)
                l2->next=t;
            l2=t;
        }
        p=p->next;
    }
    if(third)
        l1->next=third;
    return second;
}

struct node * partition2(struct node *p,int x)
{
    struct node *LH=NULL,*LT=NULL,*MH=NULL,*MT=NULL;
    while(p)
    {
        if(p->data<x)
        {
            if(LH==NULL)
            {
                LH=LT=p;
            }
            else
            {
                LT->next=p;
                LT=p;
            }
        }
        else{
            if(MH==NULL){
                MH=MT=p;
            }
            else{
                MT->next=p;
                MT=p;
            }
        }
        p=p->next;
    }

    if(LH!=NULL && MH==NULL){
        return LH;
    }
    else if(LH==NULL && MH!=NULL){
        return MH;
    }
    else if(LH && MH){
        LT->next=NULL;
        MT->next=NULL;
        LT->next=MH;
        return LH;
    }
    else
        return NULL;
}

void RDisplay(struct node *p)
{
    if (p)
    {
        cout << p->data << "->";
        RDisplay(p->next);
    }
}

int main()
{
    int A[]={1,4,3,2,5,2};
    int n=6;
    createLL1(A,n);
    ///RDisplay(first);

    ///struct node *m=partition(first,3);       ///this method have order of space O[n]

    struct node *m=partition2(first,3);     ///this method have order of space O[1]

    RDisplay(m);

    return 0;
}
