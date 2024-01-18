#include "monty.h"
/**
 * push_node - add node to the stack
 * @head: stack head
 * @count: line_number
 * Return: no return
*/
void push_node(stack_t **head, unsigned int count)
{
	int n, j = 0, control = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				control = 1; }
		if (control == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		node_add(head, n);
	else
		addsqueue(head, n);
}

