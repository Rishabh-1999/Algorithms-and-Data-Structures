#include<iostream>
using namespace std;
struct tree
{
    int data;
    tree *left;
    tree *right;
};
void insert(tree* &root,tree *temp)
    {
      if(root==NULL)
      {
          root=temp;
          temp->right=NULL;
          temp->left=NULL;
          return;
      }
         else if(temp->data>root->data)
          {
            if(root->right==NULL)
                root->right=temp;
            else
              insert(root->right,temp);
          }
          else
          {
            if(root->left==NULL)
                root->left=temp;
            else
              insert(root->left,temp);
          }
    }
 void treetodoubly(tree *root, tree **head)
{
    if (root == NULL) return;
    static tree* prev = NULL;
    treetodoubly(root->left, head);
    if (prev == NULL)
        *head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    treetodoubly(root->right, head);
}

void printdoubly(struct tree *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->right;
    }
}
int main()
{
    tree *root=NULL;
    while(1)
    {
        int n;
        cin>>n;
        if(n==-1)
            break;
        else
        {
           tree *temp=new tree();
           temp->data=n;
            insert(root,temp);
        }
    }
    struct tree *head=NULL;
    treetodoubly(root,&head);
    printdoubly(head);
}



