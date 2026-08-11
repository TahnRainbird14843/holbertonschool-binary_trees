#include "lists.h"

/**
 * get_dnodeint_at_index - get pointer to node at index
 * @head: head of list
 * @n: index of desired node
 *
 * Return: pointer to node at index
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int n)
{
	if (head == NULL)
		return (NULL);

	while (head->next != NULL && n != 0)
	{
		head = head->next;
		n--;
	}

	if (n != 0)
		return (NULL);

	return (head);
}
