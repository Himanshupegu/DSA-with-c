// Deleting the node at a particular position
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
void delPos(node **head, int position)
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
      current = current->link;
      // previous = current;
      // current = current->link;
      position--;
    }
    // previous->link = current->link;
    free(current);
    current = NULL;
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
  int position;
  printf("\nEnter the position you want to delete: ");
  scanf("%d", &position);
  delPos(&head, position);
  printList(head);
  return 0;
}