// Reversing a single linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} node;
node *reverse(node *head)
{
    node *prev = NULL;
    node *next = NULL;
    while (head != NULL)
    {
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
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
    head = reverse(head);
    node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    return 0;
}