#include <iostream>
#include <string.h>
using namespace std;

int max(int a,int b)
{
	return (a>b?a:b);
}

int solvelcs(char s1[],char s2[],int n1,int n2)
{
	if(n1==0 || n2==0)
		return 0;
	else if(s1[n1]==s2[n2])
		return 1+solvelcs(s1,s2,n1-1,n2-1);
	else	
		return max(solvelcs(s1,s2,n1-1,n2),solvelcs(s1,s2,n1,n2-1));
}

int solvelcsmatrix(char s1[],char s2[],int n1,int n2)
{
	int arr[n1+1][n2+1]={0};
	for(int i=0;i<=n1;i++)
	{
		for(int j=0;j<=n2;j++)
		{
			if(i==0 || j==0)
				arr[i][j]=0;
			else if(s1[i-1]==s2[j-1])
				arr[i][j]= 1+arr[i-1][j-1];
			else	
				arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
		}
	}
		return arr[n1][n2];
}

int main()
{
	char s1[]="AGGTAB";
	char s2[]="GXTXAYB";
	printf("Longest Common Sub-Sequence is %d",solvelcs(s1,s2,strlen(s1),strlen(s2)));
	printf("Longest Common Sub-Sequence is %d",solvelcsmatrix(s1,s2,strlen(s1),strlen(s2)));
	return 0;	
}
