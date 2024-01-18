#include "monty.h"
/**
 * mode_func -  aswitch the mode queue/stack
 * @head: head of double list
 * @count: line number of opcode
 * Return: none
 */
void mode_func(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;

	if (strcmp(datax.opcode, "queue") == 0)
		datax.mode = 1;
	else if (strcmp(datax.opcode, "stack") == 0)
		datax.mode = 0;
}

/**
 * push_func -  adds a new node at the beginning
 * @head: head of double list
 * @count: line number of opcode
 * Return: none
 */
void push_func(stack_t **head, unsigned int count)
{
	stack_t *new, *last;
	int i = 0;

	(void)count;
	if (!head)
		return;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed");
		free_stack(datax.head);
		exit(EXIT_FAILURE);
	}
	new->n = datax.push_value;
	if (datax.mode == 0 || !*head)
	{
		if (*head)
		{
			new->next = *head;
			(*head)->prev = new;
		}
		else
			new->next = NULL;
		new->prev = NULL;
		*head = new;
	}
	else if (datax.mode == 1)
	{
		last = *head;
		for (i = 0; last; i++)
		{
			if (!last->next)
				break;
			last = last->next;
		}
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}
}

/**
 * pall_func -  prints all the elements of a dlistint_t list
 * @head: head of double list
 * @count: line number of opcode
 * Return: none
 */
void pall_func(stack_t **head, unsigned int count)
{
	stack_t *current = *head;
	int i;

	(void)count;
	for (i = 0; current; i++)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
	fflush(stdout);
}

/**
 * pint_func -  prints the value at the top of the stack
 * @head: head of double list
 * @count: line number of opcode
 * Return: none
 */
void pint_func(stack_t **head, unsigned int count)
{
	if (!*head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", count);
		free_stack(datax.head);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*head)->n);
	fflush(stdout);
}

/**
 * pop_func - removes the top element of the stack
 * @head: head of double list
 * @count: line number of opcode
 * Return: none
 */
void pop_func(stack_t **head, unsigned int count)
{

	if (!*head)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		free_stack(datax.head);
		exit(EXIT_FAILURE);
	}
	if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		*head = (*head)->next;
		free((*head)->prev);
		(*head)->prev = NULL;
	}
}

/**
 * swap_func - swaps the top two elements of the stack.
 * @head: head of double list
 * count: line number of opcode
 * Return: none
 */
void swap_func(stack_t **head, unsigned int count)
{
	stack_t *tmp1;

	if (!*head || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		free_stack(datax.head);
		exit(EXIT_FAILURE);
	}
	tmp1 = *head;
	tmp1->prev = tmp1->next;
	if ((head)->next->next == NULL)
		tmp1->next = NULL;
	else
	{
		tmp1->next = tmp1->next->next;
		tmp1->next->prev = *head;
	}
	*head = tmp1->prev;
	(*head)->prev = NULL;
	(*head)->next = tmp1;
}

/**
 * add_func - adds the top two elements of the stack.
 * @head: head of double list
 * @count: line number of opcode
 * Return: none
 */
void add_func(stack_t **head, unsigned int count)
{
	int value = 0;

	if (!*head || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		free_stack(datax.head);
		exit(EXIT_FAILURE);
	}
	value = (*head)->n;
	pop_func(&datax.head, datax.line_num);
	(*head)->n += value;
}

/**
 * nop_func - doesn’t do anything.
 * @head: head of double list
 * @count: line number of opcode
 * Return: none
 */
void nop_func(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;
}

/**
 * sub_func - subtracts the top element of the stack
 *  from the second top element of the stack.
 * @head: head of double list
 * @count: line number of opcode
 * Return: none
 */
void sub_func(stack_t **head, unsigned int count)
{
	int value = 0;

	if (!*head || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		free_stack(datax.head);
		exit(EXIT_FAILURE);
	}
	value = (*head)->n;
	pop_func(&datax.head, datax.line_num);
	(*top)->n -= value;
}

/**
 * div_func - divides the second top element of
 * the stack by the top element of the stack.
 * @head: head of double list
 * @count: line number of opcode
 * Return: none
 */
void div_func(stack_t **head, unsigned int count)
{
	int value = 0;

	if (!*head || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		free_stack(datax.head);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		free_stack(datax.head);
		exit(EXIT_FAILURE);
	}
	value = (*head)->n;
	pop_func(&datax.head, datax.line_num);
	(*head)->n /= value;
}

/**
 * mul_func - multiplies the second top element
 * of the stack with the top element of the stack.
 * @head: head of double list
 * @count: line number of opcode
 * Return: none
 */
void mul_func(stack_t **head, unsigned int count)
{
	int value = 0;

	if (!*head || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", head);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	value = (*head)->n;
	_pop(&datax.head, datax.line_num);
	(*head)->n *= value;
}

/**
 * mod_func - computes the rest of the division of the second
 *  top element of the stack by the top element of the stack.
 * @head: head of double list
 * @count: line number of opcode
 * Return: none
 */
void mod_func(stack_t **head, unsigned int count)
{
	int value = 0;

	if (!*head || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		free_stack(datax.head);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		free_stack(datax.count);
		exit(EXIT_FAILURE);
	}
	value = (*head)->n;
	pop_func(&datax.head, datax.line_num);
	(*head)->n %= value;
}

/**
 * pchar_func- prints the char at the top of the stack (ascii).
 * @head: head of double list
 * @count: line number of opcode
 * Return: none
 */
void pchar_func(stack_t **head, unsigned int count)
{
	if (!*head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		free_stack(datax.head);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n > 127 || (*head)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		free_stack(datax.head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}

/**
 * pstr_func - prints the string starting at the top of the stack.
 * @head: head of double list
 * @count: line number of opcode
 * Return: none
 */
void pstr_func(stack_t **head, unsigned int count)
{
	stack_t *current = *head;
	int i;
	(void)count;

	for (i = 0; current && current->n != 0 &&
				!(current->n > 127 || current->n < 0);
		 i++)
	{
		fprintf(stdout, "%c", current->n);
		current = current->next;
	}
	fprintf(stdout, "\n");
}

/**
 * rotl_func -  rotates the stack to the top.
 * @head: head of double list
 * @count: line number of opcode
 * Return: none
 */
void rotl_func(stack_t **head, unsigned int count)
{
	stack_t *last = *head;
	int i;

	if (!*head)
		return;
	(void)count;
	for (i = 0; last; i++)
	{
		if (!last->next)
			break;
		last = last->next;
	}
	last->next = *head;
	(*head)->prev = last;
	(*head) = (*top)->next;
	(*head)->prev->next = NULL;
	(*head)->prev = NULL;
}

/**
 * rotr_func - rotates the stack to the bottom.
 * @head: head of double list
 * @count: line number of opcode
 * Return: none
 */
void rotr_func(stack_t **head, unsigned int count)
{
	stack_t *last = *head;
	int i;

	if (!*head || (*head)->next == NULL)
		return;
	(void)count;
	for (i = 0; last; i++)
	{
		if (!last->next)
			break;
		last = last->next;
	}
	last->next = *head;
	last->prev->next = NULL;
	(*head)->prev = last;
	(*head) = last;
	last->prev = NULL;
}
