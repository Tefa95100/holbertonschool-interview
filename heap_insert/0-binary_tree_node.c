#include <stdlib.h>
#include "binary_trees.h"

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_element = malloc(sizeof(*new_element));

	if (new_element == NULL)
	{
		return (NULL);
	}
	
	new_element->n = value;
	new_element->parent;
	new_element->left = NULL;
	new_element->right = NULL;
	
	return (new_element);
}
