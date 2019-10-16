#include<iostream>
#include<stack>
using namespace std;
bool tags(string str)
{
    for(int i=0;i<str.length();i++)
 {   stack<int>st;
     if(str[i]=='<'&&str[i+1]!='/')
     {
         string tag;
         while(str[i]!='>' && i<str.length())
         {
             tag+=str[i++];
         }
         tag+=str[i];
         st.push(tag);
     }
     else if(str[i]=='<'&&str[i+1]=='/')
     {
         string tag;
         while(str[i]!='>' && i<str.length())
         {
             tag+=str[i++];
         }
         tag+=str[i];
         tag.erase(remove(tag.begin(),tag.end(),'/'),tag.end());
         if(tag.compare(st.top())==0)
            tag.pop();
         else
            return false;
     }

 }
if(st.empty())
    return true;
else
    return false;
}
int main()
{
 string str;
 getline(cin,str);
 if(tags(str))
    cout<<"Valid";
 else
    cout<<"Invalid";
}
