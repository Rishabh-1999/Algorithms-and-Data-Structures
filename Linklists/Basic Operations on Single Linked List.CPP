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
	while(head!=NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
}

int main()
{
	struct node *head=NULL,*temp=NULL;
	for(int i=1;i<16;i++)
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
	print(head);
}
