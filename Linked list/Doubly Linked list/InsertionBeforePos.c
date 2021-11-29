// Insert before the given position
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;

node *addTOEmpty(node *head, int data)
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
    node *newNod = addTOEmpty(head, data);
    node *tempPtr = head;
    while (tempPtr->next != NULL)
    {
        tempPtr = tempPtr->next;
    }
    tempPtr->next = newNod;
    newNod->prev = tempPtr;
    return head;
}
node *addAtBeg(node *head, int data)
{
    node *newNode = addTOEmpty(head, data);
    head->prev = newNode;
    return head;
}
node *addBeforePos(node *head, int data, int position)
{
    node *newNode = addTOEmpty(head, data);
    node *temp = head;
    node *temp2 = NULL;
    while (position > 2)
    {
        temp = temp->next;
        position--;
    }
    if (position == 1)
    {
        head = addAtBeg(head, data);
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
    head = addTOEmpty(head, 11);
    head = addAtEnd(head, 22);
    head = addAtEnd(head, 33);
    int position = 2;
    head = addBeforePos(head, 66, position);
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");

    return 0;
}