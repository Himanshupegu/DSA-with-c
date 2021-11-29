// Deleting the last node of an linked list.
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} node;
node *addToEmpty(node *head, int data) // Function for inserting a node to the pointer head.
{
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->link = NULL;
    head = newNode;
    return head;
}
node *addAtEnd(node *head, int data) // Function for inserting a node at the end.
{
    node *newNod = addToEmpty(head, data);
    node *tempPtr = head;
    while (tempPtr->link != NULL)
    {
        tempPtr = tempPtr->link;
    }
    tempPtr->link = newNod;
    return head;
}
node *deleteAtLast(node *head) // Function for deleting the last node.
{
    if (head == NULL)
        printf("List is already empty!");
    else if (head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        node *temp = head;
        node *temp2 = head;
        while (temp->link != NULL)
        {
            temp2 = temp;
            temp = temp->link;
        }
        temp2->link = NULL;
        free(temp);
        temp = NULL;
    }
    return head;
}
node *createList(node *head) // Function for creating an Linked list.
{
    int data, n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if (n == 0)
    {
        return head;
    }
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
void printList(node *ptr) // Function for printing the linked list.
{
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL");
}
int main()
{
    node *head = NULL;
    head = createList(head);
    printf("\nBefore deleting the last node: ");
    printList(head);
    head = deleteAtLast(head);
    printf("\nAfter  deleting the last node: ");
    printList(head);
    printf("\n\n");

    return 0;
}