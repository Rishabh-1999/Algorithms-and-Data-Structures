#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

void insertBeg(struct Node** head, int data)
{
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  node->data  = data;
  node->next = *head;
  node->prev=NULL;
  if(*head != NULL)
    (*head)->prev=node;
  *head = node;
}

void insertAfter(struct Node* prev, int data)
{
  if (prev == NULL)
  {
    printf("the given previous node cannot be NULL");
    return;
  }
  struct Node* node =(struct Node*) malloc(sizeof(struct Node));
  node->data  = data; 
  node->next = prev->next;
  node->prev = prev;
  prev->next->prev=node;
  prev->next = node;
}

void insertBefore(struct Node* next, int data)
{
  if (next == NULL)
  {
    printf("the given next node cannot be NULL");
    return;
  }
  struct Node* node =(struct Node*) malloc(sizeof(struct Node));
  node->data  = data;   
  next->prev->next = node;
  node->prev = next->prev; 
  next->prev = node;
  node->next = next;
}

void insertEnd(struct Node* head, int data)
{
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  struct Node *last = head;
  node->data  = data; 
  node->next = NULL;
  if (head == NULL)
  {
    head = node;
    node->prev=NULL;
    return;
  }
  while (last->next != NULL)
    last = last->next;
  last->next = node;
  node->prev=last;
  return;
}

void printList(struct Node *node)
{
  while (node != NULL)
  {
    printf("%d -> ", node->data);
    node = node->next;
  }
  printf("\n");
}

int main()
{
  struct Node* head = NULL;
  printf("Linked List = ");
  printList(head);
  insertBeg(&head, 6);
  printf("Linked List = ");
  printList(head);
  insertBeg(&head, 2);
  printf("Linked List = ");
  printList(head);
  insertAfter(head, 4);
  printf("Linked List = ");
  printList(head);
  insertEnd(head, 8);
  printf("Linked List = ");
  printList(head);
  insertAfter(head->next, 5);
  printf("Linked List = ");
  printList(head);
  insertBefore(head->next, 3);
  printf("Linked List = ");
  printList(head);
  return 0;
}

