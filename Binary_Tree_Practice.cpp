#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}*root=NULL;

void createBT()
{
    int r;
    cout<<"Enter the value of root: "<<endl;
    cin>>r;
    struct node *t=new node;
    t->data=r;
    t->lchild=NULL;
    t->rchild=NULL;
    root=t;

    queue<struct node *> q;
    q.push(root);

    while(!q.empty())
    {
        struct node *p;
        p=q.front();
        q.pop();
        int l;
        printf("Enter left child of %d: ",p->data);
        cin>>l;
        if(l!=-1)
        {
            struct node *t=new node;
            t->data=l;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.push(t);
        }

        int r;
        printf("Enter right child of %d: ",p->data);
        cin>>r;
        if(r!=-1)
        {
            struct node *t=new node;
            t->data=r;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.push(t);
        }
    }
}

void inorderTraversal(struct node *p)
{
    if(p==NULL)
        return;

    inorderTraversal(p->lchild);
    cout<<p->data<<" ";
    inorderTraversal(p->rchild);

}

void preorderTraversal(struct node *p)
{
    if(p==NULL)
        return;

    cout<<p->data<<" ";
    preorderTraversal(p->lchild);
    preorderTraversal(p->rchild);

}

void postorderTraversal(struct node *p)
{
    if(p)
    {
        postorderTraversal(p->lchild);
        postorderTraversal(p->rchild);
        cout<<p->data<<" ";
    }
}

void levelorderTraversal(struct node *p)
{
    queue<struct node *> q;
    cout<<p->data<<" ";
    q.push(p);
    while (!q.empty())
    {
        struct node *c;
        c=q.front();
        q.pop();
        if(c->lchild)
        {
            cout<<c->lchild->data<<" ";
            q.push(c->lchild);
        }
        if(c->rchild)
        {
            cout<<c->rchild->data<<" ";
            q.push(c->rchild);
        }
    }

}

int count(struct node *p)
{
    int x,y;
    if(p)
    {
        x=count(p->lchild);
        y=count(p->rchild);
        return x+y+1;
    }
    return 0;
}

int main()
{
    createBT();
    cout<<endl<<"Inorder Traversal: ";
    inorderTraversal(root);
    cout<<endl<<"Preorder Traversal: ";
    preorderTraversal(root);
    cout<<endl<<"Postorder Traversal: ";
    postorderTraversal(root);
    cout<<endl<<"Levelorder Traversal: ";
    levelorderTraversal(root);

    cout<<endl<<"No. of Nodes are : "<<count(root)<<endl;

    return 0;
}

/// 5 4 6 2 3 7 8 -1 -1 -1 -1 -1 -1 -1 -1
