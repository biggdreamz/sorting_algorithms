#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two sorted halves of the array
 * @array: Pointer to the array to be sorted
 * @temp: Pointer to a temporary array for merging
 * @left_start: Starting index of the left subarray
 * @right_start: Starting index of the right subarray
 * @right_end: Ending index of the right subarray
 *
 * Description: This function merges two sorted subarrays within
 * the main array into a single sorted subarray.
 */
void merge(int *array, int *temp, size_t left_start,
		size_t right_start, size_t right_end)
{
	size_t left_end = right_start - 1;
	size_t temp_index = left_start;
	size_t size = right_end - left_start + 1;
	size_t i = left_start, j = right_start;

	while (i <= left_end && j <= right_end)
	{
		if (array[i] <= array[j])
			temp[temp_index++] = array[i++];
		else
			temp[temp_index++] = array[j++];
	}

	while (i <= left_end)
		temp[temp_index++] = array[i++];

	while (j <= right_end)
		temp[temp_index++] = array[j++];

	for (size_t k = 0; k < size; k++, right_end--)
		array[right_end] = temp[right_end];
}

/**
 * merge_sort_recursive - Recursively splits and sorts the array
 * @array: Pointer to the array to be sorted
 * @temp: Pointer to a temporary array for merging
 * @left: Leftmost index of the subarray to be sorted
 * @right: Rightmost index of the subarray to be sorted
 *
 * Description: This function splits the array recursively and sorts
 * each part before merging them back together.
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	if (left >= right)
		return;

	size_t middle = left + (right - left) / 2;

	merge_sort_recursive(array, temp, left, middle);
	merge_sort_recursive(array, temp, middle + 1, right);
	merge(array, temp, left, middle + 1, right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 *
 * Description: This function implements the top-down merge sort
 * algorithm, which sorts the left half before the right half and
 * ensures left subarray size <= right subarray size.
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	int *temp = malloc(size * sizeof(int));
	if (temp == NULL)
	{
		perror("Failed to allocate memory");
		return;
	}

	merge_sort_recursive(array, temp, 0, size - 1);

	free(temp);
}

/**
 * print_array - Prints an array of integers
 * @array: Pointer to the array to be printed
 * @size: Size of the array
 *
 * Description: This function prints each element of an integer array
 * separated by commas.
 */
void print_array(const int *array, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
