#include <stdlib.h>
#include <string.h>
#include "sort.h"

/**
 * counting_sort - Implements counting sort algorithm.
 * @array: Array to sort.
 * @size: Array size.
 */
void counting_sort(int *array, size_t size)
{
	int index, maximum = 0;
	int *counter = NULL;
	int *tmp = NULL;
	size_t i;

	if (array == NULL || size < 2)
		return;

	/* Find maximum number */
	for (i = 0; i < size; i++)
	{
		if (array[i] > maximum)
			maximum = array[i];
	}

	/* Allocate memory for counter and tmp */
	counter = calloc(maximum + 1, sizeof(int));
	tmp = calloc(size, sizeof(int));

	if (!counter || !tmp)
	{
		free(counter);
		free(tmp);
		return;
	}

	/* Count the array elements */
	for (i = 0; i < size; i++)
		counter[array[i]]++;

	/* Get the accumulative values */
	for (index = 1; index <= maximum; index++)
		counter[index] += counter[index - 1];

	print_array(counter, maximum + 1); /* Assuming this prints the array */

	/* Get the new sorted array */
	for (i = 0; i < size; ++i)
	{
		tmp[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}

	/* Replace old array with new sorted array */
	for (i = 0; i < size; i++)
		array[i] = tmp[i];

	free(tmp);
	free(counter);
}
