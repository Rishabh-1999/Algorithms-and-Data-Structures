#include<bits/stdc++.h> 
using namespace std; 
int maxConsecutiveOnes(int x) 
{ 
    // Initialize result 
    int count = 0; 
  
    // Count the number of iterations to 
    // reach x = 0. 
    while (x!=0) 
    { 
        // This operation reduces length 
        // of every sequence of 1s by one. 
        x = (x & (x << 1)); 
  
        count++; 
    } 
  
    return count; 
} 
  
// Driver code 
int main() 
{ 
    cout << maxConsecutiveOnes(14) << endl; 
    cout << maxConsecutiveOnes(222) << endl; 
    return 0; 
} 
