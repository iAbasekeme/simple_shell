#include "shell.h"
/**
 * executecmd - A function to execute the commands
 * @argv : Command receivedi
 * @envp : second argument to pass
 * @line : commang line entered
 *
 * Return: 0 when successful and 1 or error
 */

int executecmd(char **argv, char **envp, char *line)
{
	char *p_command;
	unsigned long hashval;
	int i = 0;

	if (_getppid(argv))
	{	free_vector(argv);
		return (1);	}
	p_command = argv[i];
	if (argv[0] == NULL)
	{
		free_vector(argv);
		free(line);
		perror("Error argv");
		return (0);
	}
	hashval = hash(p_command);
	switch (hashval)
	{
		case CD:
			cd_dir(argv, envp);
			break;
		case SETENV:
			set_env_var(argv);
			break;
		case UNSETENV:
			un_set_env_var(argv);
			break;
		case EXIT:
			exitshell(argv, line);
			break;
		case ENV:
			print_env(argv, envp);
			break;
		default:
			{
				process(argv, envp);
				return (0);
			}
	} return (0);
}
/**
 * _getppid - prints the getppid of the program
 * @argv: the command
 *
 * Return: Always 0 for success
 */
int _getppid(char **argv)
{
	char *path;
	unsigned int getpp = getpid();
	char buffer[20];
	const char *stringValue;

	sprintf(buffer, "%u", getpp);
	stringValue = buffer;
	if (!argv[1])
	{
		return (0);
	}
	if (strncmp(argv[1], "$?", 2) == 0)
	{
		myprintf(stringValue);
		myprintf("\n");
		return (1);
	}
	else if (strncmp(argv[1], "$$", 2) == 0)
	{
		myprintf(stringValue);
		myprintf("\n");
		return (1);
	}
	else if (strncmp(argv[1], "$PATH", 5) == 0)
	{
		path = getenv("PATH");
		myprintf(path);
		myprintf("\n");
		return (1);
	}
	else
	{
		myprintf("command not handled");
		return (1);
	}
	return (1);
}
