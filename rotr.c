#include "monty.h"
/**
 * stack_rotr - Rotates the stack to the right)
 * @head: Pointer to a stack_t
 * @n: Line number
 */
void stack_rotr(stack_t **head, unsigned int n)
{
	stack_t *left, *right;
	(void)n;

	if (head == NULL || (*head) == NULL || (*head)->next == NULL)
		return;
	left = right = *head;
	while (right->next)
		right = right->next;
	left->prev = right;
	right->next = left;
	left = right;
	right = left->prev;
	left->prev = NULL;
	right->next = NULL;
	*head = left;
}
