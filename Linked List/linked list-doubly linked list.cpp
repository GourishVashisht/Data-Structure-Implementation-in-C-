#include<iostream>
using namespace std;
struct node
{
   int data;
   node* prev;
   node* next;
};
node* head;
void insertAtHead(int x)
{
    node* temp=new node();
    temp->data=x;
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        return;
    }
    head->prev=temp;
    temp->next=head;
    head=temp;
}

void printForward()
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void printReverse()
{
    node* temp1=head;
    while(temp1->next!=NULL)
        temp1=temp1->next;
    if(head=NULL)
    {
        cout<<"empty list";
        return;
    }
    while(temp1!=NULL)
    {
        cout<<temp1->data<<" ";
        temp1=temp1->prev;
    }
}

void insertAtTail(int x)
{
    struct node* temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    struct node* temp1=new node();
    temp1->data=x;
    temp1->next=NULL;
    temp1->prev=NULL;

    temp1->prev=temp;
    temp->next=temp1;
}

int main()
{
    head=NULL;
    insertAtHead(10);
    insertAtHead(20);
    insertAtHead(30);
    insertAtHead(40);
    insertAtHead(50);

    printForward();
    cout<<endl;

    insertAtTail(60);
    insertAtTail(70);

    printForward();
    cout<<endl;

    printReverse();
}

