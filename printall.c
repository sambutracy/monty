#include "monty.h"
/**
 * print_all - it prints the entire stack
 * @head: stack head value
 * @counter: number used
 * Return: returns void
*/
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
