#include<stdio.h>

#define sizeArr 101

int A[sizeArr];
int top1 = -1;
int top2 = sizeArr;

void push1(int data)
{
	if(top1 < top2-1)
	{
		A[++top1] = data;
	}
	else
	{
		printf("Stack Overflow\n");
	}
}

void push2(int data)
{
	if(top1 < top2-1)
	{
		A[--top2] = data;
	}
	else
	{
		printf("Stack Overflow\n");
	}
}

int pop1()
{
	if(top1 >= 0)
	{
		return A[top1--];
	}
	else
    { 
        printf("Stack UnderFlow"); 
    } 
}

int pop2()
{
	if(top2 < sizeArr)
	{
		return A[top2++];
	}
	else
    { 
        printf("Stack UnderFlow"); 
    } 
}


int main()
{
	push1(5);
	push2(10);
	push2(15);
	push1(11);
	push2(7);
	printf("Popped element from stack1 is %d\n",pop1()); 
    push2(40); 
    printf("Popped element from stack2 is %d\n",pop2()); 
}