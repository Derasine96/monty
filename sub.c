#include "monty.h"
/**
 * stack_sub - subtracts the top element
 * @head: pointer to a stack_t
 * @n: line number
 */
void stack_sub(stack_t **head, unsigned int n)
{
	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n = ((*head)->next->n) - ((*head)->n);
	stack_pop(head, line_number);
}
