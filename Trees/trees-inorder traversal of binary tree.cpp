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
    else if(root->data <= data)
    {
        root->right=insert(root->right,data);
        return root;
    }

    else {
        root->left=insert(root->left,data);
        return root;
    }
}

/// inorder traversal of binary tree
void inorder(bstNode* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    bstNode* root=NULL;
    int n,data;
    cout<<"enter number of elements you want to enter :";
    cin>>n;
    while(n--)
    {
        cout<<"enter value: ";
        cin>>data;
        root=insert(root,data);
    }
    cout<<endl;
    cout<<"INORDER TRAVERSAL OF BINARY SEARCH TREE IS :";
    inorder(root);
    cout<<endl;
    return 0;
}
