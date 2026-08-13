#include "hash_tables.h"

/**
 * hash_table_print - print a hash table
 * @ht: hash table
 *
 * Return: 0 always
 */
int hash_table_print(hash_table_t *ht)
{
	unsigned long int i = 0;
	hash_node_t *curr_node;
	int first_call = 0;

	if (ht == NULL)
		printf("{}");

	printf("{");

	while (i < ht->size)
	{
		curr_node = ht->array[i];

		while (curr_node != NULL)
		{
			if (first_call == 0)
			{
				printf("'%s' : '%s'", curr_node->key, curr_node->value);
				first_call = 1;
			}
			else
				printf(", '%s' : '%s'", curr_node->key, curr_node->value);

			curr_node = curr_node->next;
		}
		i++;
	}

	printf("}\n");

	return (0);
}
