#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_height - finds the height
 * @tree: pointer
 * Return: 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left = binary_tree_height(tree->left);

	if (tree->right != NULL)
		right = binary_tree_height(tree->right);

	if (left > right)
		return (1 + left);
	else
		return (1 + right);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 *
 * Return: 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}
