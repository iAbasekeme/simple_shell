#include "shell.h"

/**
 * _strncpy - copy up to n characters from source string to dest buffer.
 * @dest: the destination buffer where the copied string will be stored.
 * @src: the source string to be copied.
 * @n: the maximum number of characters to copy.
 *
 * Return: a pointer to the destination buffer.
 */

char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}
