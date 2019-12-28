#include<iostream>
using namespace std;
int power(int a,int b)
{
	if(b!=0)
	{
		return (a*power(a,b-1));
	}
	else
		return 1;
}

int main()
{
	int a,b;
	cout<<"Enter base : ";
	cin>>a;
	cout<<"Enter power : ";
	cin>>b;
	cout<<power(a,b);
	return 0;
}
