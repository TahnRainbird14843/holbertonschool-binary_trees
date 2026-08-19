#include "binary_trees.h"

/**
 * height - get the height of a binary tree
 * @tree: pointer to root of tree
 *
 * Return: height of tree
 */
size_t height(const binary_tree_t *tree)
{
	size_t l_height = 0;
	size_t r_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		l_height = 1 + height(tree->left);
	else
		l_height = 0;
	if (tree->right)
		r_height = 1 + height(tree->right);
	else
		r_height = 0;

	return (l_height > r_height ? l_height : r_height);
}

/**
 * binary_tree_is_perfect - check if a binary tree is perfect
 * @tree: pointer to tree
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t l_perf = 0;
	size_t r_perf = 0;

	if (!tree)
		return (0);

	if (tree->left && tree->right && (height(tree->left) == height(tree->right)))
	{
		l_perf = 1 * binary_tree_is_perfect(tree->left);
		r_perf = 1 * binary_tree_is_perfect(tree->right);
	}
	else if (!tree->left && !tree->right)
	{
		r_perf = 1;
		l_perf = 1;
	}
	else
		r_perf = 0;

	return (l_perf && r_perf ? 1 : 0);
}
