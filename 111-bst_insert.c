#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a binary search tree
 * @tree: A double pointer to the root node of the BST
 * to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *temp = (*tree);

	/* if tree does not exist or tree is empty, create new one */
	if (tree == NULL || (*tree) == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		if (!new_node)
			return (NULL);
		(*tree) = new_node;
		return (new_node);
	}
	while (temp)
	{
		/* If equal */
		if (temp->n == value)
			return (NULL);
		/* Insert in left sub-tree */
		if (temp->n > value)
		{
			if (!temp->left)
			{
				temp->left = binary_tree_node(temp, value);
				return (temp->left);
			}
			temp = temp->left;
		}
		/* Insert in right sub-tree */
		if (temp->n < value)
		{
			if (!temp->right)
			{
				temp->right = binary_tree_node(temp, value);
				return (temp->right);
			}
			temp = temp->right;
		}
	}
	return (NULL);
}
