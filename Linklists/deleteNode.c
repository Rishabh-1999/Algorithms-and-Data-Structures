#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head;

void deleteNode(struct node *head)
{
	struct node *prev;
	if(head == NULL)
		return;
	else
	{
		while(head->next != NULL)
		{
			head->data = head->next->data;
			prev = head;
			head = head->next;
		}
		prev->next = NULL;
	}
}

int main()
{
	for(int i=1;i<6;i++)
	{
		struct node *ptr,*temp;
		ptr = (struct node*)malloc(sizeof(struct node));
		ptr->data = i;
		if(head == NULL)
		{
			ptr->next = NULL;
			head = ptr;
		}
		else
		{
			temp = head;
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = ptr;
			ptr->next = NULL;
		}
	}
	deleteNode(head);

	struct node *temp = head;
	while(temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}