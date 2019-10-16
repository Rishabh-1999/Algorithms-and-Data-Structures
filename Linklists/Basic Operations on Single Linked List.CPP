#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

void print(struct node *head)
{
	struct node *temp = head;
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

int main()
{
	struct node *head=NULL;
	for(int i=1;i<16;i++)
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
				temp = temp->next;
			temp->next = ptr;
			ptr->next = NULL;
		}
	}
	print(head);
}
