#include "binary_trees.h"
/**
 * binary_tree_depth - a function that measures
 * the depth of a node in a binary tree
 * @tree: a pointer to the node to measure the depth
 *
 * Return: the depth of the node, 0 if tree is NULL
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	const binary_tree_t *temp = tree;

	if (tree == NULL || tree->parent == NULL)
		return (0);
	while (temp->parent != NULL)
	{
		temp = temp->parent;
		depth++;
	}
	return (depth);
}
