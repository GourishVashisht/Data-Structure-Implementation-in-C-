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

node* mergeLL(node* a,node* b)
{
    if(a==NULL && b==NULL)
        return a;
    else if(a!=NULL && b==NULL)
        return a;
    else if(a==NULL && b!=NULL)
        return b;
    else{
        node* c=NULL;
        if(a->d <= b->d)
        {
            c=a;
            c->n=mergeLL(a->n,b);
            return c;
        }
        else{
            c=b;
            c->n=mergeLL(a,b->n);
            return c;
        }
    }
}

int main()
{
    head=NULL;
    node* a,* b;
    a=NULL;
    b=NULL;
    for(int i=1;i<=10;i++)
    {
        if(i%2==0)
            head=ins(head,i);
    }
    a=head;
    head=NULL;
    print(a);
    for(int i=1;i<=20;i++)
    {
        if(i%2!=0)
            head=ins(head,i);
    }
    b=head;
    head=NULL;
    print(b);
    cout<<endl;
    node* c;
    c=mergeLL(a,b);
    cout<<"The linked list after merging is : \n";
    print(c);
}
