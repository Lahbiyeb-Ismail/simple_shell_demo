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
	char *dup;
	int len = 0;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);

	dup = malloc((len + 1) * sizeof(char));

	if (dup != NULL)
	{
		_strcpy(dup, str);
		return (dup);
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
		len++;

	for (i = 0; i <= len; i++)
		dest[i] = src[i];

	return (dest);
}


/**
 * _strcmp - Entry point
 *
 *  * @s1: char array
 *  * @s2: char array
 *
 * Description: Function that compare two character arrays
 * or strings terminated by null value (C-strings) lexicographically.
 *
 * Prototype: int _strcmp(char *s1, char *s2);
 *
 *
 *
 * Return: the pointer to the copied string.
 *
 *
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, ret_val = 0;

	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			ret_val = s1[i] - s2[i];
			break;
		}

		i++;
	}

	return (ret_val);
}

/**
 * _strcat - Entry point
 *
 *  * @dest: pointer to a string
 *  * @src: pointer to a string
 *
 * Description: Function that concatenates two strings.
 *
 * Prototype: char *_strcat(char *dest, char *src);
 *
 * This function appends the src string to the dest string,
 * overwriting the terminating null byte (\0) at the end of dest
 * and then adds a terminating null byte
 *
 * Returns a pointer to the resulting string dest
 *
 * Return: char
 *
 *
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i++] = src[j];
		j++;
	}

	dest[i] = '\0';

	return (dest);
}
