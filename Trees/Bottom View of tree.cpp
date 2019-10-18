#include<iostream>
#include<map>
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

void levelTree(struct Tree *root,int d,map<int,int > &m)
{
    if(root==NULL)
        return;
    m[d]=root->data;
    levelTree(root->left,d-1,m);
    levelTree(root->right,d+1,m);
}

void printBottomView(struct Tree*  root)
{
    map<int,int>m;
    int hd=0;
    levelTree(root,hd,m);
    map<int,int >::iterator it;
    for(it=m.begin();it!=m.end();it++)
        cout<<it->second<<" ";
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
    printBottomView(root);
    return 0;
}
