#include "lists.h"

/**
 * insert_dnodeint_at_index - insert a node into a doubly linked list at index
 * @head: pointer to address of first node
 * @idx: index of new node
 * @n: value at new node
 *
 * Return: pointer to new node
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **head,
		unsigned int idx, int n)
{
	dlistint_t *curr_node = *head;
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (head == NULL || (*head == NULL && idx != 0))
	{
		free(new_node);
		return (NULL);
	}
	if (*head == NULL)
	{
		*head = new_node;
		return (*head);
	}
	while (curr_node->next != NULL && idx != 0)
	{
		curr_node = curr_node->next;
		idx--;
	}
	if (idx != 0)
	{
		free(new_node);
		return (NULL);
	}
	new_node->prev = curr_node->prev;
	new_node->next = curr_node;
	if (curr_node->prev != NULL)
		(curr_node->prev)->next = new_node;
	curr_node->prev = new_node;

	return (new_node);
}
