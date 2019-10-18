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
        cout<<root->data<<" ";
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

struct Tree * minValueNode(struct Tree* node) 
{ 
    struct Tree* current = node; 
  
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

struct Tree* deleteNode(struct Tree* root, int key) 
{ 
    if (root == NULL) 
		return root; 
	
    if (key < root->data) 
        root->left = deleteNode(root->left, key); 
    else if (key > root->data) 
        root->right = deleteNode(root->right, key);  
    else
    { 
        if (root->left == NULL) 
        { 
            struct Tree *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct Tree *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        struct Tree* temp = minValueNode(root->right); 
        root->data = temp->data; 
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
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
    deleteNode(n,10);
    cout<<"\n";
    printByRecusion(n);
	return 0;
}
