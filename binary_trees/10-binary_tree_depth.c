#include "binary_trees.h"

/**
 * binary_tree_depth: get depth of a node in a tree
 * @tree: pointer to node
 *
 * Return: depth of node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		depth += 1;
		tree = tree->parent;
	}

	return (depth);
}
