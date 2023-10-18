#include "monty.h"
/**
 * free_stack - free the stack
 * @head: ptr to head of the list
 * Return: Nothing
 */
void free_stack(stack_t **head)
{
	stack_t *temp = *head;

	while (temp)
	{
		if (!temp->next)
		{
			free(temp);
			break;
		}
		temp = temp->next;
		free(temp->prev);
	}
}
