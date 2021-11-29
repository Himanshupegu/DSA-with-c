#include <stdio.h>
#define N 20
void printArray(int arr[], int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
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
void deletion(int arr[], int size)
{
    int pos;
    printf("\nEnter the postion you want to delete: ");
    scanf("%d", &pos);
    if (pos < 0 || pos > size)
    {
        printf("\n\nINVALID POSITION!!\n\n");
    }
    else
    {
        for (int i = pos - 1; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        printf("Updated array list: ");
        printArray(arr, size);
    }
}
void sort(int a[], int n)
{
    int x;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                x = a[i];
                a[i] = a[j];
                a[j] = x;
            }
        }
    }
}
void binarySearch(int arr[], int size)

{
    sort(arr, size);
    printf("\nSorted array elements are as follows: \n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }
    int element;
    printf("\n\nEnter the element you want to search: ");
    scanf("%d", &element);
    int first, mid, last;
    first = 0;
    last = size - 1;
    while (first <= last)
    {
        mid = (first + last) / 2;
        if (arr[mid] == element)
        {
            printf("\n%d is found at index %d\n", element, mid);
            break;
        }
        if (arr[mid] < element)
        {
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }
    if (first > last)
    {
        printf("\n\n%d is not found (Element is not in the list).\n\n", element);
    }
}
void linearSearch(int arr[], int size)
{
    int element, index;
    printf("\nArrary elements are as follows: \n");
    printArray(arr, size);
    printf("\nEnter the element you want to search: ");
    scanf("%d", &element);
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            printf("\nThe element %d is found at index %d \n", element, i);
            break;
        }
    }
}
int main()
{
    int array[N], choice;
    int size;
    printf("\nEnter the number of element: ");
    scanf("%d", &size);
    do
    {
        printf("\n1) Create an array\n2) Insertion\n3) Deletion\n4) Binary Search\n5) Linear Search\n6) Print\n0) Exit\n\n");
        printf(">> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            creatArray(array, size);
            break;
        case 2:
            insertion(array, size);
            break;
        case 3:
            deletion(array, size);
            break;
        case 4:
            binarySearch(array, size);
            break;
        case 5:
            linearSearch(array, size);
            break;
        case 6:
            printArray(array, size);
        case 0:
            printf("\n\nEXIT...");
            break;
        default:
            printf("\n\nINVALID OPTION!! PLEASE TRY AGAIN....\n");
            break;
        }
    } while (choice != 0);

    return 0;
}