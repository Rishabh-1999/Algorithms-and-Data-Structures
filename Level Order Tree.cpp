#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

struct Node {
	int data;
	struct Node *left,*right;
};

struct Node* newNode(int data) {
	struct Node *h=(struct Node*)malloc(sizeof(struct Node));
	h->data=data;
	h->left=h->right=NULL;
	return h;
}

struct Node* add(struct Node *root,int data) {
	if(root==NULL)
		return newNode(data);
	if(root->data > data) 
		root->left=add(root->left,data);
		
	if(root->data <  data) 
		root->right=add(root->right,data);
		
	return root;
}

void levelbyqueue(struct Node *root) {
	
	queue<struct Node*> q;
	q.push(root);
	
	while(!q.empty()) {
		
		struct Node *s=q.front();
		q.pop();
		
		cout<<s->data<<" ";
		
		if(s->left)
			q.push(s->left);
		if(s->right)
			q.push(s->right);
	}
	
}

int main() {
	
	int n,d;
	cin>>n;
	
	struct Node *root=NULL;
	
	for(int i=0;i<n;i++) {
		cin>>d;
		root=add(root,d);
	}
	
	levelbyqueue(root);
	
	return 0;
}
