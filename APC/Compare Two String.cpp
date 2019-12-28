#include<stdio.h>
#include<string.h>
void removeExtraSpaces(char s[])
{
	int i=0,j=0,flag=0;
	while(s[i]!='\0')
	{
		if(s[i]==' ')
		{
			if(flag==1)
			{
				s[j]=s[i+1];
			}
			flag=0;
		}
		else
		{
			flag=1;
			s[j++]=s[i];
		}
		i++;
	}
	s[j]='\0';
}
int  compare(char str1[],char str2[])
{
	int i=0;
	while(str1[i]!='\0' && str2[i]!='\0')
	{
		if(str1[i]!=str2[i])
		{
			return 0;
		}
		i++;
	}
	if(str1[i]=='\0' && str2[i]=='\0')
		return 1;
	else
		return 0;
}
int main()
{
	char str1[50],str2[50];
	printf("Enter Your First String : ");
	scanf("%[^\n]s",str1);
	getchar();
	printf("Enter Your Second String : ");
	scanf("%[^\n]s",str2);
	removeExtraSpaces(str1);
	removeExtraSpaces(str2);
	int flag=compare(str1,str2);
	if(flag)
		printf("Two String are Same/Equal");
	else
		printf("Two String are Not Same/Equal");
	return 0;
}
