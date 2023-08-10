#include<bits/stdc++.h>
using namespace std;

struct BTree
{
    struct BTree *lchild;
    int data;
    struct BTree *rchild;
}*first=NULL,*second=NULL;

void createBT()
{
    struct BTree *root=new BTree;
    queue<struct BTree *> q;
    int rootData;
    cout<<"Enter the root Data: ";
    cin>>rootData;
    root->data=rootData;
    root->lchild=root->rchild=NULL;
    first=root;

    q.push(root);

    while (!q.empty())
    {
        struct BTree *f=q.front();
        q.pop();

        cout<<"Enter the Left Child of "<<f->data<<" :";
        int ldata;
        cin>>ldata;

        if(ldata!=-1){
            struct BTree *l=new BTree;
            l->data=ldata;
            l->lchild=l->rchild=NULL;
            f->lchild=l;
            q.push(l);
        }

        cout<<"Enter the Right Child of "<<f->data<<" :";
        int rdata;
        cin>>rdata;

        if(rdata!=-1){
            struct BTree *r=new BTree;
            r->data=rdata;
            r->lchild=r->rchild=NULL;
            f->rchild=r;
            q.push(r);
        }
    }    
}

void createBT2()
{
    struct BTree *root2=new BTree;
    queue<struct BTree *> q;
    int rootData;
    cout<<"Enter the root Data: ";
    cin>>rootData;
    root2->data=rootData;
    root2->lchild=root2->rchild=NULL;
    second=root2;

    q.push(root2);

    while (!q.empty())
    {
        struct BTree *f=q.front();
        q.pop();

        cout<<"Enter the Left Child of "<<f->data<<" :";
        int ldata;
        cin>>ldata;

        if(ldata!=-1){
            struct BTree *l=new BTree;
            l->data=ldata;
            l->lchild=l->rchild=NULL;
            f->lchild=l;
            q.push(l);
        }

        cout<<"Enter the Right Child of "<<f->data<<" :";
        int rdata;
        cin>>rdata;

        if(rdata!=-1){
            struct BTree *r=new BTree;
            r->data=rdata;
            r->lchild=r->rchild=NULL;
            f->rchild=r;
            q.push(r);
        }
    }    
}

void printBTree(struct BTree *p)
{
    if(p)
    {
        printBTree(p->lchild);
        cout<<p->data<<", ";
        printBTree(p->rchild);
    }
}

void preorder(node *rt)
//     {
//         if (rt)
//         {
//             cout << rt->data << ", ";
//             preorder(rt->left);
//             preorder(rt->right);
//         }
//     }
// 
//     void iterativePreorder(node *root)
//     {
//         if(root==NULL) return;
//         
//         stack<node*> st;
//         st.push(root);
// 
//         while(!st.empty())
//         {
//             node *f=st.top();
//             st.pop();
//             cout<<f->data<<", ";
//             if(f->right) st.push(f->right);
//             if(f->left) st.push(f->left);
//         }
//         cout<<endl;
//     }
//     
//     void inorder(node *root)
//     {
//         if(root)
//         {
//             inorder(root->left);
//             cout<<root->data<<", ";
//             inorder(root->right);
//         }
//     }
// 
//     void iterativeInorder(node *root)
//     {
//         if(root==NULL) return ;
//         stack<node*> st;
// 
//         while(root || !st.empty())
//         {
//             while(root)
//             {
//                 st.push(root);
//                 root=root->left;
//             }
//             root=st.top();
//             st.pop();
//             cout<<root->data<<", ";
//             root=root->right;
//         }
//     cout<<endl;
//     }
// 
//     void postorder(node *root)
//     {
//         if(root)
//         {
//             postorder(root->left);
//             postorder(root->right);
//             cout<<root->data<<", ";
//         }
//     }
// 
//     void iterativePostorder(node *root)
//     {
//         if(root==NULL) return;
// 
//         stack<node*> st1,st2;
//         st1.push(root);
// 
//         while(!st1.empty())
//         {
//             node *f=st1.top();
//             st1.pop();
// 
//             if(f->left) st1.push(f->left);
//             if(f->right) st1.push(f->right);
// 
//             st2.push(f);
//         }
// 
//         while(!st2.empty())
//         {
//             node *f=st2.top();
//             st2.pop();
//             cout<<f->data<<", ";
//         }
//         cout<<endl;
//     }

bool isBTSame(struct BTree *a,struct BTree *b)
{
    if(a==NULL && b==NULL)
        return true;

    if(a!=NULL && b==NULL) return false;
    if(b!=NULL && a==NULL) return false;

    if(a->data==b->data && isBTSame(a->lchild,b->lchild) && isBTSame(a->rchild,b->rchild))
        return true;
    return false;
}

