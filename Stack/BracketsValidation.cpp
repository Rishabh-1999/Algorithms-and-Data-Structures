#include<iostream>
#include<stack>
using namespace std;
int balancedString(string s)
{
  int  i;
  stack<char>v;
  int loc;
  for(i=0;s[i]!='\0';i++)
    {
    if(s[i]=='{'||s[i]=='('||s[i]=='[')
         v.push(s[i]);
    else if(s[i]=='}')
      {
      if(v.empty())
        return i;
      char x=v.top();
        v.pop();
       if(x=='('||x=='[')
        return i;
      }
    else if(s[i]==')')
      {
      if(v.empty())
        return i;
      char x=v.top();
      v.pop();
       if(x=='{'||x=='[')
        return i;
      }
    else if(s[i]==']')
      {
      if(v.empty())
        return i;
      char x=v.top();
      v.pop();
      if(x=='('||x=='{')
        return i;
      }
}
if(v.empty())
  return -1;
  else
    return i;
  }
int main()
{

    string str;
    cin>>str;
    cout<<balancedString(str);

}


