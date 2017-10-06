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
void deleteLL()
{
    if(head==NULL)
        return;
    node* curr=head;
    node* next=head;
    while(next!=NULL)
    {
        curr=next;
        next=next->n;
        delete curr;
    }
    head=NULL;
    cout<<"Your linked list got deleted successfully.";
}
int main()
{
    head=NULL;
    for(int i=1;i<=9;i++)
        ins(i);
    print();
    deleteLL();
    print();
    return 0;
}
