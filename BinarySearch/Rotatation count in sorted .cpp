#include<iostream>

using namespace std;

int rotation(int ar[],int n)
{
    int min1=ar[0],index=0;
    for(int i=1;i<n;i++)
    {
        if(min1>ar[i])
        {
            min1=ar[i];
            index=i;
        }
    }
    return index;
}

int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    cout<<rotation(ar,n);
}
