// Insertion after the given position to the doubly linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;
node *addToEmpty(node *head, int data) // This will add a new node to the pointer head.
{
    node *temp = malloc(sizeof(node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}
node *addAtEnd(node *head, int data) // This will add new node at the end of the list.
{
    node *tempNode = addToEmpty(head, data); // Insted of creating new node locally, I have called addToEmpty function to create new node.
    // node *tempNode = malloc(sizeof(node));
    // tempNode->prev = NULL;
    // tempNode->data = data;
    // tempNode->next = NULL;
    node *tempPtr = head;
    while (tempPtr->next != NULL)
    {
        tempPtr = tempPtr->next;
    }
    tempPtr->next = tempNode;
    tempNode->prev = tempPtr;
    return head;
}
node *addAfterPos(node *head, int data, int position) // This will add the new node at the given position.
{
    node *newNode = addToEmpty(head, data); // This will creat the new node.

    node *temp = head;
    node *temp2 = NULL;
    while (position != 1)
    {
        temp = temp->next;
        position--;
    }
    if (temp->next == NULL) // If the postion is the last node then this function will come in action and add the new node at the last position.
    {
        temp->next = newNode;
        newNode->prev = temp;
    }
    else
    {
        temp2 = temp->next;
        temp->next = newNode;
        temp2->prev = newNode;
        newNode->prev = temp;
        newNode->next = temp2;
    }
    return head;
}

int main()
{
    node *head = NULL;
    int position = 1;
    head = addToEmpty(head, 1);
    head = addAtEnd(head, 66);
    head = addAtEnd(head, 33);
    head = addAtEnd(head, 11);
    head = addAfterPos(head, 69, position); // Here position = 2, so the new node will be added after 2nd node.
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
    return 0;
}
