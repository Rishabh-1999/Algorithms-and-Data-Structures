#include <iostream>
#include <Math.h>
#include <bits/stdc++.h> 
using namespace std;
void permute(char a[], int l, int r)  
{  
    // Base case  
    if (l == r)  {
        if( atoi(a) %8==0 )
			cout<<a<<endl;
	}  
    else
    {  
        // Permutations made  
        for (int i = l; i <= r; i++)  
        {  
  
            // Swapping done  
            swap(a[l], a[i]);  
  
            // Recursion called  
            permute(a, l+1, r);  
  
            //backtrack  
            swap(a[l], a[i]);  
        }  
    }  
} 

int main()
{
	char c[] = "231";  
    int n = 3;  
    permute(c, 0, 2);  
}
