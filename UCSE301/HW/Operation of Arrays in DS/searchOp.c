#include <stdio.h>
#define N 50
void search(int num, int arrayElemens[], int element)
{
    int i;
    for (i = 0; i < num; i++)
    {
        if (arrayElemens[i] == element)
        {
            break;
        }
    }
    printf("Found element %d at position %d and number of count is %d\n", element, i + 1, i + 1);
}
int main()
{
    int num, i, element, arrayElemens[N];
    printf("Enter size of array: ");
    scanf("%d", &num);
    if (num >= N)
    {
        printf("You have excited the limited (Enter size between 1 to 50)");
    }
    else
    {
        for (i = 0; i < num; i++)
        {
            printf("Enter the element for index %d :", i);
            scanf("%d", &arrayElemens[i]);
        }
        printf("Enter the element you want to search: ");
        scanf("%d", &element);

        search(num, arrayElemens, element);
    }

    return 0;
}