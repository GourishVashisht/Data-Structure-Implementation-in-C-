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
}
int len()
{
    node* t=head;
    int c=0;
    while(t!=NULL)
    {
        c++;
        t=t->n;
    }
    return c;
}

int main()
{
    head=NULL;
    for(int i=1;i<=9;i++)
        ins(i);
    print();
    cout<<endl;
    cout<<"Length of the linked list : "<<len();
}
