#include "binary_trees.h"

/**
 * create_arr_tree - Create avl tree from sorted array
 * @arr: The sorted array
 * @first_idx: The first index of the array
 * @last_idx: The last index of the array
 *
 * Return: A pointer to the root node
 */
avl_t *create_arr_tree(int *arr, int first_idx, int last_idx)
{
	avl_t *root;
	int mid_idx;

	if (last_idx < first_idx)
		return (NULL);

	/* get the middle index of the array */
	mid_idx = (first_idx + last_idx) / 2;

	/* create root node using value at the middle index of the array*/
	root = binary_tree_node(NULL, arr[mid_idx]);
	if (root == NULL)
		return (NULL);

	/* keep adding to the left and right child of the root */
	root->left = create_arr_tree(arr, first_idx, mid_idx - 1);
	root->right = create_arr_tree(arr, mid_idx + 1, last_idx);

	if (root->left != NULL)
		root->left->parent = root;
	if (root->right != NULL)
		root->right->parent = root;
	return (root);
}
/**
 * sorted_array_to_avl -  builds an AVL tree from a sorted array
 * @array: The sorted array
 * @size:  the number of element in the array
 *
 * Return: a pointer to the root node of the created AVL tree
 * or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size < 1)
		return (NULL);
	return (create_arr_tree(array, 0, size - 1));
}
