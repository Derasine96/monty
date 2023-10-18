#include "monty.h"

/**
 * split_tokens - tokenize a given buffer
 * @buffer: string to tokenize
 *
 * Return: an array
 */
char **split_tokens(char *buffer)
{
	char *token = NULL, **arr;
	int i = 0;
	char *delim = "\t  \r\n";

	token = strtok(buffer, delim);

	if (token == NULL)
		return (NULL);

	arr = malloc(sizeof(char **) * 3);
	if (arr == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free(buffer);
		exit(EXIT_FAILURE);
	}

	while (token)
	{
		if (i < 3)
			arr[i] = token;
		token = strtok(NULL, delim);
		i++;
	}

	arr[2] = NULL;

	return (arr);
}
