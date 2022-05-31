// Insertion a Node at a Certain Position
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
node *addAtBeg(node *head, int data) // Function for inserting at the beginning
{
  node *ptr = malloc(sizeof(node));
  ptr->data = data;
  ptr->link = head;
  head = ptr;
  return head;
}
void addAtPos(node *head, int data, int pos)
{
  node *ptr = head;

  while (ptr != NULL)
  {
    if (pos == ptr->data)
    {
      break;
    }
    else
    {
      ptr = ptr->link;
    }
  }
  if (ptr == NULL)
  {
    printf("Node is not present!");
  }
  else
  {
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->link = NULL;
    newNode->link = ptr->link;
    ptr->link = newNode;
  }
}
void printList(node *ptr)
{
  while (ptr != NULL)
  {
    printf("%d ", ptr->data);
    ptr = ptr->link;
  }
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
  printList(head);
  int pos, data;
  printf("\nEnter the element after which you want to insert the data: ");
  scanf("%d", &pos);
  printf("Enter the data you want to insert: ");
  scanf("%d", &data);
  addAtPos(head, data, pos);
  printList(head);
  // ptr = head;

  return 0;
}