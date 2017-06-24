#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
node* head;
void print()
{
    node * temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void insert(int x)
{
    node* temp=new node();
    temp->data=x;
    temp->next=head;
    head=temp;
}
void reverse(node * p)
{
    if(p->next==NULL)
    {
        head=p;
        return;
    }
    reverse(p->next);
    node* q=p->next;
    q->next=p;
    p->next=NULL;
}
int main()
{
    head=NULL;
    insert(12);
    insert(25);
    insert(33);
    insert(48);
    insert(57);
    print();
    cout<<endl;
    reverse(head);
    print();
}
