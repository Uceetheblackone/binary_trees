#include "binary_trees.h"

/**
 * array_to_avl - Build an AVL tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size:  the number of element in the array
 *
 * Return:  a pointer to the root node of the created BST,
 * or NULL on failure
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *new_tree = NULL;
	size_t i;

	for (i = 0; i < size; i++)
		avl_insert(&new_tree, array[i]);

	return (new_tree);
}
