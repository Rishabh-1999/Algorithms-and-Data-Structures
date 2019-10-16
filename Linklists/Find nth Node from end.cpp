#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

int nthNodeFromLast(struct node *head,int n)
{
	if(head==NULL)
	return -1;
	struct node *temp = head;
	int len = 0;
	while(temp != NULL)
	{
		temp = temp->next;
		len++;
	}

	if(n > len)
	return -1;

	n=len-n;
	temp = head;
	int k=0;
	while(k<=n)
	{
	    temp=temp->next;
	    k++;
	}
  return temp->data;
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
			{
				temp = temp->next;
			}
			temp->next = ptr;
			ptr->next = NULL;
		}
	}
	cout<<nthNodeFromLast(head,12);
}
