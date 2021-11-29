#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
node *addToEmpty(int data)
{
    node *tempNode = malloc(sizeof(node));
    tempNode->data = data;
    tempNode->next = tempNode;
    return tempNode;
}
node *addAtEnd(node *tail, int data) // Function for inserting node at beginning of the circular singly linked list.
{
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
    return tail;
}
void printList(node *tail) // Function for Traversing Circular singly linked list
{
    node *ptr = tail->next;
    do
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != tail->next);
}
node *createList(node *tail)
{

    int num, data;
    printf("Enter the number of element: ");
    scanf("%d", &num);
    if (num == 0)
    {
        return tail;
    }
    printf("Enter the 1 element: ");
    scanf("%d", &data);
    tail = addToEmpty(data);
    for (int i = 1; i < num; i++)
    {
        printf("Enter the %d element: ", i + 1);
        scanf("%d", &data);
        tail = addAtEnd(tail, data);
    }
    return tail;
}
node *deleteLastNode(node *tail)
{
    node *tempPtr = tail->next;
    while (tempPtr->next != tail)
    {
        tempPtr = tempPtr->next;
    }
    tempPtr->next = tail->next;
    free(tail);
    tail = tempPtr;
    return tail;
}
int main()
{
    node *tail;
    tail = createList(tail);
    printList(tail);
    tail = deleteLastNode(tail);
    printf("\n");
    printList(tail);

    return 0;
}