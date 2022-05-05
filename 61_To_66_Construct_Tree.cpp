#include<bits/stdc++.h>
using namespace std;

class Tree
{
    public:
    int data;
    Tree *left,*right;

    Tree(int data)
    {
        this->data=data;
    }
};

Tree * helper(vector<int> inorder,vector<int> preorder,int InS,int InE,int PrS,int PrE)
{
    if(InS>InE) return NULL;

    int rootData=preorder[PrS];
    int rootIndex=-1;
    for(int i=InS;i<=InE;i++)
    {
        if(inorder[i]==rootData){
            rootIndex=i;
            break;
        }
    }

    Tree *root=new Tree(rootData);

    int LInS=InS;
    int LInE=rootIndex-1;
    int LPrS=PrS+1;
    int LPrE=LInE-LInS+LPrS;

    int RInS=rootIndex+1;
    int RInE=InE;
    int RPrS=LPrE+1;
    int RPrE=PrE;

    root->left=helper(inorder,preorder,LInS,LInE,LPrS,LPrE);
    root->right=helper(inorder,preorder,RInS,RInE,RPrS,RPrE);

    return root;
}

Tree * builtTreeFromPreorder(vector<int> inorder, vector<int> preorder)  ///Built Tree From Preorder & Inorder
{
    int n=inorder.size();
    return helper(inorder,preorder,0,n-1,0,n-1);
}


Tree * helper2(vector<int> inorder,vector<int> postorder,int InS,int InE,int PoS,int PoE)
{
    if(InS>InE) return NULL;

    int rootData=postorder[PoE];
    int rootIndex=-1;
    for(int i=InS;i<=InE;i++)
    {
        if(rootData==inorder[i])
        {
            rootIndex=i;
            break;
        }
    }

    int LInS=InS;
    int LInE=rootIndex-1;
    int LPoS=PoS;
    int LPoE=LInE-LInS+LPoS;

    int RInS=rootIndex+1;
    int RInE=InE;
    int RPoS=LPoE+1;
    int RPoE=PoE-1;

    Tree *root=new Tree(rootData);

    root->left=helper2(inorder,postorder,LInS,LInE,LPoS,LPoE);
    root->right=helper2(inorder,postorder,RInS,RInE,RPoS,RPoE);

    return root;
}

Tree *builtTreeFromPostorder(vector<int> inorder,vector<int> postorder) ///Construct Tree From Inorder And Postorder Traversal
{
    int n=inorder.size();
    return helper2(inorder,postorder,0,n-1,0,n-1);
}

Tree * helper3(vector<int> inorder,int s,int e)
{
    if(s>e) return NULL;

    int max=INT_MIN;
    int maxIndex=-1;
    for(int i=s;i<=e;i++)
    {
        if(max<inorder[i])
        {
            max=inorder[i];
            maxIndex=i;
        }
    }
    int rootData=max;
    Tree *root=new Tree(rootData);

    root->left=helper3(inorder,s,maxIndex-1);
    root->right=helper3(inorder,maxIndex+1,e);

    return root;
}

Tree * cartesianTree(vector<int> inorder) ///Construct Cartesian Tree from Inorder
{
    int n=inorder.size();
    return helper3(inorder,0,n-1);
}

int height(Tree *p)
{
    if(p==NULL) return 0;

    return 1+max(height(p->left),height(p->right));
}

int findDiameterOfBT(Tree* p)
{
    // This Method take order of time )[n^2] for worst case. generally Order of time for this case is O[n*h]
    // where h is heght of Binary Tree ie. log(n) for minimum case and n for maximum case.

    if(p==NULL) return 0;

    int option1=height(p->left)+height(p->right);
    int option2=findDiameterOfBT(p->left);
    int option3=findDiameterOfBT(p->right);

    return max(option1,max(option2,option3));
}

pair<int,int> heightAndDiameter(Tree *p)
{
    if(p==NULL)
    {
        pair<int,int> ans;
        ans.first=0;
        ans.second=0;
        return ans;
    }

    pair<int,int> leftAns=heightAndDiameter(p->left);
    pair<int,int> rightAns=heightAndDiameter(p->right);

    int lh=leftAns.first;
    int ld=leftAns.second;

    int rh=rightAns.first;
    int rd=rightAns.second;

    int h=1+max(lh,rh);
    int d=max(lh+rh,max(ld,rd));

    pair<int,int> res;
    res.first=h;
    res.second=d;

    return res;

}

