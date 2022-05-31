// Creating a Binary Tree

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
    printf("\nEnter data for the node(-1 for no data): ");
    scanf("%d", &x);
    if (x == -1)
    {
        return 0;
    }
    else
    {
        newNode->data = x;
        printf("\nEnter the left child of %d", x);
        newNode->left = create();
        printf("\nEnter the right child of %d", x);
        newNode->right = create();
        return newNode;
    }
}

int main()
{
    struct node *root;
    root = NULL;
    root = create();
    return 0;
}