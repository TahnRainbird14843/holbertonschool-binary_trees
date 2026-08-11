#include "lists.h"

/**
 * add_dnodeint - add a node at the start of a doubly linked list
 * @head: head of list
 * @n: int value at new node
 *
 * Return: pointer to head of list
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

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

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	(*head)->prev = new_node;
	*head = new_node;

	return (*head);
}
