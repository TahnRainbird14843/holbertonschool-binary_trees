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
	hash_node_t *new_node = malloc(sizeof(hash_node_t));

	new_node->key = strdup(key);
	new_node->value = strdup(value);

	if (ht->array[index] == NULL)
	{
		new_node->next = NULL;
		ht->array[index] = new_node;
	}
	else
	{
		new_node->next = ht->array[index];
		ht->array[index] = new_node;
	}

	return (1);
}
