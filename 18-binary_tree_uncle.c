#include "binary_trees.h"
/**
 * binary_tree_uncle - a function that finds the uncle of a node
 * @node: a pointer to the node to find the uncle
 *
 * Return: a pointer to the uncle node
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *left_uncle, *right_uncle;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	left_uncle = node->parent->parent->left;
	right_uncle = node->parent->parent->right;

	if (node->parent == left_uncle && right_uncle != NULL)
		return (right_uncle);
	else if (node->parent == right_uncle && left_uncle != NULL)
		return (left_uncle);
	return (NULL);
}
