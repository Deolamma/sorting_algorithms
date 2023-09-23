#include "sort.h"

/**
 * partition - handles te division of array into partitions
 * @array: the array to be divided
 * @start: lowwer bound
 * @end: upper bound
 * @size: size of the array
 *
 * Return: the end variable
 */

int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int temp;
	int i = start - 1;

	while (start <= end - 1)
	{
		if (array[start] <= pivot)
		{
			i++;
			/* when the value of start is <= pivot*/
			if (i != start)
			{
				temp = array[i];
				array[i] = array[start];
				array[start] = temp;
				print_array(array, size);

			}
		}
		start++;
	}
	/* move the pivot to the right position */
	if (i + 1 != end)
	{
		temp = array[i + 1];
		array[i + 1] = array[end];
		array[end] = temp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quicksort - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: the array to be divided
 * @start: lowwer bound
 * @end: upper bound
 * @size: size of the array
 */

void quicksort(int *array, int start, int end, size_t size)
{
	int loc;

	if (start < end)
	{
		loc = partition(array, start, end, size);
		quicksort(array, start, loc - 1, size);
		quicksort(array, loc + 1, end, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: the array to be divided
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	int start = 0;
	int end = size - 1;

	if (array == NULL || size < 2)
		return;

	quicksort(array, start, end, size);
}
