#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Finds the maximum value in an array.
 * @array: The array to check.
 * @size: The size of the array.
 *
 * Return: The maximum value in the array.
 */
int get_max(int *array, size_t size)
{
	int max = array[0];

	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * Copy the output array to array[], so that array[] now
 * contains sorted numbers according to the current digit
 */

	for (i = 0; i < size; i++)
		array[i] = output[i];

	/* Print the array after sorting by the current digit */
	print_array(array, size);

	free(output); /* Free allocated memory */
}

/**
 * radix_sort - Sorts an array of integers in ascending order using
 *              the Radix sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Description: This function implements the LSD (Least Significant
 * Digit) Radix Sort algorithm and prints the array after each
 * significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	/* Get the maximum number to know the number of digits */
	max = get_max(array, size);

	/* Perform counting sort for every digit */
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp);
	}
}
