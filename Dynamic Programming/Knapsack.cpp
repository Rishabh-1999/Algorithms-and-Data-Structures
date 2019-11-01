#include <iostream>

using namespace std;

int max(int a,int b)
{
	return (a>b?a:b);
}

int solveknapsack(int p[],int w[],int c,int n)
{
	if(n==0 || c==0)
		return 00;
		
	if( w[n-1] > c )
		return 	solveknapsack(p,w,c,n-1);
		
		
	return max(solveknapsack(p,w,c-w[n-1],n-1)+p[n-1],solveknapsack(p,w,c,n-1));
}

int main()
{
	
	int p[]={60, 100, 120};
	int w[]={10, 20, 30};
	int c=50;
	int n=3;
	printf("%d",solveknapsack(p,w,c,n));
	return 0;
}
