#include "shell.h"

int exc_fork(char **path, char *argv[], char *envp[])
{
	char *exec_func = search_exec(path[0]);

	pid_t pid;
	int status;
	int result;

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
			exit(EXIT_FAILURE);
		}
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		return (WEXITSTATUS(status));
	}
	return (status);
}