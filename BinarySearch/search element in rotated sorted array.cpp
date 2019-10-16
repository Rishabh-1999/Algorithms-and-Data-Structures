#include<iostream>
#include<cmath>
using namespace std;
int serach(int ar[],int s,int e,int k)
{
    int mid;
    while(s<=e)
    {
        mid=ceil((s+e)/2.0);
        if(ar[mid]==k)
            return 1;
        else if(ar[e]>k&&ar[mid]<k)
            s=mid+1;
        else
            e=mid-1;
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
    int k;
    cin>>k;
    if(serach(ar,0,n-1,k))
        cout<<"found";
    else
        cout<<"Not found";
}
