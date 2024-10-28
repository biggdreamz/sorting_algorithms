#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/* Function prototypes for internal use */
int get_max(int *array, size_t size);
void counting_sort(int *array, size_t size, int exp);

/**
 * radix_sort - Sorts an array of integers in ascending order using the
 * LSD radix sort algorithm.
 * @array: Pointer to the array to sort.
 * @size: The number of elements in the array.
 *
 * Description: This function finds the maximum number in the array
 * and sorts the array by each digit, starting from the
 * least significant digit. The array is printed after
 * sorting by each significant digit.
 */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	int exp;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp);
		print_array(array, size);
	}
}

/**
 * counting_sort - A helper function that performs counting sort based on
 *                 the digit represented by exp (1s, 10s, 100s, etc.).
 * @array: Pointer to the array to sort.
 * @size: The number of elements in the array.
 * @exp: The exponent representing the digit to sort by.
 *
 * Description: This function sorts the array based on the digit at
 * the current exponent. It uses counting sort as a
 * stable sort to maintain the relative order of elements.
 */
void counting_sort(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};
	size_t i;

	if (output == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return;
	}

	/* Store count of occurrences in count[] */
	for (i = 0; i < size; i++)
	{
		count[(array[i] / exp) % 10]++;
	}

	/* Change count[i] so that count[i] contains actual
	* position of this digit in output[] */
	for (int j = 1; j < 10; j++)
	{
		count[j] += count[j - 1];
	}

	/* Build the output array */
	for (i = size - 1; i < size; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/* Copy the output array to array[], so that array[] now
	* contains sorted numbers according to current digit */
	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}

	free(output);
}

/**
 * get_max - Returns the maximum value in an array.
 * @array: Pointer to the array to evaluate.
 * @size: The number of elements in the array.
 *
 * Return: The maximum value found in the array.
 *
 * Description: This function iterates through the array to find
 * and return the maximum value.
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return (max);
}

/**
 * print_array - Prints the elements of an array.
 * @array: Pointer to the array to print.
 * @size: The number of elements in the array.
 *
 * Description: This function prints each element of the array
 * followed by a comma, except for the last element.
 */
void print_array(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
		{
			printf(", ");
		}
	}
	printf("\n");
}
