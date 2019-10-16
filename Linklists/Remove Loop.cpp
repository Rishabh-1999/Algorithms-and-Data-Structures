#include<iostream>
#include <cstdlib>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

void detectAndRemoveLoop(node* head) 
{ 
    if (head == NULL || head->next == NULL) 
        return; 
  
    node *slow = head, *fast = head; 
  
    slow = slow->next; 
    fast = fast->next->next; 
  
    while (fast && fast->next) { 
        if (slow == fast) 
            break; 
        slow = slow->next; 
        fast = fast->next->next; 
    } 
  
    if (slow == fast) { 
        slow = head; 
        while (slow->next != fast->next) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
        fast->next = NULL;
    } 
} 

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
		struct node *ptr,*temp;
	for(int i=1;i<7;i++)
	{
		ptr=temp=NULL;
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
	temp->next=head->next->next;
	detectAndRemoveLoop(head);
	print(head);
	return 0;
}
