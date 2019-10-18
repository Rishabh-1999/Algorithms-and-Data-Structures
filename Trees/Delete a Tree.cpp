#include <iostream>
#include <cstdlib>
using namespace std;

struct Tree
{
    struct Tree *left,*right;
    int data;
};

void deleteWholeTree(Tree *root)
{
    if(root!=NULL)
    {
    	cout<<root<<" ";
        deleteWholeTree(root->left);
        deleteWholeTree(root->right);
        free(root);
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

int main()
{
    Tree *n=NULL;
    n=insert(n,10);
    Tree *n1=insert(n,15);
    insert(n,2);
    Tree *n2=insert(n,1);
    insert(n,5);
    deleteWholeTree(n);
    cout<<n->data<<n2->data;
	return 0;
}
