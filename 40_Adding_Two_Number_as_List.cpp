#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
} *first = NULL, *second = NULL, *third=NULL;

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

void createLL2(int A[], int n)
{
    struct node *t = new node;
    struct node *p;
    t->data = A[0];
    t->next = NULL;
    second = t;
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

void RDisplay(struct node *p)
{
    if (p)
    {
        cout << p->data << "->";
        RDisplay(p->next);
    }
}

struct node * AddTwoLL(struct node *p,struct node *q){
    if(p==NULL)
        return q;

    if(q==NULL)
        return p;

    int carry=0;
    struct node *m;

    while (p && q)
    {   
        struct node *t=new node;
        int s= p->data + q->data +carry;
        t->data=s%10;
        t->next=NULL;
        if(third==NULL)
        {
            third=t;
            m=t;
        }
        else{
            m->next=t;
            m=t;
        }
        carry=s/10;
        p=p->next;
        q=q->next;
    }

    while(p){
        struct node *t=new node;
        int s= p->data + carry;
        t->data=s%10;
        t->next=NULL;
        m->next=t;
        m=t;
        carry=s/10;
        p=p->next;
    }

    while (q)
    {
        struct node *t=new node;
        int s= q->data + carry;
        t->data=s%10;
        t->next=NULL;
        m->next=t;
        m=t;
        carry=s/10;
        q=q->next;
    }

    if(carry!=0){
        struct node *t=new node;
        t->data=carry;
        t->next=NULL;
        m->next=t;
        m=t;
        carry=carry/10;
    }

    return third;
}

void reverseLL(struct node *q,struct node *p){
    if(p){
        reverseLL(p,p->next);
        p->next=q;
    }
    else{
        third=q;
    }
}

int main()
{
    int A[] = {2,4,3};
    int n = 3;

    int B[]={5,6,4};
    int m=3;

    createLL1(A,n);
    RDisplay(first);
    cout<<endl;

    createLL2(B,m);
    RDisplay(second);
    cout<<endl;

    struct node * s = AddTwoLL(first,second);
    RDisplay(s);

    // reverseLL(NULL,s);
    // RDisplay(third);


    return 0;
}