bool helper(struct BTree *a,struct BTree *b)
{
    if(a!=NULL && b==NULL) return false;
    if(b!=NULL && a==NULL) return false;
    if(a==NULL && b==NULL) return true;

    if(a->data!=b->data) return false;

    return (helper(a->lchild,b->rchild) && helper(a->rchild,b->lchild));
}
bool isSymmetric(struct BTree *p)
{
    if(p==NULL) return true;

    return helper(p->lchild,p->rchild);
}


int count(struct BTree *p)
{
    if(p)
    {
        return (count(p->lchild)+count(p->rchild)+1);
    }
    return 0;
}

int height(struct BTree *p)
{
    if(p==NULL)
        return 0;

    int l=height(p->lchild);
    int r=height(p->rchild);

    return max(l,r)+1;
}

void levelOrder(struct BTree *p)
{
    queue<BTree *> q;
    cout<<p->data<<", ";
    q.push(p);

    while (!q.empty())
    {
        struct BTree *f=q.front();
        q.pop();

        if(f->lchild)
        {
            cout<<f->lchild->data<<", ";
            q.push(f->lchild);
        }
        if(f->rchild){
            cout<<f->rchild->data<<", ";
            q.push(f->rchild);
        }
    }
    
}

vector<vector<int> > levelOrder2(struct BTree *p)
{
    vector<vector<int> > v;
    if(p==NULL)
        return v;

    queue<BTree *> q;
    vector<int> temp;
    q.push(p);
    q.push(NULL);

    while (!q.empty())
    {
        struct BTree *f=q.front();
        q.pop();

        if(f==NULL)
        {
            v.push_back(temp);
            temp.clear();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            temp.push_back(f->data);
            if(f->lchild)
                q.push(f->lchild);
            if(f->rchild)
                q.push(f->rchild);
        }
    }
    return v;
    
}

stack<int> ReverseLevelOrder(struct BTree *p)
{
    stack<int> st;
    queue<struct BTree *> q;

    if(p==NULL)
        return st;

    q.push(p);

    while(!q.empty())
    {
        struct BTree *f=q.front();
        q.pop();

        st.push(f->data);

        if(f->rchild)
            q.push(f->rchild);

        if(f->lchild)
            q.push(f->rchild);
    }
    return st;
}

vector<vector<int> > reverse2(struct BTree *p)
{
    vector<vector<int> > v;
    if(p==NULL)
        return v;

    queue<BTree *> q;
    vector<int> temp;
    q.push(p);
    q.push(NULL);

    while (!q.empty())
    {
        struct BTree *f=q.front();
        q.pop();

        if(f==NULL)
        {
            v.push_back(temp);
            temp.clear();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            temp.push_back(f->data);
            if(f->lchild)
                q.push(f->lchild);
            if(f->rchild)
                q.push(f->rchild);
        }
    }
    reverse(v.begin(),v.end());
    return v;
    
}

vector<vector<int> > zigZagTraversal(struct BTree *p)
{
    vector<vector<int> > ans;
    if(p==NULL) return ans;

    queue<struct BTree *> q;
    q.push(p);
    bool LeftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> v(size);

        for(int i=0;i<size;i++){
            struct BTree *f=q.front();
            q.pop();

            int index=LeftToRight?i:(size-1-i);
            v[index]=f->data;

            if(f->lchild) q.push(f->lchild);
            if(f->rchild) q.push(f->rchild);
        }
        LeftToRight = !LeftToRight;
        ans.push_back(v);
    }
    return ans;    
    
}

vector<vector<int> > verticalTraversal(struct BTree *p)
{
    vector<vector<int> > ans;
    if(p==NULL)
        return ans;

    struct ele
    {
        struct BTree *node;
        int HD;
    };

    map<int, vector<int> > mymap;
    queue<ele> q;
    q.push({p,0});

    while (!q.empty())
    {
        struct ele front = q.front();
        q.pop();

        struct BTree *currentNode=front.node;
        int currentHD = front.HD;

        mymap[currentHD].push_back(currentNode->data);
        if(currentNode->lchild)
        {
            q.push({currentNode->lchild,currentHD-1});
        }
        if(currentNode->rchild)
        {
            q.push({currentNode->rchild,currentHD+1});
        }
    }
    for(auto it=mymap.begin();it!=mymap.end();it++){
        vector<int> r=it->second;
        sort(r.begin(),r.end());
        ans.push_back(r);
    }
    return ans;               
}

