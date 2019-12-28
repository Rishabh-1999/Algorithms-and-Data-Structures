#include <stdio.h>
int main()
{
  printf("Enter no of elements in array : ");
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
  int max=a[0];
  for(int i=0;i<n;i++)
  {
    if(a[i]>max)
      max=a[i];
  }
  printf("Max element in array is %d",max);
    return 0;
}
