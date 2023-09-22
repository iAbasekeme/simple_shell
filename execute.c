#include "shell.h"
/**
 * _exc_fork - A function that executes a line
 * @path: path to the file
 * @argv: argument vector
 * @envp: environment array
 * Return: status of file
 */
int _exc_fork(char **path, char *argv[], char *envp[])
{
	char *exec_func = search_exec(path[0]);
	pid_t pid;
	int status;
	int result;
	int y = 0;

	(void)argv;
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0)
	{
		result = execve(exec_func, path, envp);
		if (result == -1)
		{
			perror("execve");
			for (; path[y] != NULL; y++)
			{
				free(path[y]);
			}
			free(path);
			free(exec_func);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
	free(path);
	free(exec_func);
	return (status);
}
