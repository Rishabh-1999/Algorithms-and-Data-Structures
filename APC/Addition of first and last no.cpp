#include <stdio.h>
int sum(int n,int i)
{
	int k=n%10;
	if(i==1)
	{
		return (k+sum(n/10,--i));
	}
	else if(n<10)
	{
		return k;
	}
	else
	{
		return sum(n/10,i);
	}
}
int main()
{
	int n;
	printf("Enter the No : ");
	scanf("%d",&n);
	printf("Addition is %d",sum(n,1));
	return 0;
}
