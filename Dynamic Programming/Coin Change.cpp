#include <iostream>
#include <string.h>
using namespace std;

int max(int a,int b) { return (a>b?a:b); }

int solvebyrecursion( int S[], int m, int n ) 
{ 
    if (n == 0) 
        return 1; 

    if (n < 0) 
        return 0; 
   
    if (m <=0 && n >= 1) 
        return 0; 

    return solvebyrecursion( S, m - 1, n ) + solvebyrecursion( S, m, n-S[m-1] ); 
} 

int solvebyloop( int S[], int m, int n )  
{
    int table[m+1][n+1];  
     
    memset(table, 0, sizeof(table));  
    
    for(int i=0;i<m;i++) 
   		table[0][i] = 1;
      
    for(int i=1;i<=m;i++) 
    {     
        for(int j=1;j<=n;j++) 
        {
            if(S[i-1] > j)
                table[i][j] = table[i-1][j];
            else
                table[i][j] = table[i-1][j]+table[i][j-(i-1)];   
        }
    }
    return table[m][n];  
}

int main()
{
	int i, j; 
    int arr[] = {1, 2, 3}; 
    int m = sizeof(arr)/sizeof(arr[0]); 
    printf("%d ", solvebyrecursion(arr, m, 4)); 
	printf("%d ", solvebyloop(arr, m, 4)); 
	return 0;	
}
