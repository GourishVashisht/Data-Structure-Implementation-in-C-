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
int main()
{
    node* a=NULL;
    for(int i=9;i>=1;i-=2)
    {
        add(a,i);
    }
    node* b=NULL;
    for(int i=10;i>=2;i-=2)
    {
        add(b,i);
    }
    cout<<"Your first linked list is : ";
    print(a);
    cout<<endl;
    cout<<"Your second linked list is : ";
    print(b);
    cout<<endl;

    node* c=merge(a,b);
    print(c);
    return 0;
}
