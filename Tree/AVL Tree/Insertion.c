#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int key;
  struct node *left, *right;
  int height;
} avlTree;

int getHeight(avlTree *root)
{
  if (root == NULL)
  {
    return NULL;
  }
  return root->height;
}

avlTree *createNode(int key)
{
  avlTree *node = (avlTree *)malloc(sizeof(avlTree));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return node;
}
int getBalanceFactor(avlTree *root)
{
  if (root == NULL)
  {
    return 0;
  }
  return getBalanceFactor(root->left) - getBalanceFactor(root->right);
}
