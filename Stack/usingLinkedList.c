#include<stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *top = NULL;

void push(int data)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = top;
	top = newnode;
}

void pop()
{
	if(top == NULL)
	{
		printf("Stack Under Flow\n");
		return;
	}
	printf("Pop Element is %d",top->data);
	printf("\n");
	top = top->next;
}

int Top()
{
	return top->data;
}

void Print()
{
	struct node *temp = top;
	if(top == NULL)
	{
		printf("Stack is Empty\n");
		return;
	}
	printf("Stack Elements : ");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
}

int main()
{
	push(1);
	push(2);
	push(3);
	pop();
	push(4);
	printf("Top Element : ");
	printf("%d\n",Top());
	Print();
}