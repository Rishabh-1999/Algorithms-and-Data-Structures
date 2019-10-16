#include<bits/stdc++.h> 
using namespace std; 

struct Tree 
{ 
    int data; 
    struct Tree* left; 
    struct Tree* right; 
    Tree (int data) 
    { 
        this->data = data; 
        left = right = NULL; 
    } 
}; 

void inOrder(struct Tree *root) 
{ 
    stack<Tree *> s; 
    Tree *curr = root; 
  
    while (curr != NULL || s.empty() == false) 
    { 
        while (curr !=  NULL) 
        { 
            s.push(curr); 
            curr = curr->left; 
        } 
        curr = s.top(); 
        s.pop(); 
  
        cout << curr->data << " "; 
        curr = curr->right; 
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
  
    inOrder(n); 
    return 0; 
} 
