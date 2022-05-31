// Binary Tree Traversal
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} tree;

tree *create()
{
    int x;
    tree *newNode;
    newNode = (tree *)malloc(sizeof(tree));
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
        // printf("\n             ");
        // printf("\n          ____");
        // printf("\n         | %d  | ", x);
        // printf("\n         |____|");
        // printf("\n        /");
        // printf("\n  ____ /");
        // printf("\n | ?  |");
        // printf("\n |____| ");
        newNode->left = create();
        printf("\n\nEnter the data for RIGHT child of %d", x);
        // printf("\n             ");
        // printf("\n          ____");
        // printf("\n         | %d  | ", x);
        // printf("\n         |____|");
        // printf("\n               |");
        // printf("\n                |____");
        // printf("\n                | ?  |");
        // printf("\n                |____| ");
        newNode->right = create();
        return newNode;
    }
}

void preorder(tree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(tree *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
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
void main()
{
    tree *root;
    root = NULL;
    root = create();
    printf("\nThe Inorder Traversal is: ");
    inorder(root);
    printf("\nThe Preorder Traversal is: ");
    preorder(root);
    printf("\nThe Postorder Traversal is: ");
    postorder(root);
}