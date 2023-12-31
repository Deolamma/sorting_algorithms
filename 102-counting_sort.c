#include "sort.h"

/**
 * max -max element in the array
 * @array: array to be sorted
 * @size: size of the array
 * Return: the maximum element
 */

int max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort -  sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void counting_sort(int *array, size_t size)
{
	int i, k, *count = NULL, *output = NULL;

	if (array == NULL || size < 2)
		return;

	k = max(array, size);
	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}

	for (i = 0; i <= k; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		++count[array[i]];

	for (i = 1; i <= k; i++)
		count[i] = count[i] + count[i - 1];

	print_array(count, k + 1);

	for (i = size - 1; i >= 0; i--)
		output[--count[array[i]]] = array[i];

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
