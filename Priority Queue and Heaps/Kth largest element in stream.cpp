#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    int k;
    cin>>k;
    int temp[k]={0};
    for(int i=0;i<n;i++)
    {
        if(temp[0]<ar[i])
        {
            temp[0]=ar[i];
            for(int j=0;j<k-1;j++)
                for(int z=0;z<k-1-j;z++)
                if(temp[z]>temp[z+1])
            {
                int t=temp[z];
                temp[z]=temp[z+1];
                temp[z+1]=t;
            }
        }
        if(i<k-1)
            cout<<ar[0]<<" ";
        else
            cout<<temp[0]<<" ";
    }
}
