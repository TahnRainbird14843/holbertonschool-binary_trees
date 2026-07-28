#include "function_pointers.h"

/**
 * int_index - search an array for an integer
 * @array: inpput array
 * @size: size of array
 * @cmp: comparison for integer search
 *
 * Return: index of integer if found -1 if not or error
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (size <= 0)
		return (-1);

	while (i < size)
	{
		if (cmp(array[i]))
			return (i);
		
		i++;
	}

	return (-1);
}
