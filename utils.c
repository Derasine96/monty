#include "monty.h"

static instruction_t ops[] = {
	{"push", stack_push},
	{"pall", stack_pall},
	{"pint", stack_pint},
	{"pop", stack_pop},
	{"swap", stack_swap},
	{"add", stack_add},
	{"nop", stack_nop},
	{"sub", stack_sub},
	{"div", stack_div},
	{"mul", stack_mul},
	{"mod", stack_mod},
	{"pchar", stack_pchar},
	{"pstr", stack_pstr},
	{"rotl", stack_rotl},
	{"rotr", stack_rotr},
	{NULL, NULL}
};

/**
 * op_call - calls appropriate function
 * @tokens: pointer to array of operations string
 * @head: pointer to a head of the list
 *
 * Return: nothing
 */
void op_call(stack_t **head, char **tokens)
{
	int i = 0, flag = 0;

	if (tokens[0][0] == '#')
		return;

	while (ops[i].opcode)
	{
		if (strcmp(tokens[0], ops[i].opcode) == 0)
		{
			if (ops[i].f)
			{
				if (strcmp(tokens[0], "push") == 0)
					validate(tokens, head);

				if (tokens[1])
					ops[i].f(head, atoi(tokens[1]));
				else
					ops[i].f(head, line_number);
			}
			flag = 1;
			break;
		}
		i++;
	}

	if (flag == 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
				line_number,
				tokens[0]);
		fflush(stderr);
		exit(EXIT_FAILURE);
	}
}

/**
 * validate - checks if second arg of a token array is valid
 * @tokens: tokens value to check
 * @head: pointer to a head
 */
void validate(char **tokens, stack_t **head)
{
	int i = 0;

	if (!tokens[1])
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		fflush(stderr);
		if (*head)
			free_stack(head);
		free(tokens);
		exit(EXIT_FAILURE);
	}

	while (tokens[1][i])
	{
		if (tokens[1][i] == '-' && i == 0)
			i++;
		if (isdigit(tokens[1][i]) == 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			fflush(stderr);
			if (*head)
				free_stack(head);
			free(tokens);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
