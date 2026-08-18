#include "binary_trees.h"

/**
 * binary_tree_nodes - get the number of non-leaf nodes
 * @tree: pointer to root of tree
 *
 * Return: number of non-leaf nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (0);
	
	count += 1;
	if (tree->left)
		count += binary_tree_nodes(tree->left);
	if (tree->right)
		count += binary_tree_nodes(tree->right);

	return (count);
}
