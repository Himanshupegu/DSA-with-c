// Using Inorder traversal
#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h>

struct node
{
  int data;
  struct node *left, *right;
};

struct node *create()
{
  int x;
  struct node *newNode;
  newNode = (struct node *)malloc(sizeof(struct node));
  printf("\neneter the data for the node(0 for no data): ");
  scanf("%d", &x);
  if (x == 0)
  {
    return 0;
  }
  else
  {
    newNode->data = x;
    printf("\nEnter the data for LEFT child of %d", x);
    newNode->left = create();
    printf("\n\nEnter the data for RIGHT child of %d", x);
    newNode->right = create();
    return newNode;
  }
}

int isBST(struct node *root)
{
  static struct node *prev = NULL;
  if (root == NULL)
  {
    return 1;
  }
  if (isBST(root->left) == 0)
  {
    return 0;
  }
  if (prev != NULL && prev->data >= root->data)
  {
    return 0;
  }
  prev = root;
  return isBST(root->right);
}
void preorder(struct node *root)
{
  if (root != NULL)
  {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(struct node *root)
{
  if (root != NULL)
  {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}

void inorder(struct node *root)
{
  if (root != NULL)
  {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

int main()
{
  int x;
  struct node *root;
  root = NULL;
  root = create();
  x = isBST(root);
  // printf("%d", x);
  if (x == 1)
  {
    printf("The Binary Tree is a BST");
  }
  else
  {
    printf("The Binary Tree is not a BST");
  }
  printf("\nThe Inorder Traversal is: ");
  inorder(root);
  return 0;
}