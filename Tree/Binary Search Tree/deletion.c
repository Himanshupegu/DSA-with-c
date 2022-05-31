// Deletion in BST

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

// Function for Inorder Successer
tree *inOrderSuccesser(tree *root)
{
  root = root->right;
  while (root->left != NULL)
  {
    root = root->left;
  }
  return root;
}

// Function for Inorder Predecesser
tree *inOrderPredecesser(tree *root)
{
  root = root->left;
  while (root->right != NULL)
  {
    root = root->right;
  }
  return root;
}

tree *delete (tree *root, int delValue)
{
  tree *inOrderPre, *inOrderSuc;
  if (root == NULL)
  {
    return NULL;
  }
  if (root->left == NULL && root->right == NULL)
  {
    free(root);
    return NULL;
  }
  else if (delValue < root->data)
  {
    root->left = delete (root->left, delValue);
  }
  else if (delValue > root->data)
  {
    root->right == delete (root->right, delValue);
  }
  // For Inorder Successer(Which will replace the deleted node with smallest number in right subtree)
  else
  {
    inOrderSuc = inOrderSuccesser(root);
    root->data = inOrderSuc->data;
    root->right = delete (root->right, inOrderSuc->data);
  }

  // For Inorder Predecesser(Which will replace the deleted node with greatest number in left subtree)
  // else
  // {
  //   inOrderPre = inOrderPredecesser(root);
  //   root->data = inOrderPre->data;
  //   root->left = delete (root->left, inOrderPre->data);
  // }
  printf("Element is deleted successfully!!");

  return root;
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
    printf("\n\nInorder traversal defore deleting the node in BST.\n");
    inorder(root);
    printf("\n\nEnter the element you want to delete: ");
    scanf("%d", &value);
    // insertion(root, value);
    delete (root, value);
    printf("\n\nInorder traversal after deleting the node in BST.\n");
    inorder(root);
  }
  else
  {
    printf("\nIt's not a BST");
  }

  return 0;
}
