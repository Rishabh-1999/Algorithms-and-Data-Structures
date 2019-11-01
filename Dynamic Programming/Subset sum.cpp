#include <iostream>

using namespace std;

int solvesubsetsum(int arr[],int sum,int n)
{
	if(sum==0)
		return 1;
	if(n==0 && sum!=0)
		return 0;
		
	if(arr[n-1] > sum)
		return solvesubsetsum(arr,sum,n-1);
	else
		return (solvesubsetsum(arr,sum-arr[n-1],n-1) || solvesubsetsum(arr,sum,n-1));
}

int main()
{
	int arr[]={6,2,4,1};
	int sum=5;
	int n=4;
	printf("%d",solvesubsetsum(arr,sum,n));
	return 0;
}
