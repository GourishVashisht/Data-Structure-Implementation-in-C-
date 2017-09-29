#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node* link;
};
node* head;
void insert(int el)
{
    node* temp=new node();
    temp->data=el;
    temp->link=NULL;
    if(head==NULL)
    {
    head=temp;
    return;
    }
    node* temp1=head;
    while(temp1->link!=NULL)
        temp1=temp1->link;
    temp1->link=temp;
}

void print()
{
    node* temp3=head;
    while(temp3!=NULL)
    {
        cout<<temp3->data<<" ";
        temp3=temp3->link;
    }
}
void delete_node(int pos)
{
    node* temp2=head;
    if(pos==1)
    {
        head=temp2->link;
        free(temp2);
        return;
    }
    for(int i=0;i<pos-2;i++)
    {
        temp2=temp2->link;
    }
    node* temp4=temp2->link;
    temp2->link=temp4->link;
    free(temp4);
    }

int main()
{
    head=NULL;
    int n=0;
    cout<<"Enter the number of elements you want to add:-\n";
    cin>>n;
    int el;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the element:-\n";
        cin>>el;
        insert(el);
        cout<<"Linked list after inserting the elements is:-\n";
        print();
        cout<<endl;
    }
    int pos;
    cout<<"Enter the element position which you want to delete:-\n";
    cin>>pos;
    delete_node(pos);
    cout<<"Linked list after deleting the node at position "<<pos<<" is \n";
    print();
}

