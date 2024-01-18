#include "monty.h"
/**
 * print_all - it prints the entire stack
 * @head: stack head value
 * @count: number used
 * Return: returns void
*/
void print_all(stack_t **head, unsigned int count)
{
	stack_t *h;
	(void)count;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
