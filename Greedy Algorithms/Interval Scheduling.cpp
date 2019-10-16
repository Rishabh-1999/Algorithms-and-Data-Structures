#include<iostream>
#include<algorithm>
using namespace std;
struct Interval
{
    int s;
    int e;
};
bool compare(struct Interval a,struct Interval b)
{
    return (a.e<b.e);
}
int main()
{
    int n;
    cin>>n;
    struct Interval arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i].s>>arr[i].e;
    sort(arr,arr+n,compare);
    int c=1,i=arr[0].e,j=1;
    while(j<n)
    {
        if(arr[j].s>=i)
        {
            i=arr[j].e;
            c++;
        }
        j++;
    }
    cout<<c;
}
