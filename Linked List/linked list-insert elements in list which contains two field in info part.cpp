#include<iostream>
using namespace std;
struct node
{
    int rollNo;
    string name;
    node* next;
};
node* head;
void insertAtBeginning(int r,string n)
{
    node* t=new node();
    t->rollNo=r;
    t->name=n;
    t->next=head;
    head=t;
}
void print()
{
    node* t=head;
    while(t!=NULL)
        {cout<<t->rollNo<<" "<<t->name<<" ";
         t=t->next;}
}
int main()
{
    head=NULL;
    int n;
    cout<<"Enter the number of elements you want to enter :";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int r;
        string n;
        cout<<"\nenter roll no and name :";
        cin>>r>>n;
        insertAtBeginning(r,n);
        cout<<"Your linked list now is :";
        print();
        cout<<endl;
    }
    return 0;
}

