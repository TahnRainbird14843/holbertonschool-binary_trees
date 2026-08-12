#include "hash_tables.h"

/**
 * hash_table_create - create a malloc'ed hash table
 * @size: size of hash table
 *
 * Return: pointer to hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table = malloc(sizeof(unsigned long int) + sizeof(hash_node_t *));
	hash_node_t *array;

	if (hash_table == NULL)
		return (NULL);

	array = malloc(sizeof(hash_node_t) * size);

	if (array == NULL)
	{
		free(hash_table);
		return (NULL);
	}

	hash_table->size = size;
	hash_table->array = &array;

	return (hash_table);
}
