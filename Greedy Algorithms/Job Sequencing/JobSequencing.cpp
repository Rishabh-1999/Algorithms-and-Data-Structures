#include<iostream>
#include<algorithm>
using namespace std;
struct job
{
    char id;
    int dead;
    int profit;
};

bool comp(job a,job b)
{
    return (a.profit>b.profit);
}

void printjob(job arr[],int n)
{
    sort(arr,arr+n,comp);
    int result[n];
    bool s[n];
    for(int i=0;i<n;i++)
        s[i]=false;
    for(int i=0;i<n;i++)
    {
        for(int j=min(n,arr[i].dead)-1;j>=0;j--)
            if(s[j]==false)
	        {
	            result[j]=i;
	            s[j]=true;
	            break;
	        }
    }
    for(int i=0;i<n;i++)
         if(s[i])
         cout<<arr[result[i]].id<<" ";
}
int main()
{
    job arr[]={ {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};
        printjob(arr,5);
}
