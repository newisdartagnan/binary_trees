#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: A pointer to the root node of the binary tree to measure.
 *
 * Return: The height of the binary tree as a size_t.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0, height_r = 0;

	if (tree == NULL)
		return (0);

	height_l = binary_tree_height(tree->left);
	height_r = binary_tree_height(tree->right);

	if (height_l >= height_r)
		return (height_l + 1);
	else
		return (height_r + 1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 *
 * @tree: A pointer to the root node of the binary tree to measure.
 *
 * Return: The balance factor of the binary tree as an integer.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_l = 0, balance_r = 0;

	if (tree == NULL)
		return (0);

	balance_l = (tree->left != NULL) ?
		(int) binary_tree_height(tree->left) : -1;
	balance_r = (tree->right != NULL) ?
		(int) binary_tree_height(tree->right) : -1;

	return (balance_l - balance_r);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
 *
 * @tree: A pointer to the root node of the binary tree to check.
 * @min: The minimum value allowed in the binary tree.
 * @max: The maximum value allowed in the binary tree.
 *
 * Return: 1 if the binary tree is a valid BST, and 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (binary_tree_is_bst(tree->left, min, tree->n - 1) &&
		binary_tree_is_bst(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl_helper - Helper function to check if a binary tree is
 * a valid AVL Tree.
 *
 * @tree: A pointer to the root node of the binary tree to check.
 *
 * Return: The height of the binary tree as a size_t.
 */
int binary_tree_is_avl_helper(const binary_tree_t *tree)
{
	int balance = 0;
	int is_bst = 0;
	int is_avl_l = 0, is_avl_r = 0;

	if (tree == NULL)
		return (1);

	balance = binary_tree_balance(tree);

	if (balance > 1 || balance < -1)
		return (0);

	is_bst = binary_tree_is_bst(tree, INT_MIN, INT_MAX);

	if (!is_bst)
		return (0);

	is_avl_l = binary_tree_is_avl_helper(tree->left);
	is_avl_r = binary_tree_is_avl_helper(tree->right);

	if (!is_avl_l || !is_avl_r)
		return (0);

	return (1);
}
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

/* Check if the binary tree is a valid BST */
	if (binary_tree_is_bst(tree) == 0)
		return (0);


	if (abs(binary_tree_height(tree->left) - binary_tree_height(tree->right)) > 1)
		return (0);

	if (binary_tree_is_avl(tree->left) == 0)
		return (0);

	if (binary_tree_is_avl(tree->right) == 0)
		return (0);

	return (1);
}

