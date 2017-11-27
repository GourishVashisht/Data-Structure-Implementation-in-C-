#include<iostream>
#include<stack>
#include<sstream>
using namespace std;
bool match(char a,char b)
{

    if(a=='{' && b=='}')
        return true;
    else if(a=='[' && b==']')
        return true;
    else if(a=='(' && b==')')
        return true;
    else return false;
}

int main()
{
    string str;
    getline(cin,str);
    int i=0;
    stack<pair<char,int> > s;
    while(str[i]!='\0')
    {
        if(str[i]=='(' || str[i]=='[' || str[i]=='{')
        {
            s.push(make_pair(str[i],i));
        }
        else if(str[i]==')' || str[i]==']' || str[i]=='}')
        {
            if(s.empty())
                str[i]='2';
            else if(match(s.top().first,str[i]))
            {
                str[i]='1';
                str[s.top().second]='0';
                s.pop();
            }
            else{
                str[i]='2';
                str[s.top().second]='2';
                s.pop();
            }
        }
        i++;
    }
    if(!s.empty())
    {
        while(!s.empty())
        {
            str[s.top().second]='2';
            s.pop();
        }
    }

    i=0;
    string t="";
    while(str[i]!='\0')
    {
        if(str[i]=='2')
        {
            t=t+"-1";
        }
        else{
            string temp="";
            stringstream ss;
            ss<<str[i];
            ss>>temp;
            t=t+temp;
        }
        i++;
    }
    cout<<t<<endl;
    return 0;
}
