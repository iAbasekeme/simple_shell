#include "shell.h"

char *search_exec(char *command)
{
	struct stat buf;
	char *path = _getenv("PATH");
	char *directory;

	if (!path)
		return (NULL);
	char *path_copy = strdup(path);
	directory = strtok(path_copy, ":");
	char *executable_path = malloc(strlen(directory) + strlen(path_copy) + 2);
	while (directory != NULL)
	{
		if (executable_path != NULL)
		{
			_strcpy(executable_path, directory);
			strcat(executable_path, "/");
			strcat(executable_path, command);

			if (stat(executable_path, &buf) == 0)
			{
				free(path);
				return (executable_path);
			}
			printf("the path:%s\n", executable_path);
			directory = strtok(NULL, ":");
		}
	}
	free(path);
	return (NULL);
}