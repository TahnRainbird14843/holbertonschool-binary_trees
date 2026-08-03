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
	char *str_cp = strdup(str);
	list_t *mv_head;

	if (*head == NULL)
	{
		(*head)->str = str_cp;
		(*head)->len = strlen(str_cp);
		(*head)->next = NULL;
	}
	else
	{
		mv_head = malloc(sizeof(list_t *));

		if (mv_head == NULL)
			return (NULL);

		mv_head->str = (*head)->str;
		mv_head->len = (*head)->len;
		mv_head->next = (*head)->next;
		
		(*head)->str = str_cp;
		(*head)->len = strlen(str_cp);
		(*head)->next = mv_head;
	}

	return (*head);
}
