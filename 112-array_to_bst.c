#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of element in the array
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
    bst_t *root = NULL;
    bst_t *node = NULL;
    size_t i;

    if (!array || size == 0)
        return (NULL);

    for (i = 0; i < size; i++)
    {
        node = bst_insert(&root, array[i]);
        if (!node)
            continue;  /* ignore duplicates */
    }

    return (root);
}

