#include "binary_trees.h"
/**
 * binary_tree_sibling - A function that finds the sibling of a node
 * @node: is a pointer to the node to find the sibling
 * Return: A pointer to the sibling node,
 * If node is NULL or the parent is NULL, it returns NULL
 * If node has no sibling, it returns NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (node == node->parent->left)
		return (node->parent->right);
	else
		return (node->parent->left);
}
