#include <iostream>
#include <string.h>
using namespace std;

int max(int a,int b)
{
	return (a>b?a:b);
}

int solvebyrecursion( int S[], int m, int n ) 
{ 
    // If n is 0 then there is 1 solution  
    // (do not include any coin) 
    if (n == 0) 
        return 1; 
      
    // If n is less than 0 then no  
    // solution exists 
    if (n < 0) 
        return 0; 
  
    // If there are no coins and n  
    // is greater than 0, then no 
    // solution exist 
    if (m <=0 && n >= 1) 
        return 0; 
  
    // count is sum of solutions (i)  
    // including S[m-1] (ii) excluding S[m-1] 
    return solvebyrecursion( S, m - 1, n ) + solvebyrecursion( S, m, n-S[m-1] ); 
} 

int solvebyloop( int S[], int m, int n )  
{  
     //we need a two dimensional matrix to store the result 
    int table[m+1][n+1];  
    
    // Initialize all table values as 0  
    memset(table, 0, sizeof(table));  
    
    // Base case (If given value is 0)  
    for(int i=0;i<m;i++) 
   {table[0][i] = 1;  
   } 
      
    for(int i=1;i<=m;i++) 
      { 
            
          for(int j=1;j<=n;j++) 
          { 
              if(S[i-1]>j) 
              { 
                  table[i][j]=table[i-1][j]; 
                    
              } 
                
              else
              { 
                  table[i][j]=table[i-1][j]+table[i][j-(i-1)]; 
              } 
                
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
