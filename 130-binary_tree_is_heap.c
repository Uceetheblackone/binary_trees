#include "binary_trees.h"

/**
 * get_tree_size - Find the total number of nodes
 * in a tree
 * @tree: A pointer to the root node
 *
 * Return: Total number of node in a tree
 */
int get_tree_size(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	left = get_tree_size(tree->left);
	right = get_tree_size(tree->right);

	return (left + right + 1);
}

/**
 * is_complete - check if a tree / sub-tree is complete or not
 * @node: The target tree / sub-tree
 * @idx: The index of the current node
 * @size: The total size of the tree
 *
 * Return: 0 (not complete tree) 1 (complete tree)
 */
int is_complete(const binary_tree_t *node, int idx, int size)
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
		return (is_complete(node->left, idx * 2 + 1, size));

	return (is_complete(node->left, idx * 2 + 1, size) &&
			is_complete(node->right, idx * 2 + 2, size));
}
/**
 * tree_is_completed - Check if a binary tree is complete or not
 * @tree: A pointer to tree to check
 *
 * Return: 0 (not complete) 1 (complete)
 */
int tree_is_completed(const binary_tree_t *tree)
{
	int tree_size, check;

	if (tree == NULL)
		return (0);

	/* Get the total size of the tree */
	tree_size = get_tree_size(tree);

	check = is_complete(tree, 0, tree_size);
	return (check);
}
/**
 * tree_is_heap - Check if a binary tree is complete or not
 * @tree: A pointer to tree to check
 *
 * Return: 0 (not complete) 1 (complete)
 */

int tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if ((tree->left && tree->left->n > tree->n) ||
			(tree->right && tree->right->n > tree->n))
		return (0);

	return (tree_is_heap(tree->left) && tree_is_heap(tree->right));
}
/**
 * binary_tree_is_heap - Check if tree is a heap
 * @tree: pointer to the tree
 *
 * Return: 0 (not complete) 1 (complete)
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int a, b;

	a = tree_is_completed(tree);
	b = tree_is_heap(tree);
	return (a && b);
}
