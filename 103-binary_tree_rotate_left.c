#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Rotate binary tree to the left
 * @tree: A pointer to the pivot or the node to rotate
 *
 * Return: New rotated tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *old_root;

	old_root = tree;

	/* if tree is empty or not present */
	if (tree == NULL)
		return (NULL);
	/**
	 * make new root the right child of old root if it's not null
	 * i.e ritate to the left
	 */
	new_root = old_root->right;
	if (new_root == NULL)
		return (tree);
	/**
	 * if the left child of new root is not empty,
	 * change it's parent to old root.
	 */
	if (new_root->left != NULL)
		new_root->left->parent = old_root;
	old_root->right = new_root->left;
	new_root->left = old_root;
	new_root->parent = old_root->parent;
	old_root->parent = new_root;

	/**
	 * if the new root is still a child to another root, and
	 * the left child of the parent is == old root
	 * update its left child as the new node but if not
	 * equal, update it as it's right
	 */
	if (new_root->parent && new_root->parent->left == old_root)
		new_root->parent->left = new_root;
	else if (new_root->parent)
		new_root->parent->right = new_root;

	return (new_root);
}
