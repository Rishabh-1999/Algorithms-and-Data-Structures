#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

void findMiddle(struct node *head)
{
	struct node *slow = head,*fast = head;
	if(head != NULL)
	{
		while(fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		printf("%d", slow->data);
	}
}

int main()
{
	struct node *head=NULL;
	for(int i=1;i<9;i++)
	{
		struct node *ptr,*temp;
		ptr = (struct node*)malloc(sizeof(struct node));
		ptr->data = i;
		if(head == NULL)
		{
			head = ptr;
			ptr->next = NULL;
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
	findMiddle(head);
	return 0;
}
