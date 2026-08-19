#include "binary_trees.h"

/**
 * binary_tree_inorder - traverse a tree in order
 * @tree: pointer to root of tree
 * @func: func to apply to value at each node
 *
 * Return: 0 always
 */
int binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return (0);

	if (tree->left)
		binary_tree_inorder(tree->left, func);

	func(tree->n);

	if (tree->right)
		binary_tree_inorder(tree->right, func);

	return (0);
}
