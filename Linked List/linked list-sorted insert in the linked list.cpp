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
    t->n=NULL;
    if(head==NULL)
    {
        head=t;
        return;
    }
    node* temp=head;
    while(temp->n!=NULL)
        temp=temp->n;
    temp->n=t;
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
void sortedInsert(int v)
{
    node* t=new node;
    t->d=v;
    t->n=NULL;
    if(head==NULL)
    {
        head=t;
        return;
    }
    if(v<(head->d))
    {
        t->n=head;
        head=t;
        return;
    }
    node* prev=NULL;
    node* curr=head;
    while( (curr!=NULL) && (v > (curr->d)) )
    {
        prev=curr;
        curr=curr->n;
    }
    t->n=prev->n;
    prev->n=t;
}
int main()
{
    head=NULL;
    for(int i=1;i<=10;i++)
    {
        if(i==9)
            continue;
        ins(i);
    }
    print();
    sortedInsert(9);
    cout<<"\nLinked list after sorted insert : \n";
    print();
}
