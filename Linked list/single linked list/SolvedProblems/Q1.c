// Consider an implementation of unsorted single linked list.Suppose it has its representation with a head and a tail pointer(i.e.pointers to the first and last nodes of the linked list).
// Given the representation, which of the following operation can not be implemented in O(1) time
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} node;
void addAtEnd(node *tail, int data)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->link = NULL;
    tail->link = tail;
}
int main()
{
    node *head = NULL;
    head = (node *)malloc(sizeof(node));
    head->data = 45;
    head->link = NULL;
    node *current = malloc(sizeof(node));
    current->data = 98;
    current->link = NULL;
    head->link = current; // linking 1st node with 2nd node
    current = malloc(sizeof(node));
    current->data = 3;
    current->link = NULL;
    head->link->link = current;
    node *tail = NULL;
    tail = current;
    addAtEnd(tail, 50);
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->link;
    }
    return 0;
}