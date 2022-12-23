#include "binary_trees.h"

/**
 * hight - measure the height of a binary tree
 * @root: pointer to root
 * Return: int with number of levels
 */
int hight(heap_t *root)
{
	int count;

	if (!root)
		return (0);
	if (root)
		count = 1;

	count += hight(root->left);
	count += hight(root->right);

	return (count);
}

/**
 * verify_level - checks if the binary tree has the right level
 * @tree: pointer to binary tree
 * Return: 1 if perfect, 0 if not
 */
int verify_level(const heap_t *tree)
{
	int left, right;

	if (!tree)
		return (0);

	left = hight(tree->left);
	right = hight(tree->right);

	if (left == right)
		return (1);
	return (0);
}

/**
 * get_parent - finds the parent node
 * @root: pointer to root of binary tree
 * Return: pointer to parent node
 */
heap_t *get_parent(heap_t *root)
{
	heap_t *parent = NULL;
	int left_branch, right_brach, left_check, right_check;

	if (!root)
		return (NULL);

	parent = root;
	left_branch = hight(parent->left);
	right_brach = hight(parent->right);

	left_check = verify_level(parent->left);
	right_check = verify_level(parent->right);

	if (!left_branch || !right_brach)
		return (parent);

	if (!left_check || (left_check && right_check && left_branch == right_brach))
		return (get_parent(parent->left));

	if (!right_check || (left_check && right_check && left_branch > right_brach))
		return (get_parent(parent->right));

	return (parent);
}

/**
 * sorted - sorts the node values between parent and child
 * @new_node: double pointer to the new node
 */
void sorted(heap_t **new_node)
{
	heap_t *current = NULL;
	int temp;

	current = *new_node;
	while (current->parent)
	{
		if (current->parent->n < current->n)
		{
			temp = current->parent->n;
			current->parent->n = current->n;
			current->n = temp;
			*new_node = current->parent;
		}
		current = current->parent;
	}
}

/**
 * heap_insert - creates a binary tree node
 * @root: double pointer to the root node of the Heap
 * @value: value to put in the new node
 * Return: pointer to new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent = NULL;

	parent = get_parent(*root);
	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (!parent)
		*root = new_node;
	else if (!(parent->left))
		parent->left = new_node;
	else
		parent->right = new_node;

	sorted(&new_node);

	return (new_node);
}
