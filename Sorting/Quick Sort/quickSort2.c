#include <stdio.h>

void swap(int *i, int *j)
{

    int temp = *i;
    *i = *j;
    *j = temp;
}

// Hoare Partition
int partision(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = (low + 1);
    int j = high;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }

    } while (i < j);

    swap(&arr[j], &arr[low]);

    return j;
}

void quickSort(int arr[], int low, int high)
{

    if (low < high)
    {
        int prt = partision(arr, low, high);

        quickSort(arr, low, prt - 1);
        quickSort(arr, prt + 1, high);
    }
}

void printArray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {

        printf("%d ", arr[i]);
    }
}
int main()
{

    int arr[] = {1,2,3,4,5,8,9,13,15,22};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("\nUnsorted array\n");
    printArray(arr, size);

    printf("\nSorted array after calling quickSort function\n");
    quickSort(arr, 0, size - 1);
    printArray(arr, size);
    printf("\n\n");
    return 0;
}
