#include<stack>
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
int height(tree *root)
{
    if(root==NULL)
        return 0;
    int ld=height(root->left);
    int rd=height(root->right);
    if(ld>rd)
        return ld+1;
    else
        return rd+1;
}
void printgivenlevel(tree *root,int l,bool ltr)
{
    if(root==NULL)
        return;
    if(l==1)
        cout<<root->data<<" ";
    else if(l>1)
    {
        if(ltr)
        {
            printgivenlevel(root->left,l-1,ltr);
            printgivenlevel(root->right,l-1,ltr);
        }
        else
        {

            printgivenlevel(root->right,l-1,ltr);
            printgivenlevel(root->left,l-1,ltr);
        }
    }
}
void printspiral(tree *root)
{
    int h=height(root);
    bool ltr=false;
    for(int i=1;i<=h;i++)
    {

        printgivenlevel(root,i,ltr);
        ltr=!ltr;
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
    printspiral(root);
}

