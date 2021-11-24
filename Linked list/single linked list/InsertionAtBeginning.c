// Insertion at the beginning of the list
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} node;
node *addAtEnd(node *ptr, int data)
{
    node *temp = malloc(sizeof(node));
    temp->data = data;
    temp->link = NULL;
    ptr->link = temp;
    return temp;
}
node *addAtBeg(node *head, int data) // Function for inserting at the beginning
{
    node *ptr = malloc(sizeof(node));
    ptr->data = data;
    ptr->link = head;
    head = ptr;
    return head;
}
void printList(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NUll");
}
int main()
{
    node *head = NULL;
    head = malloc(sizeof(node));
    head->data = 45;
    head->link = NULL;
    node *ptr = head;
    ptr = addAtEnd(ptr, 96);
    ptr = addAtEnd(ptr, 69);
    ptr = addAtEnd(ptr, 90);
    printf("\nBefore inserting at the beginning: ");
    printList(head);
    head = addAtBeg(head, 23);
    printf("\nAfter  inserting at the beginning: ");
    printList(head);
    printf("\n\n");
    return 0;
}