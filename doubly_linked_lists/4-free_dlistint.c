#include "lists.h"

/**
 * free_dlistint - free a doubly linked list
 * @head: head of linked list
 *
 * Return: 0 always
 */
int free_dlistint(dlistint_t *head)
{
	if (head == NULL)
		return (0);

	while (head->next != NULL)
	{
		head = head->next;
		free(head->prev);
	}

	free(head);

	return (0);
}
