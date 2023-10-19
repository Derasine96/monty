#include "monty.h"
/**
 * stack_mod - divides the 2nd-top element by the top element in the stack
 * @head: pointer to a stack_t
 * @n: line number
 */
void stack_mod(stack_t **head, unsigned int n)
{
	int div1, div2, res;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", n);
		exit(EXIT_FAILURE);
	}

	div1 = (*head)->n;
	if (div1 == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", n);
		exit(EXIT_FAILURE);
	}
	div2 = (*head)->next->n;
	res = div2 % div1;
	(*head)->next->n = res;
	stack_pop(head, n);
}
