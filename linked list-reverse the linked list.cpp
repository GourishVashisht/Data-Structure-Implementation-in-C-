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
    node* temp3=head;
    while(temp3!=NULL)
    {
        cout<<temp3->data<<" ";
        temp3=temp3->next;
    }
    cout<<endl;
}

void reverseList()
{
    node* current=head,* prev=NULL,* nextnode;
    while(current!=NULL)
    {
        nextnode=current->next;
        current->next=prev;
        prev=current;
        current=nextnode;
    }
    head=prev;
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

    reverseList();

    print();
}
