#include <iostream>
#include <cstdlib>
using namespace std;

struct Tree
{
    struct Tree *left,*right;
    int data;
};

struct Tree *newNode(int item) 
{ 
    struct Tree *temp =  (struct Tree *)malloc(sizeof(struct Tree)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}

struct Tree* insert(struct Tree* node, int data) 
{ 
    if (node == NULL) 
		return newNode(data); 
  
    if (data < node->data) 
        node->left  = insert(node->left, data); 
    else if (data > node->data) 
        node->right = insert(node->right, data);    
  
    return node; 
} 

void printLeft(struct Tree *root);
void printRight(struct Tree *root);

void printTopView(struct Tree* root)
{
	if(root!=NULL)
    {
      printLeft(root);
      printRight(root->right);
    }
}
void printLeft(struct Tree *root)
{
  if(root!=NULL)
  {
    printLeft(root->left);
    printf("%d ",root->data);
    
  }
}
void printRight(struct Tree *root)
{
  if(root!=NULL)
  {
    printf("%d ",root->data);
      printRight(root->right);
  }
}

int main()
{
    Tree *n=NULL;
    n=insert(n,10);
    insert(n,15);
    insert(n,2);
    insert(n,1);
    insert(n,5);
    printTopView(n);
	return 0;
}
