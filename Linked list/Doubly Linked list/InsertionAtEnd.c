// Insertion at end of the doubly linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;
node *addAtEnd(node *head, int data)
{
    node *newNode = malloc(sizeof(node));
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;
    node *tempPtr = head;
    while (tempPtr->next != NULL)
    {
        tempPtr = tempPtr->next;
    }
    tempPtr->next = newNode;
    newNode->prev = tempPtr;
    return head;
}

int main()
{
    node *head = malloc(sizeof(node));
    head->prev = NULL;
    head->data = 60;
    head->next = NULL;
    head = addAtEnd(head, 66);
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
    return 0;
}
