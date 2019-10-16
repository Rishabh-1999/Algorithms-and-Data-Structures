#include<iostream>
#include<algorithm>
using namespace std;
struct Tree
{
    struct Tree *left=NULL,*right=NULL;
    int data;
};

int findHeight(Tree *root)
{
	if(root==NULL)
		return 0;
	int a=findHeight(root->left);
	int b=findHeight(root->right);
	//cout<<a<<" "<<b;
	return ++(a >= b ? a: b);
}

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

int max(int a, int b) 
{ 
  return (a >= b)? a: b; 
}  

int diameter(struct Tree *root)
{
	if(root==NULL)
		return 0;
	int lheight=findHeight(root->left);
	int rheight=findHeight(root->right);
	
	int ldia=diameter(root->left);
	int rdia=diameter(root->right);
	
	return max(lheight + rheight + 1, max(ldia, rdia));
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
    //printByRecusion(n);
    cout<<diameter(n);
    //cout<<findHeight(n);
	return 0;
}
