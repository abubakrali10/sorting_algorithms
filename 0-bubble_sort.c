#include "sort.h"
void swap(int *a, int *b);

/**
 * bubble_sort - sorting an array using bubble sort algo
 * @array: pinter to array to be sorted
 * @size: size of given array
 */
void bubble_sort(int *array, size_t size)
{
	int flag = 0;
	size_t i, j;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				flag = 1;
			}
		}

		if (flag == 0)
			break;
	}
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
