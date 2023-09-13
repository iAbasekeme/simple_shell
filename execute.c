#include "shell.h"

int exc_fork(const char **path, char *const argv[], char *const envp[])
{
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
        result = execve(path[0], path, envp);

        if (result == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
    waitpid(pid, &status, 0);
    if (WIFEXITED(status))
    {
        status = WEXITSTATUS(status);
    }
    return (status);
}