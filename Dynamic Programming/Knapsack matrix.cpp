#include <iostream>

using namespace std;

int max(int a,int b)
{
	return (a>b?a:b);
}

int solveknapsack(int p[],int w[],int c,int n)
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
	
	int p[]={10,12,28};
	int w[]={1,2,4};
	int c=6;
	int n=3;
	printf("%d",solveknapsack(p,w,c,n));
	return 0;
}
