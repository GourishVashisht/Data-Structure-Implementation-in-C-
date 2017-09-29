#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
void add(node* &head,int data)
{
    node* t=new node();
    t->data=data;
    t->next=head;
    head=t;
}
void print(node* head)
{
    node* t=head;
    do{
        cout<<t->data<<" ";
        t=t->next;
    }while(t!=head);
}

int main()
{
    node* head=NULL;
    for(int i=1;i<=10;i++)
        add(head,i);
    node* t=head;
    while(t->next!=NULL)
        t=t->next;
    t->next=head;
    cout<<"linked list is : ";
    print(head);
    cout<<endl;
    return 0;
}
