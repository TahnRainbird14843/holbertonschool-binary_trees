#include "lists.h"

/**
 * _strlen - find length of string
 * @str: input str
 *
 * Return: length of str
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}

/**
 * add_node_end - add a ndoe to the end of a linked list
 * @head: address of current head
 * @str: new string to be added
 *
 * Return: address of new pointer
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new = malloc(sizeof(list_t));
	list_t *curr = *head;

	if (new == NULL)
		return (NULL);

	if (head == NULL || str ==  NULL)
	{
		free(new);
		return (NULL);
	}

	new->str = strdup(str);

	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	new->len = _strlen(new->str);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;

	return (new);
}
