#include "lists.h"

/**
 * add_node - add a node at beginning of linked list
 * @head: address of a pointer to current head
 * @str: string to make new first element
 *
 * Return: pointer to new head
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new = malloc(sizeof(list_t));

	if (str == NULL || head == NULL)
	{
		free(new);
		return (NULL);
	}

	if (new == NULL)
		return (NULL);

	new->str = strdup(str);

	if (new->str == NULL)
		return (NULL);

	new->len = strlen(new->str);
	new->next = *head;
	*head = new;

	return (new);
}
