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
	char *line = NULL, *line_dup = NULL;
	ssize_t input_read;
	int j, u = 0, i;
	char **env = environ;
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
			exit(EXIT_SUCCESS);
		}
		line[input_read] = '\0';
		i = 0;
		while (i < _strlen(line) && line[i] != '\0' && line[i] == ' ')
		{
			i++;
			continue;
		}
		if ((!line + i))
			continue;
		line_dup = _strdup(line + i);
		str = split_string(line);
		if (_strcmp(str[0], "env") == 0)
		{
			for (*env = environ; *env != NULL; *env++)
			{
				write(STDOUT_FILENO, *env, _strlen(*env));
			}
		}
		if (_strcmp(str[0], "exit") == 0)
		{
			for (; str[u] != NULL; u++)
			{
				free(str[u]);
			}
			free(str);
			free(line);
			free(line_dup);
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
	free(line_dup);
	return (0);
}
