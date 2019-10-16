#include <iostream> 
#include <cstdlib>
#include <stack> 
#include <queue>
 
using namespace std; 
  
struct Tree 
{ 
    int data; 
    struct Tree* left; 
    struct Tree* right; 
}; 
  
void reverseLevelOrder(struct Tree* root) 
{
    stack <Tree *> S; 
    queue <Tree *> Q; 
    Q.push(root); 
  
    while (Q.empty() == false) 
    {
        root = Q.front();
        Q.pop();
        S.push(root);
  
        if (root->right)
    	    Q.push(root->right);
  
        if (root->left) 
     	    Q.push(root->left); 
    } 
  
    while (S.empty() == false) 
    {
        root = S.top(); 
        cout << root->data << " "; 
        S.pop(); 
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
    insert(n,15);
    insert(n,2);
    insert(n,1);
    insert(n,5);
    reverseLevelOrder(n);
    //printByRecusion(n);
	return 0;
}
