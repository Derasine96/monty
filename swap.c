#include "monty.h"
/**
 * stack_swap - swaps the data in two nodes
 * @head: pointer to a stack_t
 * @n: line number
 */
void stack_swap(stack_t **head, unsigned int n)
{
	int temp;
	stack_t *first, *second;

	if (!head || !*head || !(*head)->n)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	first = *head;
	second = (*head)->next;
	if (!second)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	temp = first->n;
	first->n = second->n;
	second->n = temp;
}
