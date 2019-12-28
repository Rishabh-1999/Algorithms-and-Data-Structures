#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct node* shiftSmallLarge(struct node *org)
{
 struct node *head=org;
  struct node *p,*p2;
  struct node *current=org;
  int max;
  if(org==NULL)
  {
    return org;
  }
  max=org->data;
  while(head->next!=NULL)
  {
    p=head;
    head=head->next;
    if(head->data<max)
    {
      max=head->data;
      p2=p;
      current=head;
    }
  }
  if(current->data!=org->data)
  {
    p2->next=current->next;
    current->next=org;
    org=current;
  }
  head=org;
  while(head->next!=NULL)
  {
    p=head;
    head=head->next;
    if(head->data>max)
    {
      max=head->data;
      p2=p;
     current=head; 
    }
  }
  if(current->next!=NULL)
  {
    p2->next=current->next;
    current->next=NULL;
    head->next=current;
  }
  
return org;
}

void print(struct node *head)
{
	while(head!=NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
}

int main()
{
	struct node *head=NULL,*temp=NULL;
	for(int i=24;i>1;i--)
	{
		if(head==NULL)
		{
			head=(struct node*)malloc(sizeof(struct node));
			temp=head;
		}
		else
		{
			temp->next=(struct node*)malloc(sizeof(struct node));
			temp=temp->next;
		}
		temp->data=i;
		temp->next=NULL;
	}
	temp->data=-9;
	print(head);
	printf("\n");
	head=shiftSmallLarge(head);
	print(head);
}
