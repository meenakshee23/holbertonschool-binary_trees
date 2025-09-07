#include "binary_trees.h"
#include <stdlib.h>
#include <stddef.h>
/**
 * binary_tree_height - height of the binary tree
 * @tree: pointer to the root node
 * Return: 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left = 1 + binary_tree_height(tree->left);

	if (tree->right != NULL)
		 right = 1 + binary_tree_height(tree->right);

	if (left > right)
		return (left);
	else
		return (right);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree:  a pointer to the root node of the tree to measure the size
 *
 * Return: 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size, right_size;

	if (tree == NULL)
		return (0);

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	return (1 + left_size + right_size);
}

/**
 * binary_tree_is_perfect -  checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height;
	size_t nodes;
	size_t expected_nodes;
	size_t i;
	size_t power = 1;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);

	nodes = binary_tree_size(tree);

	for (i = 0; i < height + 1; i++)
		power = power * 2;

	expected_nodes = power - 1;

	if (nodes == expected_nodes)
		return (1);
	else
		return (0);
}

