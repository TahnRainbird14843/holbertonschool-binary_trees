#include "binary_trees.h"

/**
 * binary_tree_preorder - traverse a tree in preorder
 * @tree: pointer to root of tree
 * @func: func to apply to value at each node
 *
 * Return: 0 always
 */
int binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree)
		return (0);

	func(tree->n);

	if (tree->left)
		binary_tree_preorder(tree->left, func);
	if (tree->right)
		binary_tree_preorder(tree->right, func);

	return (0);
}
