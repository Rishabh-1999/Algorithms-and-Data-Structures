#include <stdio.h>
#include <string>
#include <stdlib.h>
char* resize(char str[],int n)
{
	char *newstr=(char*)malloc(sizeof(char)*(n+1));
	int i;
	while(str[i]!='\0')
	{
		newstr[i]=str[i];
		i++;
	}
	newstr[i]='\0';
	return newstr;
}
void makeShortCut(char str[])
{
	char cc=str[0];
	int i=0,index=0,j=0;
	bool flag=true;
	while(str[i]!='\0')
	{
		if(str[i]==' ')
		{
			if(flag==true)
			flag=false;
		}
		else
		{
			if(flag==false)
			{
				flag=true;
				index=i;
				str[j++]=cc;
				str[j++]='.';
				cc=str[i];
			}
		}
		i++;
	}
	str[j++]=' ';
	while(str[index]!='\0')
	{
		str[j++]=str[index++];
	}
	str[j++]='\0';
	printf("%s",resize(str,j));
}
int main()
{
	char str[50];
	printf("Enter the String :");
	scanf("%[^\n]",&str);
	makeShortCut(str);
	return 0;
}
