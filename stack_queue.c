#include "monty.h"

/**
 * _stack - sets the format of the data to a queue (LIFO)
 * @head: pointer to a head of the list
 * @n: line number
 */
void _stack(stack_t **head, unsigned int n)
{
	(void)head;
	(void)n;
	data_struct = 0;
}

/**
 * _queue - sets the format of the data to a stack (FIFO)
 * @head: pointer to a head of the list
 * @n: line number
 */
void _queue(stack_t **head, unsigned int n)
{
	(void)head;
	(void)n;
	data_struct = 1;
}

/**
 * add_queue - add node to the tail stack
 * @new_node: new node to add
 * @head: head of the stack
 * Return: no return
 */
void add_queue(stack_t **head, stack_t *new_node)
{
	stack_t *temp;

	temp = *head;

	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}
