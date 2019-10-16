
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
int search(int in[],int d,int s,int e)
{
  for(int i=s;i<=e;i++)
    if(in[i]==d)
      return i;
}
struct Node* build(int in[],int pre[],int s,int e,int *p)
{
  if(s>e)
    return NULL;
  struct Node *temp=new Node();
  temp->data=pre[*p];
  (*p)++;
  if(s==e)
    return temp;
  int i=search(in,temp->data,s,e);
  temp->left=build(in,pre,s,i-1,p);
  temp->right=build(in,pre,i+1,e,p);
  return temp;
}
struct Node* buildTree(int in[], int pre[], int N)
{
int p=0;
return build(in,pre,0,N-1,&p);
}
void print(Node *root)
{
    if(root==NULL)
       return;
     print(root->left);
     cout<<root->data<<" ";
     print(root->right);
}
int main()
{
    int n;
    cin>>n;
    int in[n],pre[n];
    for(int i=0;i<n;i++)
        cin>>in[i];
    for(int i=0;i<n;i++)
        cin>>pre[i];
    struct Node* root=buildTree(in,pre,n);
    print(root);
}
