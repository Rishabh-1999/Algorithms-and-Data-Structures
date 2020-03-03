#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
	int data;
	struct Node *next;
};

struct Node* newNode(int data) {
	struct Node *h=(struct Node*)malloc(sizeof(struct Node));
	h->data=data;
	h->next=NULL;
	return h;
}

struct Node* add(struct Node *head,int data) {
	
	struct Node *root=head;
	
	if(root==NULL)
		return newNode(data);
		
	while(root->next!=NULL) {
		root=root->next;
	}
	
	root->next=newNode(data);
	return head;
}

void print(struct Node *s) {
	struct Node *r=s;
	while(r!=NULL)
	{
		cout<<r->data<<" ";
		r=r->next;
	}
	cout<<endl;
}

void replace(struct Node* root,int pos) {
	
	struct Node *slow=root,*fast=root;
	int count=0;
	while(slow && fast && fast->next){
		slow=slow->next;
		fast=fast->next->next;
		count++;
	}
	count=count*2;

	if(fast->next!=NULL)
		count++;

cout<<count<<endl;
	
	if(pos<(count/2)) {
		int k=(count/2)-pos;
		int i=count/2;
		while(i<k) {
			slow=slow->next;
			i++;
		}
	}
	 else {
		slow=root;
		int i=0,k=count-pos;
		while(i<k) {
			slow=slow->next;
			i++;
		}
	}

cout<<slow->data<<" "<<fast->data;
	
//	int temp=slow->data;
//	slow->data=fast->data;
//	fast->data=temp;
	
}

int main() {
	
	int n,data;
	cout<<"n";
	cin>>n;
	
	Node *root=NULL;
	
	for(int i=0;i<n;i++) {
		cin>>data;
		root=add(root,data);
	}
	cout<<"pos";
	int pos;
	cin>>pos;
	print(root);
	replace(root,pos);
	print(root);
	return 0;
}
