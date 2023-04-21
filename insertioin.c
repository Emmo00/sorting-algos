#include <stdio.H>

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
void *insertion_sort(int arr[], int n)
{
	int i, j;

	for (i = 1; i < n; i++)
	{
		j = i;
		while (arr[j] < arr[j - 1] && j > 0)
		{
			swap(&arr[j], &arr[j - 1]);
			j--;
		}
	}
}

int main(void)
{
	int arr[] = {56, 25, 6, 33, 21, 11, 49, 15, 56};

	print_arr(arr, 9);
	insertion_sort(arr, 9);
	print_arr(arr, 9);
	return (0);
}