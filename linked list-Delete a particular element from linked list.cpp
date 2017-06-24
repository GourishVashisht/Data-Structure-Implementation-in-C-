#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node* next;
};

node* head;

void insert(int n)
{
    node* temp=new node();
    temp->data=n;
    temp->next=head;
    head=temp;
}
void delete1(int item)
{
    node* temp;
    temp=head;
    if(temp->data==item)
    {
        head=head->next;
        delete(temp);
        return;
    }
    node* prev;
    while(temp!=NULL)
    {
        if(temp->data==item)
        {
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    delete(temp);
}
void print()
{
    node* temp;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main()
{
  head=NULL;
  insert(10);
  insert(20);
  insert(30);
  insert(40);
  insert(50);
  print();
  int item;
  cout<<"\nEnter element you want to delete: ";
  cin>>item;
  delete1(item);
  print();
}
