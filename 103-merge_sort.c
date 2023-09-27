#include "sort.h"

/**
 * mergesort - performs the merge sort
 * @array: the array to be sorted
 * @lb: lowwer bound
 * @ub: upper bound
 * @output: temp array to store sorted array
 */

void mergesort(int *array, size_t lb, size_t ub, int *output)
{
	size_t mid, i;

	if (lb < ub)
	{
		mid = lb + (ub - lb) / 2;

		mergesort(array, lb, mid, output);
		mergesort(array, mid + 1, ub, output);
		merge(array, lb, mid, ub, output);

		printf("Merging...\n");
		printf("[left]: ");
		for (i = lb; i <= mid; i++)
		{
			printf("%d", array[i]);
			if (i < mid)
				printf(", ");
		}

		printf("\n[right]: ");
		for (i = mid + 1; i <= ub; i++)
		{
			printf("%d", array[i]);
			if (i < ub)
				printf(", ");
		}

		printf("\n[Done]:");
		for (i = lb; i <= ub; i++)
		{
			printf("%d", array[i]);
			if (i < ub)
				printf(", ");
		}
		printf("\n");
	}
}

/**
 * merge - performs merging
 * @array: the array to be sorted
 * @lb: lowwer bound
 * @mid: the mid index
 * @ub: upper bound
 * @output: temp array to store sorted array
 */

void merge(int *array,  size_t lb, size_t mid, size_t ub, int *output)
{
	size_t i = lb, j = mid + 1, k = lb;

	while (i <= mid && j <= ub)
	{
		if (array[i] <= array[j])
		{
			output[k] = array[i];
			i++;
		}
		else
		{
			output[k] = array[j];
			j++;
		}
		k++;
	}
	if (i > mid)
	{
		while (j <= ub)
		{
			output[k] = array[j];
			j++;
			k++;
		}
	}
	else
	{
		while (i <= mid)
		{
			output[k] = array[i];
			i++;
			k++;
		}
	}
	for (k = lb; k <= ub; k++)
		array[k] = output[k];
}

/**
 * merge_sort - the driver function for merge sort
 * @array: the array to be sorted
 * @size: the size of the array
 */

void merge_sort(int *array, size_t size)
{
	size_t lb = 0;
	size_t ub = size - 1;
	int *output = NULL;

	if (array == NULL || size < 2)
	{
		return;
	}

	output = (int *)malloc(sizeof(size_t) * size);
	if (output == NULL)
		return;

	mergesort(array, lb, ub, output);

	free(output);
}
