#include "binary_trees.h"

/**
 * binary_tree_is_full - check if tree is full
 * @tree: pointer to tree
 *
 * Return: 1 if full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_full = 1;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (!tree->left && tree->right)
		is_full = 0;
	else if (tree->left && !tree->right)
		is_full = 0;
	else
		is_full = 1;

	is_full = is_full * binary_tree_is_full(tree->left)
		* binary_tree_is_full(tree->right);

	return (is_full);
}
