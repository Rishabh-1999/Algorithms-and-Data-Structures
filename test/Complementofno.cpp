#include <iostream>
#include <Math.h>
using namespace std;
int main()
{
	int no=4;
	int sum=0,i=0;
	while(no!=0)
	{
		int temp=no&1;
		if(temp==0)
		{
			sum+=pow(2,i);
		}
		i++;
		no=(no>>1);
	}
	return sum;
}
