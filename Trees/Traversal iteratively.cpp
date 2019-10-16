#include<iostream>
#include<stack>
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
   void printInOrderIteratively(struct tree *root)
{
    if(root==NULL)
        return;
    stack<struct tree*>s;
    struct tree *temp=root;
    while(!s.empty()||temp!=NULL)
    {
        while(temp)
        {
            s.push(temp);
            temp=temp->left;
        }
        temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        temp=temp->right;
    }
}
void printPreOrderIteratively(struct tree *root)
{
    if(root==NULL)
        return;
    stack<struct tree*>s;
    s.push(root);
    while(!s.empty())
    {
        struct tree *temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        if(temp->right)
        s.push(temp->right);
        if(temp->left)
        s.push(temp->left);
    }
}
void printPostOrderIteratively(struct tree *root)
{
    if(root==NULL)
        return;
    stack<struct tree*>s1,s2;
    s1.push(root);
    while(!s1.empty())
    {
        struct tree *temp=s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left)
            s1.push(temp->left);
        if(temp->right)
            s1.push(temp->right);
    }
    while(!s2.empty())
    {

        cout<<s2.top()<<" ";
        s2.pop();
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
    printInOrderIteratively(root);
    printPreOrderIteratively(root);
    printPostOrderIteratively(root);

}


