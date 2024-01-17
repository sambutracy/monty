#include "monty.h"
/**
 * queue - Prints the top element.
 * @head: Stack head.
 * @count: Line number.
 * Return: No return value.
 */
void queue(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;
	bus.lifi = 1;
}

/**
 * addsqueue - Adds a new node to the tail of the stack.
 * @n: New value to be added.
 * @head: Head of the stack.
 * Return: No return value.
 */
void addsqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
