#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * print_array - Prints an array of integers.
 * @array: The array to be printed.
 * @size: The size of the array.
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

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
