#include "shell.h"

/**
 * _strspn - search a string for a set of bytes
 *@s: source string
 *@accept: accepted string
 *
 * Return: number of bytes in the init segment
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int a = 0, b, t = 0;

	while (accept[a])
	{
		b = 0;

		while (s[b] != 32)
		{
			if (accept[a] == s[b])
			{
				t++;
			}
			b++;
		}
		a++;
	}
	return (t);
}

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
 * _strtok - splits string.
 * @str: the input string.
 * @delim: the string containing delimiter characters.
 *
 * Return: a pointer to the next token found in the input string, or NULL.
 */

char *_strtok(char *str, const char *delim)
{
	static char *s; /* Local buffer to track the progress */
	int i;			/* Delimiter index */
	char *token;

	if (str != NULL)
		s = str;

	else if (*s == '\0')
	{
		return (NULL);
	}
	while (*s != '\0')
	{
		for (i = 0; delim[i] != '\0'; i++)
		{
			if (*s == delim[i])
				break;
		}
		if (delim[i] == '\0')
			break;
		s++;
	}
	token = s;

	while (*s != '\0')
	{
		for (i = 0; delim[i] != '\0'; i++)
		{
			if (*s == delim[i])
			{
				*s = '\0';
				s++;
				return (token);
			}
		}
		s++;
	}
	s = "\0";
	return (token);
}
/**
 * _strcmp - a function that compares two strings
 * @s1: string to be compared
 * @s2: another string to be compared
 *
 * Return: int value
 */
// int _strcmp(const char *s1, const char *s2)
// {
// 	int i = 0;

// 	while (s1[i] && s2[i] != '\0')
// 	{
// 		if (s1[i] != s2[i])
// 		{
// 			return (s1[i] - s2[i]);
// 		}
// 		i++;
// 	}
// 	return (s1[i] - s2[i]);
// }

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