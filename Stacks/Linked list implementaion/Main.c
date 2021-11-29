#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;

} *top = NULL;
void push(int data)
{
    struct node *newNode;
    newNode = malloc(sizeof(newNode));
    if (newNode == NULL)
    {
        printf("\nStack Overflow!!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->link = top;
    top = newNode;
}
int isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
        return 0;
}
int pop()
{
    struct node *temp;
    int value;
    if (isEmpty())
    {
        printf("\nStack Underflow!!\n");
        exit(1);
    }
    temp = top;
    value = temp->data;
    top = top->link;
    free(temp);
    temp = NULL;
    return value;
}
int peek()
{
    if (isEmpty())
    {
        printf("\nStack Underflow!!\n");
        exit(1);
    }
    return top->data;
}
void print()
{
    struct node *temp;
    temp = top;
    if (isEmpty())
    {
        printf("\nStack Underflow!!\n");
        exit(1);
    }
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("NULL");
}
int main()
{
    int choice, data;
    do
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Print the top element");
        printf("\n4. Print all the element of the stack");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            printf;
            ("Deleted element is %d\n", pop());
            break;
        case 3:
            printf("The topmost element in the stack is %d", peek());
            break;
        case 4:
            print();
            break;
        case 0:
            printf("\nExit...");
            break;
        default:
            printf("\nINVALID OPTION!!\n");
            break;
        }

    } while (choice != 0);
    return 0;
}