// Find the middle of a given linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} node;
void pushNode(node **head, int data)
{
    node *newData = (node *)malloc(sizeof(node));
    newData->data = data;
    newData->link = *head;
    *head = newData;
}
void printList(node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}
void printMidNode(node *head)
{
    node *slowPtr = head;
    node *fastPtr = head;
    if (head != NULL)
    {
        while (fastPtr != NULL && fastPtr->link != NULL)
        {
            fastPtr = fastPtr->link->link;
            slowPtr = slowPtr->link;
        }
        printf("The mid element is %d\n\n", slowPtr->data);
    }
}
int main()
{
    node *head = NULL;
    for (int i = 5; i > 0; i--)
    {
        pushNode(&head, i);
        printList(head);
        printMidNode(head);
    }
    return 0;
}