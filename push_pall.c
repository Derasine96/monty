#include "monty.h"

/**
 * stack_push - pushes a node to a stack
 * @head: head of the stack
 * @data: node data
 */
void stack_push(stack_t **head, unsigned int data)
{
	stack_t *newNode = NULL;

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->prev = newNode->next = NULL;
	newNode->n = data;

	if (!(*head))
		(*head) = newNode;
	else
	{
		(*head)->prev = newNode;
		newNode->next = *head;
		*head = newNode;
	}
}

/**
 * stack_pall - prints a stack
 * @head: pointer to the head of stack_t
 * @n: line number
 */
void stack_pall(stack_t **head, unsigned int __attribute__((__unused__)) n)
{
	stack_t *temp;

	if (!head || !(*head))
		return;
	temp = *head;

	while (temp)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}
}
