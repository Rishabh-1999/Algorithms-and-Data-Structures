
#include<iostream>
using namespace std;
struct tree
{
    int data;
    tree *left;
    tree *right;
};
/*int* height(tree *root)
{
    if(root==NULL)
    {
        int *arr  = (int *)malloc(sizeof(int)*2);
        arr[0] = 0;
        arr[1] = 0;
        return arr;
    }
        return 0;
    int *left=height(root->left);
    int *right=height(root->right);
    if(left[0]>right[0])
    {
        left[1] = (left[0]+right[0]+1)>left[1]?(left[0]+right[0]+1):left[1];
        left[0] = left[0]+1;
        return left;
    }

    else
    {
         right[1] = (left[0]+right[0]+1)>right[1]?(left[0]+right[0]+1):right[1];
        right[0] = right[0]+1;
        return right;
    }

}*/
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
    int diameter(tree *root)
    {
        if(root==NULL)
            return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        int ld=diameter(root->left);
        int rd=diameter(root->right);
        int a=(max((lh+rh+1),max(ld,rd)));
        return a;
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
int h=diameter(root);
cout<<h;

}

