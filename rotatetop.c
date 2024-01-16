#include "monty.h"
/**
  *rot_top- rotates the stack to the top
  *@head: stack head
  *@count: line_number
  *Return: no return
 */
void rot_top(stack_t **head,  __attribute__((unused)) unsigned int count)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}
