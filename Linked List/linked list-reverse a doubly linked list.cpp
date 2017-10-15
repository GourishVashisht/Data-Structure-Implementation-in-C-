#include<iostream>
using namespace std;
struct node
{
    int d;
    node* n;
    node* p;
};
node* head;
void ins(int v)
{
    node* t=new node();
    t->d=v;
    t->n=head;
    if(head!=NULL)
        t->n->p=t;
    t->p=NULL;
    head=t;
}
void print()
{
    node* t=head;
    while(t!=NULL)
    {
        cout<<t->d<<" ";
        t=t->n;
    }
    cout<<endl;
}

void reverseDLL()
{
    node* prev,* curr,* next;
    curr=head;
    next=head;
    prev=NULL;
    while(next!=NULL)
    {
        next=curr->n;
        curr->n=prev;
        curr->p=next;
        prev=curr;
        curr=next;
    }
    head=prev;
}

int main()
{
    head=NULL;
    for(int i=1;i<=9;i++)
        ins(i);
    print();
    reverseDLL();
    print();
    return 0;
}


