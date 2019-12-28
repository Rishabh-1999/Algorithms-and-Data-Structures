#include<stdio.h>
void checkTree(int arr[50][50], int row, int col, int i, int j, int sum, int no) {
    if ( j<0 || i>=row || j>=col) 
	{
        return;
    }
    else
	{
       sum += arr[i][j];
       printf("No in the Pattern at %d %d is %d\n",i,j,arr[i][j]);
       checkTree(arr, row, col, i+1, j-1, sum, no);
        if(sum == no) 
		{
        	printf("No is Matched at position %d %d\n",i,j);
        	return ;
        }
        checkTree(arr, row, col, i+1, j+1, sum, no);
     	if(sum == no) 
		{
        	printf("No is Matched at position %d %d\n",i,j);
        	return ;
        }
    }
}
int main() 
{
    int n, row, col, root_i, root_j;
    printf("Enter the row and col size :\n");
    scanf("%d %d",&row,&col);
    printf("Enter the no to compare\n");
    scanf("%d",&n);
    int arr[50][50];
    printf("Enter the array elements\n");
    for(int i = 0;i< row;i++) 
	{
        for(int j = 0;j<col;j++) 
		{
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Enter the Root point\n");
    scanf("%d %d",&root_i,&root_j);
    checkTree(arr, row, col, root_i, root_j, 0, n);
     return 0;
}
