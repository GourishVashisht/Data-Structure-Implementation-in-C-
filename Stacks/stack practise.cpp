#include<iostream>
#include"Stack.h"
using namespace std;
void print(Stack<int> ob)
{
    while(!ob.isEmpty())
    {
        cout<<ob.top()<<" ";
        ob.pop();
    }
    cout<<endl;
}
int main()
{
    Stack<int> ob;
    for(int i=1;i<=10;i++)
        ob.push(i*i);
    print(ob);
    cout<<"The top of the stack contains : "<<ob.top();
    ob.pop();
    cout<<endl;
    cout<<"Is the stack empty : "<<ob.isEmpty()<<endl;;
    cout<<"Stack after popping one value is : \n";
    print(ob);
    return 0;
}
