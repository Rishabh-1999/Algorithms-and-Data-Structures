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

struct Node* build(int in[],int post[],int s,int e,int *p)
{
  if(s>e)
    return NULL;
  struct Node *temp=new Node();
  temp->data=post[*p];
  (*p)--;
  if(s==e)
    return temp;
  int i=search(in,temp->data,s,e);
  temp->right=build(in,post,i+1,e,p);
  temp->left=build(in,post,s,i-1,p);
  return temp;
}

struct Node* buildTree(int in[], int post[], int N)
{
int p=N-1;
return build(in,post,0,N-1,&p);
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
    int in[n],post[n];
    for(int i=0;i<n;i++)
        cin>>in[i];
    for(int i=0;i<n;i++)
        cin>>post[i];
    struct Node* root=buildTree(in,post,n);
    print(root);
}
