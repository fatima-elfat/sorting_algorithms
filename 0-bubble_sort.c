#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm.
 * @array: an array of ints.
 * @size: the size of array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	int tmp, b = 0;

	if (!array || size < 2)
		return;

	while (!b)
	{
		b = 1;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
				b = 0;
			}
		}
		len--;
	}
}
