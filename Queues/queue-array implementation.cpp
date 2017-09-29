#include<iostream>
//#define n 10
using namespace std;
int front=-1;
int rear=-1;
int arr[100];
int n=10;
bool full()
{
    if(front==(rear+1)%n)
        return true;
    else return false;
}

bool Isempty()
{
    if((front==-1 &&rear==-1)&&((rear+1)%n!=front))
            return true;
    else return false;
}

void push(int x)
{
    if(full())
        cout<<"SORRY!the queue is already full.\n";
    else if(Isempty())
        front=rear=0;
    else rear=(rear+1)%n;
    arr[rear]=x;
}

void pop()
{
    if(Isempty())
    {
        cout<<"SORRY ! List is empty.\n";
        return;;
    }
    else if(front==rear)
        front=rear=-1;
    else
    {
        front=(front+1)%n;
    }
}

int top()
{
    if(!Isempty())
    return arr[front];
    else
        cout<<"List is empty\n";
}

void print()
{
    for(int i=front;i<=rear;)
    {
        cout<<arr[i]<<" ";
        i=(i+1)%n;
        if(i==front)
            break;
    }
}

int main()
{
    int t,el;
    cout<<"Enter the no.of elements you want to enter : ";
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Enter the element : ";
        cin>>el;
        push(el);
        //n=(rear-front+n)%n;
    }
    n=(rear-front+n)%n+1;
    print();
    cout<<endl;
    pop();  n=(rear-front+n)%n+1; print();
    cout<<endl;
    pop(); n=(rear-front+n)%n+1;  print();
    cout<<"\nThe top element is : "<<top()<<endl;
    cout<<"Queue is empty : "<<Isempty();
    cout<<"\nQueue is full : "<<full();
    return 0;
}
