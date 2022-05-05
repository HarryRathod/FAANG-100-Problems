#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class LinkedList
{
private:
    node *first;

public:
    LinkedList()
    {
        first=NULL;
    }
    LinkedList(int A[],int n)
    {
        node *t,*last;
        t=new node;
        t->data=A[0];
        t->next=NULL;
        first=last=t;

        for(int i=1;i<n;i++)
        {
            t=new node;
            t->data=A[i];
            t->next=NULL;
            last->next=t;
            last=t;
        }
    }

    void display()
    {
        node *p=first;
        while(p)
        {
            cout<<p->data<<endl;
            p=p->next;
        }
    }

    void Reverse()
    {
        node *p=first;
        node *q=NULL,*r=NULL;
        while(p)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        first=q;
    }

    ~LinkedList()
    {
        node *p;
        while(first)
        {
            p=first;
            first=first->next;
            delete p;
        }
    }
};

int main()
{
    int A[]={2,5,7,9,10};
    int n=5;
    LinkedList L(A,n);
    L.display();

    cout<<"Iterative : "<<endl;
    L.Reverse();
    L.display();

    return 0;
}
