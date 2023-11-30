#include "shell.h"

/**
 * _strdup - Entry point
 *
 *  * @str: string to copy
 *
 * Description: Function that returns a pointer to a newly
 * allocated space in memory, which contains a copy of the
 * string given as a parameter.
 *
 * Prototype: char *_strdup(char *str);
 *
 * The _strdup() function returns a pointer to a new string which
 * is a duplicate of the string str. Memory for the new string
 * is obtained with malloc, and can be freed with free.
 *
 * Returns NULL if str = NULL
 *
 * On success, the _strdup function returns a pointer to the
 * duplicated string. It returns NULL if insufficient memory was available
 *
 * Return: A pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 *
 */

char *_strdup(char *str)
{
	char *s;
	int i = 0, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	s = malloc((len + 1) * sizeof(char));

	if (s != NULL)
	{
		for (i = 0; i <= len + 1; i++)
			s[i] = str[i];

		s[i] = '\0';

		return (s);
	}

	return (NULL);
}


/**
 * _strlen - Entry point
 *
 *  * @s: This is the C string to be reversed.
 *
 * Description: Function that returns the length of a string.
 * using recursion
 *
 * Prototype: int _strlen_recursion(char *s);
 *
 *
 * Return: The length of a string.
 *
 */

int _strlen(char *s)
{
	if (*s == '\0')
		return (0);

	else
		return (1 + _strlen(s + 1));
}


/**
 * _strcpy - Entry point
 *
 *  * @dest: pointer to a string
 *  * @src: pointer to a string
 *
 * Description: that copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 *
 * Prototype: char *_strcpy(char *dest, char *src);
 *
 * Return: the pointer to dest
 *
 */

char *_strcpy(char *dest, char *src)
{
	int i, j, len = 0;

	for (j = 0; src[j] != '\0'; j++)
	{
		len++;
	}

	for (i = 0; i <= len; i++)
	{
		dest[i] = src[i];
	}


	return (dest);
}

