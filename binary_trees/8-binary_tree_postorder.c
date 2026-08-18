#include "binary_trees.h"

/**
 * binary_tree_postorder - traverse a tree in preorder
 * @tree: pointer to root of tree
 * @func: func to apply to value at each node
 *
 * Return: 0 always
 */
int binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree)
		return (0);

	if (tree->left)
		binary_tree_postorder(tree->left, func);
	if (tree->right)
		binary_tree_postorder(tree->right, func);
	func(tree->n);

	return (0);
}
