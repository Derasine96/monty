#include "monty.h"

/**
 * data_struct - global variable to store data structure
 * when the value is 0, it's a stack and when the value is 1, it's a queue
 */
unsigned int data_struct = 0;

/**
 * main - control program flow
 * @argc: argument count
 * @argv: argument list
 * Return: Nothing
 */
int main(int argc, char *argv[])
{
	unsigned int line_number = 0;
	char **tokens = NULL;
	stack_t *head = NULL;
	char *buffer = NULL;
	FILE *fp;
	size_t n;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		fflush(stderr);
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r+");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		fflush(stderr);
		exit(EXIT_FAILURE);
	}

	while (getline(&buffer, &n, fp) != -1)
	{
		line_number++;
		tokens = split_tokens(buffer);
		if (tokens)
		{
			op_call(&head, tokens, line_number);
			free(tokens);
		}
	}
	free(buffer);
	free_stack(&head);
	fclose(fp);

	return (0);
}
