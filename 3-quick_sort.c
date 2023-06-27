#include "sort.h"

void swap(int *a, int *b);
int lomuto_partition(int *array, size_t size, int low, int high);
void sort(int *array, size_t size, int low, int high);

/**
 * quick_sort - sorting array in ascending order
 * @array: array to be sorted
 * @size: length of the array
*/
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	sort(array, size, 0, size - 1);
}

/**
 * sort - recursion for quicksort
 * @array: the array to be sorted
 * @size: length of the array
 * @low: starting index of array
 * @high: ending index of array
*/
void sort(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int pivot = lomuto_partition(array, size, low, high);

		sort(array, size, low, pivot - 1);
		sort(array, size, pivot + 1, high);
	}
}

/**
 * lomuto_partition - getting the pivot and put it in it's appropriate position
 * @array: the array
 * @size: length of subset array
 * @low: starting index of subset
 * @high: ending index of subset
 * Return: the pivot index
*/
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot_val, i, j;

	pivot_val = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot_val)
		{
			if (i < j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > pivot_val)
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * swap - swapping two elements
 * @a: pointer to first element to swap
 * @b: pointer to second element to swap
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
