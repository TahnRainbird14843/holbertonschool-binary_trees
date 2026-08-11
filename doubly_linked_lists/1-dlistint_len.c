#include "lists.h"

/**
 * dlistint_len - find length of a doubly linked list
 * @h: head of list
 *
 * Return: length of list
 */
size_t dlistint_len(const dlistint_t *h)
{
	int i = 1;

	if (h == NULL)
		return (0);

	while (h->next != NULL)
	{
		h = h->next;
		i++;
	}

	return (i);
}
