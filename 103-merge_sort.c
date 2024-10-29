#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two sorted sub-arrays into one.
 * @array: The original array containing both sub-arrays.
 * @temp: Temporary array to store merged result.
 * @left: Starting index of the left sub-array.
 * @mid: Ending index of the left sub-array.
 * @right: Ending index of the right sub-array.
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid + 1, k = left;

	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i <= mid)
		temp[k++] = array[i++];

	while (j <= right)
		temp[k++] = array[j++];

	for (i = left; i <= right; i++)
		array[i] = temp[i];
}

/**
 * merge_sort_recursive - Recursively divides and sorts an array.
 * @array: The array to be sorted.
 * @temp: Temporary array used for merging.
 * @left: Starting index of the array segment.
 * @right: Ending index of the array segment.
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	if (left < right)
	{
		size_t mid = left + (right - left) / 2;

		/* Sort the left half */
		merge_sort_recursive(array, temp, left, mid);

		/* Sort the right half */
		merge_sort_recursive(array, temp, mid + 1, right);

		/* Merge the sorted halves */
		merge(array, temp, left, mid, right);

		/* Print the array after each merge */
		printf("Merged array: ");
		print_array(array + left, right - left + 1);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(size * sizeof(int));
	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, 0, size - 1);

	free(temp);
}
