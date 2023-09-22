#include "shell.h"

/**
 * split_string - A fucntion that splits an array of strings
 * @str: array to be tokenized
 *
 * Return: The splitted strings as tokens
 */
char **split_string(char *str)
{
	int cur_position = 0;
	char **tokens;
	int count = 0;
	char *token;
	char *dup_str;

	dup_str = _strdup(str);
	if (!dup_str)
	{
		perror("_strdup");
		free(str);
		exit(EXIT_FAILURE);
	}
	token = strtok(dup_str, " \n");

	while (token != NULL)
	{
		cur_position++;
		token = strtok(NULL, " \n");
	}
	tokens = malloc((cur_position + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		perror("malloc");
		free(str);
		free(dup_str);
		exit(EXIT_FAILURE);
	}

	token = strtok(str, " \n");
	while (token != NULL)
	{
		tokens[count++] = _strdup(token);

		token = strtok(NULL, " \n");
	}
	tokens[count] = NULL;

	free(dup_str);

	return (tokens);
}