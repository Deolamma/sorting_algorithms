#include "sort.h"
/**
 * selection_sort - Sorts a given array using selection sort algortihm
 * @array: Array to be sorted
 * @size: size of the given array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_val, tmp;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_val = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_val])
				min_val = j;
		}
		if (i != min_val)
		{
			tmp = array[i];
			array[i] = array[min_val];
			array[min_val] = tmp;
			print_array(array, size);
		}
	}
}
