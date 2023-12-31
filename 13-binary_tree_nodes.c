#include "binary_trees.h"
/**
 * binary_tree_nodes - A function that counts the nodes
 * with at least 1 child in a binary tree
 * @tree: is a pointer to the root node of the tree
 * to count the number of nodes
 * If tree is NULL, the function returns 0
 * A null pointer is not considered to be a node
 * Return: number of nodes with at least 1 child in @tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);
	if (tree->left || tree->right)
	{
		return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
	}
	else
		return (0);
}
