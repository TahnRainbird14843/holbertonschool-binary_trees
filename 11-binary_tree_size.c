#include "binary_trees.h"

/**
 * binary_tree_size - get the size of a tree
 * @tree: pointer to root of tree
 *
 * Return: size of tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (!tree)
		return (0);

	if (tree->left)
		size += binary_tree_size(tree->left);
	if (tree->right)
		size += binary_tree_size(tree->right);

	size += 1;

	return (size);
}
