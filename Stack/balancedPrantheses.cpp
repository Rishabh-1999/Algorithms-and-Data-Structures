#include<iostream>
#include<string>
#include<stack>
using namespace std;

int checkBalanced(string s)
{
	stack<int> s1,s2;
	for(int i=0;i<s.length();i++)
	{
		if(s[i] == '{')
			s1.push(i+1);
		else if(s[i] == '(')
			s2.push(i+1);
		else if(s[i] == '}')
		{
			if(s1.empty())
				return i;
			else
				s1.pop();
		}
		else if(s[i] == ')')
		{
			if(s2.empty())
				return i;
			else
				s2.pop();
		}
		else{}
	}
	if(!s1.empty())
		return s1.top();
	else if(!s2.empty())
		return s2.top();
	else
		return -1;
}

int main()
{
	string s;
	cout<<"Enter String :";
	cin>>s; 
	cout<<checkBalanced(s)<<"\n";
	// if balanced return -1 else return unbalanced position
}