#include "shell.h"

// char *_getenv(const char *name)
// {
// 	// Get a pointer to the start of the environment variable list.
// 	char **env = environ;

// 	// Iterate over the environment variable list.
// 	while (*env != NULL)
// 	{
// 		// Compare the current environment variable name to the given name.
// 		if (strcmp(*env, name) == 0)
// 		{
// 			// If the names match, return the value of the current environment variable,
// 			// without the trailing slash.
// 			char *val = strtok(*env + 1, "/");
// 			return val;
// 		}

// 		// Increment the pointer to the next environment variable.
// 		env++;
// 	}

// 	// If the environment variable is not found, return NULL.
// 	return NULL;
// }

char *_getenv(const char *name)
{
	char **env = environ;
	char *val;

	while ((val = (*env++)) != NULL)
	{
		if (strncmp(val, name, strlen(name)) == 0)
		{
			// val = *(env + 1);
			return strdup(val);
		}
	}
	return (NULL);
}