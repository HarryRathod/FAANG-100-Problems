#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*first=NULL,*last=NULL,*second=NULL,*third=NULL;

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

void addAtLast(int num)
{
    if(first==NULL)
    {
        first=new node;
        first->data=num;
        first->next=NULL;
        last=first;
    }
    else
    {
        struct node *t;
        t=new node;
        t->data=num;
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

int lengthOfLL(struct node *p)
{
    int count=0;
    while(p)
    {
        count++;
        p=p->next;
    }
    return count;
}

void Insert(struct node *p,int index,int x)
{
    if(index < 0 || index > lengthOfLL(p))
        return;

    struct node *q;
    q=(struct node *)malloc(sizeof(struct node));
    q->data=x;
    int i;
    if(index==0)
    {
        q->next=first;
        first=q;
    }
    else{
    for(i=0;i<index-1 && p;i++)
          {p=p->next;
          }
    if(p){
        q->next=p->next;
        p->next=q;
    }
    }
}

void insertAtSortingPos(struct node *p,int num)
{
    struct node *t=new node;
    t->data=num;
    if(first==NULL)
    {
        t->next=NULL;
        first=t;
    }
    if(first->data>num)
    {
        t->next=first;
        first=t;
    }
    else
    {
        struct node *q=NULL;
        while(p && p->data<num){
                q=p;
                p=p->next;
        }

        t->next=q->next;
        q->next=t;
    }
}

int Delete(struct node *p,int num)
{
    struct node *q;
    if(first->data==num)
    {
        q=first;
        first=first->next;
        free(q);
        return 1;
    }
    else
    {
        q=NULL;
        while(p && p->data!=num){
            q=p;
            p=p->next;
        }
        if(p){
        q->next=p->next;
        free(p);
        return 1;
        }
    }
    return -1;
}

int searchRecursive(struct node *p,int key)
{
    static int i=0;
    if(p)
    {
        if(p->data==key)
            return i;
        i++;
        searchRecursive(p->next,key);
    }
    else
        return -1;
}

void reverseLL(struct node *p)
{
    struct node *q=NULL,*r=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void reverseLL2(struct node *q,struct node *p)
{
    if(p)
    {
        reverseLL2(p,p->next);
        p->next=q;
    }
    else
        first=q;
}

void mergeLL(struct node *p,struct node *q)
{
    struct node *thirdLast;
    if(p->data<q->data)
    {
        third=thirdLast=p;
        p=p->next;
        thirdLast->next=NULL;
    }
    else
    {
        third=thirdLast=q;
        q=q->next;
        thirdLast->next=NULL;
    }
    while(p && q)
    {
        if(p->data<q->data)
        {
            thirdLast->next=p;
            thirdLast=p;
            p=p->next;
            thirdLast->next=NULL;
        }
        else
        {
            thirdLast->next=q;
            thirdLast=q;
            q=q->next;
            thirdLast->next=NULL;
        }
    }
    while(p)
    {
            thirdLast->next=p;
            thirdLast=p;
            p=p->next;
            thirdLast->next=NULL;

    }
    while(q)
    {
            thirdLast->next=q;
            thirdLast=q;
            q=q->next;
            thirdLast->next=NULL;
    }
}

void display(struct node *p)
{
    while(p)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
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
    int A[]={1};
    int n=1;
    int B[]={2,4,6,7,9};

    create(A,n);
    addAtLast(5);
    addAtLast(8);
    create2(B,n);

    ///Insert(first,2,22);
    ///insertAtSortingPos(first,9);
    ///Delete(first,4);
    ///cout<<searchRecursive(first,8)<<endl;
    ///reverseLL(first);
    ///reverseLL2(NULL,first);
   /// mergeLL(first,second);

    Rdisplay(first);

    return 0;
}
