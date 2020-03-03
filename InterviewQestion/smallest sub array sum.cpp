#include <iostream>

using namespace std;

void method1(int a[],int n,int real_sum) {
	
	int minn=36544;
	
	for(int i=0;i<n;i++) {
		int sum=0;
		for(int j=i+1;j<n;j++) {
			sum+=a[i];
			if(sum>real_sum) {
				cout<<i<<" "<<j<<endl;
				minn=min(minn,j-i);
			}
		}
	}
	cout<<minn;
}

int main() {
	
	int n,sum;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	cin>>sum;
	method1(a,n,sum);
	
	return 0;
}
