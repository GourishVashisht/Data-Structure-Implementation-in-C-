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
void deleteMiddle()
{
    if(head==NULL)
        return;
    if(head->n==NULL)
    {
        node* temp=head;
        head=NULL;
        delete temp;
        return;
    }
    node* fast,* slow,* prev;
    fast=head;
    slow=head;
    prev=NULL;
    while(fast!=NULL && fast->n!=NULL)
    {
        prev=slow;
        slow=slow->n;
        fast=fast->n->n;
    }
    prev->n=slow->n;
    delete slow;
    return;
}

int main()
{
    head=NULL;
    for(int i=1;i<=9;i++)
        head=ins(head,i);
    print(head);
    deleteMiddle();
    cout<<"The linked list after deleting the middle element is  : \n";
    print(head);
}
