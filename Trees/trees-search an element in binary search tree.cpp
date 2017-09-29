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
    bstNode* node=getNewNode(data);
    if(root==NULL)
    {
        root=node;
    }
    else if(root->data <= data)
    {
        root->right=insert(root->right,data);
    }
    else if(root->data > data)
    {
        root->left=insert(root->left,data);
    }
    return root;
}

bool search(bstNode* root,int item)
{
    if(root==NULL)
        return false;
    else if(root->data == item)
        return true;
    else if(root->data >= item)
        return search(root->left,item);
    else return search(root->right,item);
}

int main()
{
  bstNode* root=NULL;
  int n;
  cout<<"enter number of elements:- \n";
  cin>>n;
  int val;
  while(n--)
  {

      cout<<"Enter value: ";
      cin>>val;
      root=insert(root,val);
  }
  int item;
  cout<<"Enter element to search :";
  cin>>item;
  if(search(root,item)==true)
    cout<<"\nitem found";
  else cout<<"\nitem not found";
  return 0;
}
