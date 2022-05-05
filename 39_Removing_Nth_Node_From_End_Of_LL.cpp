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
    void removingNthNOde(int n)
    {
        node *p=first,*q=first,*r=NULL;
        for(int i=0;i<n;i++){
            q=q->next;
        }
        if(q==NULL){
            first=first->next;
            delete p;
        }
        else{
        while(q)
        {
            r=p;
            p=p->next;
            q=q->next;
        }
        r->next=p->next;
        delete p;
        }
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

    L.removingNthNOde(3);

    cout<<"After Removing Node: "<<endl;
    L.display();

    return 0;
}


