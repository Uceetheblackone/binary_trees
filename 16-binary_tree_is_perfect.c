#include "binary_trees.h"
/**
 * count_total_node - counts the total nodes in a tree
 * @tree: a pointer to the root node of the tree to count
 *
 * Return: total number of nodes
*/
int count_total_node(binary_tree_t *tree)
{
	int count_left = 0, count_right = 0;

	if (tree == NULL)
		return (0);

	count_left = count_total_node(tree->left);
	count_right = count_total_node(tree->right);

	return (count_left + 1 + count_right);
}
/**
 * binary_tree_is_perfect -  a function that checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: True if tree is perfect and false if otherwise
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int count_left = 0, count_right = 0;

	if (tree == NULL)
		return (0);

	 count_left = count_total_node(tree->left);
	 count_right = count_total_node(tree->right);

	if (count_left == count_right)
		return (1);
	return (0);
}
