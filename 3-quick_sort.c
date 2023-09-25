#include "sort.h"

/**
 * Lomuto_parts - uses the Lomuto partition.
 * @array: an array of ints.
 * @size: the size of array.
 * @start: the start of the array.
 * @end: the end of the array.
 * Return: ...
 */
int Lomuto_parts(int *array, int size, int start, int end)
{
	int pivot = array[end];
	int a, t, z;

	for (a = z = start; z < end; z++)
	{
		if (array[z] <= pivot)
		{
			if (a != z)
			{
				t = array[a];
				array[a] = array[z];
				array[z] = t;
				print_array(array, size);
			}
			a++;
		}
	}
	if (a != end)
	{
		t = array[a];
		array[a] = array[end];
		array[end] = t;
		print_array(array, size);
	}
	return (a);
}
/**
 * qs_recursion - uses recursion to quick sort.
 * @array: an array of ints.
 * @size: the size of array.
 * @start: the start of the array.
 * @end: the end of the array.
 */
void qs_recursion(int *array, int size, int start, int end)
{
	int pivot;

	if (start < end)
	{
		pivot = Lomuto_parts(array, size, start, end);
		qs_recursion(array, size, start, pivot - 1);
		qs_recursion(array, size, pivot + 1, end);
	}
}
/**
 * quick_sort - sorts an array of integers in
 * ascending order using the Quick sort algorithm.
 * @array: an array of ints.
 * @size: the size of array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs_recursion(array, size, 0, size - 1);
}
