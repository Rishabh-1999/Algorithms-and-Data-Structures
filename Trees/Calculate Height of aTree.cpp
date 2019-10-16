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

int main()
{
    Tree *n=NULL;
    n=(struct Tree*)malloc(sizeof(struct Tree));
    n->left=NULL;
    n->right=NULL;
	n->data=10;
    
    n->left=(struct Tree*)malloc(sizeof(struct Tree));
    n->left->data=5;
    n->left->left=NULL;
    n->left->right=NULL;
    
    n->left->left=(struct Tree*)malloc(sizeof(struct Tree));
    n->left->left->data=1;
    n->left->left->left=NULL;
    n->left->left->right=NULL;
    
    
    n->left->right=(struct Tree*)malloc(sizeof(struct Tree));
    n->left->right->data=8;
    n->left->right->left=NULL;
    n->left->right->right=NULL;
    
    n->left->left->left=(struct Tree*)malloc(sizeof(struct Tree));
    n->left->left->left->data=0;
    n->left->left->left->left=NULL;
    n->left->left->left->right=NULL;
    
    n->right=(struct Tree*)malloc(sizeof(struct Tree));
    n->right->data=12;
    n->right->left=NULL;
    n->right->right=NULL;
    
    cout<<findHeight(n);
	return 0;
}
