#include<iostream>
#include<vector>
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
 bool path(struct tree *root,vector<int>&v,int node)
 {
     if(root==NULL)
        return false;
     v.push_back(root->data);
     if(root->data==node)
        return true;
     if(path(root->left,v,node)||path(root->right,v,node))
        return true;
     v.pop_back();
     return false;
 }
 void printpath(struct tree *root,int node)
 {
     vector<int>v;
     if(path(root,v,node))
     {
         for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
     }
     else
     cout<<"No Path";
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
    int node;
    cin>>node;
    printpath(root,node);
}
