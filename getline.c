#include "shell.h"

/**
 * get_line - a function that get line from the standard inputs
 * Return: gotten line
 */

/*int *get_line(char **a, size_t *b, ...)*/
char *get_line(void)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t input_read;
	ssize_t line_length;

	input_read = getline(&line, &n, stdin);

	if (input_read == -1)
	{
		if (feof(stdin))
		{
			free(line);
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}

	line_length = _strlen(line);
	if (line_length > 0 && line[line_length - 1] == '\n')
	{
		line[line_length - 1] = '\0';
	}
	printf("Gotten line:%s\n", line);
	return (line);
}
