// Insertion in BST

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *left, *right;
} tree;

// Function to create a Binary Tree
tree *create()
{
  int x;
  tree *newNode;
  newNode = (tree *)malloc(sizeof(tree));
  printf("\neneter the data ftree(0 for no data): ");
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
int isBST(tree *root, tree *minNode, tree *maxNode)
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

// Function to createtree
tree *createNewNode(int data)
{
  tree *newNode;
  newNode = (tree *)malloc(sizeof(tree));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Function to insert element in BST
void insertion(tree *root, int value)
{
  tree *prev = NULL;
  while (root != NULL)
  {
    prev = root;
    if (value == root->data)
    {
      printf("\nElement can't insert(Already exists in BST).");
      return;
    }
    else if (value < root->data)
    {
      root = root->left;
    }
    else
    {
      root = root->right;
    }
  }
  tree *newNode = createNewNode(value);
  if (value < prev->data)
  {
    prev->left = newNode;
    printf("\nElement is inserted in the left subtree.");
  }
  else
  {
    prev->right = newNode;
    printf("\nElement is inserted in the right subtree.");
  }
}

void inorder(tree *root)
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
  tree *root, *minNode, *maxNode;
  int value;
  root = NULL;
  root = create();
  printf("\nTree is created successfully");
  printf("\nand");
  if (isBST(root, minNode, maxNode))
  {
    printf("\nIt's a BST");
    printf("\n\nEnter the element you want to insert: ");
    scanf("%d", &value);
    insertion(root, value);
    printf("\n\nInorder traversal after inserting the new node in BST.\n");
    inorder(root);
  }
  else
  {
    printf("\nIt's not a BST");
  }

  return 0;
}
