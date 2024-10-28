#include <stdlib.h>
#include <stdio.h>
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
