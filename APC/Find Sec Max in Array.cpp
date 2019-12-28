#include <stdio.h>
int main()
{
  int max,secmax,n;
  printf("Enter no of elements in array : ");
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
  max=secmax=a[0];
  for(int i=0;i<n;i++)
	    if(max<a[i] && secmax<a[i])
	    {
	      secmax=max;
	      max=a[i];
	    }
	  else if(secmax<a[i] && max>a[i])
	    secmax=a[i];	    
  	printf("Second Max element in array is %d",secmax);
    return 0;
}
