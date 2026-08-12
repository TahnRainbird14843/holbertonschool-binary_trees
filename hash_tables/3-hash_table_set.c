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
	int i = 0;
	int key_present = 1;

	new_node->key = strdup(key);
	new_node->value = strdup(value);

	if (ht->array[index] == NULL)
	{
		new_node->next = NULL;
		ht->array[index] = new_node;
		return (1);
	}
	while (key[i] != '\0')
	{
		if (key[i] != ht->array[index]->key[i])
		{
			key_present = 0;
			break;
		}
		i++;
	}

	if (key_present == 1)
	{
		free(ht->array[index]);
		new_node->next = NULL;
		ht->array[index] = new_node;
		return (1);
	}

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
