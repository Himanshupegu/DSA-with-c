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
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != tail->next);
}

int main()
{
    node *tail;
    int data = 45;
    tail = addToEmpty(data);
    tail = addAtEnd(tail, 35);
    tail = addAtEnd(tail, 55);
    printList(tail);

    return 0;
}