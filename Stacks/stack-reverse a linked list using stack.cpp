#include<iostream>
#include<stack>
using namespace std;
struct node
{
    char data;
    node* next;
};
node* head;
void push(char c)
{
    node* temp=new node();
    temp->data=c;
    temp->next=head;
    head=temp;
}

void reverseList()
{
    if(head==NULL)
    {
        cout<<"SORRY the list is empty.";
        return;
    }
    node* temp=head;
    stack<node*> s;
    while(temp!=NULL)
    {
        s.push(temp);
        temp=temp->next;
    }
    temp=s.top();
    head=temp;
    s.pop();
    while(!s.empty())
    {
        temp->next=s.top();
        s.pop();
        temp=temp->next;
    }
    temp->next=NULL;
}

void print()
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{
    head=NULL;
    int n;
    cout<<"Enter the no.of value you want to enter :";
    cin>>n;
    char ch;
    for(int i=0;i<n;i++)
    {
       cout<<"Enter value :";
       cin>>ch;
       push(ch);
    }
    cout<<"LINKED LIST BEFORE REVERING :";
    print();

    reverseList();
    cout<<"\nLINKED LIST AFTER REVERSING :";
    print();
}
