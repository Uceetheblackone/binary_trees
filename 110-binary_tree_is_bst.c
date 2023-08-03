#include "binary_trees.h"
#include <limits.h>

/**
 * binary_validator - Helps to validate the binary search tree
 * @tree: A pointer to the root node of the tree to validate
 * @min: The minimum value
 * @max: The maximun value
 *
 * Return: 0 (if not Binary search tree) 1 (if binary search tree)
 */

int binary_validator(const binary_tree_t *tree, int min, int max)
{
	int left, right;

	/* if tree is empty */
	if (tree == NULL)
		return (1);

	/* If reference value is below min or above max value */
	if (tree->n < min || tree->n > max)
		return (0);

	/**
	 * Specify the min and max of left and right node
	 * For left, max value = root node value - 1, so that numbers
	 * @ the left node are lower than root
	 *
	 * For right, min value = root node value + 1, so that numbers
	 * @ the right node are greater than root
	 *
	 */
	left = binary_validator(tree->left, min, tree->n - 1);
	right = binary_validator(tree->right, tree->n + 1, max);
	return (left && right);
}

/**
 * binary_tree_is_bst - Check if binary tree is a valid Binary
 * search tree
 * @tree: A pointer to the root node of the tree
 *
 * Return: 1 (true) 0 (false)
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_validator(tree, INT_MIN, INT_MAX));

}
