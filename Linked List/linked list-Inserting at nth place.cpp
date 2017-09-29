#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node* link;
};
node* head;
void insert(int el,int pos)
{
    node* temp=new node();
    temp->data=el;
    temp->link=NULL;
    if(pos==1)
    {
        temp->link=head;
        head=temp;
    }
    else
    {
    node* temp1=head;
    for(int i=0;i<pos-2;i++)
    {
        temp1=temp1->link;
    }
    temp->link=temp1->link;
    temp1->link=temp;
    }
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
int main()
{
    head=NULL;
    int n=0;
    cout<<"Enter the number of elements you want to add:-\n";
    cin>>n;
    int el,pos;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the element:-\n";
        cin>>el;
        cout<<"Enter its position:\n";
        cin>>pos;
        insert(el,pos);
        cout<<"Linked list after inserting the elements is:-\n";
        print();
        cout<<endl;
    }
}
