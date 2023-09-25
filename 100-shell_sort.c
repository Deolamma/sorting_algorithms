#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using
 * the Shell sort algorithm, using the Knuth sequence
 * @array: array to be tested
 * @size:size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t j, i;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (gap <= size / 3)
	{
		gap = gap * 3 - 1;
	}

	while (gap > 0)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; i < size &&
				array[i + gap] < array[i]; i = i - gap)
			{
				temp = array[i];
				array[i] = array[i + gap];
				array[i + gap] = temp;
			}
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
