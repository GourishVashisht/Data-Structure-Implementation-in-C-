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

bstNode* find(bstNode* root,int data)
{
    if(root==NULL)
        return NULL;
    else if(root->data == data)
        return root;
    else if(root->data <= data)
        return find(root->right,data);
    else if(root->data > data)
        return find(root->left,data);
}
/// inorder successor of a node in binary search tree
bstNode* inorderSuccessor(bstNode* root,int data)
{
    if(root==NULL)
        return NULL;
    /// search for node
    bstNode* current=find(root,data);
    if(current==NULL)
        return NULL;
    else if(current->right!=NULL)
    {
        bstNode* temp=current->right;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        return temp;
    }
    else{
        bstNode* successor=NULL;
        bstNode* ancestor = root;
        while(ancestor!=current)
        {
            if(current->data < ancestor->data)
            {
                successor=ancestor;
                ancestor=ancestor->left;
            }
            else ancestor=ancestor->right;
        }
        return successor;
    }
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
    int value;
    cout<<"Enter the element whose inorder successor you want to search : ";
    cin>>value;
    bstNode* temp=inorderSuccessor(root,value);
    if(temp==NULL)
        cout<<"Either tree is empty or element does not exist in tree.\n";
    else
        cout<<"\nThe inorder successor of "<<value<<" is "<<temp->data<<endl;
    return 0;
}
