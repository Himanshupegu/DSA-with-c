#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} node;

node *addToEmpty(node *head, int data) // Function for adding node to empty head
{
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->link = NULL;
    head = newNode;
    return head;
}
node *addAtEnd(node *head, int data) // Function for adding node at end of the Linked List
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
node *createList(node *head) // Function for creating an Linked List
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
    printf("\n");
    return head;
}
node *addAtBeg(node *head, int data) // Function for inserting node at the beginning
{
    node *ptr = malloc(sizeof(node));
    ptr->data = data;
    ptr->link = head;
    head = ptr;
    return head;
}
node *deleteAtBeg(node *head) // Function for deleting the beginning node
{
    if (head == NULL)
        printf("List ia already empty");
    else
    {
        node *temp = head;
        head = head->link;
        free(temp);
        temp = NULL;
    }
    return head;
}
node *deleteAtLast(node *head) // Function for deleting the last node.
{
    if (head == NULL)
        printf("List is already empty!");
    else if (head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        node *temp = head;
        node *temp2 = head;
        while (temp->link != NULL)
        {
            temp2 = temp;
            temp = temp->link;
        }
        temp2->link = NULL;
        free(temp);
        temp = NULL;
    }
    return head;
}
void deleteAtPos(node **head, int position) // Function for deleting at particular position.
{
    node *current = *head;
    node *previous = *head;
    if (*head == NULL)
        printf("List is already empty!");
    else if (position == 1)
    {
        *head = current->link;
        free(current);
        current = NULL;
    }
    else
    {
        while (position != 1)
        {
            previous = current;
            current = current->link;
            position--;
        }
        previous->link = current->link;
        free(current);
        current = NULL;
    }
}
void addAtPos(node *head, int data, int pos)
{
    node *ptr = head;
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->link = NULL;

    pos--;
    while (pos != 1)
    {
        ptr = ptr->link;
        pos--;
    }
    newNode->link = ptr->link;
    ptr->link = newNode;
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
    int choice, insertAtEndData, insertAtBegData, insertionPos, insertAtPosData, deleteAtBegData, deleteAtPosData;
    do
    {

        printf("\n1. Create an Linked list.\n2. Insert at beginning\n3. Insert at end\n4. Insert at particular position\n5. Delete at beginning\n6. Delete at end\n7. Delete at particular position\n8. Display\n0. Exit\n\n");
        printf(">> ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            head = createList(head);
            printList(head);
            printf("\n\nLinked is created successfully.");
            printf("\n");
            break;
        case 2:
            printf("Enter the data you want to insert: ");
            scanf("%d", &insertAtBegData);
            printf("\n");
            head = addAtBeg(head, insertAtBegData);
            printList(head);
            printf("\n\nUpdated Linked List after inserting at beginning.\n");
            break;
        case 4:
            printf("\nEnter the postion you want to insert the node: ");
            scanf("%d", &insertionPos);
            printf("\nEnter the data you want to insert: ");
            scanf("%d", &insertAtPosData);
            printf("\n");
            addAtPos(head, insertAtPosData, insertionPos);
            printList(head);
            printf("\n\nUpdated Linked List after inserting at %d position.", insertionPos);
            break;
        case 3:
            printf("Enter the number you want to insert: ");
            scanf("%d", &insertAtEndData);
            printf("\n");
            head = addAtEnd(head, insertAtEndData);
            printList(head);
            printf("\n\nUpdated Linked List after inserting at end.\n");
            break;
        case 5:
            head = deleteAtBeg(head);
            printList(head);
            printf("\n\nUpdate Linked List after deleting first node.\n");
            break;
        case 6:
            head = deleteAtLast(head);
            printList(head);
            printf("\n\nUpdate Linked List after deleting last node.\n");
            break;
        case 7:
            printf("Enter the position you want to delete the node from: ");
            scanf("%d", &deleteAtPosData);
            printf("\n");
            deleteAtPos(&head, deleteAtPosData);
            printList(head);
            printf("\n\nUpdate Linked List after deleting at %d position.\n", deleteAtPosData);
            break;
        case 8:
            printList(head);
            printf("\n");
            break;
        case 0:
            printf("Exit...");
            break;
        default:
            printf("\nINVALID OPTION!!");
            break;
        }
    } while (choice != 0);
    return 0;
}