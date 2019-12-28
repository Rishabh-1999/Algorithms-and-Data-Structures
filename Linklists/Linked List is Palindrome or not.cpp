#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct node* copy(struct node *h)
{
  struct node *ptr=NULL,*head=NULL,*h1=h;
  if(h==NULL)
    return head;
  while(h1!=NULL)
  {
    if(head==NULL)
    {
      head=(struct node*)malloc(sizeof(struct node*));
      ptr=head;
    }
	else
    {
      ptr->next=(struct node*)malloc(sizeof(struct node));
      ptr=ptr->next;
    }
    ptr->data=h1->data;
    ptr->next=NULL;
    h1=h1->next;
  }
  return head;
}

struct node* reverse(struct node *head)
{
  struct node *current=head;
  struct node*prev=NULL,*next=NULL;
  while(current!=NULL)
  {
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;
  }
  head=prev;
  return head;
}

int checkPalindrome(struct node* head) 
{
  	if(head==NULL)
      	return 0;
	struct node* h1=copy(head);
  	h1=reverse(h1);
  	while(head!=NULL)
    {
      if(head->data!=h1->data)
      return 0;
      head=head->next;
      h1=h1->next;
    }
  return 1;
}

int main()
{
	struct node *head=NULL;
	for(int i=1;i<2;i++)
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
	if(checkPalindrome(head))
	cout<<"Yes";
	else
	cout<<"No";
}
