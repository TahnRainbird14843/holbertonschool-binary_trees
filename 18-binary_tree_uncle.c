#include "binary_trees.h"

/**
 * sibling - get the sibling of a node in a tree
 * @node: input node
 *
 * Return: pointer to sibling
 */
binary_tree_t *sibling(binary_tree_t *node)
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

/**
 * binary_tree_uncle - get the uncle of a node in a tree
 * @node: input node
 *
 * Return: pointer to uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	return (sibling(node->parent));
}
