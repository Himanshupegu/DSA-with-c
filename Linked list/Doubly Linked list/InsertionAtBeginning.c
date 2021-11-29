// Insertion at the beginning of doubly linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;

node *addAtBeg(node *head, int data)
{
    node *temp = malloc(sizeof(node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}
int main()
{
    node *head = malloc(sizeof(node));
    head->prev = NULL;
    head->data = 50;
    head->next = NULL;
    head = addAtBeg(head, 55);
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");

    return 0;
}