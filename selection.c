#include <stdio.h>

void print_arr(int arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *x, int *y)
{
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}
void selection_sort(int arr[], int n)
{
    int min, i, j, minIndex;

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

int main(void)
{
    int arr[] = {56, 25, 6, 33, 21, 11, 49, 15, 56};

    print_arr(arr, 9);
    selection_sort(arr, 9);
    print_arr(arr, 9);
    return (0);
}