#include "sort.h"


/**
 * selection_sort - sorts an array of integers
 * in ascending order using the Selection sort algorithm.
 * @array: an array of ints.
 * @size: the size of array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min, tmp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		for (j = i + 1; j < size; j++)
			if (array[j] < min)
				min = array[j];

		if (min != array[i])
		{
			tmp = array[i];
			array[i] = min;
			min = tmp;
			print_array(array, size);
		}
	}
}
