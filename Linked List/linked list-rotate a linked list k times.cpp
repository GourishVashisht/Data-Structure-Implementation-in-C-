#include<iostream>
using namespace std;
struct node
{
    int d;
    node* n;
};
node* head;

node* ins(node* &head,int v)
{
    node* t=new node();
    t->d=v;
    t->n=NULL;
    if(head==NULL)
    {
        head=t;
        return head;
    }
    node* temp=head;
    while(temp->n!=NULL)
        temp=temp->n;
    temp->n=t;
    return head;
}

void print(node* head)
{
    node* t=head;
    while(t!=NULL)
    {
        cout<<t->d<<" ";
        t=t->n;
    }
    cout<<endl;
}
int len()
{
    node* t=head;
    int c=0;
    while(t!=NULL)
    {
        c++;
        t=t->n;
    }
    return c;
}

void rotateLL(int k)
{
    int l=len();
    if(k%l==0)
        return;
    k=k%l;
    node* temp=head;
    while(temp->n!=NULL)
        temp=temp->n;
    node* t;
    while(k--)
    {
        t=head;
        head=head->n;
        temp->n=t;
        t->n=NULL;
        temp=t;
    }

}
int main()
{
    head=NULL;
    for(int i=1;i<=9;i++)
        head=ins(head,i);
    print(head);
    int k=4;
    rotateLL(k);
    cout<<"The linked list after rotating the linked list is : \n";
    print(head);
}
