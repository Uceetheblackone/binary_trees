#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree (int)
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t count_left, count_right, total;

	count_left = count_right = 0;

	if (tree == NULL)
		return (0);

	/* Recussively count the left sub-tree */
	count_left += binary_tree_height(tree->left);

	/* Recussively count the right sub-tree */
	count_right += binary_tree_height(tree->right);

	/**
	 * Get the maximum value between left and right sub-tree
	 * +1 add the current node / parent  of the respective child
	 */
	total = count_left > count_right ? count_left + 1 : count_right + 1;

	return (total);
}
/**
 * binary_tree_balance - Measures the factor balance of a binary tree
 * @tree: A pointer to the root node of the tree to measure the balance
 *
 * Return: The factor balance of the tree (int)
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int count_left, count_right;

	if (tree == NULL)
		return (0);

	count_left = binary_tree_height(tree->left);
	count_right = binary_tree_height(tree->right);

	return (count_left - count_right);
}

/**
 * check_BST_n_balance - Helps to validate the binary search tree and
 * checks factor balance of the tree
 * @tree: A pointer to the root node of the tree to validate
 * @min: The minimum value
 * @max: The maximun value
 *
 * Return: 0 (if not Binary search tree) 1 (if binary search tree)
 */

int check_BST_n_balance(const binary_tree_t *tree, int min, int max)
{
	int left, right, balance;

	/* if tree is empty */
	if (tree == NULL)
		return (1);

	/* If reference value is below min or above max value */
	if (tree->n < min || tree->n > max)
		return (0);
	/* check the balance of the tree */
	balance = binary_tree_balance(tree);
	if (balance > 1 || balance < -1)
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
	left = check_BST_n_balance(tree->left, min, tree->n - 1);
	right = check_BST_n_balance(tree->right, tree->n + 1, max);
	return (left && right);
}

/**
 * binary_tree_is_avl - Check if binary tree is a valid AVL
 * @tree: A pointer to the root node of the tree
 *
 * Return: 1 (true) 0 (false)
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (check_BST_n_balance(tree, INT_MIN, INT_MAX));

}
