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
    else if(root->data >= data)
        root->left=insert(root->left,data);
    else
        root->right=insert(root->right,data);
    return root;
}

int height(bstNode* root)
{
    if(root==NULL)
        return -1;
    return max(height(root->left),height(root->right))+1;
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
    cout<<"The height of the tree : "<<height(root);
    return 0;
}
