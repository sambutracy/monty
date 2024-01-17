#include "monty.h"
/**
* execution - execution of the given opcode
* @stack: Head of the linked list representing the stack.
* @count: line counter
* @file: Pointer to the Monty file
* @content: line content
* Return: no return
*/
int execution(char *content, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t opst[] = {
				{"push node", push_node},
				{"print all", print_all},
				{"print", print},
				{"top", print_top},
				{"swap", swap_top},
				{"add", add_funct},
				{"nothing", print_nothing},
				{"subtract", subtraction},
				{"divide", divide},
				{"multiply", multiply},
				{"modulus", mod},
				{"print char", printchar},
				{"print str", print_string},
				{"rotate top", print_top},
				{"rotate", rotate},
				{"queue", queue},
				{"stack", print_top},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
