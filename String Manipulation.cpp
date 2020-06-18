#include <iostream>
#include <string.h>

using namespace std;

int check(char c) {
	if((c>=65 && c<=90) || (c>=95 && c<=120))
		return 1;
	else
		return 0;
}

int main() {
	
	string str;
	cin>>str;
	
	int start=0,end=str.length();
	while(start<end) {
		while(!check(str[start]) && start<end )
			start++;
		
		while(!check(str[end])  && start<end)
			end--;
				
		if(start>=end)
		break;
		
		char c;
		c=str[start];
		str[start++]=str[end];
		str[end--]=c;
	}	
	cout<<str;
	return 0;
}
