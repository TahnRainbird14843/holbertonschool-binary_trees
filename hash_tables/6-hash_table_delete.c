#include "hash_tables.h"

/**
 * hash_table_delete - delete a hash table
 * @ht: hash table
 *
 * Return: 0
 */
int hash_table_delete(hash_table_t *ht)
{
	unsigned long int i = 0;
	hash_node_t *curr_node;
	hash_node_t *prev_node;

	while (i < ht->size)
	{
		curr_node = ht->array[i];

		while (curr_node != NULL)
		{
			free(curr_node->key);
			free(curr_node->value);
			prev_node = curr_node;
			curr_node = curr_node->next;
			free(prev_node);
		}

		i++;
	}

	free(ht->array);
	free(ht);

	return (0);
}
