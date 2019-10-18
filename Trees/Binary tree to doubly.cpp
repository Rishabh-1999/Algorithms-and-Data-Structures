#include<iostream>
#include <cstdlib>
using namespace std;

struct Tree
{
    int data;
    Tree *left;
    Tree *right;
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

void Treetodoubly(Tree *root, Tree **head)
{
    if (root == NULL)
		return;
    static Tree* prev = NULL;
    Treetodoubly(root->left, head);
    if (prev == NULL)
        *head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    Treetodoubly(root->right, head);
}

void printdoubly(struct Tree *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->right;
        
    }
}

int main()
{
    Tree *root=NULL;
    int n,i=0,data=0;
    cin>>n;
    while(n > i)
    {
    	cin>>data;
    	if(root==NULL)
    	root=insert(root,data);
    	else
    	insert(root,data);
    	i++;
	}
    
    struct Tree *head=NULL;
    Treetodoubly(root,&head);
    printdoubly(head);
    return 0;
}
