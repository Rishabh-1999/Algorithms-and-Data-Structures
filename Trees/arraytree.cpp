#include<iostream>
using namespace std;
void arraytree(int result[],int data,int i)
{
if(result[i]==0)
{
   result[i]=data;
   return;
}
else
{
    if(result[i]>=data)
    arraytree(result,data,2*i+1);
    else
    arraytree(result,data,2*i+2);
}
}
int main()
{
    int n,j=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int result[50]={0};
    for(int i=0;i<n;i++)
    arraytree(result,arr[i],0);
    cout<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<result[i]<<" ";
    }
}
