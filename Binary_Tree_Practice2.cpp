#include <iostream>
#include <vector>
#include<queue>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }
};

TreeNode<int> *takeInput()
{
    int rootData;
    cout<<"Enter the Value of Root : ";
    cin>>rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        struct TreeNode<int> *f=q.front();
        q.pop();

        cout<<"Enter the Number of Children of "<<f->data<<" : ";
        int n;
        cin>>n;

        for(int i=1;i<=n;i++)
        {
            int childData;
            cout<<"Enter the valur of "<<i<<"th child of "<<f->data<<" : ";
            cin>>childData;

            TreeNode<int> *child = new TreeNode<int>(childData);
            f->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    cout << root->data << ": ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ", ";
    }
    cout << endl;

    for (int i = 0; i < root->children.size(); i++)
        printTree(root->children[i]);
}

int main()
{
    TreeNode<int> *root;
    root=takeInput();
    printTree(root);

    return 0;
}