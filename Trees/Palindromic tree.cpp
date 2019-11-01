#include<iostream>
#include<queue>
using namespace std;
struct Node{
int data;
Node *left;
Node *right;
};
struct Node* buildNodeRec(struct Node* root,int t[],int n,int i)
{
  if(i<n)
  {
    struct Node* temp=new Node();
    temp->data=t[i];
    root=temp;
    root->left=buildNodeRec(root->left,t,n,2*i+1);
    root->right=buildNodeRec(root->right,t,n,2*i+2);
  }
  return root;
}
void inorder(int ar[],int *k,Node *root)
{
    if(root==NULL)
        return;
    inorder(ar,k,root->left);
    ar[(*k)++]=root->data;
    inorder(ar,k,root->right);
}
void findMirror(struct Node* root)
{
    queue<struct Node*>q;
    if(root==NULL)
    return;
    q.push(root);
    while(!q.empty())
    {
	    struct Node *temp=q.front();
	    q.pop();
	    struct Node *temp1=temp->right;
	    temp->right=temp->left;
	    temp->left=temp1;
	    if(temp->left)
	      q.push(temp->left);
	    if(temp->right)
	      q.push(temp->right);
    }
}
int main()
{
 int n;
 cin>>n;
 int ar[n];
 for(int i=0;i<n;i++)
        cin>>ar[i];
 struct Node *root=buildNodeRec(root,ar,n,0);
 int first[n];
 int k=0;
 inorder(first,&k,root);
 findMirror(root);
 int second[n];
 k=0;
 int c=0;
 inorder(second,&k,root);
 for(int i=0;i<n;i++)
    if(first[i]!=second[i])
 {
     c=1;
     break;
 }
 if(c==0)
 cout<<"Palindrom Tree";
 else
 cout<<"Not Palindrome";

}