int findDiameterOfBT2(Tree *p)
{
    
    pair<int,int> ans=heightAndDiameter(p);
    return ans.second;
}

Tree * helper4(vector<int> v,int s,int e)
{
    if(s>e)
        return NULL;

    int mid=(s+e)/2;
    int rootData=v[mid];
    Tree *p=new Tree(rootData);
    p->left=helper4(v,s,mid-1);
    p->right=helper4(v,mid+1,e);

    return p;
}

Tree * BSTFromSortedArray(vector<int> v)
{
    int n=v.size();
    return helper4(v,0,n-1);
}

void inOrderHelper(Tree *p,vector<int> &v)
{
    if(p)
    {
        inOrderHelper(p->left,v);
        v.push_back(p->data);
        inOrderHelper(p->right,v);
    }
}

int findKthSmallestNumber(Tree *p,int k)
{
    vector<int> v;
    inOrderHelper(p,v);
    return v[k-1];
}


void inOrderHelper2(Tree *p,int k,int &ans,int &count)
{
    if(p==NULL) return;
    inOrderHelper2(p->left,k,ans,count);
    count++;
    if(count==k)
    {
        ans=p->data;
        return;
    }
    inOrderHelper2(p->right,k,ans,count);
}

int findKthSmallestNumber2(Tree *p,int k) 
{
    ///This is Optimized Solution.this does not take any Extra Space.
    int ans=-1;
    int count=0;
    inOrderHelper2(p,k,ans,count);
    return ans;
}

void preOrder(Tree *p)
{
    if(p==NULL) return;

    cout<<p->data<<" ,";
    preOrder(p->left);
    preOrder(p->right);
}

void inOrder(Tree *p)
{
    if(p==NULL) return;

    inOrder(p->left);
    cout<<p->data<<" ,";
    inOrder(p->right);
}

void postOrder(Tree *p)
{
    if(p==NULL) return;

    postOrder(p->left);
    postOrder(p->right);
    cout<<p->data<<" ,";
}

int main()
{
    vector<int> inorder{3,4,2,5,6};
    vector<int> preorder{5,4,3,2,6};
    vector<int> postorder{3,2,4,6,5};
    vector<int> inorder2{1,4,5,3,7,9,0};
    vector<int> inorder3{1,2,3,4,5,6,7};

    Tree *first=builtTreeFromPreorder(inorder,preorder);
    Tree *second=builtTreeFromPostorder(inorder,postorder); 
    

    cout<<"Inorder Traversal: "<<endl;
    inOrder(first);

    cout<<endl<<"Preorder Travesal: "<<endl;
    preOrder(first);   

    cout<<endl<<"Postorder Traversal: "<<endl;
    postOrder(second);

    Tree *third=cartesianTree(inorder2);

    cout<<endl<<"Inorder Trversal of Cartesian Tree: "<<endl;
    inOrder(third);

    cout<<endl<<"Diameter of first BT is: "<<findDiameterOfBT(first)<<endl;
    cout<<endl<<"Diameter of third BT is: "<<findDiameterOfBT(third)<<endl;

    cout<<endl<<"Diameter of first BT (by Better Approach) is: "<<findDiameterOfBT2(first)<<endl;
    cout<<endl<<"Diameter of third BT (by Better Approach) is: "<<findDiameterOfBT2(third)<<endl;

    Tree *fourth=BSTFromSortedArray(inorder3);
    cout<<"Inorder Traversal of Tree Created from Sorted Array: "<<endl;
    inOrder(fourth);
    cout<<endl<<"Preorder Traversal of Tree Created from Sorted Array: "<<endl;
    preOrder(fourth);


    cout<<endl<<"Kth Smallest Element is :"<<findKthSmallestNumber(fourth,3)<<endl;
    cout<<endl<<"Kth Smallest Element is :"<<findKthSmallestNumber2(fourth,4)<<endl;

    return 0;
}