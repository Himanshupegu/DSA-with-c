//Insertion at the end of the list
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} node;
void addAtEnd(node *head, int data)
{
    node *ptr, *temp;
    ptr = head;
    temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->link = NULL;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}
int main()
{
    node *head = malloc(sizeof(node));
    head->data = 45;
    head->link = NULL;
    addAtEnd(head, 50);
    addAtEnd(head, 3);
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}