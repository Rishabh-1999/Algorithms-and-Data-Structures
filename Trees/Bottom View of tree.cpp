#include<iostream>
#include<map>
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
     void leveltree(struct tree *root,int d,map<int,vector<int> > &m)
{
    if(root==NULL)
        return;
     m[d].push_back(root->data);
    leveltree(root->left,d-1,m);
    leveltree(root->right,d+1,m);
}
void printBottomView(struct tree*  root)
{
    map<int,vector<int> >m;
    int hd=0;
    leveltree(root,hd,m);
    map<int,vector<int> >::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        cout<<it->second[it->second.size()-1]<<" ";
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
    printBottomView(root);
}



