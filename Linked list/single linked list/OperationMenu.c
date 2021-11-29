//INCOMPLETE
// //Insert, delete mode at certain postion, reversing a single linked list
// //Insert, delete at the beginning. Insert, delete at the end and delete entire Linked list
// #include <stdio.h>
// #include <stdlib.h>
// typedef struct node
// {
//     int data;
//     struct node *link;
// } node;
// node *creatList(node *head)
// {
//     int num;
//     printf("Enter the data: ");
//     scanf("%d", num);
//     head->data = num;
//     head->link = NULL;
//     return head;
// }
// void printList(node *ptr)
// {
//     // ptr = head;
//     while (ptr != NULL)
//     {
//         printf("%d", ptr->data);
//         ptr = ptr->link;
//     }
// }
// node *addAtEnd(node *ptr)
// {
//     int n;
//     printf("Enter the data: ");
//     scanf("%d", &n);
//     node *temp = malloc(sizeof(node));
//     temp->data = n;
//     temp->link = NULL;
//     ptr->link = temp;
//     return temp;
// }
// int main()
// {
//     int num;
//     node *head = NULL;
//     node *ptr = head;
//     head = (node *)malloc(sizeof(node));
//     printf("Creating first node\n");
//     printf("Enter the 1st node's data: ");
//     scanf("%d", num);
//     head->data = num;
//     head->link = NULL;
//     int choice;
//     do
//     {
//         printf("\n\n1. Creat a single linked list\n");
//         printf("2. Insert at end\n");
//         printf("3. Insert at beginning\n");
//         printf("4. Insert at certain position\n");
//         printf("5. Delete last node\n");
//         printf("6. Delete first node\n");
//         printf("7. Delete certain postion\n");
//         printf("8. Reverse the Linked list\n");
//         printf("9. Display the Linked list\n");
//         printf("10. Delete the entire Linked list\n");
//         printf("0. Exit\n");
//         printf("\nEnter your option: ");
//         scanf("%d", &choice);
//         switch (choice)
//         {
//         case 0:
//             break;
//         case 1:
//             head = creatList(head);
//             break;
//         case 2:
//             ptr = addAtEnd(ptr);
//         case 9:
//             ptr = head;
//             printList(ptr);
//         default:
//             printf("\nInvalid option!");
//             break;
//         }
//     } while (choice != 0);
//     return 0;
// }