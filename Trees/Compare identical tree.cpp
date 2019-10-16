int areSameTree(struct Node* t1, struct Node* t2)
{
  if(t1==NULL && t2==NULL)
    return 1;
  else if(t1!=NULL && t2==NULL)
          return 0;
       else if(t1==NULL && t2!=NULL)
          return 0;

  if(t1->data==t2->data && areSameTree(t1->right,t2->right) && areSameTree(t1->left,t2->left))
    return 1;
  else
    return 0;
}
