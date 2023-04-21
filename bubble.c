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
void bubble_sort(int arr[], int n)
{
    int i, j;
    int swapped;

    for (i = 0; i < n; i++)
    {
    swapped = 0;
        for (j = 1; j < n; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(&arr[j], &arr[j - 1]);
                swapped++;
            }
        }
        if (swapped == 0)
            return;
    }
}

int main(void)
{
    int arr[] = {56, 25, 6, 33, 21, 11, 49, 15, 56};

    print_arr(arr, 9);
    bubble_sort(arr, 9);
    print_arr(arr, 9);
    return (0);
}