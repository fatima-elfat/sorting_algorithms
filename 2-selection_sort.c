#include "sort.h"

/**
 * selection_sort - sorts an array of integers
 * in ascending order using the Selection sort algorithm.
 * @array: an array of ints.
 * @size: the size of array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int tmp;

	if (!array || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (min = i + 1, j = size - 1; j > i ; j--)
		{
			if (array[min] > array[j])
				min = j;
		}
		if (array[min] < array[i])
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
