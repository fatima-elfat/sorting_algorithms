#include "sort.h"

/**
 * ms_recursive - uses the recursive programming to merge sort.
 * @array: an array of ints.
 * @array02: the array of sorted elements.
 * @a: the start.
 * @z: the end.
 */
void ms_recursive(int *array, int *array02, size_t a, size_t z)
{
	size_t i = 0, j = 0, k = 0, middle;

	if (z > a + 1)
	{
		middle = a + (z - a) / 2;
		ms_recursive(array, array02, a, middle);
		ms_recursive(array, array02, middle, a);
		printf("Merging...\n[left]: ");
		print_array(array + a, middle - a);
		printf("[right]: ");
		print_array(array + middle, z - middle);
		for (i = a, j = middle; i < middle && j < z; k++)
		{
			if (array[i] >= array[j])
				array02[k] = array[j++];
			else
				array02[k] = array[i++];
		}
		for (; i < middle; i++)
			array02[k++] = array[i];
		for (; j < z; j++)
			array02[k++] = array[j];
		for (i = a, k = 0; i < z; i++)
			array[i] = array02[k++];
		printf("[Done]: ");
		print_array(array + a, z - a);
	}
}
/**
 * merge_sort - sorts an array of integers
 * in ascending order using the Merge sort algorithm.
 * @array: an array of ints.
 * @size: the size of array.
 */
void merge_sort(int *array, size_t size)
{
	int *array02;

	if (!(array) || size < 2)
		return;
	array02 = malloc(sizeof(int) * size);
	if (!(array02))
		return;
	ms_recursive(array, array02, 0, size);
	free(array02);
}
