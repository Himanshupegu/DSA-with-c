// Searching in Binary Search Tree(Searching in each sub binary tree)

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *left, *right;
} tree;

// Function to create a Binary Tree
struct node *create()
{
  int x;
  tree *newNode;
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
// Function to check whether the Binary Tree is BST or not
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
// Function to search an element in BST
tree *search(tree *root, int value)
{
  if (root == NULL)
  {
    return NULL;
  }
  if (value == root->data)
  {
    return root;
  }
  else if (value < root->data)
  {
    return search(root->left, value);
  }
  else
  {
    return search(root->right, value);
  }
}

int main()
{
  tree *root, *minNode, *maxNode;
  int value;
  root = NULL;
  root = create();
  printf("\nTree is created successfully");
  printf("\nand");
  if (isBST(root, minNode, maxNode))
  {
    printf("\nIt's a BST");
    printf("\nEnter the element you want to search: ");
    scanf("%d", &value);
    tree *x = search(root, value);
    if (x != NULL)
    {
      printf("\nFound the element %d.", x->data);
    }
    else
    {
      printf("\nElement not found!!");
    }
  }
  else
  {
    printf("\nIt's not a BST");
  }

  return 0;
}