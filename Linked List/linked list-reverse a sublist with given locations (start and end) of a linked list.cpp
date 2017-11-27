#include<iostream>
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
int len()
{
    node* t=head;
    int c=0;
    while(t!=NULL)
    {
        c++;
        t=t->next;
    }
    return c;
}

void reverseSublist(int a,int b)
{
    if(a<1 || b>len())
    {
        cout<<"The locations are not correct.";
        return;
    }
    if(a==b)
        return;

    /// start_prev will hold the previous address of the first element of the sublist
    /// starting will store the address of first element of sublist

    node* start_prev=NULL;
    node* starting=head;
    for(int i=1;i<a;i++)
    {
        start_prev=starting;
        starting=starting->next;
    }

    /// ending will store the address of the last element of sublist
    node* ending=head;
    for(int j=1;j<=b;j++)
    {
        ending=ending->next;
    }

    /// process for sublist reversal
    node* curr;
    if(start_prev)
        curr=starting;
    else curr=head;
    node* temp=curr;
    node* prev=NULL;
    node* nxt;
    for(int k=1;k<=b-a+1;k++)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    if(a==1)
        head=prev;
    else start_prev->next=prev;

    temp->next=ending;
}
int main()
{
  head=NULL;
  for(int i=1;i<=10;i++)
    insert(i);
  cout<<"The linked list is : ";
  print();
  cout<<endl;

  int a,b;
  cout<<"Enter the starting and ending locations of the sub list : ";
  cin>>a>>b;
  reverseSublist(a,b);
  cout<<"The linked list after reversing the sublist becomes : ";
  print();
  return 0;
}

