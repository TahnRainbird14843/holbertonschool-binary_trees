#include "binary_trees.h"

/**
 * binary_tree_leaves - count the number of leaves in a tree
 * @tree: point to root of tree
 *
 * Return: number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);
	else
	{
		if (tree->left)
			count += binary_tree_leaves(tree->left);
		if (tree->right)
			count += binary_tree_leaves(tree->right);
	}

	return (count);
}
