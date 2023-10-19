#include "monty.h"
/**
 * _add - adds the top two elements of the stack
 * @head: pointer to a head_t
 * @n: line number
 */
void stack_add(stack_t **head, unsigned int n)
{
	int result;
	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, head too short\n", n);
		exit(EXIT_FAILURE);
	}

	result = (*head)->n + (*head)->next->n;
	stack_pop(head, n);
	(*head)->n = result;
}
