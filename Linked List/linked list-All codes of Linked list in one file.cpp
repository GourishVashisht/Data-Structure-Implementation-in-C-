#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

/// add at beginning
void add(node* &head,int data)
{
    node* t=new node();
    t->data=data;
    t->next=head;
    head=t;
}

/// print the linked list
void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

/// operator overloading to take print head using cout function
void operator<<(ostream &os,node* head)
{
    print(head);
}

/// length of the linked list
int length(node* head)
{
    int len=0;
    while(head!=NULL)
    {
        head=head->next;
        len++;
    }
    return len;
}

/// insert at position
void insert(node* &head,int data,int p)
{
    node* t=new node();
    t->data=data;
    t->next=NULL;
    if(p==0)
    {
        t->next=head;
        head=t;
        return;
    }
    node* t1=head;
    for(int i=0;i<p-1;i++)
        t1=t1->next;
    t->next=t1->next;
    t1->next=t;
}

/// delete at front
void deleteAtFront(node* &head)
{
    node* t=head;
    head=head->next;
    delete t;
}

/// deleting at particular position
void deleteAtPosition(node* &head,int pos)
{
    if(pos==0)
    {
        deleteAtFront(head);
        return;
    }
    node* t=head;
    for(int i=0;i<pos-1;i++)
        t=t->next;
    node* temp=NULL;
    temp=t->next;
    t->next=temp->next;
    delete temp;
}

/// print linked list in reverse order
void printReverse(node* head)
{
    if(head==NULL)
        return;
    printReverse(head->next);
    cout<<head->data<<" ";
}

/// reverse a linked list iteration
void reverseListIt(node* &head)
{
    node* prev,*curr,*nextptr;
    prev=NULL;
    curr=head;
    while(curr!=NULL)
    {
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
    }
    head=prev;
}

/// reverse a linked list recursive
node* reverseListRec(node* head)
{
    if(head->next==NULL)
    {
        return head;
    }
    node* chotta=reverseListRec(head->next);
    head->next->next=head;
    head->next=NULL;
    return chotta;
}

int main()
{
    node* head=NULL;
    for(int i=0;i<10;i++)
    {
        add(head,i);
    }
    cout<<"Your linked list is : ";
    cout<<head; /// or use print func.directly
    cout<<endl<<endl;

    cout<<"Length of the linked list is : "<<length(head)<<endl;

    int d,p;
    cout<<"Give the data and position : ";
    cin>>d>>p;
    insert(head,d,p);
    cout<<"Linked list after insertion is : ";
    cout<<head;
    cout<<endl<<endl;

    cout<<"Linked list after Deleting at front : ";
    deleteAtFront(head);
    cout<<head;
    cout<<endl<<endl;

    int pos;
    cout<<"Enter the position to delete : ";
    cin>>pos;
    deleteAtPosition(head,pos);
    cout<<head;
    cout<<endl<<endl;

    cout<<"Reverse printing a linked list : ";
    printReverse(head);
    cout<<endl<<endl;

    cout<<"Linked list after reversing using iteration : ";
    reverseListIt(head);
    cout<<head;
    cout<<endl<<endl;

    cout<<"Linked list after reversing using recursion : ";
    head=reverseListRec(head);
    cout<<head;
    cout<<endl<<endl;
    return 0;
}
