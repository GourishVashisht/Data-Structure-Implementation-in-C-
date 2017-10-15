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
    while(t->n!=head)
    {
        cout<<t->d<<" ";
        t=t->n;
    }
    cout<<t->d;
    cout<<endl;
}
void sortedInsert(int v)
{
    node* temp=new node();
    temp->d=v;
    temp->n=NULL;
    node* t=head;
    if(v <= head->d)
    {
        while(t->n!=head)
            t=t->n;
        temp->n=head;
        head=temp;
        t->n=head;
        return;
    }
    t=head;
    node* prev=NULL;
    while(t->n!=head)
    {
        if(t->d >= v)
            break;
        prev=t;
        t=t->n;
    }
    if(t->n==head)
    {
        if(v <= t->d)
        {
            temp->n=t;
            prev->n=temp;
        }
        else{
            t->n=temp;
            temp->n=head;
        }
    }
    else{
        temp->n=t;
        prev->n=temp;
    }
}
int main()
{
    head=NULL;
    for(int i=10;i>=1;i--)
    {
        if(i==2)
            continue;
        ins(i);
    }
    node* t=head;
    while(t->n!=NULL)
        t=t->n;
    t->n=head;
    print();
    cout<<"Inserted 2 \n";
    sortedInsert(2);
    print();
    cout<<"\nInserted 0 \n";
    sortedInsert(0);
    print();
    cout<<"\nInserted 2 \n";
    sortedInsert(2);
    print();
    cout<<"\nInserted 9 \n";
    sortedInsert(9);
    print();
    cout<<"\nInserted 10 \n";
    sortedInsert(10);
    print();
    cout<<"\nInserted 11 \n";
    sortedInsert(11);
    print();
    return 0;
}


