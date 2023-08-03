#include "binary_trees.h"
/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree: is a pointer to the root node of the tree to check
 * If tree is NULL, the function returns 0
 * Return: 1 if @tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left && tree->right)
	{
		if (binary_tree_is_full(tree->left) == 0)
			return (0);
		if (binary_tree_is_full(tree->right) == 0)
			return (0);
		else
			return (1);
	}
	else if (!tree->left && !tree->right)
		return (1);
	else
		return (0);
}
