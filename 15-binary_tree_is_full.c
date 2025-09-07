#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 * Return: 0 if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left != NULL && tree->right != NULL)
	{

		int left_full = binary_tree_is_full(tree->left);
		int right_full = binary_tree_is_full(tree->right);

		return (left_full && right_full);
	}

	return (0);
}

