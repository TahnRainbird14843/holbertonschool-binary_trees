#include "lists.h"

/**
 * free_list - frees a list
 * @head: pointer to start of list
 *
 * Return: 0 always
 */
int free_list(list_t *head)
{
	list_t *prev;

	if (head == NULL)
		return (0);

	while (head->next != NULL)
	{
		prev = head;
		head = head->next;
		free(prev->str);
		free(prev);
	}

	free(head->str);
	free(head->next);
	free(head);

	return (0);
}
