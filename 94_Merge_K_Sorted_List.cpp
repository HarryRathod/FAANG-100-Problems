#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

node *Insert(node *&head,int data)
{
    if(head==NULL)
    {
        head=new node(data);
    }
    else{
        node *temp=new node(data);
        temp->next=head;
        head=temp;
    }
    return head;
}

void displayLL(node *head)
{
    while(head)
    {
        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<endl;
}

struct mycmp
{
    bool operator()(node *a,node *b)
    {
        return a->data>b->data;
    }
};

node * mergeKSortedList(vector<node*> &lists)
{
    priority_queue<node *,vector<node *>,mycmp> q;

    for(int i=0;i<lists.size();i++)
    {
        if(lists[i]!=NULL)
            q.push(lists[i]);
    }

    node *head=NULL;
    node *tail=NULL;

    while(!q.empty())
    {
        node *temp=q.top();
        q.pop();

        if(head==NULL)
            head=tail=temp;
        else{
            tail->next=temp;
            tail=temp;
        }
        if(temp->next!=NULL)
            q.push(temp->next);
    }
    return head;
}

int main()
{
    node *head=NULL;

    Insert(head,11);
    Insert(head,6);
    Insert(head,5);
    Insert(head,2);    

    displayLL(head);

    node *head2=NULL;
    Insert(head2,9);
    Insert(head2,7);
    Insert(head2,1);

    displayLL(head2);

    node *head3=NULL;
    Insert(head3,12);
    Insert(head3,10);
    Insert(head3,1);

    displayLL(head3);

    vector<node *> lists={head,head2,head3};

    node *ans=mergeKSortedList(lists);

    displayLL(ans);

    return 0;
}