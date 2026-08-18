#include "binary_trees.h"

/**
 * binary_tree_delete - delete a binary tree
 * @tree: pointer to root of tree
 *
 * Return: 0 always
 */
int binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left)
	{
		binary_tree_delete(tree->left);
		tree->left = NULL;
	}
	if (tree->right)
	{
		binary_tree_delete(tree->right);
		tree->right = NULL;
	}

	free(tree);
	tree = NULL;

	return (0);
}
