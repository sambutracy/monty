#include "monty.h"

/**
 * execute - exec opcode
 * Return: none
 */
void execute(void)
{
	instruction_t ins[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{"swap", swap_func},
		{"add", add_func},
		{"nop", nop_func},
		{"sub", sub_func},
		{"div", div_func},
		{"mul", mul_func},
		{"mod", mod_func},
		{"pchar", pchar_func},
		{"pstr", pstr_func},
		{"rotl", rotl_func},
		{"rotr", rotr_func},
		{"queue", mode_func},
		{"stack", mode_func},
		{NULL, NULL},
	};
	int j = 0;

	for (j = 0; ins[j].opcode; j++)
	{
		if (strcmp(datax.opcode, ins[j].opcode) == 0)
		{
			ins[j].f(&datax.head, datax.line_num);
			break;
		}
	}
	if (!ins[j].opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
				datax.line_num, datax.opcode);
		free_stack(datax.head);
		exit(EXIT_FAILURE);
	}
}
/**
 * remove_spaces - remove spaces
 * @str: string
 * Return: new string
 */
char *remove_spaces(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			str++;
		else
			break;
	}
	return (str);
}

/**
 * main -  count how many charachter in number
 * @argc: number
 * @argv: number
 * Return: the number lentgh
 */
int main(int argc, char **argv)
{
	char line[100], *token;
	int i = 0;

	datax.mode = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	datax.mfile = openfile_f(argv[1]);
	while (fgets(line, sizeof(line), datax.mfile) != NULL)
	{
		if (strlen(remove_spaces(line)) < 3 || remove_spaces(line)[0] == '#')
		{
			datax.line_num++;
			continue;
		}
		datax.line_num++;
		token = strtok(line, " \n");
		for (i = 0; token != NULL && i < 2; i++)
		{
			if (i == 0) /*first part command first loop*/
				datax.opcode = token;
			if (strcmp(datax.opcode, "push") != 0) /*if opcode is not push break*/
				break;
			if (i == 1)
				verify(token);
			token = strtok(NULL, " \n");
		}
		if (strcmp(datax.opcode, "push") == 0 && i == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", datax.line_num);
			free_stack(datax.head);
			exit(EXIT_FAILURE);
		}
		execute();
	}
	free_stack(datax.head);
	exit(EXIT_SUCCESS);
}
