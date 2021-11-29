#include <stdio.h>
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
    int element;
    printf("\nEnter the element you want to search: ");
    scanf("%d", &element);
    sort(arr, size);
    printf("\nArrary elements are as follows: \n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }
    int first, mid, last;
    first = 0;
    last = size - 1;
    while (first <= last)
    {
        mid = (first + last) / 2;
        if (arr[mid] == element)
        {
            printf("\n%d is found at index %d: ", element, mid);
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
        printf("\n\n%d is not found.(Element is not in the list)", element);
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
        // for (int i = 0; i < size - 1; i++)
        // {
        //     for (int j = i + 1; j < size; j++)
        //     {
        //         int x;
        //         if (a[i] > a[j])
        //         {
        //             x = a[i];
        //             a[i] = a[j];
        //             a[j] = x;
        //         }
        //     }
        // }
    }
    // printf("Sorted element : ");
    // for (int i = 0; i < size; i++)
    // {
    //     printf(" %d ", a[i]);
    // }
    binarySearch(a, size);
    return 0;
}