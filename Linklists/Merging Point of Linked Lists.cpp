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

struct Node* findMergePoint(struct Node* head1, struct Node* head2) 
{
  struct Node *h1=head1,*h2=head2,*r=NULL,temp;
  while(h1!=NULL)
  {
    h2=head2;
    while(h2!=NULL)
    {
      if(h1==h2)
        return h2;
      h2=h2->next;
    }
    h1=h1->next;
  }
  return r;
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
	return 0;
}
