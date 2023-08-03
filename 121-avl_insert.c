#include "binary_trees.h"

/**
 * insert_in_avl - Recursively inserts new node to existing AVL tree
 *
 * @tree: pointer to the current node being examined
 * @parent: parent of the current node being examined
 * @value: the value to be inserted
 *
 * Return: pointer to the new_node node
 */
avl_t *insert_in_avl(avl_t *tree, avl_t *parent, int value)
{
	avl_t *new_node;

	/**
	 * BASE CASE 1:
	 *
	 * if the node being examined is a leaf node i.e
	 * with no children/null children, create new child
	 * and place it either left or right based on the parent's value
	 */
	if (tree == NULL)
	{
		new_node = binary_tree_node(parent, value);
		if (new_node == NULL)
			return (NULL);
		if (parent->n > new_node->n)
			parent->left = new_node;
		else
			parent->right = new_node;
		return (new_node);
	}
	/**
	 * BASE CASE 2:
	 *
	 * if the value to be inserted is the same with node being examined,
	 * do nothing.
	 * if value is < node, recurssively keep passing left node till it
	 * gets to the leaf node, then create new node and add it.
	 * if value > node, reccursively pass right node
	 */
	else if (value == tree->n)
		return (NULL);
	else if (value < tree->n)
		return (insert_in_avl(tree->left, tree, value));
	else
		return (insert_in_avl(tree->right, tree, value));
}

/**
 * balance_avl - rebalance an AVL tree if needed
 *
 * @root: pointer to the root of the tree
 * @tree: pointer to the node to be rebalanced
 * @value: inserted value
 * Return: 0
 */

void balance_avl(avl_t **root, avl_t *tree, int value)
{
	int balance_length;

	balance_length = binary_tree_balance(tree);
	if (balance_length > 1)
	{
		if (tree->left->n > value)
		{
			if ((*root) == tree)
				(*root) = tree->left;
			binary_tree_rotate_right(tree);
		}
		else
		{
			if ((*root) == tree)
				(*root) = tree->left->right;
			binary_tree_rotate_left(tree->left);
			binary_tree_rotate_right(tree);
		}
	}
	if (balance_length < -1)
	{
		if (tree->right->n < value)
		{
			if ((*root) == tree)
				(*root) = tree->right;
			binary_tree_rotate_left(tree);
		}
		else
		{
			if ((*root) == tree)
				(*root) = tree->right->left;
			binary_tree_rotate_right(tree->right);
			binary_tree_rotate_left(tree);
		}
	}
}

/**
 * avl_insert - Insets the value in avl
 *
 * @tree: double pointer to root
 * @value: the value
 * Return: pointer to the new node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node, *parent;

	if (tree == NULL)
		return (NULL);
	/* create a root node if tree is empty */
	if ((*tree) == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		(*tree) = new_node;
		return (new_node);
	}
	new_node = insert_in_avl(*tree, NULL, value);
	parent = new_node->parent;

	while (parent != NULL)
	{
		balance_avl(tree, parent, value);
		parent = parent->parent;
	}

	return (new_node);
}
