#include<iostream>
#include <cstdlib>
using namespace std;

struct Tree
{
    struct Tree *left=NULL,*right=NULL;
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

void inorder(struct Tree* root)
{
	if(root!=NULL)
    {
      inorder(root->left);
      printf("%d ",root->data);
      inorder(root->right);
    }
}

void preorder(struct Tree* root)
{
	if(root!=NULL)
    {
      printf("%d ",root->data);
      preorder(root->left);
      preorder(root->right);
    }
}

void postorder(struct Tree* root)
{
	if(root!=NULL)
    {
      postorder(root->left);
      postorder(root->right);
    printf("%d ",root->data);
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
    //insert(n,25);
    inorder(n);
    cout<<"\n";
    preorder(n);
    cout<<"\n";
    postorder(n);
	return 0;
}
