#include<iostream>
#include<stack>
#include<cstring>
#include<cmath>
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
using namespace std;
int main()
{
    string str;
    cout<<"Enter the prefix expression for evaluation : ";
    getline(cin,str);
    stack<int> s;
    int i,x,y,ans,res=0,arr[100];
    for(i=str.length()-1;i>=0;i--)
    {
        if(str[i]==',' || str[i]==' ')
            continue;
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
            int j=0;
            while(i>=0 && isdigit(str[i]))
            {
                res=res+(str[i]-'0')*pow(10,j);
                j++;
                i--;
            }
            s.push(res);
            cout<<s.top()<<endl;
        }
    }
    cout<<"The answer of the expression is :"<<s.top();
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


