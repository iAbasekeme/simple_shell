#include "shell.h"
/**
 * execute -function for executing commands
 * @tokens: array of tokens
 * @argv: array of argument
 * @env: environment
 * @number: number of executed command
 * Return: 0 if success.
 */
int execute(char **tokens, char **argv, char **env, int number)
{
	struct builtin commands[] = {
		{"cd", my_cd},
		{NULL, NULL}
	};


	pid_t child_pid;
	int status;
	char *enter_command;
	int exit_status;
	int i;

	(void)argv;

	enter_command = get_path(tokens[0]);

	for (i = 0; commands[i].name != NULL; i++)
	{
		if (_strcmp(tokens[0], commands[i].name) == 0)
		{
			commands[i].f(tokens);
			free(enter_command), enter_command = NULL;
			free_array(tokens);
			return (1);
		}
	}
	if ((_strcmp(tokens[0], "env") == 0))
	{
		my_env(env);

		free(enter_command), enter_command = NULL;
		free_array(tokens);
		return (1);
	}

	if (my_exit(tokens[0]))
	{
		if (tokens[1] != NULL)
		{
			exit_status = atoi(tokens[1]);
			free(enter_command), enter_command = NULL;
			free_array(tokens);
			exit(exit_status);
		}
		else
		{
			free_array(tokens);
			exit(2);
		}
	}

	if (enter_command == NULL || ((_strcmp(tokens[0], "hbtn_ls") == 0) && tokens[1] == NULL))
	{
		erro_mess(argv[0], tokens[0], number);
		free_array(tokens);
		free(enter_command), enter_command = NULL;
		exit(127);
	}
	else
	{
		child_pid = fork(); /* Here we create a child process*/
		if (child_pid == -1)
		{
			perror("Error: ");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0) /*Here we execute command*/
		{
			if ((execve(enter_command, tokens, env) == -1))
			{
				perror("execve");
				free(enter_command), enter_command = NULL;
				free_array(tokens);
				exit(EXIT_FAILURE);
			}
		}
		else /*Herre we are waiting for child process*/
		{
			if (waitpid(child_pid, &status, 0) == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}

			free(enter_command), enter_command = NULL;
			free_array(tokens);
			/*return (status);*/
			return (0);
		}
	}
}

