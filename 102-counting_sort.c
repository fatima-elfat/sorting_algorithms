#include "sort.h"
/**
 * counting_sort - sorts an array of integers
 * in ascending order using the Counting sort algorithm.
 * @array: an array of ints.
 * @size: the size of array.
 */
void counting_sort(int *array, size_t size)
{
	int i, j;
	int *cont, *l;

	if (!array || size < 2)
		return;
	for (j = array[0], i = 1; i < (int)size; i++)
	{
		if (array[i] > j)
			j = array[i];
	}
	cont = malloc(sizeof(int) * (j + 1));
	if (cont == NULL)
		return;
	for (i = 0; i < (j + 1); i++)
		cont[i] = 0;
	for (i = 0; i < (int)size; i++)
		cont[array[i]] += 1;
	for (i = 0; i < j; i++)
		cont[i + 1] += cont[i];
	print_array(cont, j + 1);
	l = malloc(sizeof(int) * size);
	if (!l)
		return;
	for (i = 0; i < (int)size; i++)
	{
		l[cont[array[i]] - 1] = array[i];
		cont[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = l[i];
	free(l);
	free(cont);
}
