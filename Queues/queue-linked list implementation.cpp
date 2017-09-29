#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
node* front;
node* rear;

bool isEmpty()
{
    if(front==NULL && rear==NULL)
        return true;
    else return false;
}
void push(int x)
{
      node* temp=new node();
      temp->data=x;
      if(isEmpty())
      {
          front=rear=temp;
          return;
      }
      rear->next=temp;
      rear=temp;
}
void pop()
{
    if(isEmpty())
    {
        cout<<"sorry the linked list is empty"<<endl;
        return;
    }
    node* temp=front;
    front=front->next;
    delete(temp);
}
int top()
{
    if(isEmpty())
        cout<<"empty queue";
    else return front->data;
}
void print()
{
    node* temp=front;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
     front=NULL;
     rear=NULL;
     int n=0,x=0;
     cout<<"Enter the number of elements you want to add :-"<<endl;
     cin>>n;
     for(int i=0;i<n;i++)
     {
         cout<<"Enter the element :"<<endl;
         cin>>x;
         push(x);
         cout<<"Linked list after inserting element is :-"<<endl;
         print();
     }
     cout<<isEmpty()<<endl;
     pop();
     print();
}
