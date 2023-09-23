#include "shell.h"
<<<<<<< HEAD
/**
 * sigint_handler - function to send signal for ctrl + c
 */
void sigint_handler()
{
	char *prompt_shell = "\n#cisfun$ ";

	write(STDOUT_FILENO, prompt_shell, _strlen(prompt_shell));
}
=======
int check_exit_status(char *str);
>>>>>>> 79099a6883339fa0e057ba90257bb155bbb24edb
/**
 * interactive_mode - shell interaction mode
 * @argv: array of argument
 * @env: the environment
 */
void interactive_mode(char **argv, char **env)
{
<<<<<<< HEAD
	char *line;
	char **tokens;
	char *prompt_shell = "#cisfun$ ";
	int len = _strlen(prompt_shell);
	int number = 0;

=======
	size_t prompdisp, n;
	char **str, *prompt = "#cisfun$ ";
	char *line = NULL;
	ssize_t input_read;
	int j, u = 0, i, k, exit_status = EXIT_SUCCESS;
	(void)ac;
>>>>>>> 79099a6883339fa0e057ba90257bb155bbb24edb

	while (1)
	{
		if (signal(SIGINT, sigint_handler) == SIG_ERR)
		{
<<<<<<< HEAD
			perror("signal");
			exit(EXIT_FAILURE);
=======
			prompdisp = _strlen(prompt);
			write(1, prompt, prompdisp);
>>>>>>> 79099a6883339fa0e057ba90257bb155bbb24edb
		}
		write(STDOUT_FILENO, prompt_shell, len);
		line = prompt();
		if (line == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			free(line);
<<<<<<< HEAD
		}
		tokens =  _split(line);
		if (tokens == NULL)
=======
			exit(exit_status);
		}
		line[input_read] = '\0';
		i = 0;
		while (i < _strlen(line) && line[i] != '\0' && line[i] == ' ')
>>>>>>> 79099a6883339fa0e057ba90257bb155bbb24edb
		{
			continue;
		}
<<<<<<< HEAD
		number++;
		execute(tokens, argv, env, number);
	}
}

/**
 * main -my own shell program
 * @argc: number of argument
 * @argv: array of argumemnt
 * @env: environment
 * Return: 0 if success, otherwise -1
 */
int main(int argc __attribute__((unused)), char **argv, char **env)
{

	char *line;
	/*char *command[] = {NULL, NULL};*/
	char **tokens;
	int number = 0;

	if (isatty(STDIN_FILENO) == 1) /*check if we are in interactive mode*/
	{
		interactive_mode(argv, env);
	}
	else
	{
		while (1)
		{
			/*line = non_interactive();*/
			line = prompt();
			if (line == NULL)
=======
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
			if (str[1])
				exit_status = check_exit_status(str[1]);
			for (; str[u] != NULL; u++)
>>>>>>> 79099a6883339fa0e057ba90257bb155bbb24edb
			{
				/*write(STDOUT_FILENO, "\n", 1);*/
				free(line), line = NULL;
				exit(EXIT_SUCCESS);
			}
<<<<<<< HEAD
			tokens = _split(line);
			if (tokens == NULL)
				continue;
			number++;
			execute(tokens, argv, env, number);
=======
			free(str);
			free(line);
			exit(exit_status);
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
>>>>>>> 79099a6883339fa0e057ba90257bb155bbb24edb
		}
	}
<<<<<<< HEAD
	return (0);
=======
	free(line);
	exit(exit_status);
}

/**
 * check_exit - A function that checks the the exit status of an executable
 * @str: string
 *
 * Return: exit status
 */
int check_exit_status(char *str)
{
	int exit_status;

	if (_strcmp(str, "1000") == 0)
	{
		exit_status = 232;
	}
	else if (_strcmp(str, "98") == 0)
	{
		exit_status = 98;
	}
	else
	{
		fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", str);
		exit_status = 2;
	}
	return (exit_status);
>>>>>>> 79099a6883339fa0e057ba90257bb155bbb24edb
}

