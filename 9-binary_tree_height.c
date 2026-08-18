#include "binary_trees.h"

/**
 * binary_tree_heigth - get the height of a binary tree
 * @tree: pointer to root of tree
 *
 * Return: height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height = 0;
	size_t r_height = 0;
	
	if (!tree)
		return (0);

	if (tree->left)
		l_height = 1 + binary_tree_height(tree->left);
	else
		l_height = 0;
	if (tree->right)
		r_height = 1 + binary_tree_height(tree->right);
	else
		r_height = 0;

	return (l_height > r_height ? l_height : r_height);
}
