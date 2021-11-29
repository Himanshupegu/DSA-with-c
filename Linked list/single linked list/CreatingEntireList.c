// Creating an entire linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} node;

node *addToEmpty(node *head, int data)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->link = NULL;
    head = newNode;
    return head;
}
node *addAtEnd(node *head, int data)
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
node *createList(node *head)
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
void printList(node *ptr)
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
    printList(head);
    printf("\nLinked is created successfully.");
    printf("\n\n");
    return 0;
}