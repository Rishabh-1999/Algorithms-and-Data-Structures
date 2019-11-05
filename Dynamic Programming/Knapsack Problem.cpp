#include <iostream>

using namespace std;

int max(int a,int b)
{
	return (a>b?a:b);
}

int solveknapsack(int p[],int w[],int c,int n)
{
	if(n==0 || c==0)
		return 0;
		
	if( w[n-1] > c )
		return 	solveknapsack(p,w,c,n-1);
				
	return max(solveknapsack(p,w,c-w[n-1],n-1)+p[n-1],solveknapsack(p,w,c,n-1));
}

int solveknapsackbymatrix(int p[],int w[],int c,int n)
{
	int arr[n+1][c+1]={0};
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=c;j++)
		{
			if(i==0 || j==0)
				arr[i][j]=0;
			else if(w[i-1] <= j)
				arr[i][j]=max(arr[i-1][j-w[i-1]]+p[i-1],arr[i-1][j]);
			else
				arr[i][j]=arr[i-1][j];
		}
	}
	return arr[n][c];
}

int main()
{
	int p[]={60, 100, 120};
	int w[]={10, 20, 30};
	int c=50;
	int n=3;
	printf("%d \n",solveknapsack(p,w,c,n));
	printf("%d \n",solveknapsackbymatrix(p,w,c,n));
	return 0;
}
