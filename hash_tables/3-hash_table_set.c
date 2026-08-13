#include "hash_tables.h"

/**
 * chuck_a_fit - throw a tantrum and free everything
 * @ptr1: input 1
 * @ptr2: input 2
 *
 * Return: 0 always
 */
int chuck_a_fit(void *ptr1, void *ptr2)
{
	if (ptr1 != NULL)
		free(str1);
	if (ptr2 != NULL)
		free(str2);

	return (0);
}

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
	unsigned long int index;
	hash_node_t *new_node;
	hash_node_t *curr_node;

	if (ht == NULL)
		return (0);

	index = hash_djb2((const unsigned char *)key) % ht->size;
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
		return (chuck_a_fit(new_node, NULL));
	new_node->value = strdup(value);
	if (new_node->value == NULL)
		return (chuck_a_fit(new_node->key, new_node));

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
