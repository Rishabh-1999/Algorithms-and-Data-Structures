#include<stdio.h>

#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;

void push(int data)
{
	if(top == MAX_SIZE-1)
	{
		printf("StackOverflow\n");
		return;
	}
	A[++top] = data;
}

void pop()
{
	if(top == -1)
	{
		printf("No element to pop\n");
		return;
	}
	top--;
}

int Top()
{
	return A[top];
}

int isEmpty()
{
	if(top == -1)
		return 1;
	return 0;
}

void Print()
{
	printf("Stack Elements : ");
	for(int i=0;i<=top;i++)
		printf("%d ",A[i]);
}

int main()
{
	push(1);
	push(2);
	Print();
	pop();
	push(3);
	printf("\nTop Element : ");
	printf("%d\n",Top());
	printf("Empty or Not : ");
	if(isEmpty())
		printf("Yes\n");
	else
		printf("No\n");
	Print();
}