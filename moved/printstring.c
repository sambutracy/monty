#include "monty.h"
/**
 * print_string - prints the string from top of the stack
 * followed by a new
 * @head: stack head value
 * @counter: number of line
 * Return: returns void
*/
void print_string(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
