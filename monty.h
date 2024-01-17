#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - Doubly linked list representation of a stack (or queue).
 * @n: Integer value.
 * @prev: Points to the previous element of the stack (or queue).
 * @next: Points to the next element of the stack (or queue).
 *
 * Description: Doubly linked list node structure
 * for stack, queues, LIFO, FIFO in Holberton project.
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bus_s - Structure containing variables for args, file, line content
 * @arg: Value.
 * @file: Pointer to the Monty file.
 * @content: Line content.
 * @lifi: Flag indicating a change between stack and queue.
 *
 * Description: This structure carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;
/**
 * struct instruction_s - Structure representing an opcode and its function.
 * @opcode: The opcode.
 * @f: Function to handle the opcode.
 *
 * Description: The structure defines an opcode and its corresponding function
 * for stack, queues, LIFO, FIFO in the Holberton project.
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void push_node(stack_t **head, unsigned int number);
void print_all(stack_t **head, unsigned int number);
void print(stack_t **head, unsigned int number);
int execution(char *content, stack_t **head, unsigned int count, FILE *file);
void stack_free(stack_t *head);
void print_top(stack_t **head, unsigned int count);
void swap_top(stack_t **head, unsigned int count);
void add_funct(stack_t **head, unsigned int count);
void print_nothing(stack_t **head, unsigned int count);
void subtraction(stack_t **head, unsigned int count);
void divide(stack_t **head, unsigned int count);
void multiply(stack_t **head, unsigned int count);
void mod(stack_t **head, unsigned int count);
void printchar(stack_t **head, unsigned int count);
void print_string(stack_t **head, unsigned int count);
void rot_top(stack_t **head, unsigned int count);
void rotate(stack_t **head, __attribute__((unused)) unsigned int count);
void node_add(stack_t **head, int n);
void addsqueue(stack_t **head, int n);
void queue(stack_t **head, unsigned int count);
void stack_free(stack_t **head, unsigned int count);
#endif
