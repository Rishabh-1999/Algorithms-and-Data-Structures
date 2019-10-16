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
	struct node *ptr1 = head,*ptr2;
	while(ptr1 != NULL && ptr1->next != NULL)
	{
		ptr2 = ptr1;
		while(ptr2->next!=NULL)
		{
			if(ptr1->data == ptr2->next->data)
			{
				ptr2->next = ptr2->next->next;
			}
			else
			{
				ptr2= ptr2->next;
			}
		}
		ptr1 = ptr1->next;
	}
}

int main()
{
	int size,n;
	printf("Enter size : \n");
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
			while(temp->next!=NULL)
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