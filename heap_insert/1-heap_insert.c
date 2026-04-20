#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}
	
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

heap_t *get_parent(heap_t *root, size_t index, size_t bit)
{
	if (bit == 1)
		return (root);

	if (index & bit)
		return (get_parent(root->right, index, bit >> 1));
	else
		return (get_parent(root->left, index, bit >> 1));
}

void heapify_up(heap_t *node)
{
	int tmp;

	while (node->parent && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}
}

heap_t *heap_insert(heap_t **root, int value)
{
	size_t size, bit;
	heap_t *parent, *new_node;

	if (!root)
		return (NULL);

	if (*root == NULL)
		return (*root = binary_tree_node(NULL, value));

	size = binary_tree_size(*root);
	size++; /*index of new node*/

	/*Find the most significant bit*/
	bit = 1;
	while (bit <= size)
		bit <<= 1;
	bit >>= 2;

	parent = get_parent(*root, size, bit);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	heapify_up(new_node);

	return (new_node);
}