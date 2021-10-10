//Deleting the entire single linked list
//Insertion a Node at a Certain Position
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} node;
node *addAtEnd(node *ptr, int data)
{
    node *temp = malloc(sizeof(node));
    temp->data = data;
    temp->link = NULL;
    ptr->link = temp;
    return temp;
}
void addAtPos(node *head, int data, int pos)
{
    node *ptr = head;
    node *ptr2 = malloc(sizeof(node));
    ptr2->data = data;
    ptr2->link = NULL;
    pos--;
    while (pos != 1)
    {
        ptr = ptr->link;
        pos--;
    }
    ptr2->link = ptr->link;
    ptr->link = ptr2;
}
node *delList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->link;
        free(head);
        head = temp;
    }
    return head;
}
int main()
{
    node *head = NULL;
    head = malloc(sizeof(node));
    head->data = 45;
    head->link = NULL;
    node *ptr = head;
    ptr = addAtEnd(ptr, 96);
    ptr = addAtEnd(ptr, 69);
    ptr = addAtEnd(ptr, 90);
    int pos, data;
    printf("Enter the Position you want to insert the data: ");
    scanf("%d", &pos);
    printf("Enter the data you want to insert: ");
    scanf("%d", &data);
    addAtPos(head, data, pos);
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    head = delList(head);
    if (head == NULL)
        printf("\nLinked list is deleted successfully!");
    return 0;
}