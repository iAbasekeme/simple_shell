#include "shell.h"
/**
 * main - A main function
 * @ac: argument count
 * @argv: argument vector
 * @env: environment
 *
 * Return: 0 on success
 */
int main(int ac, char *argv[], char *env[])
{
	size_t prompdisp, n;
	char **str, *prompt = "#cisfun$ ";
	char *line = NULL;
	ssize_t input_read;
	int j, u = 0, i, k, exit_status = EXIT_SUCCESS;
	(void)ac;

	while (1)
	{
		if (isatty(0) == 1)
		{
			prompdisp = _strlen(prompt);
			write(1, prompt, prompdisp);
		}
		input_read = getline(&line, &n, stdin);
		if (input_read == -1)
		{
			free(line);
			exit(exit_status);
		}
		line[input_read] = '\0';
		i = 0;
		while (i < _strlen(line) && line[i] != '\0' && line[i] == ' ' && line[i] == '\t')
		{
			i++;
			continue;
		}
		if ((!line + i))
			continue;
		str = split_string(line + i);
		if (_strcmp(str[0], "env") == 0)
		{
			for (j = 0; *(environ + j) != NULL; j++)
			{
				write(STDOUT_FILENO, *(environ + j), _strlen(*(environ + j)));
				write(1, "\n", 1);
			}
			k = 0;
			while (str[k] != NULL)
			{
				free(str[k]);
				k++;
			}
			free(str);
			continue;
		}
		if (_strcmp(str[0], "exit") == 0)
		{
			for (; str[u] != NULL; u++)
			{
				free(str[u]);
			}
			free(str);
			free(line);
			exit(EXIT_SUCCESS);
		}
		if (_exc_fork(str, argv, env) == EXIT_FAILURE)
			exit_status = 127;
		else
			exit_status = EXIT_SUCCESS;
		j = 0;

		while (str[j] != NULL)
		{
			free(str[j]);
			j++;
		}
		free(str);
	}
	free(line);
	return (0);
}
