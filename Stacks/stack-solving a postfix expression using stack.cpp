#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int perform(char ,int ,int );
bool isDigit(char c)
{
    if(c>='0'&&c<='9')
        return true;
    else false;
}
bool isOperator(char c)
{
    if(c=='+' ||c=='-' ||c=='*' ||c=='/' ||c=='%')
        return true;
    else return false;
}
int main()
{
    string str;

    cout<<"Enter the postfix expression for evaluation : ";
    getline(cin,str);
    stack<int> s;
    int i=0,x,y,ans,res=0;
    for(i=0;i<str.length();i++)
    {
        if(str[i]==' ')
            {continue;}
        else if(isOperator(str[i]))
        {
            int y=s.top();
            s.pop();
            int x=s.top();
            s.pop();
            ans=perform(str[i],x,y);
            s.push(ans);
        }
        else if(isDigit(str[i]))
        {
            res=0;
            while(i<str.length() && isdigit(str[i]))
            {
                res=(res*10)+(str[i]-'0');
                i++;
            }
            ///i--; /// when last time i got plussed so we need to revert back
            s.push(res);
        }
    }
    cout<<"\nThe answer of the expression is :"<<s.top();
}
int perform(char c,int x,int y)
{
    if(c=='+')
        return x+y;
    else if(c=='-')
        return x-y;
    else if(c=='*')
        return x*y;
    else if(c=='/')
        return x/y;
    else if(c=='%')
        return x%y;
}

