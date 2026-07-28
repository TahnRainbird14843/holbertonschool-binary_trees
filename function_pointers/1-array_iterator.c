#include "function_pointers.h"
#include <stddef.h>

/**
 * array_iterator - iterate an operation over an array
 * @array: input array
 * @size: size of array
 * @action: action to be iterated over array
 *
 * Return: 0 always
 */
int array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i = 0;

	while (i < size)
		action(array[i++]);

	return (0);
}
