#include<iostream>
using namespace std;
int find(int ar[],int s,int e,int d)
{
    while(s<=e)
    {
        int m=(s+e)/2;
        if(ar[m]==d)
            return 1;
        else if(ar[m]>d)
            e=m-1;
        else
            s=m+1;
    }
    return 0;
}
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    int d;
    cin>>d;
    cout<<find(ar,0,n-1,d);
    return 0;
}
