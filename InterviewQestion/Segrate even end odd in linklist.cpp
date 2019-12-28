#include <iostream> 
#include <stdlib.h> 
using namespace std; 
  
struct Node 
{ 
    int data; 
    struct Node *next; 
}; 

void segregateEvenOdd(struct Node **root)
{
	struct Node *evenstart,*evenend,*oddstart,*oddend,*head=*root;
	evenstart=evenend=oddstart=oddend=NULL;
	
	while(head!=NULL)
	{
		int val=head->data;
		
		if(val%2==0)
		{
			if(evenstart==NULL)
			{
				evenstart=head;
				evenend=evenstart;
			}
			else
			{
				evenend->next=head;
				evenend=evenend->next;
			}
		}
		else
		{
				if(oddstart==NULL)
			{
				oddstart=head;
				oddend=oddstart;
			}
			else
			{
				oddend->next=head;
				oddend=oddend->next;
			}
		}
		head=head->next;
	}
	if(evenstart==NULL && oddstart==NULL)
	return;
	
	evenend->next=oddstart;
	oddend->next=NULL;
	
	*root=evenstart;
}  

  void push(struct Node** head_ref, int new_data) 
{ 
    /* allocate node */
    struct Node* new_node = 
        (struct Node*) malloc(sizeof(struct Node)); 
  
    /* put in the data */
    new_node->data = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
} 

void printList(struct Node *node) 
{ 
    while (node!=NULL) 
    { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
} 

int main() 
{
    struct Node* head = NULL; 
    push(&head, 11); 
    push(&head, 10); 
    push(&head, 9); 
    push(&head, 6); 
    push(&head, 4); 
    push(&head, 1); 
    push(&head, 0); 
  
    printf("\nOriginal Linked list \n"); 
    printList(head); 
  
    segregateEvenOdd(&head); 
  
    printf("\nModified Linked list \n"); 
    printList(head); 
  
    return 0; 
}
