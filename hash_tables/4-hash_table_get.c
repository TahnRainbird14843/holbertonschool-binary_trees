#include "hash_tables.h"

/**
 * hash_table_get - get the value associated to a given key in ht
 * @ht: hash table
 * @key: input key
 *
 * Return: value associated to key, NULL if key is not found
 */
char *hash_table_get(hash_table_t *ht, const char *key)
{
	unsigned long int idx = hash_djb2((const unsigned char *)key) % ht->size;
	hash_node_t *node = ht->array[idx];

	while (node != NULL)
	{
		if (strcmp(key, node->key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}
