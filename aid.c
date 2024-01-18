#include "monty.h"
/**
 * openfile_f -  open file
 * @name: file name
 * Return: FILE
 */
FILE *openfile_f(char *name)
{
	FILE *mfile;

	mfile = fopen(name, "r");
	if (!mfile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", name);
		exit(EXIT_FAILURE);
	}
	return (mfile);
}

/**
 * num_length -  count how many charachter in number
 * @number: number
 * Return: the number lentgh
 */
size_t num_length(int number)
{
	int length = 0;

	if (!number)
		return (1);
	if (number <= 0)
		length++;
	while (number != 0)
	{
		number /= 10;
		length++;
	}
	return (length);
}

/**
 * verify -  verify is number for push opcode
 * is valid or not
 * @token: token string
 * Return: none
 */
void verify(char *token)
{
	int i = 0;

	if (atoi(token) < 0)
		i++;
	if ((isdigit(token[i]) && strlen(token) == num_length(atoi(token))) ||
		(token[0] == '-' && isdigit(token[1])))
		datax.push_value = atoi(token);
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", datax.line_num);
		free_stack(datax.head);
		exit(EXIT_FAILURE);
	}
}

/**
 * free_stack -  frees stack
 * @head: head of double list
 * Return: none
 */
void free_stack(stack_t *head)
{
	stack_t *nav, *nav2;

	nav = head;
	while (nav)
	{
		nav2 = nav->next;
		free(nav);
		nav = nav2;
	}
	datax.head = NULL;
	fclose(datax.mfile);
}
