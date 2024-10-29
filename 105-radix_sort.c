#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Finds the maximum value in an array.
 * @array: The array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
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
 * counting_sort - Performs a counting sort on an array based on a specific digit.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @exp: The current digit's place value (1, 10, 100, etc.).
 */
void counting_sort(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};
	size_t i;

	if (!output)
		return;

	/* Count occurrences of each digit in the current place value */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* Accumulate counts */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/* Copy the sorted numbers back to the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	/* Print the array after sorting by the current digit */
	print_array(array, size);

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the Radix sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max;
	int exp;

	if (!array || size < 2)
		return;

	/* Find the maximum number to know the number of digits */
	max = get_max(array, size);

	/* Perform counting sort for each digit place (1, 10, 100, etc.) */
	for (exp = 1; max / exp > 0; exp *= 10)
		counting_sort(array, size, exp);
}
