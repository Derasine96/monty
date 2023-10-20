#include "monty.h"
/**
 * stack_pop - remove the top element of the stack
 * @head: pointer to a stack_t
 * @line_no: line number
 */
void stack_pop(stack_t **head, unsigned int line_no)
{
	stack_t *top;

	if (!head || !*head)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_no);
		exit(EXIT_FAILURE);
	}
	top = *head;
	*head = top->next;
	if (*head)
		(*head)->prev = NULL;
	free(top);
}
