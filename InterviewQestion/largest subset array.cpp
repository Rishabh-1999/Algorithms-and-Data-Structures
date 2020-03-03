#include <iostream>

using namespace std;

void method1(int a[],int n,int sum) {
	int max=-35544,in_index=0,en_index=0;
	for(int i=0;i<n;i++) {
		int sum=0;
		for(int j=i+1;j<n;j++) {
			sum+=a[j];
		if(sum>max)	{
			max=sum;
			in_index=i+1;
			en_index=j;
			cout<<in_index<<" "<<en_index<<endl;
		}
		}
	}
	cout<<max;
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
