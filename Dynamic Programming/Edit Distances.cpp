#include <iostream>
#include <string.h>
#include<bits/stdc++.h>
using namespace std;

int min(int x, int y, int z) { return min(min(x, y), z); }

int cutRodByRecursion(char str1[],char str2[],int n,int m)
{
	if(n==0)
		return m;
	
	if(m==0)
		return n;
		
	if(str1[n-1]==str2[m-1])
		return cutRodByRecursion(str1,str2,n-1,m-1);
	
	return 1 + min(cutRodByRecursion(str1,str2,n-1,m-1),cutRodByRecursion(str1,str2,n-1,m),cutRodByRecursion(str1,str2,n,m-1));
}


int cutRodByMatrix(char str1[],char str2[],int n,int m)
{
	int arr[n+1][m+1]={0};
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0)
				arr[i][j]=j;
			else if(j==0)
				arr[i][j]= i;
			else if(str1[i-1]==str2[j-1])
				arr[i][j]=arr[i-1][j-1];
			else
				arr[i][j]=1+min(arr[i-1][j-1],arr[i-1][j],arr[i][j-1]);
		}
	}
	return arr[n][m];
}

int main()
{
	char str1[]="sunday";
	char str2[]="saturday";
	printf("%d \n",cutRodByRecursion(str1,str2,strlen(str1),strlen(str2)));
	printf("%d",cutRodByMatrix(str1,str2,strlen(str1),strlen(str2)));
	return 0;
}
