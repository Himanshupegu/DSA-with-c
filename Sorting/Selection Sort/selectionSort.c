#include <stdio.h>
#include <stdlib.h>
#define N 10

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
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
    print(arr, size);
}

void selectionSort(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            // swap(arr[i], arr[min]);
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int main()
{
    int arr[N];
    int size;
    printf("Enter the number of element: ");
    scanf("%d", &size);
    creatArray(arr, size);
    selectionSort(arr, size);
    printf("\n\nAfter Selection Sort array elements are as follow: ");
    print(arr, size);
}