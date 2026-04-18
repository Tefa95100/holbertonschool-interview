#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Add a node in a tree
 * @parent: pointer of parent
 * @value: int to add in the node
 * Return: Return the new element
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	/*Alloc memory for node*/
	binary_tree_t *new_element = malloc(sizeof(*new_element));

	/*Check if allocation is ok*/
	if (new_element == NULL)
	{
		return (NULL);
	}

	/*Attribute parameters to variable of node*/
	new_element->n = value;
	new_element->parent = parent;
	new_element->left = NULL;
	new_element->right = NULL;

	return (new_element);
}
