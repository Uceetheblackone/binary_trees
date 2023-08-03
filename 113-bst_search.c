#include "binary_trees.h"

/**
 * bst_search - Search for a value in Binary search tree
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to search in the tree
 *
 * Return: a pointer to the node containing a value equals to value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	const bst_t *temp = tree;

	/**
	 * If node is empty or node value == search value
	 * return the node
	 * If root node value > search value, search left side
	 * If root node value < search value, search right side
	 */
	if (temp == NULL || temp->n == value)
		return ((binary_tree_t *)temp);

	if (temp->n > value)
		return (bst_search(temp->left, value));
	else
		return (bst_search(temp->right, value));
}
