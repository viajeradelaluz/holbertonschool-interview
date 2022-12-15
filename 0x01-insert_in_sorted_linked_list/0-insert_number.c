#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *current;

	current = *head;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (!head)
	{
		*head = new;
		return (new);
	}

	while (current->next != NULL)
	{
		if (current->n <= number && current->next->n >= number)
		{
			new->next = current->next;
			current->next = new;
			return (new);
		}
		current = current->next;
	}

	return (new);
}
