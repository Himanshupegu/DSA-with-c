//Creating a single linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} node;
int main()
{
    node *head = NULL;
    head = (node *)malloc(sizeof(node));
    head->data = 45;
    head->link = NULL;
    node *current = malloc(sizeof(node));
    current->data = 98;
    current->link = NULL;
    head->link = current; // linking 1st node with 2nd node
    current = malloc(sizeof(node));
    current->data = 3;
    current->link = NULL;
    head->link->link = current;
    return 0;
}