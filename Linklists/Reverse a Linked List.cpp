#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

void reverseList(struct node **head)
{
	struct node *next = NULL,*prev = NULL,*current = *head;
	while(current!=NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

void reverseUtil(node* curr, node* prev, node** head); 
  
void reverseByRecursion(node** head) 
{ 
    if (!head) 
        return; 
    reverseUtil(*head, NULL, head); 
} 

void reverseUtil(node* curr, node* prev, node** head) 
{ 
    if (!curr->next) { 
        *head = curr; 
  
        curr->next = prev; 
        return; 
    } 
  
    node* next = curr->next; 
  
    curr->next = prev; 
  
    reverseUtil(next, curr, head); 
} 

node *reverseListByStack(node* head) 
{ 
    stack<node *> stk; 
  
    node* ptr = head; 
    while (ptr->next != NULL) { 
        stk.push(ptr); 
        ptr = ptr->next; 
    } 
  
    head = ptr; 
    while (!stk.empty()) { 
        ptr->next = stk.top(); 
  
        ptr = ptr->next; 
        stk.pop(); 
    } 
      
    ptr->next = NULL; 
      
    return head; 
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

	reverseList(&head);

	struct node *temp = head;
	while(temp!=NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	
	reverseByRecursion(&head);

	temp = head;
	while(temp!=NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	
	head=reverseListByStack(head);

	temp = head;
	while(temp!=NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}
