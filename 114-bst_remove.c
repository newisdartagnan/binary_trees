#include "binary_trees.h"

/**
 * bst_remove - removes a node from a Binary Search Tree
 *
 * @root: pointer to the root node of the tree
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root node of the tree after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return NULL;

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else {
		if (root->left == NULL && root->right == NULL) {
			free(root);
			root = NULL;
		} else if (root->left == NULL) {
			bst_t *temp = root;
			root = root->right;
			root->parent = temp->parent;
			free(temp);
		} else if (root->right == NULL) {
			bst_t *temp = root;
			root = root->left;
			root->parent = temp->parent;
			free(temp);
		} else {
			bst_t *temp = root->right;
			while (temp->left != NULL)
				temp = temp->left;
			root->n = temp->n;
			root->right = bst_remove(root->right, temp->n);
		}
	}

	return root;
}

