#include "shell.h"

/**
 * _strcat - concatenates two strings.
 * @dest: the destination string.
 * @src: the source string to be appended to the destination.
 *
 * Return: pointer to the resulting string @dest.
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int len = 0;

	while (dest[len])
	{
		len++;
	}

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[len] = src[i];
		len++;
	}

	dest[len] = '\0';
	return (dest);
}
