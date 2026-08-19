#include "binary_trees.h"

/**
 * height2 - get the height of a binary tree
 * @tree: pointer to root of tree
 *
 * Return: height of tree
 */
size_t height2(const binary_tree_t *tree)
{
	size_t l_height = 0;
	size_t r_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		l_height = 1 + height2(tree->left);
	else
		l_height = 0;
	if (tree->right)
		r_height = 1 + height2(tree->right);
	else
		r_height = 0;

	return (l_height > r_height ? l_height : r_height);
}

/**
 * binary_tree_balance - get the balance factor of a binary tree
 * @tree: pointer to root of tree
 *
 * Return: balance factor of tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (height2(tree->left) - height2(tree->right));
}
