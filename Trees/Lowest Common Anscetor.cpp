#include<iostream>
#include<algorithm>
using namespace std;
struct Tree
{
    struct Tree *left=NULL,*right=NULL;
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

int lowestCommonAncestor(struct Tree* root, int k1, int k2)
{
	if( root == NULL)
      return -1;
  
  if( root->data ==k1 || root->data == k2)
  return root->data;
  int a=lowestCommonAncestor(root->left,k1,k2);
  int b=lowestCommonAncestor(root->right,k1,k2);

  if( a != -1 && b!=-1)
    return root->data;
  
  return ( a > b?a:b);
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
    cout<<lowestCommonAncestor(n,1,15);
    //printByRecusion(n);
	return 0;
}
