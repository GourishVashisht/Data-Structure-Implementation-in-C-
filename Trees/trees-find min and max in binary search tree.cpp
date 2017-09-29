#include<iostream>
using namespace std;
struct bstNode
{
    int data;
    bstNode* left;
    bstNode* right;
};

bstNode* getNewNode(int data)
{
    bstNode* newNode=new bstNode();
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
bstNode* insert(bstNode* root,int data)
{
    if(root==NULL)
    {
        root=getNewNode(data);
        return root;
    }
    else if(root->data > data)
        root->left=insert(root->left,data);
    else if(root->data <= data)
        root->right=insert(root->right,data);
    return root;
}

/// to find minimum
int findMin(bstNode* root)
{
    if(root==NULL)
    {
        cout<<"empty tree\n";
        return -1;
    }
    else if(root->left==NULL)
        return root->data;
    else return findMin(root->left);
}
/// to find maximum
int findMax(bstNode* root)
{
    if(root==NULL)
    {
        cout<<"empty tree\n";
        return -1;
    }
    else if(root->right==NULL)
        return root->data;
    else return findMax(root->right);
}
int main()
{
    bstNode* root=NULL;
    int n;
    cout<<"enter number of elements :";
    cin>>n;
    int data;
    while(n--)
    {
        cout<<"enter element : ";
        cin>>data;
        root=insert(root,data);
    }
    cout<<"The minimum element in the tree is : "<<findMin(root);
    cout<<endl;
    cout<<"The maximum element in the tree is : "<<findMax(root);

    return 0;
}
