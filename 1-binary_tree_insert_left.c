#include "binary_trees.h"

/**
 * binary_tree_insert_left -  a function that inserts
 * a node as the left-child of another node
 * @parent: a pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 *
 * Return: a pointer to the new_node if successful and NULL on failure
*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *old_left_child;
	/*checking if there is no root node*/
	if (parent == NULL)
		return (NULL);
	/* creating a new node*/
	new_node = binary_tree_node(parent, value);

	/**
	 * checking if parent has an old-left child
	 * updatnig the left child with a new node
	 * still keeping the old-left child with a new parent
	*/
	old_left_child = parent->left;
	parent->left = new_node;
	if (old_left_child != NULL)
	{
		new_node->left = old_left_child;
		old_left_child->parent = new_node;
	}
	return (new_node);
}
