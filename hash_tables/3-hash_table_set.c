#include "hash_tables.h"

/**
 * hash_table_set - set a key-value pair in a hash table
 * @ht: pointer to hash table
 * @key: input key
 * @value: input value
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = hash_djb2((const unsigned char *)key) % ht->size;
	hash_node_t *new_node;
	hash_node_t *curr_node;

	if (ht == NULL)
		return (0);

	curr_node = ht->array[index];

	while (curr_node != NULL)
	{
		if (strcmp(curr_node->key, key) == 0)
		{
			free(curr_node->value);
			curr_node->value = strdup(value);
			if (curr_node->value == NULL)
				return (0);

			return (1);
		}
		curr_node = curr_node->next;
	}

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}
	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
