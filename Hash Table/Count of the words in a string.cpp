#include <iostream>
using namespace std;
int noofword(char *str)
{
	int hash[256]={0};
	int i=0,c=0;
	while(str[i]!='\0') {
		hash[str[i]]+=1;
		if(hash[str[i]]==1)
		c++;
		i++;
	}
	return c;
}
int main()
{
	char a[]="rishabh";
	cout<<"No of unqine words in a string are "<<noofword(a);
}
