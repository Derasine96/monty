#include "monty.h"
/**
 * stack_rotl - Rotates the stack to the left
 * @head: Pointer to a stack_t
 * @n: Line number
 */
void stack_rotl(stack_t **head, unsigned int n)
{
	stack_t *new_top, *new_last;

	(void)n;
	if (!head || !(*head) || !(*head)->next)
		return;
	new_top = new_last = *head;
	while (new_last->next)
		new_last = new_last->next;
	new_last->next = new_top;
	new_top->prev = new_last;
	*head = new_top->next;
	(*head)->prev = NULL;
	new_top->next = NULL;
}
