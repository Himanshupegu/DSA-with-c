// Deleting the first node of an doubly linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;
node *addToEmpty(node *head, int data) // Function for adding node to a pointer
{
    node *newNode = malloc(sizeof(node));
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;
    head = newNode;
    return head;
}
node *addAtEnd(node *head, int data) // Function for adding node at the end
{
    node *newNode = addToEmpty(head, data);
    node *tempPtr = head;
    while (tempPtr->next != NULL)
    {
        tempPtr = tempPtr->next;
    }
    tempPtr->next = newNode;
    newNode->prev = tempPtr;
    return head;
}
node *createList(node *head) // Function for creating an doubly lingked list
{
    int data, n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if (n == 0)
        return head;
    printf("Enter the element for the node 1: ");
    scanf("%d", &data);
    head = addToEmpty(head, data);
    for (int i = 1; i < n; i++)
    {
        printf("Enter the element for the node %d: ", i + 1);
        scanf("%d", &data);
        head = addAtEnd(head, data);
    }
    return head;
}
node *deleteFirst(node *head)
{
    if (head == NULL)
    {
        printf("List is already empty!!");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
    }
    else
    {
        head = head->next;
        free(head->prev);
        head->prev = NULL;
    }
    return head;
}
void printList(node *head) // Function for printing the doubly linked list
{
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d <=> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}
int main()
{
    node *head = NULL;
    head = createList(head);
    printf("\nBefore deleting the last node: ");
    printList(head);
    head = deleteFirst(head);
    printf("\nAfter  deleting the fist node: ");
    printList(head);
    printf("\n\n");
    return 0;
}
