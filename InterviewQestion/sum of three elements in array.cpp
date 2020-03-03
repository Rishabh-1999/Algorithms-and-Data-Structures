#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void method1(int a[],int n,int sum) {
	int in_index=0,end_index=n;

	if(n>2)
	for(int i=0;i<n-2;i++) {
		for(int j=i+1;j<n-1;j++) {
			for(int k=j+1;k<n;k++) {
				if((a[i]+a[j]+a[k])==sum) {
					cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
					return;
				}
			}
		}
	}
}

void method2(int a[],int n,int sum) {
	
	for(int i=0;i<n-2;i++) {
		
		set<int> s;
		int curr_sum=sum-a[i];
		for(int j=i+1;j<n;j++) {
			if(s.find(curr_sum - a[j])!=s.end()) {
				cout<<a[i]<<" "<<a[j]<<" "<<curr_sum-a[j];
			}
		s.insert(a[j]);
	}
}
}

int main(){
	
	int n,sum;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	cin>>sum;
	
	method1(a,n,sum);
	
	method2(a,n,sum);
	return 0;
}

