#include "lists.h"

/**
 * add_dnodeint_end - add a node at the end of a doubly linked list
 * @head: pointer to address of head
 * @n: int value of new node
 *
 * Return: pointer to new head
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t));
	dlistint_t *curr_node;

	if (new_node == NULL)
		return (NULL);

	if (head == NULL)
	{
		free(new_node);
		return (NULL);
	}

	if (*head == NULL)
	{
		new_node->n = n;
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
		return (*head);
	}

	curr_node = *head;

	while (curr_node->next != NULL)
		curr_node = curr_node->next;

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = curr_node;
	curr_node->next = new_node;

	return (*head);
}
