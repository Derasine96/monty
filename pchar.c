#include "monty.h"
/**
 * stack_pchar - prints out a char
 * @head: pointer to a stack_t
 * @n: line number where the opcode is called
 */
void stack_pchar(stack_t **head, unsigned int n)
{
	if (!head || !(*head) || (*head)->n < 0 || (*head)->n > 127)
	{
		if (!head || !(*head))
			fprintf(stderr, "L%u: can't pchar, stack empty\n", n);
		else
			fprintf(stderr, "L%u: can't pchar, value out of range\n", n);

		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", (*head)->n);
}
