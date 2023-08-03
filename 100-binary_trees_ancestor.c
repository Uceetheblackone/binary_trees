#include "binary_trees.h"

size_t binary_tree_depth(const binary_tree_t *tree);

/**
 * binary_trees_ancestor - A function that finds
 * the lowest common ancestor of two nodes
 *
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the two given nodes,
 * or Null if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(
const binary_tree_t *first, const binary_tree_t *second)
{
	size_t d1, d2;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	d1 = binary_tree_depth(first);
	d2 = binary_tree_depth(second);
	if (d1 > d2)
	{
		while (first && d1 > d2)
		{
			first = first->parent;
			d1--;
		}
	}
	else if (d2 > d1)
	{
		while (second && d2 > d1)
		{
			second = second->parent;
			d2--;
		}
	}

	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return (NULL);
}

/**
 * binary_tree_depth - a function that measures
 * the depth of a node in a binary tree
 * @tree: a pointer to the node to measure the depth
 *
 * Return: the depth of the node, or 0 if tree is NULL
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
