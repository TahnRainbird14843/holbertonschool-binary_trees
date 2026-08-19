#include "binary_trees.h"

/**
 * binary_tree_sibling - get the sibling of a node in a tree
 * @node: input node
 *
 * Return: pointer to sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *curr = node;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	node = node->parent;

	if (node->left == curr && node->right != NULL)
		return (node->right);
	if (node->right == curr && node->left != NULL)
		return (node->left);

	return (NULL);
}
