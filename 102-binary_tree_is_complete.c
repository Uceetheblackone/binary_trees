#include "binary_trees.h"

/**
 * total_tree_size - Find the total number of nodes
 * in a tree
 * @tree: A pointer to the root node
 *
 * Return: Total number of node in a tree
 */
int total_tree_size(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	left = total_tree_size(tree->left);
	right = total_tree_size(tree->right);

	return (left + right + 1);
}

/**
 * complete - check if a tree / sub-tree is complete or not
 * @node: The target tree / sub-tree
 * @idx: The index of the current node
 * @size: The total size of the tree
 *
 * Return: 0 (not complete tree) 1 (complete tree)
 */
int complete(const binary_tree_t *node, int idx, int size)
{
	if (node == NULL)
		return (0);

	if (idx >= size)
		return (0);
	if (!node->left && !node->right)
		return (1);
	if (!node->left && node->right)
		return (0);
	if (node->left && !node->right)
		return (complete(node->left, idx * 2 + 1, size));

	return (complete(node->left, idx * 2 + 1, size) &&
			complete(node->right, idx * 2 + 2, size));
}
/**
 * binary_tree_is_complete - Check if a binary tree is complete or not
 * @tree: A pointer to tree to check
 *
 * Return: 0 (not complete) 1 (complete)
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int tree_size, check;

	if (tree == NULL)
		return (0);

	/* Get the total size of the tree */
	tree_size = total_tree_size(tree);

	check = complete(tree, 0, tree_size);
	return (check);
}
