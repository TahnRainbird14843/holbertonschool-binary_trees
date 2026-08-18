#include "binary_trees.h"

/**
 * binary_tree_is_perfect - check if a binary tree is perfect
 * @tree: pointer to tree
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int perfect = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);


