#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

extern unsigned int data_struct;

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

void stack_push(stack_t **head, unsigned int n);
void stack_pall(stack_t **head, unsigned int n);
void validate(char **tokens, stack_t **head, unsigned int line_number);
void op_call(stack_t **head, char **tokens, unsigned int line_number);
void free_stack(stack_t **head);
char **split_tokens(char *buffer);
void stack_pint(stack_t **head, unsigned int n);
void stack_pop(stack_t **head, unsigned int line_no);
void stack_swap(stack_t **head, unsigned int line_no);
void stack_add(stack_t **head, unsigned int n);
void stack_nop(stack_t **head, unsigned int n);
void stack_sub(stack_t **head, unsigned int n);
void stack_div(stack_t **head, unsigned int n);
void stack_mul(stack_t **head, unsigned int n);
void stack_mod(stack_t **head, unsigned int n);
void stack_pchar(stack_t **head, unsigned int n);
void stack_pstr(stack_t **head, unsigned int n);
void stack_rotl(stack_t **head, unsigned int n);
void stack_rotr(stack_t **head, unsigned int n);
void _stack(stack_t **head, unsigned int n);
void _queue(stack_t **head, unsigned int n);
void add_queue(stack_t **head, stack_t *new_node);

#endif /* MONTY_H */
