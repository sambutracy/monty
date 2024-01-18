#include "monty.h"
/**
  *subtraction- subtration
  *@head: stack head
  *@count: line_number
  *Return: no return
 */
void subtraction(stack_t **head, unsigned int count)
{
	stack_t *aux;
	int x, no_of_nodes;

	aux = *head;
	for (no_of_nodes = 0; aux != NULL; no_of_nodes++)
		aux = aux->next;
	if (no_of_nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	x = aux->next->n - aux->n;
	aux->next->n = x;
	*head = aux->next;
	free(aux);
}
