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

    int findingMiddleNode()
    {
        int ans;
        node *p,*q;
        p=q=first;
        while(q->next)
        {
            p=p->next;
            ans=p->data;
            q=q->next;
            q=q->next?q->next:q;
        }
        return ans;
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
    int A[]={2,5,7,9,10,12,13,14};
    int n=8;
    LinkedList L(A,n);
    L.display();

    cout<<"Middle Node data is : "<<L.findingMiddleNode()<<endl;

    return 0;
}

