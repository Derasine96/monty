#include "monty.h"
/**
 * stack_mul - multiply and pop nodes
 * @head: pointer to stack_t
 * @n: number of lines
 * Return: Nothing
 */
void stack_mul(stack_t **head, unsigned int n)
{
	if (head == NULL || (*head == NULL) || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", n);
		if (*head)
			free_stack(head);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n = ((*head)->next->n) * ((*head)->n);
	stack_pop(head, n);
}
