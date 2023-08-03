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
	return (height_l > height_r ? height_l + 1 : height_r + 1);
}

/**
 * print_node_value - prints the value of each node at a perticular level
 * @level: the level of the tree
 * @func: a pointer to a function to call for each node.
 * @tree: a pointer to the root node of the tree to print
 *
 * Return: Nothing
*/
void print_node_value(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);

	else if (level > 1)
	{
		print_node_value(tree->left, level - 1, func);
		print_node_value(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - a function that goes through
 * a binary tree using level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node.
 *
 * Return: Nothing
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int level = 0, i = 1;

	if (tree == NULL || func == NULL)
		return;
	level = binary_tree_height(tree);

	while (i <= level)
	{
		print_node_value(tree, i, func);
		i++;
	}
}
