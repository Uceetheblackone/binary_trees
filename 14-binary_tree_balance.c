#include "binary_trees.h"

/**
 * binary_tree_height - A function that measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height.
 * If tree is NULL, the function returns 0
 * Return: height of @tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (tree == NULL)
		return (0);
	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_balance - a function that measures the balance
 * factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 *
 * Return: the balance factor
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int height_left_subtree, height_right_subtree;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL)
		height_left_subtree = 0;
	else
		height_left_subtree = binary_tree_height(tree->left) + 1;

	if (tree->right == NULL)
		height_right_subtree = 0;
	else
		height_right_subtree = binary_tree_height(tree->right) + 1;

	return (height_left_subtree - height_right_subtree);
}
