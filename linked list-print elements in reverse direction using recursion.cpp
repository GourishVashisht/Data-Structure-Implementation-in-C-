#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};
node* head;
void insert(int x)
{
      node* temp=new node();
      temp->data=x;
      temp->next=head;
      head=temp;
}
void print()
{
    node* temp1=head;
    while(temp1!=NULL)
    {
        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
    cout<<endl;
}

void printReverse(node* temp)
{
    if(temp==NULL)
        return;
    printReverse(temp->next);
    cout<<temp->data<<" ";
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
    printReverse(head);
}

