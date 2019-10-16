#include<iostream>
#include <cstdlib>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

int detectLoop(struct node *head)
{
	struct node *slow = head,*fast = head;
	while(slow && fast && fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
			return 1;
	}
	return 0;
}

int main()
{
	struct node *head=NULL;
	for(int i=1;i<6;i++)
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
	head->next->next->next->next = head;
	if(detectLoop(head))
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}
