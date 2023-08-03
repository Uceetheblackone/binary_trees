#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Rotate binary tree to the right
 * @tree: A pointer to the pivot or the node to rotate
 *
 * Return: New rotated tree
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *old_root;

	old_root = tree;

	/* if tree is empty or not present */
	if (tree == NULL)
		return (NULL);
	/**
	 * make new root the left child of old root if it's not null
	 * i.e rotate to the right
	 */
	new_root = old_root->left;
	if (new_root == NULL)
		return (tree);
	/**
	 * if the right child of new root is not empty,
	 * change it's parent to old root.
	 */
	if (new_root->right != NULL)
		new_root->right->parent = old_root;
	old_root->left = new_root->right;
	new_root->right = old_root;
	new_root->parent = old_root->parent;
	old_root->parent = new_root;

	/**
	 * if the new root is still a child to another root, and
	 * the right child of the parent is == old root
	 * update its right child as the new node but if not
	 * equal, update it as it's left
	 */
	if (new_root->parent && new_root->parent->right == old_root)
		new_root->parent->right = new_root;
	else if (new_root->parent)
		new_root->parent->left = new_root;

	return (new_root);
}
