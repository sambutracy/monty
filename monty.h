#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data - all data in program
 * @push_value: value to push
 * @line_num: line number of opcode
 * @opcode: the opcode
 * @mfile: file to open
 * @head: the top of stack
 * @mode: 0 mean stack, 1 mean queue
 * in stack you push in the start
 * in the queue you push at end
 */
typedef struct data
{
	int push_value;
	unsigned int line_num;
	char *opcode;
	FILE *mfile;
	stack_t *head;
	int mode;
} data;
data datax;

/*main.c*/
void execute(void);
int main(int argc, char **argv);

/*opcodes.c*/
void push_func(stack_t **head, unsigned int count);
void pall_func(stack_t **head, unsigned int count);
void pint_func(stack_t **head, unsigned int count);
void pop_func(stack_t **head, unsigned int count);
void swap_func(stack_t **head, unsigned int count);
void add_func(stack_t **head, unsigned int count);
void nop_func(stack_t **head, unsigned int count);
void sub_func(stack_t **head, unsigned int count);
void div_func(stack_t **head, unsigned int count);
void mul_func(stack_t **head, unsigned int count);
void mod_func(stack_t **head, unsigned int count);
void pchar_func(stack_t **head, unsigned int count);
void pstr_func(stack_t **head, unsigned int count);
void rotl_func(stack_t **head, unsigned int count);
void rotr_func(stack_t **head, unsigned int count);
void mode_func(stack_t **head, unsigned int count);

/*aid.c*/
FILE *openfile_f(char *name);
size_t num_length(int number);
void verify(char *token);
void free_stack(stack_t *head);

#endif
