#include "shell.h"

/**
 * _strlen - Returns the length of a string
 * @s: length of string to be printed.
 *
 * Return: string length
 */
int _strlen(char *s)
{
	int c = 0;

	for (; *s != '\0'; s++)
	{
		c++;
	}
	return (c);
}

/**
 * *_strchr - a function that locates a character in a string.
 * @s: the string to be scanned
 * @c: character to be searched in the string
 *
 * Return: memory area replaced
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	if (c == '\0')
	{
		return (s);
	}
	return ('\0');
}

/**
 * _strcmp - a function that compares two strings
 * @s1: string to be compared
 * @s2: another string to be compared
 *
 * Return: int value
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * _strdup - duplicates a string.
 * @str: the string to be duplicated.
 *
 * Return: a pointer to newly allocated memory containing a duplicate of @str.
 * NULL if insufficient memory is available or @str is NULL.
 */
char *_strdup(const char *str)
{
	char *new_str;
	size_t len;

	if (str == NULL)
	{
		return (NULL);
	}

	len = strlen(str);
	new_str = malloc(sizeof(char) * (len + 1));

	if (!new_str)
	{
		return (NULL);
	}

	_strncpy(new_str, str, len + 1);

	return (new_str);
	free(new_str);
}

/**
 * *_strncpy - a function that copies a string.
 * @dest: destination value
 * @src: source value
 *
 * Return: pointer to string dest
 */
char *_strcpy(char *dest, char *src)
{
	int j = 0;

	while (src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

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