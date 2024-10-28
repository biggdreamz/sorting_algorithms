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
 * counting_sort - Performs counting sort based on a specific digit.
 * @array: The array to sort.
 * @size: The size of the array.
 * @exp: The significant digit to sort by.
 *
 * Description: This function sorts the array according to the
 * specified digit (unit, tens, etc.) and prints the array
 * after each sorting step.
 */
void radix_sort(int *array, size_t size);
{
	int *output = malloc(size * sizeof(int));

	int count[10] = {0}; /* Initialize count array for base 10 */

	size_t i;

	/* Store count of occurrences in count[] */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* Change count[i] to contain actual position of this digit */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = size - 1; (ssize_t)i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
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
