// Deleting the Intermediate note or the given position's node
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;
node *addToEmpty(node *head, int data)
{
    node *newNode = malloc(sizeof(node));
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;
    head = newNode;
    return head;
}
node *addAtEnd(node *head, int data)
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
node *createList(node *head)
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
node *deleteInter(node *head, int position) // Function for deleting the intermediate node or given position's node.
{
    node *temp = head;
    node *temp2 = NULL;
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
        while (position > 1)
        {
            temp = temp->next;
            position--;
        }
        temp2 = temp->prev;
        temp2->next = temp->next;
        temp->next->prev = temp2;
        free(temp);
        temp = NULL;
    }
    return head;
}
void printList(node *ptr)
{
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
    int position = 3;
    head = createList(head);
    printf("\nBefore deleting the intermediate node: ");
    printList(head);
    head = deleteInter(head, position);
    printf("\nAfter  deleting the intermediate node: ");
    printList(head);
    printf("\n\n");
    return 0;
}
