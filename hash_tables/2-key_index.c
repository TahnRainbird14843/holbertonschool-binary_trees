#include "hash_tables.h"

/**
 * key_index - get the index of a value from a given key
 * @key: input key
 * @size: size of hash table
 *
 * Return: index of key in hash table
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
