#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*first=NULL,*last=NULL,*second=NULL;

void create(int A[],int n)
{
    struct node *t;
    first=new node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void create2(int A[],int n)
{
    struct node *t;
    second=new node;
    second->data=A[0];
    second->next=NULL;
    last=second;

    for(int i=1;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

int getIntersection(struct node *p,struct node *q)
{
    while(p)
    {
       struct node *head=q;
       while(head)
       {
           if(head==p)
            return p->data;
           head=head->next;
       }
       p=p->next;
    }
    return -1;
}

int getIntersection2(struct node *p,struct node *q)
{
    unordered_map<struct node *,bool> mymap;
    while(q)
    {
        mymap[q]=true;
        q=q->next;
    }
    while(p)
    {
        if(mymap.count(p))
            return p->data;
        p=p->next;
    }
    return -1;
}

int Length(struct node *p)
{
    int count=0;
    while(p)
    {
        count++;
        p=p->next;
    }
    return count;
}

int getIntersection3(struct node *p,struct node *q)
{
    int m=Length(p);
    int n=Length(q);

    int d=abs(n-m);
    if(m>n)
        swap(p,q);
    for(int i=0;i<d;i++)
        q=q->next;
    while(p && q)
    {
        if(p==q)
            return p->data;
        p=p->next;
        q=q->next;
    }
    return -1;
}

int getIntersection4(struct node *p,struct node *q)
{
    int ans=-1;
    stack<struct node*> st1;
    stack<struct node*> st2;

    while(p)
    {
        st1.push(p);
        p=p->next;
    }
    while(q)
    {
        st2.push(q);
        q=q->next;
    }

    while(st1.top()==st2.top())
    {
        struct node *t;
        t=st1.top();
        ans=t->data;
        st1.pop();
        st2.pop();
    }
    return ans;
}

void Rdisplay(struct node *p)
{
    if(p)
    {
        cout<<p->data<<endl;
        Rdisplay(p->next);
    }
}

int main()
{
    struct node *inter;
    int A[]={2,3,1000,5,6,7};
    int n=6;
    int B[]={11,12,13,14,15,16};

    create(A,n);
    create2(B,n);

    cout<<"First: "<<endl;
    Rdisplay(first);

    cout<<"Second: "<<endl;
    Rdisplay(second);

    struct node *p=first;
    for(int i=0;i<2;i++)
        p=p->next;
    inter=p;

    struct node *q=second;
    while(q->next)
        q=q->next;
    q->next=inter;

    cout<<"Second: "<<endl;
    Rdisplay(second);


    cout<<endl<<getIntersection(first,second)<<endl;
    cout<<endl<<getIntersection2(first,second)<<endl;
    cout<<endl<<getIntersection3(first,second)<<endl;
    cout<<endl<<getIntersection4(first,second)<<endl;

    return 0;


}
