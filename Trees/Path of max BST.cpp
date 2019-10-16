#include<iostream>
#include<algorithm>
using namespace std;
struct Tree
{
    struct Tree *left=NULL,*right=NULL;
    int data;
};

struct Node
{
	Tree *arr[1000];
	int size=0;
	int sum=0;

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

struct Node* path(Tree *root)
{	
	cout<<"SD"<<root->data<<endl;
	struct Node *a=NULL,*b=NULL;
	if(root->left==NULL && root->right==NULL)
	{
		struct Node *c=(struct Node*)malloc(sizeof(struct Node));
		c->arr[0]=root;
		c->size=0;
		return c;
	}
		if(root->left!=NULL) {
			a=path(root->left);
			if(root->right==NULL)
			{
				a->arr[++(a->size)]=root;
				return a;
			}	
		}
		if(root->right!=NULL) {
			b=path(root->right);
			if(root->left==NULL)
			{
				b->arr[++(b->size)]=root;
				return b;
			}	
		}
		
		cout<<"get"<<(a->arr[a->size])->data<<" "<<(b->arr[b->size])->data<<endl;
	if(a->size > b->size)
	{
		cout<<"a"<<root->data;
		a->arr[++(a->size)]=root;
		return a;
	}
	else
	{
		cout<<"b"<<root->data;
		b->arr[++(b->size)]=root;
		return b;
	}
}

int main()
{
    Tree *n=NULL;
    n=insert(n,10);
    insert(n,15);
    insert(n,3);
    insert(n,2);
    insert(n,1);
    insert(n,5);
    
	struct Node *c=path(n);
	cout<<"ans"<<endl;;
	int i=0;
	while( i <= c->size)
	{
		cout<<c->arr[i]->data<<endl;
		i++;
	}
	
	return 0;
}
