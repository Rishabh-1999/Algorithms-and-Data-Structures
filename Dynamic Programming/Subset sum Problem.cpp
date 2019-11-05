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

int solvesubsetsummatrix(int arr[],int sum,int n)
{
	int m[n+1][sum+1]={0};
	
	for(int i=0;i<=n;i++)
		m[i][0]=1;
		
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(arr[i-1] > j)
				m[i][j]=m[i-1][j];
			if(j >= arr[i-1])
				m[i][j]= m[i-1][j-arr[i-1]] || m[i-1][j];
		}
	}
	return m[n][sum];
}

int main()
{
	int arr[]={6,2,4,1};
	int sum=5;
	int n=4;
	printf("%d",solvesubsetsum(arr,sum,n));
	printf("%d",solvesubsetsummatrix(arr,sum,n));
	return 0;
}
