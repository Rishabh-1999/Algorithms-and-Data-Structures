#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head;

void removeDuplicates(struct node *head)
{
	struct node *temp = head;
	if(temp == NULL)
		return;

	while(temp->next != NULL)
	{
		if(temp->data == temp->next->data)
		{
			temp->next = temp->next->next;
		}
		else
		{
			temp = temp->next;
		}
	}
}

int main()
{
	int size,n;
	printf("ENTER SIZE = ");
	printf("\n");
	scanf("%d",&size);
	for(int i=0;i<size;i++)
	{
		printf("ENTER NO = ");
		scanf("%d",&n);
		struct node *ptr,*temp;
		ptr = (struct node*)malloc(sizeof(struct node));
		ptr->data = n;
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

	removeDuplicates(head);

	struct node *temp = head;
	while(temp!=NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}