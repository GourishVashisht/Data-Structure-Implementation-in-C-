#include<iostream>
#include<queue>
using namespace std;

struct bstNode
{
    char data;
    bstNode* left;
    bstNode* right;
};

bstNode* getNewNode(char data)
{
    bstNode* newNode=new bstNode();
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

bstNode* insert(bstNode* root,char data)
{
    if(root==NULL)
    {
        root=getNewNode(data);
    }
    else if(root->data >= data)
    {
        root->left=insert(root->left,data);
    }
    else
        root->right=insert(root->right,data);
    return root;
}

void print(bstNode* root)
{
    if(root==NULL)
    {
        cout<<"Empty tree.";
        return;
    }
    queue<bstNode*> q;
    bstNode* temp;
    q.push(root);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
    }
}
int main()
{
    bstNode* root=NULL;
    int n;
    cout<<"enter thenumber of elements ";
    cin>>n;
    char data;
    while(n--)
    {
        cout<<"enter data ";
        cin>>data;
        root=insert(root,data);
    }
    print(root);
    return 0;
}
