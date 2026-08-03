#include "lists.h"

/**
 * add_node_end - add a ndoe to the end of a linked list
 * @head: address of current head
 * @str: new string to be added
 *
 * Return: address of new pointer
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *curr = *head;
	char *str_cp = strdup(str);
	list_t *new = malloc(sizeof(list_t));

	if (head == NULL)
	{
		free(new);
		(*head)->str = str_cp;
		(*head)->len = strlen(str_cp);
		(*head)->next = NULL;
	}

	new->str = str_cp;
	new->len = strlen(str_cp);
	new->next = NULL;

	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;

	return (new);
}
