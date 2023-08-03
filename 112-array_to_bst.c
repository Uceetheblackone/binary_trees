#include "binary_trees.h"

/**
 * array_to_bst - Build binary search tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size:  the number of element in the array
 *
 * Return:  a pointer to the root node of the created BST,
 * or NULL on failure
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *new_tree = NULL;
	size_t i;

	for (i = 0; i < size; i++)
		bst_insert(&new_tree, array[i]);

	return (new_tree);
}
