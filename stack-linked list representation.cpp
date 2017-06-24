#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node
{
    int value;
    node* next;
};

node* top;

void push(int val)
{
    node* temp=new node();
    temp->value=val;
    temp->next=top;
    top=temp;
}

void pop()
{
    node* temp;
    if(top==NULL)
        cout<<"SORRY ! Stack is already empty.\n";
    else
    {
        temp=top;
        top=top->next;
        free(temp);
    }
}

void isempty()
{
    if(top==NULL)
        cout<<"Stack is empty.\n";
    else
        cout<<"Stack is not empty.\n";
}

node* topvalue()
{
    return top;
}

void print()
{
    struct node* temp1=top;
    while(temp1!=NULL)
    {
        cout<<temp1->value<<" ";
        temp1=temp1->next;
    }
}

int main()
{
    top=NULL;
    int n;
    cout<<"Enter the number of values you want to enter : ";
    cin>>n;
    int t;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the value : ";
        cin>>t;
        push(t);
        print();
        cout<<endl;
    }
    int z;
    cout<<"Enter the number of values you want to delete from stack : ";
    cin>>z;
    for(int i=0;i<z;i++)
    {
        pop();
        cout<<"Stack after "<<i+1<<" pop :";
        print();
        cout<<endl;
    }
    node* te=topvalue();
    cout<<"\nThe value of top is : "<<te->value;
    cout<<"\n\nStack is empty or not ?\n";
    isempty();
}

