#include "monty.h"
/**
 * print_top - Prints the top element.
 * @head: Stack head.
 * @count: Line number.
 * Return: No return value.
 */
void print_top(stack_t **head, unsigned int count)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
