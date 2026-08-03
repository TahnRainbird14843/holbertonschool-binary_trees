#include "lists.h"

/**
 * list_len - print the length of a given linked list
 * @h: head of list
 *
 * Return: length of list
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	if (h == NULL)
		return (0);

	while (h->next != NULL)
	{
		count++;
		h = h->next;
	}
	count++;

	return (count);
}
