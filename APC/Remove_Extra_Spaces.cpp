#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	getline(cin,str);
	int start=0,end=0,i=0,j=0,flag=0;
	while(str[i]!='\0')
	{
		if(str[i]==' ' || i==0)
		{
			if(flag==1)
			{
				
				while(i>end)
				{
				str[start++]=str[end];
				str[end]=' ';
				end++;
				flag=0;
				}
				start++;
			}
		}
		else
		{
				if(flag==0)
				{
				end=i;
				}
			flag=true;
		}
		i++;

	}
	while(i>end)
				{
				str[start++]=str[end];
				str[end]=' ';
				end++;
				}
str[start]='\0';
	cout<<str;
return 0;
}
