#include "binary_trees.h"

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 *
 * @tree: A pointer to the root node of the binary tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_balance(tree) != 0)
		return (0);

	if (tree->left != NULL)
	{
		if (tree->left->n >= tree->n)
			return (0);

		if (!binary_tree_is_avl(tree->left))
			return (0);
	}

	if (tree->right != NULL)
	{
		if (tree->right->n <= tree->n)
			return (0);

		if (!binary_tree_is_avl(tree->right))
			return (0);
	}

	return (1);
}

