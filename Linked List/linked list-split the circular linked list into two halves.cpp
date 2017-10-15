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
    while(t->n!=head)
    {
        cout<<t->d<<" ";
        t=t->n;
    }
    cout<<t->d;
    cout<<endl;
}
node* mid()
{
    node* slow=head;
    node* fast=head;
    while(fast->n!=head && fast->n->n!=head)
    {
        slow=slow->n;
        fast=fast->n->n;
    }
    return slow;
}
void splitCLL()
{
    node* t1=mid();
    node* t2;
    t2=t1->n;
    node* temp=t2;
    while(temp->n!=head)
        temp=temp->n;
    /// first circular LL
    cout<<"First part of the circular LL : \n";
    t1->n=head;
    t1=head;
    print(t1);

    /// second circular LL
    cout<<"Second part of the circular LL : \n";
    temp->n=t2;
    print(t2);
}
int main()
{
    head=NULL;
    for(int i=10;i>=1;i--)
        ins(i);
    node* t=head;
    while(t->n!=NULL)
        t=t->n;
    t->n=head;
    print(head);

    splitCLL();
    return 0;
}


