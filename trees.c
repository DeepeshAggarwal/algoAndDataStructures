#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node* left, *right;
};
 
struct node* newNode(int data);
 
int max(int a, int b);
 
int height(struct node* node);
 
int diameter(struct node *root, int* height)
{
  int lh = 0, rh = 0;
  
  int ldiameter = 0, rdiameter = 0;
  
  if(root == NULL)
  {
    *height = 0;
     return 0;
  }
  
  ldiameter = diameter(root->left, &lh);
  rdiameter = diameter(root->right, &rh);
  
  *height = max(lh, rh) + 1;
  printf("%d---->\t%d\t%d\t%d\t%d\t%d\n",root->data, *height, lh, rh, ldiameter, rdiameter);
  return max(lh + rh + 1, max(ldiameter, rdiameter));
}
 
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 
int max(int a, int b)
{
  return (a >= b)? a: b;
}    
 
int main()
{
 
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  struct node *temp = root->left->right;
  temp->left = newNode(6);
  temp->left->right = newNode(7);
  temp->left->right->right = newNode(8);
  temp->left->right->right->right = newNode(9);
  temp->left->right->right->left = newNode(10);
  printf("value   height  left\tright   lDia\trDia\n");
  int a = 0;
  printf("Diameter of the given binary tree is %d\n", diameter(root, &a));
 
  return 0;
}