#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};

/// add at beginning
void add(node* &head,int data)
{
    node* t=new node();
    t->data=data;
    t->next=head;
    head=t;
}

/// print the linked list
void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
node* merge(node* a,node* b)
{
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    node* c=NULL;
    if(a->data < b->data)
    {
        c=a;
        c->next=merge(a->next,b);
    }
    else
    {
        c=b;
        c->next=merge(a,b->next);
    }
    return c;
}

node* mid(node* head)
{
    node* slow=head;
    node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

node* mergesort(node* a)
{
    if(a==NULL || a->next==NULL)
        return a;
    node* m=mid(a);
    node* second=m->next;
    node* first=a;
    m->next=NULL;

    first=mergesort(first);
    second=mergesort(second);
    return merge(first,second);
}
int main()
{
    node* a=NULL;
    for(int i=1;i<=10;i++)
    {
        add(a,i);
    }
    cout<<"linked list is : ";
    print(a);
    cout<<endl;
    a=mergesort(a);
    print(a);
    return 0;
}
