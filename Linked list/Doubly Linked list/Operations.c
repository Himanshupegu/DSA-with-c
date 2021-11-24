// Menu Program
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;
node *creatList(node *head)
{
    int num;
    printf("\nEnter the data: ");
    scanf("%d", &num);
    node *temp = (node *)malloc(sizeof(node));
    temp->prev = NULL;
    temp->data = num;
    temp->next = NULL;
    head = temp;
    printf("\nDoubly Linked list is created successfully.\n");
    return head;
}
void printList(node *ptr)
{
    printf("%d\n", ptr->data);
}
node *addAtBeg(node *head)
{
    int num;
    printf("Enter the data: ");
    scanf("%d", &num);
    node *temp = malloc(sizeof(node));
    temp->prev = NULL;
    temp->data = num;
    temp->next = NULL;
    temp->next = head;
    head->prev = temp;
    printf("\nNode is added successfully.\n");
    return head;
}
node *addAtEnd(node *head)
{
    int num;
    printf("Enter the data: ");
    scanf("%d", &num);
    node *tempNode = malloc(sizeof(node));
    tempNode->prev = NULL;
    tempNode->data = num;
    tempNode->next = NULL;
    node *tempPtr = head;
    while (tempPtr->next != NULL)
    {
        tempPtr = tempPtr->next;
    }
    tempPtr->next = tempNode;
    tempNode->prev = tempPtr;
    printf("\nNode is added successfully.\n");
    return head;
}
int main()
{
    node *head = NULL;
    int choice;
    do
    {
        printf("\n1. Creating a doubly linked list.\n");
        printf("2. Insert at the beginning.\n");
        printf("3. Insert at the end.\n");
        printf("7. Print the existing doubly kinked list.\n");

        printf("0. Exit\n\n");
        printf("Enter your option: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = creatList(head);
            break;
        case 2:
            head = addAtBeg(head);
            break;
        case 3:
            head = addAtEnd(head);
            break;
        case 7:
            printList(head);
            break;
        default:
            printf("Invalid option!");
            break;
        }
    } while (choice != 0);
    return 0;
}