#include "binary_trees.h"

/**
 * min_val_finder - Find the minimum value node in AVL
 * @root: A pointer to root node
 *
 * Return: The node with minimum value
 */
avl_t *min_val_finder(avl_t *root)
{
	/**
	 * keep traversing the left child of the root node
	 * until you get to the node with the minimum value
	 * or node with no left child
	 */
	while (root->left)
		root = root->left;
	return (root);
}
/**
 * avl_remove - Removes a node from a binary search tree
 * if the value in the node to delete is greater than the
 * root node, search the right side of the root node.
 * If less than, search left side
 * else if equal, start checking it's children:
 * When node to delete has no children
 * when node to delete only has right but not left child
 * when node to delete only has left but not right child
 * when node to delete has both children - left and right
 *
 * @root: a pointer to the root node of the tree where you will remove a node
 * @value: the value to remove in the tree
 *
 * Return: a pointer to the new root node of the tree after removing
 * the desired value
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp, *node_parent;

	if (root == NULL)
		return (NULL);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else if (value < root->n)
		root->left = avl_remove(root->left, value);
	else
	{
		if (!root->left && !root->right)
		{
			free(root);
			root = NULL;
		}
		else if (!root->left)
		{
			temp = root;
			node_parent = root->parent;
			root = root->right;
			root->parent = node_parent;
			free(temp);
		}
		else if (!root->right)
		{
			temp = root;
			node_parent = root->parent;
			root = root->left;
			root->parent = node_parent;
			free(temp);
		}
		else
		{
			temp = min_val_finder(root->right);
			root->n = temp->n;
			root->right = avl_remove(root->right, temp->n);
		}
	}
	return (root);
}
