#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node* next;
};
node* head;
int main()
{
     head=NULL;
     //INSERTING TWO ELEMENTS
     node* t1=(node*)malloc(sizeof(node));
     head=t1;
     t1->data=20;
     t1->next=NULL;
     node* t2=(node*)malloc(sizeof(node));
     t1->next=t2;
     t2->data=40;
     t2->next=NULL;

     //PRINTING ELEMENTS OF LINKED LIST
     node* temp=head;
     while(temp!=NULL)
     {
         cout<<temp->data<<endl;
         temp=temp->next;
     }
}
