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
	unsigned int i = 0;

	if (head == NULL || new_node == NULL)
		return (NULL);

	if (idx == 0)
		new_node = add_dnodeint(head, n);

	else
	{
		while (curr_node->next != NULL && i != idx)
		{
			curr_node = curr_node->next;
			i++;
		}

		if (idx > i + 1)
			return (NULL);

		else if (idx == i + 1)
			new_node = add_dnodeint_end(head, n);

		else
		{
			new_node->n = n;
			new_node->prev = curr_node->prev;
			new_node->next = curr_node;
			(curr_node->prev)->next = new_node;
			curr_node->prev = new_node;
		}
	}

	return (new_node);
}
