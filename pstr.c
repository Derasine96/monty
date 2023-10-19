#include "monty.h"
/**
 * stack_pstr - prints a string
 * @head: pointered to a stack
 * @n: line number that opcode is call at.
 */
void stack_pstr(stack_t **head, unsigned int n)
{
	stack_t *temp;
	(void) n;

	if (head == NULL || (*head) == NULL)
	{
		fprintf(stdout, "\n");
		return;
	}

	temp = *head;
	while (temp != NULL)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		fprintf(stdout, "%c", temp->n);
		temp = temp->next;
	}
	fprintf(stdout, "\n");
}
