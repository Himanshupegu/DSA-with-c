// Taking array elements in input and printing it
#include <stdio.h>
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }
}
void insertion(int arr[], int size)
{
    int element, pos;
    printf("\n\nEnter the position you want to insert: ");
    scanf("%d", &pos);
    if (pos < 0 || pos > size)
    {
        printf("\nINVALID POSITION!!\n\n");
    }
    else
    {
        printf("Enter the element you want to insert: ");
        scanf("%d", &element);
        for (int i = size - 1; i >= pos - 1; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[pos - 1] = element;
        printf("\nArray list after insertion: ");
        printArray(arr, size);
    }
}
void creatArray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        printf("\nEnter the input for index %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n\nArray element are as follow: ");
    printArray(arr, size);
}
int main()
{
    int arr[20];
    int size;
    printf("Enter the number of element: ");
    scanf("%d", &size);
    creatArray(arr, size);
    insertion(arr, size);
    return 0;
}