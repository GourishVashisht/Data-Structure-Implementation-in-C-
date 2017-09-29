#include<iostream>
using namespace std;
int arr[100];
int top=-1;

void push(int x)
{
    top=top+1;
    arr[top]=x;
}

void pop()
{
    top=top-1;
}

string isempty()
{
    if(top==-1)
        return "Stack is empty.\n";
    else return "Stack is not empty.\n";
}

int topele()
{
    return arr[top];
}

void print()
{
    for(int i=0;i<=top;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n,b,j;
    cout<<"Enter no. of values you want to add in stack :";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"enter value :";
        cin>>b;
        push(b);
        cout<<"stack becomes :";
        print();
    }
    cout<<"Enter no. of elements you want to pop :";
    cin>>j;
    for(int i=0;i<j;i++)
    {
        pop();
        cout<<"stack after "<<i+1<<" pop :";
        print();
    }
    cout<<isempty();
    cout<<"top element is "<<topele();
}
