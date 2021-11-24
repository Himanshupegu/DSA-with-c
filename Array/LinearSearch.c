#include <stdio.h>
#define N 20
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", array[i]);
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
    int a[20], i, size;
    printf("Enter the number of element: ");
    scanf("%d", &size);
    if (size > 20)
    {
        printf("Please enter the number of element under 20(Array size is 20)");
    }
    else
    {
        for (i = 0; i < size; i++)
        {
            printf("Enter the input for index %d: ", i);
            scanf("%d", &a[i]);
        }

        linearSearch(a, size);
    }

    return 0;
}