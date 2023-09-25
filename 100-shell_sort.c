#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence.
 * @array: an array of ints.
 * @size: the size of array.
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, tmp, gap = 1;

	if (!array || size < 2)
		return;
	while (gap < (size / 3))
		gap = gap * 3 + 1;
	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				tmp = array[j];
				array[j] = array[j - gap];
				array[j - gap] = tmp;
				j = j - gap;
			}
		}
		print_array(array, size);
	}
}
