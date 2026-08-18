#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert node to left of a parent
 * @parent: pointer to parent node
 * @value: value of new node
 *
 * Return: pointer to new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->left = parent->left;
	if (parent->left != NULL)
		(parent->left)->parent = new_node;
	parent->left = new_node;
	new_node->parent = parent;
	new_node->n = value;
	new_node->right = NULL;

	return (new_node);
}
