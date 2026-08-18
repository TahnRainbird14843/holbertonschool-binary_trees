#include "binary_trees.h"

/**
 * binary_tree_balance - get the balance factor of a binary tree
 * @tree: pointer to root of tree
 *
 * Return: balance factor of tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance = 0;

	if (!tree)
		return (0);
	if (tree->left && !tree->right)
		balance += 1;
	if (!tree->left && tree->right)
		balance -= 1;

	balance += binary_tree_balance(tree->left) - binary_tree_balance(tree->right);

	return (balance);
}
