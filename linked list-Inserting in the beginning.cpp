#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node* link;
};
node* head;

void insert_element(int x)
{
      node* temp=(node*)malloc(sizeof(node));
      temp->data=x;
      temp->link=head;
      head=temp;
}

void print()
{
    node* temp1=head;
    while(temp1!=NULL)
    {
        cout<<temp1->data<<" ";
        temp1=temp1->link;
    }
    cout<<endl;
}
int main()
{
     head=NULL;
     int n=0,x=0;
     cout<<"Enter the number of elements you want to add :-"<<endl;
     cin>>n;
     for(int i=0;i<n;i++)
     {
         cout<<"Enter the element :"<<endl;
         cin>>x;
         insert_element(x);
         cout<<"Linked list after inserting element is :-"<<endl;
         print();
     }
}
