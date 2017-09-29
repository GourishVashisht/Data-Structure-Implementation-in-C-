#include<iostream>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;
class node
{
public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

/// build tree
node* buildTree(node* root)
{
    cout<<"Enter root data :";
    int d;
    cin>>d;
    if(d==-1)
        return NULL;
    node* temp=new node(d);
    temp->left=buildTree(temp->left);
    temp->right=buildTree(temp->right);
    return temp;
}

/// level order print
void levelOrderPrint(node* root)
{
    if(root==NULL)
        return;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* f=q.front();
        q.pop();
        cout<<f->data<<" ";
        if(f->left!=NULL)
        {
            q.push(f->left);
        }
        if(f->right!=NULL)
        {
            q.push(f->right);
        }
    }
}
/// level order print like actual tree
void levelOrderLikeActualTree(node* root)
{
    if(root==NULL)
        return;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* f=q.front();
        q.pop();
        cout<<f->data<<" ";
        if(f->left!=NULL)
        {
            q.push(f->left);
        }
        if(f->right!=NULL)
        {
            q.push(f->right);
        }
        f=q.front();
        if(f==NULL)
        {
            cout<<endl;
            q.pop();
            if(!q.empty())
                q.push(NULL);
        }
    }
}
/// postorder print
void postorder(node* root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

/// preorder print
void preorder(node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

/// inorder print
void inorder(node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

/// count nodes in a tree
int countNodes(node* root)
{
    if(root==NULL)
        return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}

/// height of tree
int height(node* root)
{
    if(root==NULL)
        return 0;
    return 1+max(height(root->left),height(root->right));
}

/// diameter of tree
int diameter(node* root)
{
    if(root==NULL)
        return 0;
    int option1=height(root->left)+height(root->right);
    int option2=diameter(root->left);
    int option3=diameter(root->right);
    return max(option1,max(option2,option3));
}

int main()
{
    node* root=NULL;
    cout<<"Building a tree : \n";
    root=buildTree(root);
    cout<<endl;
    cout<<"Levelorder print of tree is : ";
    levelOrderPrint(root);
    cout<<endl;
    cout<<"Level order printing like actual tree : \n";
    levelOrderLikeActualTree(root);
    cout<<endl;

    cout<<"Inorder traversal of tree is : ";
    inorder(root);
    cout<<endl;

    cout<<"Postorder traversal of tree is : ";
    postorder(root);
    cout<<endl;

    cout<<"Preorder traversal of tree is : ";
    preorder(root);
    cout<<endl;

    cout<<"The number of nodes in tree is :"<<countNodes(root);
    cout<<endl;

    cout<<"Height of tree is : "<<height(root);
    cout<<endl;

    cout<<"Diameter of tree is : "<<diameter(root);
    cout<<endl;
    return 0;
}
