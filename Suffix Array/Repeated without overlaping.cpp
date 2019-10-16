#include <iostream>
#include <cstdlib>
using namespace std;

int longestRepeatedString(string str)
{
	int n=str.length();
	int arr[n+1][n+1];
	
	memset(str,0,sizeof(arr));
}

int main()
{

	string a="banana";
	
	cout<<longestRepeatedString(a); 
	    
	return 0;
}
