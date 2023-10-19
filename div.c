#include "monty.h"
/**
 * stack_div - divides the 2nd-top element by the top element in the stack
 * @head: pointer to a stack_t
 * @n: line number
 */
void stack_div(stack_t **head, unsigned int n)
{
	int div1, div2, result;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", n);
		if (*head)
			free_stack(head);
		exit(EXIT_FAILURE);
	}
	div1 = (*head)->n;
	if (div1 == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", n);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	div2 = (*head)->next->n;
	result = div2 / div1;
	(*head)->next->n = result;
	stack_pop(head, n);
}
