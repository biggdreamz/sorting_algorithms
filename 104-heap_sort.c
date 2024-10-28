#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

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
 * sift_down - Sifts down the element at index in the heap
 * @array: Pointer to the array representing the heap
 * @size: Size of the array
 * @root: Index of the root of the heap to sift down from
 * @end: Index of the last element in the heap
 *
 * Description: This function enforces the max-heap property for a given
 * subtree rooted at the given index.
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left <= end && array[left] > array[largest])
		largest = left;

	if (right <= end && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		int temp = array[root];
		array[root] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		sift_down(array, size, largest, end);
	}
}

/**
 * build_max_heap - Builds a max heap from an unsorted array
 * @array: Pointer to the array to be turned into a heap
 * @size: Size of the array
 *
 * Description: This function rearranges the array elements to satisfy
 * the max-heap property.
 */
void build_max_heap(int *array, size_t size)
{
	ssize_t i;
	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, i, size - 1);
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 *
 * Description: This function uses the sift-down heap sort algorithm,
 * printing the array every time two elements are swapped.
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	
	if (array == NULL || size < 2)
		return;

	build_max_heap(array, size);

	for (end = size - 1; end > 0; end--)
	{
		int temp = array[0];
		array[0] = array[end];
		array[end] = temp;
		print_array(array, size);

		sift_down(array, size, 0, end - 1);
	}
}
