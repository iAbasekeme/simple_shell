#include "shell.h"

/**
 * _getenv - A function that gets an environment variable
 * @name: the name of the environent variable
 * Return: Duplicate of the environment variable, else (NULL)
 */
char *_getenv(const char *name)
{
	char **env = environ;
	char *val;

	while ((val = (*env++)) != NULL)
	{
		if (strncmp(val, name, strlen(name)) == 0)
		{
			return (strdup(val));
		}
	}
	return (NULL);
}

