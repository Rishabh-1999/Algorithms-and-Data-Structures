#include <iostream>
#include <string> 
#include <vector> 
#include <algorithm>

using namespace std;

int myCompare(string f,string s) {
	string fs=f.append(s);
	string sf=s.append(f);
	
	return fs.compare(sf) > 0?1:0;
}

void printLongest(vector<string> arr) {

	sort(arr.begin(),arr.end(),myCompare);
	
	for(int i=0;i<arr.size();i++)
		cout<<arr[i];
}

int main() {
	vector<string> arr;
	arr.push_back("54"); 
    arr.push_back("546"); 
    arr.push_back("548"); 
    arr.push_back("60"); 
	printLongest(arr);
	return 0;
}
