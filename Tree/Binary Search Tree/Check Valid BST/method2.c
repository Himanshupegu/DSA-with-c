// Using Min and Max nodes(efficient)
#include <stdio.h>
#include <stdlib.h>

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

int isBST(struct node *root, struct node *minNode, struct node *maxNode)
{
  if (root == NULL)
  {
    return 1;
  }
  if (minNode && root->data <= minNode->data || maxNode && root->data >= maxNode->data)
  {
    return 0;
  }
  return (isBST(root->left, minNode, root) && isBST(root->right, root, maxNode));
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
  struct node *root;
  struct node *minNode, *maxNode;
  minNode = maxNode = NULL;
  root = NULL;
  root = create();
  // isBST(root);
  if (isBST(root, minNode, maxNode))
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