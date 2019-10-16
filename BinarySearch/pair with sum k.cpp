#include<iostream>
#include<algorithm>
int countpair(int ar[],int s,int e,int sum)
{
    int c=0;
    while(s<e)
    {
        int total=ar[s]+ar[e];
        if(total==sum)
        {
           if(ar[s]==ar[s+1])
           {
               int temp=0;
               while(temp<e)
               {
                   if(ar[temp]+ar[e]==sum)
                    c++;
                   temp++;
               }
               e--;
           }
           else{
            c++;
             s++;
           }
        }
        else if(total<sum)
            s++;
        else
            e--;
    }
    return c;
}
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    int sum;
    cin>>sum;
    sort(ar,ar+n);
    cout<<countpair(ar,0,n-1,sum);
}
