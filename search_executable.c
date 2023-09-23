#include "shell.h"

/**
 * search_exec - A function that searches for executable in a file
 * @command: command to search for
 *
 * Return: Duplicated string of the command
 */

char *search_exec(char *command)
{
	struct stat buf;
	char *path = _getenv("PATH");
	char *path_copy;
	char *directory;
	char *executable_path;

	if (!path)
		return (NULL);
	path_copy = _strdup(path);
	directory = strtok(path_copy, ":");
	executable_path = malloc(_strlen(directory) + _strlen(path_copy) + 2);
	while (directory != NULL)
	{
		if (executable_path != NULL)
		{
			_strcpy(executable_path, directory);
			_strcat(executable_path, "/");
			_strcat(executable_path, command);
			if (stat(executable_path, &buf) == 0)
			{
				free(path);
				free(path_copy);
				return (executable_path);
			}
			directory = strtok(NULL, ":");
		}
	}
	if (stat(command, &buf) == 0)
	{
		free(path);
		free(path_copy);
		free(executable_path);
		return (_strdup(command));
	}
	free(path_copy);
	free(executable_path);
	/**free(command);*/
	free(path);
	return (NULL);
}
