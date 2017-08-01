#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};
void add(node* &head,int data)
{
    node* t=new node();
    t->data=data;
    t->next=head;
    head=t;
}
void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
void operator<<(ostream &os,node* head)
{
    print(head);
}
/// mid point
/// take two ptrs one slow and one fast
/// fast moves twice distance then slow
int mid(node* head)
{
    node* slow=head;
    node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    int ans=slow->data;
    return ans;
}
int main()
{
    node* head=NULL;
    for(int i=1;i<=10;i++)
        add(head,i);
    cout<<"linked list is : ";
    cout<<head;
    cout<<endl;

    cout<<"Mid point of the linked list is : "<<mid(head);
    return 0;
}
