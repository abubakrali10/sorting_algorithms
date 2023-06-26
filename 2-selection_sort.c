#include "sort.h"

void swap(int *a, int *b);

/**
 * selection_sort - sorting array using selection sor algo
 * @array: pointer to array to be sorted
 * @size: size of given array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, minIndex;

	for (i = 0; i < size - 1; i++)
	{
		minIndex = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
				swap(&array[i], &array[minIndex]);
				print_array(array, size);
			}
		}
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
