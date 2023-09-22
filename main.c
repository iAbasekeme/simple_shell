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
	int j, u = 0, i = 0;
	(void)ac;
	while (1)
	{
		if (isatty(0) == 1)
		{
			prompdisp = _strlen(prompt);
			write(1, prompt, prompdisp);
		}
		input_read = getline(&line, &n, stdin);
		if (_strcmp(line, "") == 0)
			continue;
		else if (input_read == -1)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		while (i < _strlen(line) && line[i] != '\0' && line[i] == ' ')
		{
			i++;
			continue;
		}
		str = split_string(line);
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
		_exc_fork(str, argv, env);
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
