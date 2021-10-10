//Traversing a Single Linked List, counting the nodes and printing the data in it.
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} node;
void countOfNodes(node *head)
{
    int i, count = 0;
    if (head == NULL)
        printf("Linked List is empty");
    node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        count++;
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\nNumber of nodes = %d", count);
}
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
    countOfNodes(head);
    return 0;
}