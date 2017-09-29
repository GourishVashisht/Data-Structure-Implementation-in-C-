#include<iostream>
#include<stack>
using namespace std;
bool checkPair(char a,char b)
{

    if(a=='{' && b=='}')
        return true;
    else if(a=='[' && b==']')
        return true;
    else if(a=='(' && b==')')
        return true;
    else return false;
}
bool checkBalance(string s)
{
    int i=0;
    stack<char> st;
    while(s[i]!='\0')
    {
        if(s[i]=='{' ||s[i]=='[' ||s[i]=='(')
            st.push(s[i]);
        else if(s[i]=='}'|| s[i]==']' || s[i]==')')
        {
            if(st.empty() || checkPair(st.top(),s[i])==false)
                return false;
            else st.pop();
        }
        i++;
    }
    if(st.empty())
        return true;
}

int main()
{
    string s;
    getline(cin,s);
    if(checkBalance(s))
        cout<<"Yes the paranthesis are balanced.";
    else cout<<"No the parenthesisi are balanced.";
}
