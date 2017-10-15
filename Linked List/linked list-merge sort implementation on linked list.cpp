#include<iostream>
using namespace std;
struct node
{
    int d;
    node* n;
};
node* head;
void ins(int v)
{
    node* t=new node();
    t->d=v;
    t->n=head;
    head=t;
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

node* mergeLL(node* a,node* b)
{
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    node* c=NULL;
    if(a->d < b->d)
    {
        c=a;
        c->n=mergeLL(a->n,b);
    }
    else
    {
        c=b;
        c->n=mergeLL(a,b->n);
    }
    return c;
}
node* midLL(node* head)
{
    node* slow=head;
    node* fast=head;
    while(fast->n!=NULL && fast->n->n!=NULL)
    {
        slow=slow->n;
        fast=fast->n->n;
    }
    return slow;
}
node* mergeSortLL(node* c)
{
    if(c==NULL || c->n==NULL)
        return c;
    node* mid=midLL(c);
    node* a=c;
    node* b=mid->n;
    mid->n=NULL;
    a=mergeSortLL(a);
    b=mergeSortLL(b);
    return mergeLL(a,b);
}
int main()
{
    head=NULL;
    cout<<"Linked list : \n";
    for(int i=0;i<=10;i++)
        ins(i);
    print(head);
    head=mergeSortLL(head);
    cout<<"Sorted linked list is : \n";
    print(head);
    return 0;
}



