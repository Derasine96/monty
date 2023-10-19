#include "monty.h"
/**
 * stack_pint - prints the value at the top stack
 * @head: pointer to first node
 * @n: line number that opcode is call at.
 */
void stack_pint(stack_t **head, unsigned int n)
{
	stack_t *temp;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", n);
		exit(EXIT_FAILURE);
	}

	temp = *head;

	if (temp != NULL)
	{
		fprintf(stdout, "%d\n", (*head)->n);
		return;
	}
}
