// C++ program to find k'th largest element in BST 
#include<iostream> 
#include <cstdlib>
using namespace std; 
  
// A BST node 
struct Tree 
{ 
    int data; 
    struct Tree *left, *right; 
}; 
  
// A function to find 
int KSmallestUsingMorris(struct Tree *root, int k) 
{ 
    // Count to iterate over elements till we 
    // get the kth smallest number 
    int count = 0; 
  
    int ksmall = 0; // store the Kth smallest 
    struct Tree *curr = root; // to store the current node 
  
    while (curr != NULL) 
    { 
        // Like Morris traversal if current does 
        // not have left child rather than printing 
        // as we did in inorder, we will just 
        // increment the count as the number will 
        // be in an increasing order 
        if (curr->left == NULL) 
        { 
            count++; 
  
            // if count is equal to K then we found the 
            // kth smallest, so store it in ksmall 
            if (count==k) 
                ksmall = curr->data; 
  
            // go to current's right child 0
            curr = curr->right; 
        } 
        else
        { 
            // we create links to Inorder Successor and 
            // count using these links 
            struct Tree *pre = curr->left; 
            while (pre->right != NULL && pre->right != curr) 
                pre = pre->right; 
  
            // building links 
            if (pre->right==NULL) 
            { 
                //link made to Inorder Successor 
                pre->right = curr; 
                curr = curr->left; 
            } 
  
            // While breaking the links in so made temporary 
            // threaded tree we will check for the K smallest 
            // condition 
            else
            { 
                // Revert the changes made in if part (break link 
                // from the Inorder Successor) 
                pre->right = NULL; 
  
                count++; 
  
                // If count is equal to K then we found 
                // the kth smallest and so store it in ksmall 
                if (count==k) 
                    ksmall = curr->data; 
  
                curr = curr->right; 
            } 
        } 
    } 
    return ksmall; //return the found value 
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
    n=insert(n,50);
    insert(n,30);
    insert(n,20);
    insert(n,40);
    insert(n,70);
    insert(n,60);
    insert(n,80);
    
    for (int k=1; k<=7; k++) 
       printf("%d ", KSmallestUsingMorris(n, k)); 
    
	return 0;
}
