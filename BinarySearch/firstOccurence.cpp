#include<iostream>
#include<algorithm>
using namespace std;
int first(int ar[],int s,int e,int k)
{
    int pos=-1;
    while(s<=e)
    {
        int m=(s+e)/2;
        if(ar[m]==k)
        {
            pos=m;
            e=m-1;
        }
        else if(ar[m]<k)
        {
            s=m+1;
        }
        else
            e=m-1;
    }
    return pos;
}
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    int k;
    cin>>k;
    sort(ar,ar+n);
    cout<<first(ar,0,n-1,k);
}