int minDepth(struct BTree *p)
{
    if(p==NULL)
        return 0;
    class pair
    {
        public:
        struct BTree *node;
        int depth;

        pair(struct BTree *node,int depth){
            this->node=node;
            this->depth=depth;
        }
    };

    queue<pair> q;
    q.push({p,1});

    while (!q.empty())
    {
        pair m=q.front();
        q.pop();

        struct BTree *currentNode=m.node;
        int currentDepth=m.depth;

        if(currentNode->lchild==NULL && currentNode->rchild==NULL)
            return currentDepth;
        if(currentNode->lchild)
            q.push({currentNode->lchild,currentDepth+1});
        if(currentNode->rchild)
            q.push({currentNode->rchild,currentDepth+1});
    }
    return -1;
}

struct BTree * lCAinBST(struct BTree *p,int a,int b)   ///Least/Lowest Common Ancestor in BST
{
    while (p!=NULL)
    {
        if(p->data>a && p->data>b)
            p=p->lchild;
        else if(p->data<a && p->data<b)
            p=p->rchild;
        else
            return p;
    }
    return NULL;
}

struct BTree * LCAinBT(struct BTree *p,int a,int b)  ///Least/Lowest Common Ancestor in BT 
{
    if(p==NULL) return NULL;

    if(p->data==a || p->data == b) return p;

    struct BTree *left=LCAinBT(p->lchild,a,b);
    struct BTree *right=LCAinBT(p->rchild,a,b);

    if(left==NULL && right==NULL) return NULL;
    if(left!=NULL && right==NULL) return left;
    if(left==NULL && right!=NULL) return right;
    
    return p;
}


void isBST(struct BTree *p,vector<int> &v1)
{
    if(p)
    {
        isBST(p->lchild,v1);
        v1.push_back(p->data);
        isBST(p->rchild,v1);
    }
}

bool isBST2(struct BTree *p,long long minV=-10000000000, long long maxV=10000000000)
{
    if(p==NULL) return true;

    bool left=isBST2(p->lchild,minV,p->data);
    bool right=isBST2(p->rchild,p->data,maxV);

    if(left && right && p->data>minV && p->data<maxV) return true;
    else return false;
}

struct BTree * invertBT(struct BTree *p)  ///for this the BT should be Symmetric BT
{
    if(p==NULL) return NULL;

    swap(p->lchild,p->rchild);
    p->lchild=invertBT(p->lchild);
    p->rchild=invertBT(p->rchild);

    return p;
}




int main()
{
    createBT();
    //createBT2();

    cout<<endl<<"First BTree => ";
    printBTree(first);

    // cout<<endl<<"Second BTree => ";
    // printBTree(second);

    // cout<<endl<<"Same BT Status : "<<isBTSame(first,second)<<endl;

    // cout<<endl<<"Symmetric Binary Tree Status: "<<isSymmetric(first)<<endl;

    // cout<<"Numbers of Nodes are : "<<count(first)<<endl;

    // cout<<"Height of BT is : "<<height(first)<<endl;

    // cout<<"Level Order Traversal : ";
    // levelOrder(first);
    // cout<<endl;

    // cout<<"Level Order Traversal by  Vector : ";
    // vector<vector<int> > v=levelOrder2(first);
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout<<"[ ";
    //     for(int j = 0; j < v[i].size(); j++)
    //     {
    //         cout<<v[i][j]<<", ";
    //     }
    //     cout<<"]"<<endl;
        
    // }
    
    // cout<<endl;



    // vector<vector<int> > v2 = reverse2(first);
    // cout<<"Reverse Level Order Traversal by  Vector : ";
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout<<"[ ";
    //     for(int j = 0; j < v[i].size(); j++)
    //     {
    //         cout<<v[i][j]<<", ";
    //     }
    //     cout<<"]"<<endl;
        
    // }
    
    // cout<<endl;

    // stack<int> st = ReverseLevelOrder(first);
    // while (!st.empty())
    // {
    //     cout<<st.top()<<", ";
    //     st.pop();
    // }

    

    // cout<<endl<<"Zig Zag order Traversal: "<<endl;
    // vector<vector<int> > v=zigZagTraversal(first);
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout<<"[ ";
    //     for(int j = 0; j < v[i].size(); j++)
    //     {
    //         cout<<v[i][j]<<", ";
    //     }
    //     cout<<"]"<<endl;
        
    // }


    cout<<endl<<"Vertical order Traversal: "<<endl;
    vector<vector<int> > v=verticalTraversal(first);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<"[ ";
        for(int j = 0; j < v[i].size(); j++)
        {
            cout<<v[i][j]<<", ";
        }
        cout<<"]"<<endl;
        
    }

    cout<<"Minimum Depth of Binary Tree : "<<minDepth(first)<<endl;


    vector<int> v1;
    isBST(first,v1);
    int i;
    for (i = 0; i < v1.size()-1; i++)
    {
        if(v1[i]>v1[i+1])
            break;
    }
    if(i==v1.size()-1)
        cout<<"BT is BST"<<endl;
    else
        cout<<"BT is not BST"<<endl;
    

    return 0;
}

