#include<iostream>
#include<stack>
#include<string.h>
#include<stdio.h>
using namespace std;
void reversestring(char c[],int n)
{
    stack<char> s;
    for(int i=0;i<n;i++)
        s.push(c[i]);
    for(int i=0;i<n;i++)
    {
        c[i]=s.top();
        s.pop();
    }
}
int main()
{
    char s[100];
    cout<<"entre string :";
    gets(s);
    cout<<"The string before reversal : "<<s;
    reversestring(s,strlen(s));
    cout<<"\n\nThe string after reversal : "<<s;
}

