//Menu driven programing - i) Insertion ii) Deletion iii) Traversing
#include <stdio.h>
#define N 50

void insert(int size, int a[])
{
    int position, data, i;
    printf("Enter the position: ");
    scanf("%d", &position);
    printf("Enter the data you want to insert: ");
    scanf("%d", &data);
    for (i = size - 1; i >= position - 1; i--)
    { 
        
        a[i + 1] = a[i];
    }
    a[position - 1] = data;
    size++;
    printf("The array elements after insertion: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
}
void delete (int size, int a[])
{
    int position, i;
    printf("Enter the position from which you want to delete the data: ");
    scanf("%d", &position);
    if (position <= 0 || position > size)
    {
        printf("Invalid position!");
    }
    else
    {
        for (i = position - 1; i < size - 1; i++)
        {
            a[i] = a[i + 1];
        }
        size--;
    }
    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
}
void traversing(int size, int a[])
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("Element in index %d : %d\n", i, a[i]);
    }
}
int main()
{
    int a[N], size, i;
    printf("Enter size of Array: ");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
    {
        printf("Enter the input for index %d: ", i);
        scanf("%d", &a[i]);
    }
    printf("Array elements are as follows: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }

    int choice;
    do
    {
        printf("\n1. Insertion\n2. Deletion\n3. Traversing\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert(size, a);
            break;
        case 2:
            delete (size, a);
            break;
        case 3:
            traversing(size, a);
            break;
        }
    } while (choice != 0);
    return 0;
}
