#include "lists.h"

/**
 * delete_dnodeint_at_index - delete a node of dll at index
 * @head: pointer to address of head
 * @index: index of node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *curr_node;

	if (head == NULL || *head == NULL)
		return (-1);
	if (index == 0 && (*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
		return (1);
	}
	if (index == 0)
	{
		*head = (*head)->next;
		free((*head)->prev);
		(*head)->prev = NULL;
		return (1);
	}
	curr_node = *head;
	while (curr_node->next != NULL && index != 0)
	{
		curr_node = curr_node->next;
		index--;
	}
	if (index != 0)
		return (-1);
	if (curr_node->next == NULL)
	{
		(curr_node->prev)->next = NULL;
		free(curr_node);
		return (1);
	}
	(curr_node->prev)->next = curr_node->next;
	(curr_node->next)->prev = curr_node->prev;
	free(curr_node);

	return (1);
}
