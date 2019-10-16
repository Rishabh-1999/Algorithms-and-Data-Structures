#include <iostream>
#include <cstdlib>
using namespace std;

struct Tree
{
    struct Tree *left,*right;
    int data;
};

void printByRecusion(Tree *root)
{
    if(root!=NULL)
    {
        printByRecusion(root->left);
        cout<<root->data<<"\n";
        printByRecusion(root->right);
    }
}

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

int isBinarySearchTree(struct Tree* t1)
{
	if(t1==NULL)
      return 1;
  if(t1->left!=NULL && t1->left->data > t1->data)
    return 0;
  if(t1->right!=NULL && t1->right->data < t1->data)
    return 0;
  
  if(!isBinarySearchTree(t1->left) || !isBinarySearchTree(t1->right))
    return 0;
  return 1;
  
}

int main()
{
    Tree *n=NULL;
    n=insert(n,10);
    insert(n,15);
    insert(n,2);
    insert(n,1);
    insert(n,5);
    printByRecusion(n);
    if(isBinarySearchTree(n))
    cout<<"Yes";
    else
    cout<<"No";
	return 0;
}
