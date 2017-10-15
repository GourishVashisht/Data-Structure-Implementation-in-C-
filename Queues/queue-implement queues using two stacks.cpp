#include<iostream>
#include<stack>
using namespace std;
void enqueue(stack<int> &s1,int v)
{
    s1.push(v);
}
int dequeue(stack<int> &s1,stack<int> &s2)
{
    if(s1.empty() && s2.empty())
        return -1;
    if(s2.empty())
    {
        while(!s1.empty())
        {
            int r=s1.top();
            s1.pop();
            s2.push(r);
        }
    }
    int res=s2.top();
    s2.pop();
    return res;
}
int main()
{
    stack<int> s1,s2;
    for(int i=1;i<=5;i++)
        enqueue(s1,i);
    cout<<"Dequeue first element : ";
    int res=dequeue(s1,s2);
    cout<<"\nThe element dequeued is "<<res<<endl;
    cout<<"An element is enqueued which is 6 \n";
    enqueue(s1,6);
    cout<<"Dequeue second element : ";
    res=dequeue(s1,s2);
    cout<<"\nThe element dequeued is "<<res;
}
