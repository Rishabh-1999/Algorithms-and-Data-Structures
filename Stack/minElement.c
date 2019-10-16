#include<stdio.h>

#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;
int minEle;

void push(int data)
{
	if(top == MAX_SIZE-1)
	{
		printf("StackOverflow\n");
		return;
	}
	if(top == -1)
	{
		minEle = data;
		A[++top] = data;
	}
	else if(data < minEle)
	{
		A[++top] = 2*data - minEle;
		minEle = data;
	}
	else
	{
		A[++top] = data;
	}
}

void pop()
{
	if(top == -1)
	{
		printf("No element to pop\n");
		return;
	}
	 if(A[top] < minEle)
	 {
	 	printf("Poped Element is : %d\n", minEle);
	 	minEle = 2*minEle - A[top];
	 	top--; 
	 } 
	 else
	 {
	 	printf("Poped Element is : %d\n", A[top--]);
	 }
}

void Print()
{
	printf("Stack Elements : ");
	for(int i=0;i<=top;i++)
		printf("%d ",A[i]);
	printf("\n");
}

int main()
{
	push(3);
	push(5);
	push(2);
	push(1);
	push(4);
	Print();
	printf("The Min Element is : %d\n",minEle);
	pop();
	pop();
	pop();
	pop();
	pop();
}