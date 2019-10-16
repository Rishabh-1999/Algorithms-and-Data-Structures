#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

struct Tree
{
    struct Tree *left,*right;
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

void printGivenLevel(struct Tree* root, int level, int ltr); 
int height(struct Tree* node); 
struct Tree* newNode(int data); 
  
void printSpiralByRecursion(struct Tree* root) 
{ 
    int h = height(root); 
    int i; 
  
    bool ltr = false; 
    for (i = 1; i <= h; i++) { 
        printGivenLevel(root, i, ltr); 
  
        ltr = !ltr; 
    } 
} 

void printGivenLevel(struct Tree* root, int level, int ltr) 
{ 
    if (root == NULL) 
        return; 
    if (level == 1) 
        printf("%d ", root->data); 
    else if (level > 1) { 
        if (ltr) { 
            printGivenLevel(root->left, level - 1, ltr); 
            printGivenLevel(root->right, level - 1, ltr); 
        } 
        else { 
            printGivenLevel(root->right, level - 1, ltr); 
            printGivenLevel(root->left, level - 1, ltr); 
        } 
    } 
} 

int height(Tree *root)
{
	if(root==NULL)
		return 0;
	int a=height(root->left);
	int b=height(root->right);
	return ++(a >= b ? a: b);
}

void printSpiralByStack(struct Tree* root) 
{ 
    if (root == NULL) 
        return;
  
    stack<struct Tree*> s1;
    stack<struct Tree*> s2;
  
    s1.push(root); 
  
    while (!s1.empty() || !s2.empty()) { 
        while (!s1.empty()) { 
            struct Tree* temp = s1.top(); 
            s1.pop(); 
            cout << temp->data << " "; 
  
            if (temp->right) 
                s2.push(temp->right); 
            if (temp->left) 
                s2.push(temp->left); 
        } 
  
        while (!s2.empty()) { 
            struct Tree* temp = s2.top(); 
            s2.pop(); 
            cout << temp->data << " "; 
  
            if (temp->left) 
                s1.push(temp->left); 
            if (temp->right) 
                s1.push(temp->right); 
        } 
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
    printSpiralByRecursion(n);
    cout<<"\n";
    printSpiralByStack(n);
	return 0;
}
